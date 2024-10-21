#include <iostream>
#include <algorithm>

using namespace std;

struct singly_ll_node
{
	int data;
	singly_ll_node* next;
};
// 컴파일러가 구조체의 크기를 미리 알 필요가 없기에 구조체가 자기 자신을 '포인터'로써 포함하는 것은 가능
// 보통 구조체의 크기는 4byte or 8byte인데 포인터는 주소만을 필요로 하기에 에러가 발생하지 않음

class singly_ll
{
public:
	using node=singly_ll_node; // singly_ll_node를 node라는 이름으로 별칭을 지정
	using node_ptr=node*; // node*을 node_ptr이라는 이름의 별칭으로 지정
	
private:
	node_ptr head;
	// singly_ll_node* head; 와 동일한 코드
	
public:
	void push_front(int val) // forward_list의 front에 push하는 함수
	{
		auto new_node=new node{val,nullptr}; // NULL은 단순히 값 0을 의미, nullptr은 포인터 타입의 null을 의미
		if(head!=nullptr) // head에 다른 노드가 이미 존재하는 경우
			new_node->next=head; // 새로 추가하는 노드의 next(다음 노드를 가리키는 포인터)는 기존의 head를 가리킴
		head=new_node; // head는 새로 추가된 노드를 가리킴
	}
	
	void pop_front() // front의 노드를 pop하는 함수
	{
		auto first=head;
		if(head!=nullptr)
		{
			head=head->next; // 기존의 head를 다음 노드로 옮김
			delete first; // 기존 head 노드 삭제
		}
	}
	
	struct singly_ll_iterator
	{
	private:
		node_ptr ptr; // singly_ll_node* ptr;와 동일한 포인터 멤버
		
	public:
		singly_ll_iterator(node_ptr p):ptr(p){} // 생성자. singly_ll_node*형을 인수로 받아서 ptr에 저장
		int& operator*() {return ptr->data;} // * 연산자 오버로딩. 노드의 data 값을 반환
		node_ptr get() {return ptr;} // 현재 가리키고 있는 노드의 포인터를 반환
	
		// 전위 증가 연산자는 객체의 참조를 반환
		singly_ll_iterator& operator++()
		{
			ptr=ptr->next;
			return *this; // 증가된 후의 ptr을 가리킴
		}

		// 후위 증가 연산자는 이동하기 전 상태의 객체가 필요하기 때문에 객체를 반환
		singly_ll_iterator operator++(int)
		{
			singly_ll_iterator result=*this; // 현재 노드 저장
			++(*this); // 다음 노드로 이동
			return result; // 이전 상태의 객체를 반환하고 다음 노드로 이동
		}

		// friend를 이용해 미멤버함수로 정의
		// 좌우 인자들을 대등하게 다룰 때 미멤버함수로 정의
		// ++나 *와 같이 좌측 피연산자가 항상 객체일 때는 멤버함수로 사용
		// L-value를 주체로 사용할 때는 멤버함수, L-value와 R-value를 동등하게 다룰 때는 비멤버 함수를 사용
		friend bool operator==(const singly_ll_iterator& left,const singly_ll_iterator& right)
		{
			return left.ptr==right.ptr;
		}

		friend bool operator!=(const singly_ll_iterator& left,const singly_ll_iterator& right)
		{
			return left.ptr!=right.ptr;
		}
	};
	
	// const 객체와 비-const 객체가 모두 정의되어 있는 이유는 const 객체는 const 객체만 호출이 가능하기 때문
	// const 객체와 비-const 객체 모두에서 사용할 수 있는 인터페이스를 제공하기 위함
	singly_ll_iterator begin() {return singly_ll_iterator(head);}
	singly_ll_iterator end() {return singly_ll_iterator(nullptr);}
	singly_ll_iterator begin() const {return singly_ll_iterator(head);}
	singly_ll_iterator end() const {return singly_ll_iterator(nullptr);}
	
	singly_ll()=default; // 클래스의 기본 생성자를 생성
	
	// 기존의 singly_ll 객체를 기반으로 새로운 객체를 생성
	singly_ll(const singly_ll& other):head(nullptr)
	{
		if(other.head)
		{
			head=new node{0,nullptr};
			auto cur=head;
			auto it=other.begin();
			while(true)
			{
				cur->data=*it; // 원본 리스트의 현재 노드를 새로운 리스트의 현재 노드에 복사
				
				auto tmp=it; // 현재 반복자 복사
				++tmp; // 다음 노드로 이동
				if(tmp==other.end())
					break;
				
				cur->next=new node{0,nullptr}; // 다음 노드 생성
				cur=cur->next; // cur 포인터를 다음 노드로 이동
				it=tmp; // 다음 노드를 가리키도록 변경
			}
		}
	}
	
	// initializer_list : 템플릿 클래스. 초기화 리스트를 전달할 수 있게 해줌.
	singly_ll(const std::initializer_list<int>& ilist):head(nullptr)
	{
		for(auto it=std::rbegin(ilist);it!=std::rend(ilist);it++)
			push_front(*it); // this->push_front(*it);와 동일
	}
};

int main()
{
	singly_ll sll={1,2,3};
	sll.push_front(0);
	
	cout<<"첫 번째 리스트: ";
	for(auto i:sll)
		cout<<i<<" ";
	cout<<endl;
	
	auto sll2=sll;
	sll2.push_front(-1);
	cout<<"첫 번째 리스트를 복사한 후, 맨 앞에 -1을 추가: ";
	for(auto i:sll2)
		cout<<i<<" ";
	cout<<endl;
	
	cout<<"깊은 복사 후 첫 번째 리스트: ";
	for(auto i:sll)
		cout<<i<<" ";
	cout<<endl;
}
