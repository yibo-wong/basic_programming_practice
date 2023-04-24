#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[1050],s[1050];
bool used[1050],flag,p,fi;
int n,cnt;
int y;
void doit()
{
	flag=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=s[i])
		{
			flag=0;break;
		}
	}
	if(flag) p=1;
	if(p) cnt++;
	if(cnt==y)
	{
		for(int i=1;i<=n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
		fi=1;
	}
}
void dfs(int k)
{
	if(fi==1) return;
	if(k>n)
	{
		doit();
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(used[i]==0)
		{
			a[k]=i;used[i]=1;
			dfs(k+1);
			a[k]=0;used[i]=0;
		}
	}
	if(fi==1) return;
}
int main()
{
	int totalcases;
	cin>>totalcases;
	while(totalcases--)
	{
		cin>>n>>y;
		cnt=-1;
		memset(a,0,sizeof(a));
		memset(s,0,sizeof(s));
		memset(used,0,sizeof(used));
		for(int i=1;i<=n;i++) cin>>s[i];
		fi=0;p=0;
		for(;;)
		{
			dfs(1);
			if(fi==1) break;
		}
	}
}
