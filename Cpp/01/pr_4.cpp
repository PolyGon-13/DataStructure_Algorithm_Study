#include <iostream>
#include <forward_list>
#include <vector>

using namespace std;

int main()
{
	vector<string> vec=
	{
		"Lewis Hamilton", "Lewis Hamilton", "Nico Roseberg",
		"Sebastian Vettel", "Lewis Hamilton", "Sebastian Vettel",
		"Sebastian Vettel", "Sebastian Vettel", "Fernando Alonso"
	};
	
	// vector를 이용한 방법
	auto it=vec.begin();
	cout<<"가장 최근 우승자 : "<<*it<<endl;
	
	it+=8;
	cout<<"8년 전 우승자 : "<<*it<<endl;
	
	advance(it,-3);
	cout<<"그후 3년 뒤 우승자 : "<<*it<<endl;
	cout<<endl;
	
	// forward_list를 이용한 방법
	forward_list<string> fwd(vec.begin(),vec.end());
	
	auto it1=fwd.begin();
	cout<<"가장 최근 우승자 : "<<*it<<endl;
	
	advance(it1,5);
	cout<<"5년 전 우승자 : "<<*it<<endl;
	
	// advance(it1,-2); forward_list는 순방향으로만 이동할 수 있기에 해당 코드는 에러 발생
	
	return 0;
}
