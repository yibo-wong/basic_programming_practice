#include <iostream>
#include <algorithm>
using namespace std;
int n;
int price[210][210];
int dp[210];
int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
			cin>>price[i][j];
	}
	dp[1]=0;
	dp[2]=price[1][2];
	for(int i=3;i<=n;i++)
	{
		int temp=99999;
		for(int j=1;j<i;j++)
		{
			if(dp[j]+price[j][i]<temp) temp=dp[j]+price[j][i];
		}
		dp[i]=temp;
	}
	cout<<dp[n]<<endl;
	return 0;
}
