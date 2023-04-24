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
int dist[35][35];
int pre[35][35];

void floyd()
{
	for(int i=1;i<=p;i++)
		for(int j=1;j<=p;j++)
			pre[i][j]=j;
	for(int k=1;k<=p;k++)
	{
		for(int i=1;i<=p;i++)
		{
			for(int j=1;j<=p;j++)
			{
				if(dist[i][j]>dist[i][k]+dist[k][j])
				{
					dist[i][j]=dist[i][k]+dist[k][j];
					pre[i][j]=pre[i][k];
				}
			}
		}
	}
}

void print(int i,int target)
{
	if(i==target) cout<<name[target]<<endl;
	else
	{
		cout<<name[i]<<"->("<<dist[i][pre[i][target]]<<")->";
		print(pre[i][target],target);	
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
	memset(a,inf,sizeof(a));
	memset(dist,inf,sizeof(dist));
	int v;
	for(int i=1;i<=q;i++)
	{
		cin>>aa>>bb>>v;
		a[dic[aa]][dic[bb]]=a[dic[bb]][dic[aa]]=v;
		dist[dic[aa]][dic[bb]]=dist[dic[bb]][dic[aa]]=v;
	}
	floyd();
	cin>>r;
	for(int i=1;i<=r;i++)
	{
		cin>>aa>>bb;
		if(aa==bb) cout<<aa<<endl;
		else
		{
			print(dic[aa],dic[bb]);
		}
	}
	return 0;
}
