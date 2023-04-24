#include <iostream>
#include <algorithm>
using namespace std;
int e;
int n,len;
int temp;
int x,y;
int a[1000050];
int main()
{
	cin>>e;
	while(e--)
	{
		cin>>len>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		a[0]=0;a[n+1]=len;
		temp=0;
		for(int i=1;i<=n;i++)
		{
			if(temp<max(a[i]-a[0],a[n+1]-a[i])) temp=max(a[i]-a[0],a[n+1]-a[i]);
		}
		y=temp;
		temp=0;
		for(int i=1;i<=n;i++)
		{
			if(temp<min(a[i]-a[0],a[n+1]-a[i])) temp=min(a[i]-a[0],a[n+1]-a[i]);
		}
		x=temp;
		cout<<x<<" "<<y<<endl;
	}
	return 0;
}
