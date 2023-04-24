#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
int a[1005],b[1005];
vector<int>tmp;
int lchild[1005],rchild[1005];
void f(const int n1,const int n2,int len)//1 post,2 mid,a post,b mid
{
	int p;
	//cout<<n1<<" "<<n2<<" "<<len<<endl;
	if(len==1)
	{
		lchild[n1]=rchild[n1]=-1;
		return;
	}
	for(int i=n2;i<=n2+len-1;i++)
	{
		if(b[i]==a[n1+len-1])
		{
			p=i;
			break;
		}
	}
	int x=p-n2;
	int y=len-x-1;
	//cout<<"xy "<<x<<" "<<y<<endl;
	//cout<<a[n1]<<" "<<a[n2]<<" "<<x<<" "<<y<<" "<<len<<endl;
	if(x>=1)
	{
		lchild[n1+len-1]=n1+x-1;
		f(n1,n2,x);
	}
	else lchild[n1+len-1]=-1;
	if(y>=1)
	{
		rchild[n1+len-1]=n1+len-2;
		f(n1+x,n2+x+1,y);
	}
	else rchild[n1+len-1]=-1;
}
void pre(int x)
{
	cout<<a[x]<<" ";
	if(lchild[x]!=-1) pre(lchild[x]);
	if(rchild[x]!=-1) pre(rchild[x]);
}
int main()
{
	int t;
	while(cin>>t) tmp.push_back(t);
	int length=tmp.size()/2;
	for(int i=0;i<length;i++) b[i]=tmp[i];
	for(int i=length;i<length*2;i++) a[i-length]=tmp[i];
	memset(lchild,-1,sizeof(lchild));
	memset(rchild,-1,sizeof(rchild));
	f(0,0,length);
	//for(int i=0;i<length;i++) cout<<lchild[i]<<" "<<rchild[i]<<endl;
	pre(length-1);
	return 0;
}
