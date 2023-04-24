#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[320],s[320];
int n,p,m,cur,cnt,num,ans;
bool flag;
int next(int x)
{
	return x%m+1;
}
int main()
{
	while(cin>>n>>p>>m)
	{
		if(n==0&&p==0&&m==0) return 0;
		memset(s,0,sizeof(s));
		cur=p;cnt=0;num=0;flag=0;
		while(true)
		{
			for(int i=1;i<=n;i++)
			{
				if(i==p) flag=1;
				if(flag&&s[i]==0)
				{
					num=next(num);
					if(num==m){
						s[i]=1;
						cout<<i<<",";
						cnt++;
					} 
				}
				if(cnt==n-1)
				{
					break;
				}
			}
			if(cnt==n-1)
			{
				break;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(s[i]==0)
			{
				cout<<i<<endl;
			}
		}
	}
}
