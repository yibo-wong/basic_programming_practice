#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
string a,b;
int lchild[1005],rchild[1005];
void f(const int n1,const int n2,int len)//1 pre,2 mid
{
	int p;
	for(int i=n2;i<=n2+len-1;i++)
	{
		if(b[i]==a[n1])
		{
			p=i;
			break;
		}
	}
	int x=p-n2;
	int y=len-x-1;
	//cout<<a[n1]<<" "<<a[n2]<<" "<<x<<" "<<y<<" "<<len<<endl;
	if(x>1)
	{
		lchild[n1]=n1+1;
		f(n1+1,n2,x);
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
		f(n1+x+1,n2+x+1,y);
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
		f(0,0,lena);
		post(0);
		cout<<endl;
	}
	return 0;
}
