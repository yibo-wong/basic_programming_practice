#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#define inf 0x3f3f3f3f
#define maxn 1000
using namespace std;
int n,a[maxn][maxn];
int mincost[maxn];
bool vis[maxn];
priority_queue<pair<int,int> >q;

void dijkstra(int m)
{
	memset(vis,0,sizeof(vis));
	memset(mincost,inf,sizeof(mincost));
	mincost[m]=0;
	q.push(make_pair(0,m));
	while(!q.empty())
	{
		int x=q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=1;i<=n;i++)
		{
			if(mincost[i]>mincost[x]+a[x][i])
			{
				mincost[i]=mincost[x]+a[x][i];
				q.push(make_pair(-mincost[i],i));
			}
		}
		//for(int i=1;i<=n;i++) cout<<mincost[i]<<" ";cout<<endl;
	}
}
void dijkstra2(int m)
{
	memset(vis,0,sizeof(vis));
	memset(mincost,inf,sizeof(mincost));
	mincost[m]=0;
	int counter=n;
	while(counter--)
	{
		int tmp=0;
		for(int i=1;i<=n;i++)
			if(vis[i]==0 && (tmp==0 || mincost[tmp]>mincost[i])) tmp=i;
		vis[tmp]=1;
		for(int i=1;i<=n;i++)
			if(vis[i]==0 && mincost[i]>mincost[tmp]+a[tmp][i])
				mincost[i]=mincost[tmp]+a[tmp][i];
	}
}
int main()
{
	int t;
	cin>>n>>t;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	dijkstra(t);
	for(int i=1;i<=n;i++) cout<<mincost[i]<<" ";
	dijkstra2(t);
	for(int i=1;i<=n;i++) cout<<mincost[i]<<" ";
}
