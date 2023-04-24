#include <iostream>
#include <algorithm>
using namespace std;
int m,n,maze[60][60],tot,maxn,ans;
bool vis[60][60];
int dx[]={0,-1,0,1};
int dy[]={-1,0,1,0};
int wall[]={1,2,4,8};//w,n,e,s
bool in(int x,int y)
{
	if(x>=1&&x<=m&&y>=1&&y<=n) return true;
	else return false;
}
void dfs(int x,int y)
{
	for(int i=0;i<=3;i++)
	{
		if(in(x+dx[i],y+dy[i])&&vis[x+dx[i]][y+dy[i]]==0&&((maze[x][y]&wall[i])==0))
		{
			vis[x+dx[i]][y+dy[i]]=1;
			maxn++;
			dfs(x+dx[i],y+dy[i]);
		}
	}
}
int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>maze[i][j];
		}
	}
	ans=0;tot=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(vis[i][j]==0)
			{
				vis[i][j]=1;
				tot++;
				maxn=1;
				dfs(i,j);
				ans=max(ans,maxn);
			}
		}
	}
	cout<<tot<<endl;
	cout<<ans<<endl;
	return 0;
}
