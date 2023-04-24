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
	int tmp,p;
	for(int i=1;i<n;i++) edge[i]=a[i][0];
	int counter=n;
	used[0]=1;
	while(counter--)
	{
		tmp=inf;
		for(int i=1;i<n;i++)
		{
			if(edge[i]<tmp && used[i]==0)
			{
				tmp=edge[i];
				p=i;
			}
		}
		used[p]=1;
		for(int i=0;i<=n;i++)
		{
			if(used[i]==0 && edge[i]>a[i][p]) edge[i]=a[i][p];
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

