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
	int m,k;
	cin>>m;
	sieve(m);
	for(int i=0;i<prime.size();i++) 
	{
		a[i]=prime[i];
		cout<<prime[i]<<" ";
	}
	cout<<endl;
	//cout<<upper_bound(a,a+prime.size(),k)-a<<endl;
	//cout<<lower_bound(a,a+prime.size(),k)-a<<endl;
	return 0;
}
