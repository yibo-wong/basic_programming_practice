#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
int n,m1,m2,sum;
int i,j,s;
int a[1000][1000],b[1000][1000],c[1000][1000];
int main()
{
	cin>>n>>m1>>m2;
	for(int ii=1;ii<=m1;ii++)
	{
		cin>>i>>j>>s;
		a[i][j]=s;
	}
	for(int ii=1;ii<=m2;ii++)
	{
		cin>>i>>j>>s;
		b[i][j]=s;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			sum=0;
			for(int k=0;k<n;k++)
			{
				sum+=a[i][k]*b[k][j];
			}
			c[i][j]=sum;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(c[i][j]!=0)
			{
				cout<<i<<" "<<j<<" "<<c[i][j]<<endl;
			}
		}
	}
	return 0;
}
