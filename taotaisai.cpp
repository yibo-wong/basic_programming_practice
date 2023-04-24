#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n,a[1010],b[1010];
int main()
{
	cin>>n;
	for(int i=(1<<n);i<=(1<<(n+1))-1;i++)
	{
		cin>>b[i];
		a[i]=i+1-(1<<n); 
	}
	for(int i=n-1;i>=0;i--)
	{
		for(int j=(1<<i);j<(1<<(i+1));j++)
		{
			if(b[2*j]>b[2*j+1])
			{
				b[j]=b[2*j];
				a[j]=a[2*j];
			}
			else
			{
				b[j]=b[2*j+1];
				a[j]=a[2*j+1];
			}
		}
	}
	for(int i=1;i<(1<<(n+1));i++) cout<<a[i]<<" ";cout<<endl;
	cout<<a[2]+a[3]-a[1]<<endl;
	return 0;
} 
