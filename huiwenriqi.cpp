#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;
int month[]={0,31,29,31,30,31,30,31,31,30,31,30,31},n;
int ans;
int q[400],p;
string s;
char r[30];
string rev(string s)
{
	string a="0000";
	for(int i=0;i<=3;i++)
	{
		a[i]=s[3-i];
	}
	a=a+s;
	return a;
}
int main()
{
	p=0;
	for(int i=1;i<=12;i++)
	{
		for(int j=1;j<=month[i];j++)
		{
			n=i*100+j;
			p++;
			if(n<1000)
			{
				sprintf(r,"%d",n);
				s=r;
				s="0"+s;
				s=rev(s);
				sscanf(s.c_str(),"%d",&n);
				cout<<n<<endl;
				q[p]=n;
			}
			else
			{
				sprintf(r,"%d",n);
				s=r;
				s=rev(s);
				sscanf(s.c_str(),"%d",&n);
				cout<<n<<endl;
				q[p]=n;
			}
		}
	}
	cout<<p<<endl;
	sort(q+1,q+p+1);
	cin>>ans;
	for(int i=1;i<=p;i++)
	{
		if(q[i]<=ans&&q[i]>=10000101)
		{
			cout<<q[i]<<" ";
		}
	}
	return 0;
}
