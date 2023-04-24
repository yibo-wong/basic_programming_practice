#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
string a,b;
int lchild[1005],rchild[1005];
void f(int n1,int m1,int n2,int m2)//1 for a,2 for b
{
	int p;
	for(int i=n2;i<=m2;i++)
	{
		if(b[i]==a[n1])
		{
			p=i;
			break;
		}
	}
	int x=p-n2;
	int y=m2-p;
	//cout<<a[n1]<<" "<<a[n2]<<" "<<x<<" "<<y<<" "<<m1-n1+1<<endl;
	if(x==1 && y==1)
	{
		lchild[n1]=n1+1;
		rchild[n1]=n1+2;
		lchild[n1+1]=rchild[n1+1]=-1;
		lchild[n1+2]=rchild[n1+2]=-1;
		return;
	}
	if(x==0 && y==1)
	{
		lchild[n1]=-1;
		rchild[n1]=n1+1;
		lchild[n1+1]=rchild[n1+1]=-1;
		return;
	}
	if(x==1 && y==0)
	{
		lchild[n1]=n1+1;
		rchild[n1]=-1;
		lchild[n1+1]=rchild[n1+1]=-1;
		return;
	}
	if(x==0 && y==0) return;
	
	if(x>1)
	{
		lchild[n1]=n1+1;
		f(n1+1,n1+x,n2,n2+x-1);
	}
	else if(x==1)
	{
		lchild[n1]=n1+1;
		lchild[n1+1]=rchild[n1+1]=-1;
	}
	else lchild[n1]=-1;
	
	if(y>1)
	{
		rchild[n1]=n1+x+1;
		f(n1+x+1,m1,n2+x+1,m2);
	}
	else if(y==1)
	{
		rchild[n1]=n1+x+1;
		lchild[n1+x+1]=rchild[n1+x+1]=-1;
	}
	else rchild[n1]=-1;
}
void post(int x)
{
	if(lchild[x]!=-1) post(lchild[x]);
	if(rchild[x]!=-1) post(rchild[x]);
	cout<<a[x];
}
int main()
{
	while(cin>>a)
	{
		cin>>b;
		memset(rchild,0,sizeof(rchild));
		memset(lchild,0,sizeof(lchild));
		int lena=a.size();
		int lenb=b.size();
		f(0,lena-1,0,lenb-1);
		post(0);
		cout<<endl;
	}
	return 0;
}
