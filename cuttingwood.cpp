#include <iostream>
#include <algorithm>
using namespace std;
struct tree
{
	int x;
	int h;
}a[100050];
bool cmp(tree &m,tree &n)
{
	return m.x<n.x;
}
int dp[100050];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].x>>a[i].h;
	}
	sort(a,a+n,cmp);
	int left=0;
	dp[0]=1;
	left=a[0].x;
	for(int i=1;i<n-1;i++)
	{
		if(left>=a[i].x-a[i].h&&a[i].x+a[i].h>=a[i+1].x)
		{
			dp[i]=dp[i-1];
			left=a[i].x;
			////
			//cout<<i<<" "<<dp[i]<<endl;
		}
		else if(left<a[i].x-a[i].h)
		{
			dp[i]=dp[i-1]+1;
			left=a[i].x;
			//////
			//cout<<i<<" "<<dp[i]<<endl;
		}
		else if(a[i].x+a[i].h<a[i+1].x)
		{
			dp[i]=dp[i-1]+1;
			left=a[i].x+a[i].h;
			//////
			//cout<<i<<" "<<dp[i]<<endl;
		}
	}
	//for(int i=0;i<n;i++) cout<<dp[i]<<" ";
	dp[n-1]=dp[n-2]+1;
	cout<<dp[n-1];
	return 0;
}
