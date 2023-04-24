#include <iostream>
#include <cstring>
#include <algorithm>
#define maxn 110
#define inf 0x3f3f3f3f
using namespace std;
int a[maxn][maxn];
int n;
bool used[maxn];
int edge[maxn],sum;
void prim()
{
	int tmp,p;
	memset(used,0,sizeof(used));
	for(int i=1;i<n;i++) edge[i]=a[i][0];
	int counter=n-1;
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
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>a[i][j];
		prim();
		sum=0;
		for(int i=0;i<n;i++) sum+=edge[i];
		cout<<sum<<endl;
	}
}

