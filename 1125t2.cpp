#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int prime[2020];
int p;
int a[2020];
bool isp[2020];
void sieve(int n)
{
	memset(isp,1,n);
	p=0;
	isp[1]=0;isp[0]=0;
	for(int i=2;i<=n;i++)
	{
		if(isp[i]) 
		{
			prime[p]=i;p++;
			for(int j=i;j<=n;j+=i) isp[j]=0;
		}
	}
}
int main()
{
	int n;
	cin>>n;
	if(n%2!=0||n<6)
	{
		cout<<"Error!"<<endl;
		return 0;
	}
	sieve(2000);
	for(int i=0;prime[i]<=n/2;i++)
	{
		for(int j=i;;j++)
		{
			if(prime[j]+prime[i]==n)
			{
				cout<<n<<"="<<prime[i]<<"+"<<prime[j]<<endl;
				break;
			}
			if(prime[j]+prime[i]>n) break;
		}
	}
	return 0;
}
