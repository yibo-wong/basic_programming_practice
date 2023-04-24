#include <iostream>
#include <cstring>
using namespace std;
struct node
{
	int x;
	int y;
	int z;
}a[105];
int main()
{
	int n;
	cin>>n;
	int p=0;
	int q=0;
	int r=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	for(int i=1;i<=n;i++)
	{
		p+=a[i].x;
		q+=a[i].y;
		r+=a[i].z;
	}
	if(p==0&&q==0&&r==0) cout<<"YES";
	else cout<<"NO";
	return 0;
}
