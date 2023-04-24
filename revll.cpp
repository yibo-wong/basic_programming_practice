#include <iostream>
#include <algorithm>
using namespace std;
//reverse a linked list
typedef struct node;
typedef node *list;
struct node
{
	int data;
	node *next;	
};
list myl,cur,last;
void crt(list &p)
{
	int n;
	cin>>n;
	if(n!=-1)
	{
		p=new node;
		p->data=n;
		crt(p->next);
	}
	else
	{
		p=NULL;
		return;
	}
}
int getlen(list p,int depth)
{
	if(p->next==NULL) return depth;
	else return getlen(p->next,depth+1);
}
void print(list p)
{
	if(p==NULL)
	{
		cout<<endl;
		return;
	}
	else 
	{
		cout<<p->data<<" ";
		print(p->next);
	}
}
void rev(list &p)
{
	last=p;
	cur=p->next;
	list tmp;
	p->next=NULL;
	do
	{
		tmp=cur->next;
		cur->next=last;
		last=cur;
		cur=tmp;
	}while(cur->next!=NULL);
	cur->next=last;
	return;
}
int main()
{
	list p;
	crt(p);
	print(p);
	cout<<getlen(p,1)<<endl;
	rev(p);
	print(cur);
	return 0;
}
