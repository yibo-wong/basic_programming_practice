#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=100005;
struct node
{
	int y,v;
	node(){}
	node(int y_,int v_):y(y_),v(v_){}
};
int dis[maxn];
bool vis[maxn]={false};
vector<node>vc[maxn];
priority_queue<pair<int,int> >q;
int n,m;
int x,y,z,s;
void print()
{
	for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
	cout<<endl;
	for(int i=1;i<=n;i++) cout<<vis[i]<<" ";
	cout<<endl;
}
void dijk(int s)
{
	memset(vis,0,sizeof(vis));
	memset(dis,inf,sizeof(dis));
	dis[s]=0;
	q.push(make_pair(0,s));
	while(q.size())
	{
		int x=q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=0;i<vc[x].size();i++)
		{
			int tmp=vc[x][i].y;
			if(dis[tmp]>dis[x]+vc[x][i].v)
			{
				dis[tmp]=dis[x]+vc[x][i].v;
				q.push(make_pair(-dis[tmp],tmp));
			}
		}
	}
}
int main()
{
	cin>>n>>m>>s;
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			cin>>x>>y>>z;
			vc[x].push_back(node(y,z));
			//vc[y+n].push_back(node(x+n,z));
		}
	}
	dijk(s);
	for(int i=1;i<=n;i++)
	{
		cout<<dis[i]<<endl;
	}
	return 0;
}
