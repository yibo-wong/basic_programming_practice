#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m;
bool a[110][110];
bool vis[110][110];
string tmp;
int sum;
int dx[]={0,0,1,-1,1,-1,1,-1};
int dy[]={1,-1,0,0,1,-1,-1,1};
bool in(int x,int y)
{
	if(1<=x && x<=n && 1<=y && y<=m) return true;
	else return false;
}
void dfs(int x,int y)
{
	vis[x][y]=1;
	for(int i=0;i<8;i++)
	{
		if(in(x+dx[i],y+dy[i]) && a[x+dx[i]][y+dy[i]]==1 && vis[x+dx[i]][y+dy[i]]==0)dfs(x+dx[i],y+dy[i]);
	}
}
int main()
{
	while(cin>>n && n)
	{
		cin>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>tmp;
			for(int j=1;j<=m;j++) a[i][j]= tmp[j-1]=='@' ? 1 : 0;
		}
		sum=0;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(a[i][j] && vis[i][j]==0)
				{
					sum++;
					dfs(i,j);
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
