#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,m;
int a[100050];
char t;
int tmp;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	while(m--)
	{
		cin>>t>>tmp;
		if(t=='C')
		{
			for(int i=1;i<=n;i++) a[i]+=tmp;
		}
		else
		{
			int sum=0;
			for(int i=1;i<=n;i++)
			{
				sum+=(a[i]>>tmp)&1;
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}
