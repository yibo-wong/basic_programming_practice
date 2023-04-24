#include <iostream>
#include <cstring>
using namespace std;
int n,a[1050],b[1050],c[1050];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		c[i]=a[i]+b[n+1-i];
	}
	for(int i=1;i<=n;i++) cout<<c[i]<<" ";
	return 0;
}
