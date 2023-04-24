#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
vector <int> a[12];
queue<int>q;
int n;
bool vis[12];
bool bfs()
{
	q.push(1);
	vis[1]=1;
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		if(t==n) return true;
		for(int i=0;i<a[t].size();i++)
		{
			if(vis[a[t][i]]==0)
			{
				q.push(a[t][i]);
				vis[a[t][i]]=1;
			}
		}
	}
	return false;
}
int main()
{
	int casenum;
	cin>>casenum;
	while(casenum--)
	{
		cin>>n;
		while(!q.empty()) q.pop();
		for(int i=1;i<=n;i++)
		{
			while(!a[i].empty()) a[i].pop_back();
		}
		memset(vis,0,sizeof(vis));
		int tmp;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>tmp;
				if(tmp>0) a[i].push_back(j);
			}
		}
		if(bfs()) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
