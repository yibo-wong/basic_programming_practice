#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int l,n,k;
int a[20050];
int judge(int x)
{
	int len;
	int sum=0;
	for(int i=2;i<=n;i++)
	{
		len=a[i]-a[i-1];
		if(len%x==0) sum+=len/x-1;
		else sum+=len/x;
	}
	if(sum<=k) return 1;
	else return 0;
}
int main()
{
	cin>>l>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	int le=0,ri=l;
	while(le<ri)
	{
		int mid=le+(ri-le)/2;
		if(judge(mid)==1) ri=mid;
		else le=mid+1;
	}
	cout<<le<<endl;
	return 0;
}
