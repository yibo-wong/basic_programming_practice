#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
struct node
{
	string a;
	int len;
}x[1050];
bool cmp(node m,node n)
{
	string s=m.a+n.a;
	string t=n.a+m.a;
	return s.compare(t);
}
int n;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x[i].a;
		x[i].len=sizeof(x[i].a);
	}
	sort(x,x+n,cmp);
	string ans1,ans2;
	for(int i=n-1;i>=0;i--)
	{
		ans1=x[i].a+ans1;
	}
	cout<<ans1;
	cout<<" ";
	for(int i=0;i<=n;i++)
	{
		ans2=x[i].a+ans2;
	}
	cout<<ans2;
	return 0;
}
