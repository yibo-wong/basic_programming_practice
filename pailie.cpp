#include <iostream>
#include <algorithm>
using namespace std;
int a[1050];
int b[1050];
int n;
void f(int m)
{
	if(m==n)
	{
		for(int i=1;i<=n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
	else
	{
		for(int i=m;i<=n;i++)
		{
			swap(a[m],a[i]);
			f(m+1);
			swap(a[m],a[i]);
		}
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		a[i]=i;
	f(1);
	return 0;
}
