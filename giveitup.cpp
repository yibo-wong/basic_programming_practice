#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
struct node
{
	int a,b;
	double v;
}stu[1050];
bool cmp(node x,node y)
{
	if(x.a!=0||y.a!=0)
	{
		if(x.v==y.v) return x.a>y.a;
		return x.v>y.v;
	}
	else
	{
		return x.b<y.b;
	}
}
int n,k;
int main()
{
	while(cin>>n>>k)
	{
		if(n==0&&k==0) return 0;
		for(int i=1;i<=n;i++)
		{
			cin>>stu[i].a;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>stu[i].b;
		}
		for(int i=1;i<=n;i++)
		{
			stu[i].v=1.0*stu[i].a/stu[i].b;
		}
		sort(stu+1,stu+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			cout<<stu[i].a<<" "<<stu[i].b<<endl;
		}
		int tot1=0,tot2=0;
		for(int i=1;i<=n-k;i++)
		{
			tot1+=stu[i].a;
			tot2+=stu[i].b;
		}
		cout<<tot1<<" "<<tot2<<endl;
		cout<<round(1.0*100*tot1/tot2)<<endl;
	}
}
