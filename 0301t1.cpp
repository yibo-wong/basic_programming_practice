#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
int dp[10][32];//10^n mod m
int ans[10][32];
int sum;
bool ok[10];
string s;
int n1,n2,n3;
void ini()
{
	for(int i=2;i<=9;i++)
	{
		dp[i][0]=1;
		for(int j=1;j<=30;j++)
		{
			dp[i][j]=(dp[i][j-1]*10)%i;
		}
	}
	return;
}
int main()
{
	cin>>s;
	ini();
	memset(ok,0,sizeof(ok));
	memset(ans,0,sizeof(ans));
	int len=s.size();
	for(int i=2;i<=9;i++)
	{
		ans[i][0]=(s[len-1]-'0')%i;
		for(int j=1;j<len;j++)
		{
			ans[i][j]=(dp[i][j]*(s[len-j-1]-'0') + ans[i][j-1]) %i;
		}
		if(ans[i][len-1]==0) ok[i]=1;
	}
	bool flag=0;
	for(int i=2;i<=9;i++)
	{
		if(ok[i])
		{
			cout<<i<<" ";
			flag=1;
		}
	}
	if(flag==0) cout<<"none"<<endl;
	return 0;
}


