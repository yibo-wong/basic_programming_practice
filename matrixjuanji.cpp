#include <iostream>
using namespace std;
int a[1000][1000];
int b[1000][1000];
int ans[1000][1000];
int m,n,p,q;
int tot;
int main()
{
	cin>>m>>n>>p>>q;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=p;i++)
	{
		for(int j=1;j<=q;j++)
		{
			cin>>b[i][j];
		}
	}
	for(int i=1;i<=m+1-p;i++)
	{
		for(int j=1;j<=n+1-q;j++)
		{
			tot=0;
			for(int ii=1;ii<=p;ii++)
			{
				for(int jj=1;jj<=q;jj++)
				{
					tot+=b[ii][jj]*a[ii+i-1][jj+j-1];
				}
			}	
			ans[i][j]=tot;
		}
	}
	for(int i=1;i<=m+1-p;i++)
	{
		for(int j=1;j<=n+1-q;j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
