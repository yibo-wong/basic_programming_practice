#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int n,m;
ll int a[100050];
ll int b[100050];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	//for(int i=1;i<=n;i++) cout<<a[i]<<endl;
	for(int i=1;i<n;i++)
	{
		b[i]=a[i+1]-a[i];
	}
	sort(b+1,b+n,cmp);
	//for(int i=1;i<n;i++) cout<<b[i]<<endl;
	ll int tot=0;
	for(int i=1;i<=m-1;i++) tot+=b[i];
	cout<<a[n]-a[1]-tot<<endl;
	return 0;
}
