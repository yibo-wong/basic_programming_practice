#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>a[200050];
bool cat[200050];
int m,n,x,y,cnt,vis[200050];
void dfs(int s,int depth)
{
	if(depth>m) return;
	bool flag=1;
	for(int i=0;i<a[s].size();i++)
	{
		if(vis[a[s][i]]==0)
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
	{
		cnt++;
		return;
	}
	for(int i=0;i<a[s].size();i++)
	{
		if(vis[a[s][i]]==0)
		{
			vis[a[s][i]]=1;
			if(cat[a[s][i]]==1)
				dfs(a[s][i],depth+1);
			else
				dfs(a[s][i],0);
		}
	}
}
int main()
{
	cin>>n>>m;
	cnt=0;
	for(int i=1;i<=n;i++)
		cin>>cat[i];
	while((scanf("%d%d",&x,&y))!=EOF)
	{
		a[x].push_back(y);
		a[y].push_back(x);
	}
	vis[1]=1;
	dfs(1,cat[1]);
	cout<<cnt<<endl;
	return 0;
}
