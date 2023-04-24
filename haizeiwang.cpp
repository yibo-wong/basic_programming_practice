#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
bool vis[20];
int n,maze[20][20];
int tot,final,totalcases;
void dfs(int k,int x) //k for the times,x for the island
{
	if(tot>final) return;
	//for(int i=1;i<=n;i++) cout<<vis[i]<<" ";
	//cout<<endl;
	//cout<<tot<<endl;
	if(k==n-1)
	{
		tot+=maze[x][n];
		final=min(final,tot);
		tot-=maze[x][n];
		//cout<<"final "<<final<<endl;
		return;
	}
	for(int i=1;i<=n-1;i++)
	{
		if(!vis[i]&&i!=x)
		{
			tot+=maze[x][i];
			vis[i]=1;
			dfs(k+1,i);
			tot-=maze[x][i];
			vis[i]=0;
		}
	}
}
int main()
{
	totalcases=1;
	while(totalcases--)
	{
		cin>>n;
		memset(maze,0,sizeof(maze));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				cin>>maze[i][j];
		vis[1]=1;
		tot=0;final=10000000;
		dfs(1,1);
		cout<<final<<endl;
	}
	return 0;
}
