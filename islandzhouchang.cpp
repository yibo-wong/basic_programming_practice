#include <iostream>
using namespace std;
int a[110][110];
int dx[]={0,-1,0,1};
int dy[]={1,0,-1,0};
int n,m;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==1)
			{
				for(int k=0;k<=3;k++)
				{
					if(a[i+dx[k]][j+dy[k]]==0) cnt++;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
