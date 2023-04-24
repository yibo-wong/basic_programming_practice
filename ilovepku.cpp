#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <queue>
#include <vector>
#define inf 0x3f3f3f3f
using namespace std;
string tmp;
map<string,int>dic;
int a[35][35];
string name[35];
int mincost;
bool vis[35];
int p,q,r;
int target;
vector<int>res;
vector<int>final;

void print()
{
	for(int i=0;i<final.size()-1;i++)
	{
		cout<<name[final[i]]<<"->("<<a[final[i]][final[i+1]]<<")->";
	}
	cout<<name[final[final.size()-1]]<<endl;
}

void dfs(int now,int cost)
{
	if(cost>=mincost) return;
	if(now==target)
	{
		if(cost<mincost)
		{
			mincost=cost;
			final.clear();
			for(int i=0;i<res.size();i++) final.push_back(res[i]);
			return;
		}
	}
	for(int i=1;i<=p;i++)
	{
		if(vis[i]==0 && a[now][i]>0)
		{
			vis[i]=1;
			res.push_back(i);
			dfs(i,cost+a[now][i]);
			res.pop_back();
			vis[i]=0;
		}
	}
}

int main()
{
	cin>>p;
	for(int i=1;i<=p;i++)
	{
		cin>>tmp;
		name[i]=tmp;
		dic.insert(make_pair(tmp,i));
	}
	cin>>q;
	string aa,bb;
	memset(a,-1,sizeof(a));
	int v;
	for(int i=1;i<=q;i++)
	{
		cin>>aa>>bb>>v;
		a[dic[aa]][dic[bb]]=a[dic[bb]][dic[aa]]=v;
	}
	cin>>r;
	for(int i=1;i<=r;i++)
	{
		cin>>aa>>bb;
		if(aa==bb) cout<<aa<<endl;
		else
		{
			mincost=inf;
			target=dic[bb];
			memset(vis,0,sizeof(vis));
			vis[dic[aa]]=1;
			res.clear();final.clear();
			res.push_back(dic[aa]);
			dfs(dic[aa],0);
			print();
		}
	}
	return 0;
}
