#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int d,n,a[1040][1040],x,y,p;
bool in(int x,int y)
{
	if(x>=0&&x<=1024&&y>=0&&y<=1024) return true;
	return false;
}
int main()
{
	cin>>d;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y>>p;
		for(int j=x-d;j<=x+d;j++)
		{
			for(int k=y-d;k<=y+d;k++)
			{
				if(in(j,k))
				{
					a[j][k]+=p;
				}
			}
		}
	}
	int cnt=0;
	int sum=0;
	for(int i=0;i<=1024;i++)
	{
		for(int j=0;j<=1024;j++)
		{
			if(a[i][j]>cnt) cnt=a[i][j];
		}
	}
	for(int i=0;i<=1024;i++)
	{
		for(int j=0;j<=1024;j++)
		{
			if(a[i][j]==cnt) sum++;
		}
	}
	cout<<sum<<" "<<cnt<<endl;
	return 0;
}
