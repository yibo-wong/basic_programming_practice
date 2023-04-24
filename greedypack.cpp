#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
	int m,v;
	double ave;
}a[105];
bool cmp(node x,node y)
{
	return x.ave>y.ave;
}
int main()
{
	int n,t;
	cin>>n>>t;
	for(int i=1;i<=n;i++)
		cin>>a[i].m>>a[i].v;
	for(int i=1;i<=n;i++)
		a[i].ave=1.0*a[i].v/a[i].m;
	sort(a+1,a+n+1,cmp);
	int i=1;
	double tot=0;
	while(t>=a[i].m&&t>=0&&i<=n)
	{
		t-=a[i].m;
		tot+=a[i].v;
		i++;
	}
	if(i<=n) tot+=1.0*a[i].ave*t;
	printf("%.2f",tot);
	return 0;
}
