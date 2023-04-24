#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct node
{
	int le,ri,h;
}a[10000];
bool cmp(node s,node t)
{
	return s.h>t.h;
}
int cases;
bool flag1,flag2;
int n,x,y,m,t,temp,final;
int num1,num2;
int dp[10000][2];//1 left,2 right
bool s[10000];
int main()
{
	cin>>cases;
	while(cases--)
	{
		cin>>n>>x>>y>>m;
		final=0;
		memset(dp,0,sizeof(dp));
		memset(s,0,sizeof(s));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].le>>a[i].ri>>a[i].h;
		}
		a[0].le=x;a[0].ri=x;a[0].h=y;
		s[0]=1;
		sort(a,a+n+1,cmp);
		//flag1=0;
		final=0;
		dp[0][1]=0;dp[0][2]=0;
		//for(int i=0;i<=n;i++) cout<<a[i].le<<" "<<a[i].ri<<" "<<a[i].h<<" # "<<endl;
		//cout<<endl;
		if(n==1)
		{
			if(a[1].le<=x&&x<=a[1].ri)
			{
				cout<<min(y+x-a[1].le,y+a[1].ri-x)<<endl;
			}
			else
				cout<<y<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			num1=100000000;num2=100000000;
			for(int j=0;j<i;j++)
			{
				if(a[j].h-a[i].h<=m&&s[j]==1)
				{
					
					if(a[i].le<=a[j].le&&a[j].le<=a[i].ri)
					{
						flag2=true;
						if(i-j>1)
						{
						
							for(int k=j+1;k<=i-1;k++)
							{
								if(a[k].le<=a[j].le&&a[j].le<=a[k].ri)
								{
									flag2=false;break;
								}
							}
						}
						if(flag2==true)
						{
							num1=min(num1,a[j].h-a[i].h+dp[j][1]+a[j].le-a[i].le);
							num2=min(num2,a[j].h-a[i].h+dp[j][1]+a[i].ri-a[j].le);
							s[i]=1;
							dp[i][1]=num1;
							dp[i][2]=num2;
							final=i;
						}
					}
					if(a[i].le<=a[j].ri&&a[j].ri<=a[i].ri)
					{
						flag2=true;
						if(i-j>1)
						{
							for(int k=j+1;k<=i-1;k++)
							{
								if(a[k].le<=a[j].ri&&a[j].ri<=a[k].ri)
								{
									flag2=false;break;
								}
							}
						}
						if(flag2==true)
						{
							num1=min(num1,a[j].h-a[i].h+dp[j][2]+a[j].ri-a[i].le);
							num2=min(num2,a[j].h-a[i].h+dp[j][2]+a[i].ri-a[j].ri);
							s[i]=1;
							dp[i][1]=num1;
							dp[i][2]=num2;
							final=i;
						}
					}
				}
			}
		}
		//cout<<temp<<endl;
		//for(int i=0;i<=n;i++) cout<<dp[i][1]<<" "<<dp[i][2]<<" "<<s[i]<<" "<<a[i].h<<" $ "<<endl;
		//cout<<endl;
		temp=10000000;
		for(int i=1;i<=n;i++)
		{
			flag2=true;
			if(s[i]==1&&a[i].h<=m)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(a[j].le<=a[i].le&&a[i].le<=a[j].ri)
								{
									flag2=false;break;
								}
				}
			}
			else
			{
				flag2=false;
			}
			if(flag2==true)
			{
				temp=min(temp,dp[i][1]+a[i].h);
			}
		}
		for(int i=1;i<=n;i++)
		{
			flag2=true;
			if(s[i]==1&&a[i].h<=m)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(a[j].le<=a[i].ri&&a[i].ri<=a[j].ri)
								{
									flag2=false;break;
								}
				}
			}
			else
			{
				flag2=false;
			}
			if(flag2==true)
			{
				temp=min(temp,dp[i][2]+a[i].h);
			}
		}
		cout<<temp<<endl;
	}
	return 0;
}
