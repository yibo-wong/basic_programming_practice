#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define maxn 1000000
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
int main()
{
	sieve(12000);
	int t,n;
	cin>>t;
	for(int j=1;j<=t;j++)
	{
		cin>>n;
		cout<<"Case"<<j<<":"<<endl;
		if(n<=11) cout<<"NULL"<<endl;
		else
		{
			for(int i=0;prime[i]<n;i++)
			{
				if(prime[i]%10==1)
				{
					cout<<prime[i]<<" ";
				}
			}
			cout<<endl;
		}
	}
	return 0;
}
