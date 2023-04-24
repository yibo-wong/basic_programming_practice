#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n,tot;
struct node
{
	int p,w;
	double a;
}x[110];
bool cmp(node s,node t)
{
	return s.a>t.a;
}
int main()
{
	cin>>n>>tot;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i].p>>x[i].w;
		x[i].a=1.0*x[i].p/x[i].w;
	}
	sort(x+1,x+n+1,cmp);
	int sum=0;
	double final;
	int temp;
	bool flag=false;
	for(int i=1;i<=n;i++)
	{
		if(sum+x[i].w<=tot)
		{
			sum+=x[i].w;
			final+=x[i].p;
		}
		else
		{
			if(sum==tot) flag=false;
			else flag=true;
			temp=i;
			break;
		}
	}
	if(flag) final+=x[temp].a*(tot-sum);
	printf("%.1f",final);
	return 0;
}
