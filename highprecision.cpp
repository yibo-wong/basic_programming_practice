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
	pls(x,y);
	bool flag=0;
	for(int i=x[0];i>0;i--)
	{
		if(x[i]!=0&&flag==0)
		{
			flag=1;
			cout<<x[i];
		}
		else if(flag==0&&x[i]==0)
		{
			continue;
		}
		else
			cout<<x[i];
	}
	return 0;	
}
