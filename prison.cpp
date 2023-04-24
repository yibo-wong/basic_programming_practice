#include <iostream>
#include <cstring>
#include <algorithm>
#define maxn 20050
using namespace std;
struct edge
{
	int x,y;
	int len;
}a[100050];
bool cmp(edge s,edge t)
{
	return s.len>t.len;
}
int fa[maxn];
int op[maxn];
int n,m;
void ini()
{
	for(int i=1;i<=n;i++) fa[i]=i;
}
int search(int a)
{
	if(fa[a]==a) return a;
	return fa[a]=search(fa[a]);
}
void unite(int a,int b)
{
	fa[search(a)]=search(b);
}
bool same(int a,int b)
{
	return search(a)==search(b);
}
int main()
{
	cin>>n>>m;
	ini();
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].len;
	}
	sort(a+1,a+m+1,cmp);
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		if(same(a[i].x,a[i].y))
		{
			ans=a[i].len;break;
		}
		else
		{
			if(op[a[i].x]==0) op[a[i].x]=a[i].y;
			else unite(op[a[i].x],a[i].y);
			if(op[a[i].y]==0) op[a[i].y]=a[i].x;
			else unite(op[a[i].y],a[i].x);
		}
	}
	cout<<ans<<endl;
	return 0;
}
