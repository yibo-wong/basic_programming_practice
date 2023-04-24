#include <iostream>
#include <algorithm>
using namespace std;
int n;
long long int a[100050];
//long long int b[100050];
long long int dp[100050];
struct node
{
	long long int p;
	long long int v;
}b[100050];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	int pp=1;
	b[1].p=a[1];b[1].v=a[1];
	for(int i=2;i<=n;i++)
	{
		if(a[i]!=a[i-1])
		{
			pp++;
			b[pp].v=0;
		}
		b[pp].p=a[i];b[pp].v+=a[i];
	}
	dp[1]=b[1].v;
	if(n==1)
	{
		cout<<dp[1];return 0;
	}
	if(b[1].p+1==b[2].p) dp[2]=max(b[1].v,b[2].v);
	else dp[2]=b[1].v+b[2].v;
	for(int i=3;i<=pp;i++)
	{
		if(b[i].p-1!=b[i-1].p) dp[i]=dp[i-1]+b[i].v;
		else
		{
			dp[i]=max(dp[i-2]+b[i].v,dp[i-1]);
		}
	}
	//cout<<pp<<endl;
	//for(int i=1;i<=pp;i++) cout<<b[i].p<<" "<<b[i].v<<endl;
	//for(int i=1;i<=pp;i++) cout<<dp[i]<<endl;
	cout<<dp[pp]<<endl;
	return 0;
}
