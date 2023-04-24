#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#define inf 10000000
using namespace std;
int casenum,n,tot;
string str[20],ans;
int len[12][12],x[12],vis[12];
int f(string x,string y)
{
	if(x.size()==0||y.size()==0) return 0;
	int flag=0;
	int temp=0;
	for(int i=min(x.size(),y.size());i>=1;i--)
	{
		//cout<<i<<endl;
		//cout<<x.substr(x.size()-i,i)<<endl;
		//cout<<y.substr(0,i)<<endl;
		if(x.substr(x.size()-i,i)==y.substr(0,i))
		{
			flag=1;
			temp=i;
			break;
		}
	}
	if(flag) return temp;
	else return 0;
}
void dfs(int s,int t,int lastnum)
{
	if(t>tot) return;
	if(s==n)
	{
		tot=min(tot,t);
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			dfs(s+1,t+x[i]-len[lastnum][i],i);
			vis[i]=0;
		}
	}
}
int main()
{
	cin>>casenum;
	while(casenum--)
	{
		cin>>n;
		memset(len,0,sizeof(len));
		memset(x,0,sizeof(x));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
		{
			cin>>str[i];
			x[i]=str[i].size();
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
				{
					len[i][j]=f(str[i],str[j]);
				} 
			}
		}
		tot=inf;
		for(int i=1;i<=n;i++)
		{
			vis[i]=1;
			dfs(1,x[i],i);
			vis[i]=0;
		}
		cout<<tot<<endl;
	}
	return 0;
}
