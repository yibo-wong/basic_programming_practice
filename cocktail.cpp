#include <iostream>
#include <cstdio>
using namespace std;
int a[105];
int main()
{
	int n;
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		sum+=a[i];
	}
	double ans=0.00;
	ans=1.0*sum/n;
	printf("%.10f",ans);
	return 0;
}
