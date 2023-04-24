#include <iostream>
#include <vector>
#include <cstring>
#define maxn 10000
using namespace std;
vector<int>prime;
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
vector <int> a;
int p=0;
void f(int n)
{
	if(prime[p]>n) return;
	if(n%prime[p]==0)
	{
		
		while(n%prime[p]==0)
		{
			n=n/prime[p];
			a.push_back(prime[p]);
		}
		p++;
		f(n);
	}
	else
	{
		//cout<<"iii"<<endl;
		p++;
		f(n);
	}
}
int main()
{
	int m;cin>>m;
	sieve(10000);
	//cout<<"uuu"<<endl;
	//cout<<prime[0]<<endl;
	f(m);
	//cout<<"iii"<<endl;
	//for(int i=1;i<=1000;i++) cout<<prime[i]<<" ";
	for(int i=0;i<a.size();i++)
		cout<<a[i]<<" ";
	return 0;
}
