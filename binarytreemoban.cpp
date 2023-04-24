#include <iostream>
#include <algorithm>
using namespace std;
struct node;
typedef node* tree;
struct node
{
	int data;
	node *lchild,*rchild;
};
void crt(tree &bt)
{
	int ch;
	cin>>ch;
	if(ch!=-1)
	{
		bt=new node;
		bt->data=ch;
		crt(bt->lchild);
		crt(bt->rchild);
	}
	else bt=NULL;
}
void preorder(tree bt)
{
	if(bt)
	{
		cout<<bt->data<<" ";
		preorder(bt->lchild);
		preorder(bt->rchild);
	}
}
void inorder(tree bt)
{
	if(bt)
	{
		inorder(bt->lchild);
		cout<<bt->data<<" ";
		inorder(bt->rchild);
	}
}
void postorder(tree bt)
{
	if(bt)
	{
		postorder(bt->lchild);
		postorder(bt->rchild);
		cout<<bt->data<<" ";
	}
}
void insert(tree &bt,int n)
{
	if(bt)
	{
		if(n<bt->data) insert(bt->lchild,n);
		else insert(bt->rchild,n);
	}
	else
	{
		bt=new node;
		bt->data=n;
		bt->lchild=NULL;
		bt->rchild=NULL;
	}
}
void print(tree bt)
{
	if(bt)
	{
		cout<<bt->data;
		cout<<"(";
		if(bt->lchild)
		{
			print(bt->lchild);
		}
		else cout<<"NULL";
		cout<<",";
		if(bt->rchild)
		{
			print(bt->rchild);
		}
		else cout<<"NULL";
		cout<<")";
	}
}
int main()
{
	tree mybt=NULL;
	int casenum,num;
	cin>>casenum;
	while(casenum--)
	{
		cin>>num;
		insert(mybt,num);
	}
	preorder(mybt);
	cout<<endl;
	inorder(mybt);
	cout<<endl;
	print(mybt);
	return 0;
}


