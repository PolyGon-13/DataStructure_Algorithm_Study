#include <iostream>

using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

struct bst
{
	node* root=nullptr;
	
	node* find(int value)
	{
		return find_impl(root,value);
	}
	
private:
	node* find_impl(node* current,int value)
	{
		if(!current)
		{
			cout<<endl;
			return nullptr;
		}
		
		if(current->data==value)
		{
			cout<<value<<"을(를) 찾았습니다."<<'\n';
			return current;
		}
		
		if(value<current->data)
		{
			cout<<current->data<<"에서 왼쪽으로 이동: ";
			return find_impl(current->left,value);
		}
		
		cout<<current->data<<"에서 오른쪽으로 이동: ";
		return find_impl(current->right,value);
	}
	
public:
	void insert(int value)
	{
		if(!root) // 루트 노드에 아무것도 없는 경우
			root=new node{value,nullptr,nullptr};
		else
			insert_impl(root,value);
	}
	
private:
	void insert_impl(node* current,int value)
	{
		if(value<current->data)
		{
			if(!current->left)
				current->left=new node{value,nullptr,nullptr};
			else
				insert_impl(current->left,value);
		}
		else
		{
			if(!current->right)
				current->right=new node{value,nullptr,nullptr};
			else
				insert_impl(current->right,value);
		}
	}
	
public:
	void inorder()
	{
		inorder_impl(root);
	}
	
private:
	void inorder_impl(node* start)
	{
		if(!start)
			return;
		
		inorder_impl(start->left);
		cout<<start->data<<" ";
		inorder_impl(start->right);
	}
	
public:
	node* successor(node* start)
	{
		auto current=start->right; // 현재 노드를 기준으로 오른쪽 노드로 이동
		while(current && current->left)
			current=current->left; // 이동한 오른쪽 노드에서 가장 왼쪽에 존재하는 노드까지 이동
		return current;
	}
	
	void deleteValue(int value)
	{
		root=delete_impl(root,value);
	}
	
private:
	node* delete_impl(node* start,int value)
	{
		if(!start)
			return nullptr;
		
		if(value<start->data)
			start->left=delete_impl(start->left,value);
		else if(value>start->data)
			start->right=delete_impl(start->right,value);
		else
		{
			if(!start->left) // start 노드를 삭제해야 하는데 자식 노드가 전혀 없거나, 왼쪽 자식 노드만 없는 경우
			{
				auto tmp=start->right; // 오른쪽 자식 노드를 복사
				delete start; // start 노드 삭제
				return tmp; // 이어붙여야할 start 노드의 오른쪽 자식 노드 return
			}
			
			if(!start->right) // 오른쪽 자식 노드만 없는 경우
			{
				auto tmp=start->left;
				delete start;
				return tmp;
			}
			
			// 자식 노드가 둘 다 있는 경우
			auto succNode=successor(start); // successor 함수 적용하여 start 노드의 오른편의 노드 중 가장 큰 값을 선택
			start->data=succNode->data; // start 노드의 값을 위 함수를 통해 얻은 값으로 변경
			
			start->right=delete_impl(start->right,succNode->data); // 위 함수를 통해 얻은 값을 가지고 있는 노드 삭제
		}
		
		return start;
	}
};

int main()
{
	bst tree;
	
	tree.insert(12);
	tree.insert(10);
	tree.insert(20);
	tree.insert(8);
	tree.insert(11);
	tree.insert(15);
	tree.insert(28);
	tree.insert(4);
	tree.insert(2);
	
	
	cout<<"중위 순회: ";
	tree.inorder();
	cout<<'\n';
	
	tree.deleteValue(12);
	cout<<"12를 삭제한 후 중위 순회: ";
	tree.inorder();
	cout<<'\n';
	
	if(tree.find(12))
		cout<<"원소 12는 트리에 있습니다."<<'\n';
	else
		cout<<"원소 12는 트리에 없습니다."<<'\n';
}
