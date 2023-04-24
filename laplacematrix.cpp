#include <iostream>
using namespace std;
int n,m;
int d[1000][1000];
int a[1000][1000];
int ans[1000][1000];
int x,y;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++) 
	{
		cin>>x>>y;
		a[x][y]=1;
		a[y][x]=1;
		d[x][x]++;
		d[y][y]++;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			ans[i][j]=d[i][j]-a[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
