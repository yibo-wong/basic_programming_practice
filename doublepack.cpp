#include <iostream>
#include <algorithm>
using namespace std;
int m1,m2;
int tot;
int n;
int x[52],y[52],v[52];
int f[402][402];
int main()
{
	cin>>m1>>m2;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i]>>v[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=m1;j>=x[i];j--)
		{
			for(int k=m2;k>=y[i];k--)
			{
				f[j][k]=max(f[j][k],f[j-x[i]][k-y[i]]+v[i]);
			}
		}
	}
	cout<<f[m1][m2];
	return 0;
}
