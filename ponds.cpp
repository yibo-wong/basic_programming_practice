#include <iostream>
using namespace std;
char maze[1000][1000];
bool vis[1000][1000];
bool flag;
int n,m;
int dx[]={-1,0,1,-1,1,-1,0,1};
int dy[]={-1,-1,-1,0,0,1,1,1};
void dfs(int s,int t)
{
	vis[s][t]==0;
	flag=true;
	for(int i=0;i<8;i++)
	{
		if(vis[s+dx[i]][t+dy[i]]==1)
		{
			flag=false;break;
		} 
	}
	if(flag) return;
	for(int i=0;i<8;i++)
	{
		if(s+dx[i]<1||s+dx[i]>n||t+dy[i]<1||t+dy[i]>m) continue;
		if(vis[s+dx[i]][t+dy[i]]==1)
		{
			vis[s+dx[i]][t+dy[i]]=0;
			dfs(s+dx[i],t+dy[i]);
		}
	}
}
int main()
{
	int cases;
	int cnt=0;
	char temp;
	cin>>cases;
	while(cases--)
	{
		cin>>n>>m;
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>temp;
				if(temp=='W') vis[i][j]=1;
				else vis[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(vis[i][j]==1)
				{
					dfs(i,j);
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
