#include <iostream>
#include <cstdio>
using namespace std;
int k;
int main()
{
	int n,tot=0;cin>>n;
	for(int i=1;i<=n/2+1;i++)
	{
		k=n/i;
		tot+=n*i;
	}
	for(int i=n/2+2;i<=n;i++)
	{
		tot+=i;
	}
	cout<<tot<<endl;
	return 0;
}
