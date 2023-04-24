#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int fa[320];
int n;
int a[320][320];
int ans[320][320];
string tmp;
void ini()
{
	for(int i=1;i<=n;i++) fa[i]=i;
}
int search(int i)
{
	if(fa[i]==i) return i;
	return search(fa[i]);
}
void uni(int x,int y)
{
	fa[search(x)]=search(y);
}
bool same(int x,int y)
{
	if(search(x)==search(y)) return true;
	else return false;
}
int main()
{
	cin>>n;
	ini();
	for(int i=1;i<=n;i++)
	{
		cin>>tmp;
		for(int j=1;j<=n;j++)
		{
			a[i][j]=tmp[j-1]-'0';
			if(i!=j && a[i][j]==1) uni(i,j);
		}
	}
		
	for(int i=1;i<=n;i++) ans[i][i]=1;
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(same(i,j)) ans[i][j]=ans[j][i]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<ans[i][j];
		}
		cout<<endl;
	}
}

