#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n;
double ave;
struct node
{
	int t,x;
}a[1010];
bool cmp(node c,node b)
{
	if(c.t==b.t) return c.x<b.x;
	return c.t<b.t;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].t;
		a[i].x=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		cout<<a[i].x<<" ";
	cout<<endl;
	ave=0;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			ave+=a[j].t;
		}
	}
	ave=1.0*ave/n;
	printf("%.2f",ave);
	return 0;
}
