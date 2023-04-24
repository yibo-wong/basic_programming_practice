#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n,a[10],temp;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>temp;
		a[temp]=1;
	}
	if(a[1]==1&&a[2]==1)
	{
		cout<<0<<endl;
		return 0;
	}
	if(a[3]==1&&a[4]==1)
	{
		cout<<0<<endl;
		return 0;
	}
	if(a[5]!=a[6])
	{
		cout<<0<<endl;
		return 0;
	}
	if(a[7]==0&&a[8]==0)
	{
		cout<<0<<endl;
		return 0;
	}
	cout<<1<<endl;
	return 0;
}
