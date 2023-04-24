#include <iostream>
using namespace std;
int a[400];
int n,m;
int p,count;
int temp;
int main()
{
	while(1)
	{
		cin>>n>>m;
		if(n==0&&m==0) return 0;
		for(int i=1;i<n;i++) a[i]=i+1;
		a[n]=1;
		p=n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				temp=p;
				p=a[p];
				//cout<<p<<endl;
				//for(int ii=1;ii<=n;ii++) cout<<a[ii]<<" ";
				//cout<<endl;
			}
			a[temp]=a[p];
		}
		cout<<p<<endl;
	}
}
