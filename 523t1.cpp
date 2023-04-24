#include <iostream>
#include <cstring>
using namespace std;
long long int dp[20];
int n;
int main()
{
	cin>>n;
	dp[0]=1;
	dp[1]=1;dp[2]=2;
	for(int i=3;i<=18;i++)
	{
		dp[i]=0;
		for(int j=0;j<i;j++)
		{
			dp[i]+=dp[j]*dp[i-j-1];
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}
