#include <iostream>
using namespace std;
int m,n,sum,t;
int a[100050];
char tmp;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	while(m--)
	{
		cin>>tmp>>t;
		if(tmp=='C')
		{
			for(int i=1;i<=n;i++) a[i]+=t;
		}
		else
		{
			sum=0;
			for(int i=1;i<=n;i++) sum+=(a[i]>>t)&1;
			cout<<sum<<endl;
		}
	}
	return 0;
}
