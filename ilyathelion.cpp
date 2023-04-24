#include <iostream>
#include <cstring>
using namespace std;
char a[100050];
int n;
int le,ri;
int counter;
int main()
{
	cin>>a;
	int dp[strlen(a)+2];
	memset(dp,0,sizeof(dp));
	dp[1]=0;
	for(int i=2;i<=strlen(a);i++)
	{
		if(a[i-2]==a[i-1]) dp[i]=dp[i-1]+1;
		else dp[i]=dp[i-1];
	}
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		counter=0;
		cin>>le>>ri;
		cout<<dp[ri]-dp[le]<<endl;
	}
	return 0;
}
