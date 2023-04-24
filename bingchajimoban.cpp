#include <iostream>
#define maxn 5000000
using namespace std;
int par[maxn];
int rrank[maxn];
void initial(int s)
{
	for(int i=1;i<=s;i++)
	{
		par[i]=i;rrank[i]=0;
	}
}
int ffind(int x)
{
	if(x==par[x]) return x;
	else
	{
		par[x]=ffind(par[x]);
		return ffind(par[x]);
	}
}
void unite(int x,int y)
{
	x=ffind(x);
	y=ffind(y);
	if(rrank[x]<rrank[y]) par[x]=y;
	else if(rrank[x]>rrank[y]) par[y]=x;
	else
	{
		par[x]=y;
		rrank[y]++;
	}
}
bool same(int x,int y)
{
	return ffind(x)==ffind(y);
}
int n,k;
int t[maxn],x[maxn],y[maxn];
int main()
{
	cin>>n>>k;
	int ans=0;
	//cout<<"gh00"<<endl;
	for(int i=1;i<=k;i++)
	{
		cin>>t[i]>>x[i]>>y[i];
	}
	//cout<<"gh"<<endl;
	initial(n*3);
	for(int i=1;i<=k;i++)
	{
		if(x[i]<=0||x[i]>n||y[i]<=0||y[i]>n)
		{
			//cout<<"t0 "<<i<<endl;
			ans++;
			continue;
		}
		if(t[i]==1)
		{
			if(same(x[i],y[i]+n)||same(x[i],y[i]+2*n))
			{
				//cout<<"t1 "<<i<<endl;
				ans++;continue;
			}
			else
			{
				unite(x[i],y[i]);unite(x[i]+n,y[i]+n);unite(x[i]+2*n,y[i]+2*n);
				//cout<<"gh1"<<endl;
			}
		}
		if(t[i]==2)
		{
			if(same(x[i],y[i])||same(x[i],y[i]+2*n))
			{
				//cout<<"t2 "<<i<<endl;
				ans++;continue;
			}
			else
			{
				unite(x[i],y[i]+n);unite(x[i]+n,y[i]+2*n);unite(x[i]+2*n,y[i]);
				//cout<<"gh2"<<endl;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
