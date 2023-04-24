#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>
#define maxn 100000050
using namespace std;
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
int m,n;
int tot=0,temp;
bool flag;
double x;
int main()
{
	cin>>m>>n;
	sieve(10000);
	//for(int i=1;i<=600;i++) cout<<prime[i]<<" ";
	while(m--)
	{
		tot=0;x=0;
		for(int r=1;r<=n;r++)
		{
			cin>>temp;
			flag=false;
			for(int i=1;prime[i]*prime[i]<=temp;i++)
			{
				if(prime[i]*prime[i]==temp) flag=true;
				cout<<prime[i]<<endl;
			}
			if(flag) tot+=temp;
		}
		//cout<<tot<<endl;
		x=1.0*tot/n;
		if(x!=0) printf(".2f\n",x);
		else printf("0\n");
	}
}
