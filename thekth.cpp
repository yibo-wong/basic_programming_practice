#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[1050],arev[1050];
bool flag,p,fi;
int n,cnt;
int y;
void rev(int k);
void next()
{
	flag=0;
	int temp,m,pm;
	for(int i=n-1;i>=1;i--)
	{
		if(a[i]<a[i+1]) 
		{
			temp=i;
			flag=1;break;
		}
	}
	if(flag==0)
	{
		rev(1);
		return;
	}
	m=100000;pm=0;
	for(int i=temp+1;i<=n;i++)
	{
		if(a[i]>a[temp]) 
		{
			if(a[i]<=m) 
			{
				m=a[i];pm=i;
			}
		}
	}
	swap(a[pm],a[temp]);
	rev(temp+1);
}
void rev(int k)
{
	for(int i=k;i<=n;i++) arev[i]=a[i];
	for(int i=k;i<=n;i++) a[i]=arev[n+k-i];
}
int main()
{
	int totalcases;
	cin>>totalcases;
	while(totalcases--)
	{
		cin>>n>>y;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=y;i++) next();
		for(int i=1;i<=n;i++) cout<<a[i]<<" ";
		cout<<endl;
	}
}
