#include <iostream>
using namespace std;
int r1,c1,r2,c2,r3,c3;
int a[1000][1000],b[1000][1000],c[1000][1000];
int d[1000][1000];
int main()
{
	cin>>r1>>c1;
	for(int i=1;i<=r1;i++)
		for(int j=1;j<=c1;j++)
			cin>>a[i][j];
	cin>>r2>>c2;
	for(int i=1;i<=r2;i++)
		for(int j=1;j<=c2;j++)
			cin>>b[i][j];
	cin>>r3>>c3;
	for(int i=1;i<=r3;i++)
		for(int j=1;j<=c3;j++)
			cin>>c[i][j];
	if(r3!=r1||c3!=c2||c1!=r2)
	{
		cout<<"Error!"<<endl;
		return 0;
	}
	for(int i=1;i<=r3;i++)
	{
		for(int j=1;j<=c3;j++)
		{
			for(int k=1;k<=c1;k++)
				d[i][j]+=a[i][k]*b[k][j];
			d[i][j]+=c[i][j];
		}
	}
	for(int i=1;i<=r3;i++)
	{
		for(int j=1;j<=c3;j++)
		{
			cout<<d[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
