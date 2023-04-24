#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[300010];
double p;
double ans;
double h;
int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=3;i++)
	{
		p=1.0*i/4;
		h=(n-1)*p+1;
		ans=a[int(h)]+(h-int(h))*(a[int(h)+1]-a[int(h)]);
		printf("%.2f\n",ans);
	}
	return 0;
}
