#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
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
	for(int i=1;i<=n;i++)
	{
		int tmp=0;
		for(int j=1;j<=n;j++)
		{
			if(vis[j]==0 && (tmp==0 || dis[tmp]>dis[j])) tmp=j;
		}
		vis[tmp]=1;
		for(int k=0;k<vc[tmp].size();k++)
		{
			int s=vc[tmp][k].y;
			if(vis[s]==0 && dis[s]>dis[tmp]+vc[tmp][k].v)
				dis[s]=dis[tmp]+vc[tmp][k].v;
		}
		//print();
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
	for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
	return 0;
}
