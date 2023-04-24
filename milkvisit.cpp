#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#define maxn 100050
using namespace std;
int fa[maxn];
char cow[maxn];
int n,m;
string s;
vector<vector<int> >q[maxn];
void ini()
{
	for(int i=1;i<=n;i++) fa[i]=i;
}
int ffind(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=ffind(fa[x]);
}
void merge(int x,int y)
{
	fa[ffind(x)]=ffind(y);
}
bool same(int x,int y)
{
	return ffind(x)==ffind(y);
}
int main()
{
	cin>>n>>m;
	cin>>s;
	ini();
	int a,b;
	char t;
	for(int i=1;i<=n;i++) cow[i]=s[i-1];
	for(int i=1;i<n;i++)
	{
		cin>>a>>b;
		if(cow[a]==cow[b]) merge(a,b);
	}
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b>>t;
		if(same(a,b) && t!=cow[a]) cout<<"0";
		else cout<<"1";
	}
	return 0;
}
