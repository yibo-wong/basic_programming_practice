#include <iostream>
#include <algorithm>
#include <queue>
#define maxn 1000000
using namespace std;
queue <int> q;
int vis[maxn];
int n,k,temp;
int main()
{
	cin>>n>>k;
	q.push(n);
	while(!q.empty())
	{
		temp=q.front();
		q.pop();
		if(temp==k) break;
		if(0<=temp-1 && temp-1<=maxn)
		{
			if(vis[temp-1]==0)
			{
				vis[temp-1]=vis[temp]+1;
				q.push(temp-1);
			}
		}
		if(0<=temp+1 && temp+1<=maxn)
		{
			if(vis[temp+1]==0)
			{
				vis[temp+1]=vis[temp]+1;
				q.push(temp+1);
			}
		}
		if(0<=temp*2 && temp*2<=maxn)
		{
			if(vis[temp*2]==0)
			{
				vis[temp*2]=vis[temp]+1;
				q.push(temp*2);
			}
		}
	}
	cout<<vis[k];
	return 0;
}
