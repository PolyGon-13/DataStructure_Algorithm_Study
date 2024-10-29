#include <iostream>
#include <queue>

using namespace std;

struct node
{
	string position;
	node* first; // 첫 번째 자식노드를 가리키는 포인터
	node* second; // 두 번째 자식노드를 가리키는 포인터
};

struct org_tree
{
	node* root; // 루트노드 생성
	
	static org_tree create_org_structure(const string& pos) // 정적 멤버 함수 선언 : 객체 선언 없이 사용 가능
	{
		org_tree tree;
		tree.root=new node{pos,nullptr,nullptr}; // 입력받은 pos로 루트노드 생성
		return tree;
	}
	
	static node* find(node* root,const string& value)
	{
		if(root==nullptr) // 노드가 없는 경우
			return nullptr;
		
		if(root->position==value) // 노드의 값이 찾는 값인 경우
			return root;
		
		auto firstFound=org_tree::find(root->first,value); // 첫 번째 자식노드 탐색
		
		if(firstFound!=nullptr)
			return firstFound;
		
		return org_tree::find(root->second,value); // 두 번째 자식노드 탐색
	}
	
	bool addSubordinate(const string& manager,const string& subordinate)
	{
		auto managerNode=org_tree::find(root,manager);
		
		if(!managerNode)
		{
			cout<<manager<<"을(를) 찾을 수 없습니다: "<<'\n';
			return false;
		}
		
		if(managerNode->first && managerNode->second) // 자식노드가 모두 존재하는 경우
		{
			cout<<manager<<" 아래에 "<<subordinate<<"을(를) 추가할 수 없습니다."<<'\n';
			return false;
		}
		
		if(!managerNode->first) // 첫 번째 자식노드가 없는 경우
			managerNode->first=new node{subordinate,nullptr,nullptr}; // 첫 번째 자식노드에 subordinate 노드 추가
		else // 두 번째 자식노드가 없는 경우
			managerNode->second=new node{subordinate,nullptr,nullptr}; // 두 번째 자식노드에 subordinate 노드 추가
		
		cout<<manager<<" 아래에 "<<subordinate<<"을(를) 추가했습니다."<<'\n';
		
		return true;
	}
};

int main()
{
	auto tree=org_tree::create_org_structure("CEO");
	
	tree.addSubordinate("CEO","부사장");
	tree.addSubordinate("부사장","IT부장");
	tree.addSubordinate("부사장","마케팅부장");
	tree.addSubordinate("IT부장","보안팀장");
	tree.addSubordinate("IT부장","앱개발팀장");
	tree.addSubordinate("마케팅부장","물류팀장");
	tree.addSubordinate("마케팅부장","홍보팀장");
	tree.addSubordinate("부사장","재무부장");
}
