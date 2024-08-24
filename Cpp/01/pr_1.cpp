#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

template <typename T>
class dynamic_array
{
	T* data; // T형으로 주솟값을 저장하는 자료형 (배열로 선언되면 0번째 요소를 가리키는 포인터)
	size_t n;
	
public:
	dynamic_array(int n)
	{
		this->n=n; // this->n은 멤버변수, n은 매개변수
		data=new T[n]; // 동적할당
	}
	
	dynamic_array(const dynamic_array<T>& other) // 오버로딩
	{
		n=other.n;
		data=new T[n];
		
		for(int i=0;i<n;i++)
			data[i]=other[i];
	}
	
	T& operator[](int index)
	{
		return data[index];
	}

	// 반환값 상수화. 래퍼런스를 리턴하게 되면 상수 래퍼런스를 반환하여 상수 래퍼런스 변수에만 담을 수 있음.
	// 함수 뒤에 const가 있으면 해당 함수에서 멤버변수가 수정이 불가능하다는 의미.
	const T& operator[](int index) const
	{
		return data[index];
	}
	
	T& at(int index)
	{
		if(index<n)
			return data[index];
		throw "Index out of range";
	}

	// const 객체는 const 함수만 호출가능
	// frined로 선언된 operator+ 함수에서 arr2가 const형이 아닌데도 size 함수 호출이 가능한 것은 size 함수의 반환값이 int형이기 때문.
	size_t size() const
	{
		return n;
	}
	
	~dynamic_array()
	{
		delete[] data;
	}
	
	T*begin() { return data; }
	const T* begin() const { return data; }
	T* end() { return data+n; }
	const T* end() const { return data+n; }

	// freind 함수는 클래스 내부의 함수가 privata이나 protected 멤버를 public처럼 접근할 수 있도록 해줌.
	friend dynamic_array<T> operator+(const dynamic_array<T>& arr1, dynamic_array<T>& arr2)
	{
		dynamic_array<T> result(arr1.size()+arr2.size()); // arr1과 arr2의 크기를 더한 크기의 새로운 객체 result 선언
		copy(arr1.begin(),arr1.end(),result.begin());
		copy(arr2.begin(),arr2.end(),result.begin()+arr1.size());
		// copy 함수는 algorithm 헤더파일에 존재하는 함수
		
		return result;
	}
	
	string to_string(const string& sep=", ")
	{
		if(n==0)
			return "";
		
		ostringstream os; // 문자열 조립
		os<<data[0];
		
		for(int i=1;i<n;i++)
			os<<sep<<data[i]; // os변수에 sep와 data[i]를 계속 붙여나감
		
		return os.str(); // 조립한 결과를 return
	}
};

struct student
{
	string name;
	int standard;
};

// ostream은 출력을 위한 클래스
ostream& operator<<(ostream& os,const student& s) // 오버로딩. cout를 대신할 함수를 정의
{
	return (os<<"["<<s.name<<", "<<s.standard<<"]");
}

int main()
{
	int nStudent;
	cout<<"1번 학생 수를 입력하세요: ";
	cin>>nStudent;
	
	dynamic_array<student> class1(nStudent);
	for(int i=0;i<nStudent;i++)
	{
		string name;
		int standard;
		cout<<i+1<<"번째 학생 이름과 나이를 입력하세요: ";
		cin>>name>>standard;
		class1[i]=student{name,standard};
	}
	
	try
	{
		class1.at(nStudent)=student{"John",8};
	}
	catch(...)
	{
		cout<<"예외 발생!"<<endl;
	}

	// 깊은 복사
	auto class2=class1;
	cout<<"1반을 복사하여 2반을 생성: "<<class2.to_string()<<endl;
	// 오버로딩한 to_string과 operator<< 함수 사용
	
	auto class3=class1+class2; // operator+ 함수 이용
	cout<<"1반과 2반을 합쳐 3반 생성: "<<class3.to_string()<<endl;
	
	return 0;
}
