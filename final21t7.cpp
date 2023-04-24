#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int ans[550];
long long int dp[550][550];
string s;
int hashmod,ansmod,len;
void make()
{
	ans[0]=1%hashmod;
	for(int i=1;i<len;i++)
	{
		ans[i]=(ans[i-1]*26)%hashmod;
	}
}
int main()
{
	cin>>hashmod>>ansmod>>len;
	cin>>s;
	memset(dp,0,sizeof(dp));
	make();
	for(int i=0;i<26;i++) dp[0][i%hashmod]++;
	for(int i=1;i<len;i++)
	{
		for(int j=0;j<26;j++)
		{
			int plus=(j*ans[i])%hashmod;
			for(int k=0;k<hashmod;k++)
			{
				dp[i][(k+plus)%hashmod]+=dp[i-1][k];
				dp[i][(k+plus)%hashmod]%=ansmod;
			}
		}
	}
	int hash=0;
	for(int i=0;i<s.size();i++)
	{
		hash+=ans[i]*(s[i]-'a');
		hash%=hashmod;
	}
	cout<<dp[len-1][hash];
	return 0;
}
