#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define maxn 1000
using namespace std;
int fa[maxn],n,edgenum;
struct edge
{
	int len;
	int u,v;
}a[maxn];
bool cmp(edge a,edge b)
{
	return a.len<b.len;
}
void ini()
{
	for(int i=0;i<=26;i++) fa[i]=i;
}
int ffind(int i)
{
	if(fa[i]==i) return i;
	return fa[i]=ffind(fa[i]);
}
void unite(int x,int y)
{
	fa[ffind(x)]=ffind(y);
}
bool same(int x,int y)
{
	return ffind(x)==ffind(y);
}
int kruskal()
{
	int sum=0;
	int num=0;
	ini();
	sort(a+1,a+edgenum+1,cmp);
	for(int i=1;i<=edgenum;i++)
	{
		if(!same(a[i].u,a[i].v))
		{
			sum++;
			num+=a[i].len;
			//cout<<"add "<<a[i].len<<endl;
			unite(a[i].u,a[i].v);
		}
		if(sum==n-1) break;
	}
	return num;
}
int main()
{
	while(cin>>n)
	{
		if(n==0) return 0;
		char p,e;
		int tmp,v;
		edgenum=0;
		for(int i=0;i<n-1;i++)
		{
			cin>>p>>tmp;
			while(tmp--)
			{
				cin>>e>>v;
				edgenum++;
				a[edgenum].len=v;
				a[edgenum].u=p-'A';
				a[edgenum].v=e-'A';
			}
		}
		cout<<kruskal()<<endl;
	}
}
