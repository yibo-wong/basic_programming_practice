#include <iostream>
using namespace std;
int a[105][105];
int nei[105][105];
int b[105][105];
int m,n;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			nei[i][j]=a[i-1][j-1]+a[i-1][j]+a[i-1][j+1]+a[i][j-1]+a[i][j+1]+a[i+1][j-1]+a[i+1][j]+a[i+1][j+1];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]&&nei[i][j]<2) b[i][j]=0;
			else if(a[i][j]&&nei[i][j]>=2&&nei[i][j]<=3) b[i][j]=1;
			else if(a[i][j]&&nei[i][j]>3) b[i][j]=0;
			else if(a[i][j]==0&&nei[i][j]==3) b[i][j]=1;
			else b[i][j]=a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
