#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
char a[2050];
char b[2050];
int x[2050];
int y[2050];
int end[2050];
void pls(int s[],int t[])
{
	int temp;
	int n=0;
	for(int i=1;i<=max(s[0],t[0])+1;i++)
	{
		temp=(s[i]+t[i]+n)%10;
		n=(s[i]+t[i]+n)/10;
		s[i]=temp;
	}
	if(s[max(s[0],t[0])+1]==0) s[0]=max(s[0],t[0]);
	else s[0]=max(s[0],t[0])+1;
}
void in(int s[],int temp[])
{
	memset(s,0,sizeof(s));
	for(int i=0;i<=temp[0];i++)
	{
		s[i]=temp[i];
	}
}
void timenum(int s[],int temp[],int m)
{
	memset(temp,0,sizeof(temp));
	int n=0;
	for(int i=1;i<=s[0]+1;i++)
	{
		temp[i]=(s[i]*m+n)%10;
		n=(s[i]*m+n)/10;
	}
	if(temp[s[0]+1]==0) temp[0]=s[0];
	else temp[0]=s[0]+1;
}
void move(int s[],int m)
{
	s[0]+=m;
	for(int i=s[0];i>=1;i--)
	{
		s[i+m]=s[i];
	}
	for(int i=1;i<=m;i++)
		s[i]=0;
}
void time(int s[],int t[],int ans[])
{
	int temp[2050];
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=t[0];i++)
	{
		timenum(s,temp,t[i]);
		move(temp,i-1);
		pls(ans,temp); 	
	}
	if(ans[s[0]+t[0]]==0) ans[0]=s[0]+t[0]-1;
	else ans[0]=s[0]+t[0];
}
int main()
{
	cin>>a;
	for(int i=0;i<strlen(a);i++)
	{
		x[strlen(a)-i]=a[i]-'0';
	}
	x[0]=strlen(a);
	
	cin>>b;
	for(int i=0;i<strlen(b);i++)
	{
		y[strlen(b)-i]=b[i]-'0';
	}
	y[0]=strlen(b);
	time(x,y,end);
	for(int i=end[0];i>0;i--)
		cout<<end[i];
	
	return 0;
	
	
}
