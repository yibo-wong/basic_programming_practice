#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
struct node
{
	int a;
	int b;
}p[300000];
bool cmp(node x,node y)
{
	return x.a>y.a;
}
int cases;
int n;
bool flag=false;
int point;
int tot;
int main()
{
	cin>>cases;
	for(int w=1;w<=cases;w++)
	{
		cin>>n;
		for(int i=1;i<=n;i++) cin>>p[i].a;
		for(int i=1;i<=n;i++) cin>>p[i].b;
		if(n==1)
		{
			cout<<min(p[1].a,p[1].b)<<endl;
			continue;
		}
		sort(p+1,p+n+1,cmp);
		tot=0;
		flag=true;
		for(int i=1;i<=n;i++)
		{
			tot+=p[i].b;
			point=i;
			if(tot>p[i].a)
			{
				tot-=p[i].b;
				flag=false;
				break;
			}
		}
		if(point==1) cout<<p[1].a<<endl;
		else if(point==n&&flag) cout<<tot<<endl;
		else cout<<max(p[point].a,tot)<<endl;
	}
	return 0;
}
