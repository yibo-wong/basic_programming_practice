#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct node
{
	int data;
	node* pre;
	node* post;
};
typedef node* point;
int len=0;
int n,a,b;
point pfirst,plast;
int main()
{
	int casenum;
	cin>>casenum;
	while(casenum--)
	{
		len=0;
		cin>>n;
		while(n--)
		{
			cin>>a>>b;
			if(a==2 && len>1)
			{
				if(b==0)
				{
					point tmp=pfirst;
					pfirst=pfirst->post;
					delete tmp;
				}
				else
				{
					point tmp=plast;
					plast=plast->pre;
					delete tmp;
				}
				len--;
			}
			else if(a==2 && len==1)
			{
				len=0;
				delete pfirst;
			}
			if(a==1)
			{
				if(len==0)
				{
					pfirst=new node;
					plast=pfirst;
					pfirst->data=b;
					pfirst->pre=NULL;
					pfirst->post=NULL;
				}
				else
				{
					point tmp=new node;
					tmp->data=b;
					tmp->pre=plast;
					tmp->post=NULL;
					plast->post=tmp;
					plast=tmp;
				}
				len++;
			}
		}
		if(len==0) cout<<"NULL"<<endl;
		else
		{
			point p=pfirst;
			for(int i=1;i<=len;i++)
			{
				cout<<(p->data)<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
