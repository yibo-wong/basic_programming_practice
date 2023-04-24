#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int test,n;
int ans;
struct node
{
	int dx,dy;
};
node a[500050];
int x[1050],y[1050];
bool cmp(node s,node t)
{
	if(s.dx==t.dx) return s.dy<t.dy;
	return s.dx<t.dx;
}
int main()
{
	cin>>test;
	while(test--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i]>>y[i];
		}
		int sum=0;
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				a[sum].dx=x[j]-x[i];
				a[sum].dy=y[j]-y[i];
				sum++;
			}
		}
		sort(a,a+sum,cmp);
		int tmp=0;
		ans=0;
		for(int i=1;i<sum;i++)
		{
			if(a[i].dx==a[i-1].dx && a[i].dy==a[i-1].dy) tmp++;
			else
			{
				ans+=tmp*(tmp+1)/2;
				tmp=0;
			}
		}
		ans+=tmp*(tmp+1)/2;
		tmp=0;
		cout<<ans<<endl;
	}
	return 0;
}
