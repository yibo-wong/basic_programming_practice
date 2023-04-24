#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int a[60];
int s[5];
int minx;
int cur=0;
int tot=0;
int temp;
int total;
int abs(int x)
{
	return x>0 ? x : -x;
}
void dfs(int m,int x)
{
	if(x>m)
	{
		if(minx>min(minx,abs(total-temp*2)))
		{
			minx=abs(total-temp*2);
			cur=max(total-temp,temp);
		}
		//cout<<"ttt"<<cur<<endl;
		return;
	}
	temp+=a[x];
	dfs(m,x+1);
	temp-=a[x];
	dfs(m,x+1);
}
int main()
{
	for(int i=1;i<=4;i++) cin>>s[i];
	for(int w=1;w<=4;w++)
	{
		memset(a,0,sizeof(a));
		minx=10000000;
		total=0;
		for(int i=1;i<=s[w];i++) cin>>a[i];
		for(int i=1;i<=s[w];i++) total+=a[i];
		dfs(s[w],1);
		tot+=cur;
	}
	cout<<tot<<endl;
}
