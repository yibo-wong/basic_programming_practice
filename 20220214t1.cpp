#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxn 100000
using namespace std;
int par[maxn],rank[maxn];
void ini(int s)
{
	for(int i=1;i<=s;i++)
	{
		par[x]=x;
		rank[x]=1;
	}
}
int myfind(int x)
{
	if(par[x]==x) return x;
	par[x]=ffind(par[x]);
	return ffind(par[x]);
}
void unite(int x,int y)
{
	x=myfind(x);
	y=myfind(y);
	if(rank[x]<rank[y]) par[x]=y;
	else if(rank[x]>rank[y]) par[y]=x;
	else
	{
		par[x]=y;
		rank[y]++;
	}
}
int n,h,r;
int x[1050],y[1050],r[1050]
