#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
	int w;
	char color[11];
}a[105];
bool cmp(node &x,node &y)
{
	return x.w>y.w;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].w;
		cin>>a[i].color;
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++)
	{
		cout<<a[i].color<<endl;
	}
	return 0;
}
