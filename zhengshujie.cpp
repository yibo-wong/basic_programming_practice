#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;
ll int a[1001000],b[1001000];
ll int p,q,casenum,n;
bool flag;
void init(int k)
{
	for(ll int i=0;i<=k;i++)
	{
		a[i]=i*i;
		b[i]=3*i*i;
	}
}
int main()
{
	cin>>casenum;
	init(1000000);
	while(casenum--)
	{
		cin>>n;
		if(n<0)
		{
			cout<<"no"<<endl;
			continue;
		}
		if(n==0)
		{
			cout<<"yes"<<endl;
			continue;
		}
		p=0;q=sqrt(n)+2;
		flag=0;
		while(p<=q)
		{
			if(a[p]+b[q]==n)
			{
				flag=1;
				break;
			}
			if(a[p]+b[q]<n)
			{
				p++;
				continue;
			}
			if(a[p]+b[q]>n)
			{
				q--;
				continue;
			}
		}
		if(flag)
		{
			cout<<"yes"<<endl;
			continue;
		}
		q=0;p=sqrt(n)+2;
		flag=0;
		while(p>=q)
		{
			if(a[p]+b[q]==n)
			{
				flag=1;
				break;
			}
			if(a[p]+b[q]<n)
			{
				q++;
				continue;
			}
			if(a[p]+b[q]>n)
			{
				p--;
				continue;
			}
		}
		if(flag)
		{
			cout<<"yes"<<endl;
			continue;
		}
		if(flag==0) cout<<"no"<<endl;
	}
}
