#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#define maxn 1000050
using namespace std;
string s;
int n,tot;
bool flag;
bool isnum(string x)
{
	if(x.size()==0) return false;
	bool flag=true;
	for(int i=0;i<x.size();i++)
	{
		if(x[i]<'0'||x[i]>'9')
		{
			flag=false;break;
		}
	}
	return flag;
}
vector<int>prime;
int a[maxn];
bool isp[maxn];
void sieve(int n)
{
	memset(isp,1,n);
	int p=0;
	isp[1]=0;isp[0]=0;
	for(int i=2;i<=n;i++)
	{
		if(isp[i]) 
		{
			prime.push_back(i);
			for(int j=i;j<=n;j+=i) isp[j]=0;
		}
	}
}

void div(int n)
{
	int r,w;
	if(n==1)
	{
		return;
	}
	for(r=0;;r++)
	{
		w=0;
		if(n%prime[r]==0)
		{
		tot+=1;
		while(n%prime[r]==0)
		{
			n=n/prime[r];
			w++;
		}
		if(w%2==0)
		{
			flag=1;
			return;
		}
		if(n==1)
		{
			return;
		}
		}
	}
}

int main()
{
	cin>>n;
	if(n==1)
	{
		cout<<"1"<<endl;
		return 0;
	}
	sieve(100000);
	tot=0;
	flag=0;
	div(n);
	if(flag==1)
	{
		cout<<"0"<<endl;
	}
	else
	{
		if(tot%2==1)
		{
			cout<<"-1"<<endl;
		}
		else
		{
			cout<<"1"<<endl;
		}
	}
	return 0;
}
