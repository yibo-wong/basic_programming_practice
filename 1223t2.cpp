#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n,m,len,depth;
int x,y,s;
vector<int>a[110];
bool vis[110];
void dfs(int t)
{
	//cout<<"init "<<t<<" "<<depth<<endl;
	if(depth>len)
	{
		vis[t]=0;
		return;
	}
	cout<<t<<" ";
	if(a[t].size()==0)
		return;
	for(int i=0;i<a[t].size();i++)
	{
		if(vis[a[t][i]]==0)
		{
			vis[a[t][i]]=1;
			depth++;
			dfs(a[t][i]);
			depth--;
			//vis[a[t][i]]=0;
		}
	}
}
int main()
{
	cin>>n>>m>>len;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for(int i=0;i<=102;i++)
	{
		sort(a[i].begin(),a[i].end());
	}
	cin>>s;
	vis[s]=1;
	depth=0;
	dfs(s);
	return 0;
}
