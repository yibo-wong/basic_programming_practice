#include <iostream>
#include <algorithm>
using namespace std;
int a[1050];
int dp[1050];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int temp;
	dp[1]=1;
	for(int i=2;i<=n;i++)
	{
		temp=0;
		for(int j=1;j<i;j++)
		{
			if(a[j]<a[i]) temp=max(temp,dp[j]);
		}
		dp[i]=temp+1;
	}
	temp=0;
	for(int i=1;i<=n;i++) temp=max(temp,dp[i]);
	cout<<temp<<endl;
}
