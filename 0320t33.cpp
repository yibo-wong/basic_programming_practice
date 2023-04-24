#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
bool vis[11];
int des[11];
int v,n,x;
int a[11];
void dfs(int depth)
{
	if(depth>n)
	{
		if(v > n-v)
		{
			for(int i=1;i<=n;i++) cout<<des[i]<<" ";
			cout<<endl;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			des[depth]=i;
			if(i-a[depth]>=x)
			{
				v++;
				vis[i]=1;
				dfs(depth+1);
				vis[i]=0;
				v--;
			}
			else
			{
				vis[i]=1;
				dfs(depth+1);
				vis[i]=0;
			}
		}
	}
}
int main()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1);
	return 0;
}
