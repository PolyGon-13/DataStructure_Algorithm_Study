#include <iostream>

using namespace std;

template <typename T>
struct cir_list_node
{
	T* data;
	cir_list_node* next;
	cir_list_node* prev;
	
	~cir_list_node()
	{
		delete data;
	}
};

template <typename T>
struct cir_list
{
public:
	using node=cir_list_node<T>; // <T>는 템플릿 매개변수로써 T를 전달하는데 사용
	using node_ptr=node*;
	
private:
	node_ptr head; // cir_list_node<T>* head와 동일
	size_t n; // 부호없는 정수형 (배열의 크기나 동적 메모리 할당과 관련된 작업에서 주로 사용됨)
	
public:
	cir_list():n(0)
	{
		head=new node{nullptr,nullptr,nullptr};
		head->next=head;
		head->prev=head;
	}
	
	size_t size() const
	{
		return n;
	}
	
	void insert(const T& value)
	{
		node_ptr newNode=new node{new T(value),nullptr,nullptr};
		n++; // 노드 개수 증가
		
		auto dummy=head->prev; // 원형 연결 리스트에서 head->prev는 마지막 노드를 가리킴
		dummy->next=newNode; // 마지막 노드의 다음을 newNode로 설정
		newNode->prev=dummy; // newNode의 이전을 기존의 마지막 노드로 설정
		
		if(head==dummy) // 리스트가 비어있거나 노드가 하나만 있는 경우
		{
			dummy->prev=newNode; // 기존의 head를 newNode와 연결
			newNode->next=dummy; // newNode의 다음을 기존의 head로 설정
			head=newNode; // newNode를 head로 설정
			return;
		}
		
		newNode->next=head;
		head->prev=newNode;
		head=newNode;
	}
	
	void erase(const T& value)
	{
		auto cur=head; // 시작 노드
		auto dummy=head->prev; // 마지막 노드
		
		while(cur!=dummy)
		{
			if(*(cur->data)==value) // cur 노드의 데이터와 value가 같은지 비교
			{
				cur->prev->next=cur->next; // 이전 노드가 cur의 다음 노드를 가리키도록 설정
				cur->next->prev=cur->prev; // 다음 노드가 cur의 이전 노드를 가리키도록 설정
				if(cur==head) // 삭제할 노드가 head인 경우
					head=head->next; // head를 다음 노드로 이동
				delete cur;
				n--; // 노드 개수 감소
				return;
			}
			cur=cur->next; // value를 찾기 위해 다음 노드로 이동
		}
	}
	
	struct cir_list_it
	{
	private:
		node_ptr ptr;
		
	public:
		cir_list_it(node_ptr p):ptr(p){}
		
		T& operator*()
		{
			return *(ptr->data);
		}
		
		node_ptr get()
		{
			return ptr;
		}
		
		cir_list_it& operator++() // 전위 증감 연산자(++it)
		{
			ptr=ptr->next; // 다음 노드로 이동
			return *this; // 현재 객체 자체를 반환
		}
		
		cir_list_it& operator++(int) // 후위 증감 연산자(it++)
		{
			cir_list_it it=*this; // 현재 객체의 복사본 생성
			++(*this); // 전위 증감 연산자 호출
			return it; // 복사본 반환 (증가 전 상태)
		}
		
		cir_list_it& operator--()
		{
			ptr=ptr->prev;
			return *this;
		}
		
		cir_list_it operator--(int)
		{
			cir_list_it it=*this;
			--(*this);
			return it;
		}
		
		friend bool operator==(const cir_list_it& it1,const cir_list_it& it2)
		{
			return it1.ptr==it2.ptr; // 두 반복자가 같은 노드를 가리키는지 확인
		}
		
		friend bool operator!=(const cir_list_it& it1,const cir_list_it& it2)
		{
			return it1.ptr!=it2.ptr;
		}
	};
	
	cir_list_it begin()
	{
		return cir_list_it{head}; // head를 가리키는 반복자 cir_list_it를 생성하여 반환
	}
	
	cir_list_it begin() const
	{
		return cir_list_it{head};
	}
	
	cir_list_it end()
	{
		return cir_list_it{head->prev};
	}
	
	cir_list_it end() const
	{
		return cir_list_it{head->prev};
	}
	
	cir_list(const cir_list<T>& other):cir_list() // 복사 생성자
	{
		for(const auto& i:other)
			insert(i);
	}
	
	cir_list(const std::initializer_list<T>& i1):head(nullptr),n(0)
	{
		for(const auto& i:i1)
			insert(i);
	}
	
	~cir_list()
	{
		while(size())
		{
			erase(*(head->data));
		}
		
		delete head;
	}
};

struct playlist
{
	cir_list<int> list;
	
	void insert(int song)
	{
		list.insert(song);
	}
	
	void erase(int song)
	{
		list.erase(song);
	}
	
	void loopOnce()
	{
		for(auto& song:list)
			cout<<song<<" ";
		cout<<'\n';
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	playlist p1;
	p1.insert(1);
	p1.insert(2);
	cout<<"재생 목록: ";
	p1.loopOnce();
	
	playlist p2=p1;
	p2.erase(2);
	p2.insert(3);
	cout<<"두 번째 재생목록: ";
	p2.loopOnce();
}
