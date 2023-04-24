#include <iostream>
#include <cstring>
using namespace std;
struct node
{
	char e[12];
}a[210];
int dp[20050];
char s[20050];
bool flag;
int main()
{
	int n=1;
	while(true)
	{
		cin>>a[n].e;
		if(a[n].e[0]=='.') break;
		n++;
	}
	n--;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		if(s[0]==a[i].e[0]&&strlen(a[i].e)==1) dp[0]=1;
		else
		{
			cout<<"0";
			return 0;
		}
	}
	for(int i=0;i<strlen(s);i++)
	{
		for(int j=1;j<=n;j++)
		{
			flag=1;
			for(int k=0;k<strlen(a[j].e);k++)
			{
				if(a[j].e[k]!=s[strlen(s)-strlen(a[j].e)+k]) 
				{
					flag=0;
					break;
				}
			}
			if(dp[i-strlen(a[j].e)]==1&&flag)
			{
				dp[i]=1;
				break;
			}
		}
	}
	int counter=0;
	for(int i=0;i<n;i++)
	{
		if(dp[i]==1)
		{
			counter++;
		}
		if(dp[i]==0)
			break;
	}
	cout<<counter;
	return 0;
}
