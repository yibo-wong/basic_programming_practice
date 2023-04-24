#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
struct node
{
	string s;
	int id;
}a[110];
int f(string s)
{
	int len=s.size();
	int sum=0;
	for(int i=0;i<len;i++)
	{
		for(int j=i+1;j<len;j++)
		{
			if(s[i]>s[j]) sum++;
		}
	}
	return sum;
}
bool cmp(node a,node b)
{
	if(f(a.s)==f(b.s)) return a.id<b.id;
	return f(a.s)<f(b.s);
}
int main()
{
	int m,n;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>a[i].s;
		a[i].id=i;
	}
	sort(a,a+m,cmp);
	for(int i=0;i<m;i++) cout<<a[i].s<<endl;
	return 0;
}
