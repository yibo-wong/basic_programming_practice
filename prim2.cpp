#include <iostream>
#include <cstring>
#include <algorithm>
#define inf 0x3f3f3f3f
using namespace std;
int a[30][30];
int n;
bool used[30];
int edge[100],sum;
void prim()
{
	used[0]=1;
	for(int i=0;i<n;i++)
	{
		edge[i]=a[i][0];
	}
	int u=0;
	for(int ii=1;ii<=n;ii++)
	{
		int temp=inf;
		for(int i=0;i<n;i++)
		{
			if(!used[i] && temp>edge[i])
			{
				u=i;
				temp=edge[i];
			}
		}
		used[u]=true;
		for(int i=0;i<n;i++)
		{
			if(!used[i] && edge[i] > a[i][u])
			{
				edge[i]=a[i][u];
			}
		}
	}
}
int main()
{
	while(cin>>n)
	{
		if(n==0) return 0;
		memset(a,inf,sizeof(a));
		memset(used,0,sizeof(used));
		char p,e;
		int tmp,v;
		for(int i=0;i<n-1;i++)
		{
			cin>>p>>tmp;
			while(tmp--)
			{
				cin>>e>>v;
				a[p-'A'][e-'A']=v;
				a[e-'A'][p-'A']=v;
			}
		}
		for(int i=0;i<=26;i++) a[i][i]=0;
		prim();
		sum=0;
		for(int i=0;i<n;i++) sum+=edge[i];
		cout<<sum<<endl;
	}
}
