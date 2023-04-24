#include <iostream>
#include <algorithm>
using namespace std;
struct node;
typedef node* tree;
struct node
{
	char data;
	tree lchild,rchild;
};
void crt(tree &bt) 
{
	char ch;
	ch=getchar();
	if(ch!='$')
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
		cout<<bt->data;
		preorder(bt->lchild);
		preorder(bt->rchild);
	}
}
void inorder(tree bt)
{
	if(bt)
	{
		inorder(bt->lchild);
		cout<<bt->data;
		inorder(bt->rchild);
	}
}
void postorder(tree bt)
{
	if(bt)
	{
		postorder(bt->lchild);
		postorder(bt->rchild);
		cout<<bt->data;
	}
}
int main()
{
	tree bt=new node;
	crt(bt);
	preorder(bt);
	inorder(bt);
	postorder(bt);
	return 0;
}

