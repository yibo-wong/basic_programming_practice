#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n,a[1050],tot;
double ans;
int main()
{
	while((scanf("%d",&n))!=EOF)
	{
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		tot=0;
		for(int i=1;i<=n-1;i++) tot+=a[i];
		if(tot>=a[n])
		{
			ans=1.0*(tot+a[n])/2;
			printf("%.1f\n",ans);
		}
		else
		{
			ans=tot;
			printf("%.1f\n",ans);
		}
	}
	return 0;
}
