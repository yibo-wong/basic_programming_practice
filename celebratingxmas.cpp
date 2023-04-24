#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int a[3];
int abs(int x)
{
	if(x<0) return -x;
	else return x;
}
int main()
{
	cin>>a[0];
	cin>>a[1];
	cin>>a[2];
	sort(a,a+3);
	int m=10000;
	for(int i=a[0];i<=a[2];i++)
	{
		m=min(m,abs(i-a[0])+abs(i-a[1])+abs(i-a[2]));
	}
	cout<<m;
	return 0;
}
