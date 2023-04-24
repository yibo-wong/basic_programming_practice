#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int ans=0x37;
int d[19],n,tot;
bool used[19];
int w[19];
int num(int k)
{
	int sum=0,tmp=0;
	for(int i=1;i<=k;i++)
	{
		tmp+=w[d[i]];
		if(tmp>tot)
		{
			sum++;
			tmp=w[d[i]];
		}
	}
	sum++;
	return sum;
}
void print()
{
	for(int i=1;i<=n;i++) cout<<d[i]<<" ";
	cout<<endl;
}
void dfs(int pos)
{
	//cout<<"get "<<pos<<endl;
	if(pos>n)
	{
		//print();
		int t=num(n);
		ans=min(ans,t);
		return;
	}
	if(pos>1)
	{
		//cout<<"num "<<num(pos-1)<<endl;
		if(num(pos-1)>ans) return;
	}
	for(int i=1;i<=n;i++)
	{
		if(used[i]==0)
		{
			used[i]=1;
			d[pos]=i;
			dfs(pos+1);
			used[i]=0;
			d[pos]=0;
		}
	}
}
int main()
{
	cin>>n>>tot;
	for(int i=1;i<=n;i++) cin>>w[i];
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
