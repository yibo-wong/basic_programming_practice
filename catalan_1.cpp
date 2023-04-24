#include <iostream>
#include <algorithm>
using namespace std;
int dp[20];
int main()
{
	dp[0]=1;dp[1]=1;
	for(int i=2;i<=20;i++)
	{
		int sum=0;
		for(int j=0;j<=i-1;j++) sum+=dp[j]*dp[i-1-j];
		dp[i]=sum;
	}
	int n;
	cin>>n;
	cout<<dp[n];
	return 0;
}
