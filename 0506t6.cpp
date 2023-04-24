#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int a[100050];
long long int sum;
int n;
void msort(int s,int e)
{
	if(s==e) return;
	int mid=(s+e)/2;
	msort(s,mid);
	msort(mid+1,e);
	int p=s,q=mid+1;
	int pre=0;
	vector<int>tmp;
	while(1)
	{
		if(p>mid || q>e) break;
		if(a[p]<=a[q])
		{
			tmp.push_back(a[p]);
			sum+=pre;
			p++;
		}
		else
		{
			tmp.push_back(a[q]);
			pre++;
			q++;
		}
	}
	if(p>mid)
	{
		while(q<=e)
		{
			tmp.push_back(a[q]);
			q++;
		}
	}
	else
	{
		while(p<=mid)
		{
			tmp.push_back(a[p]);
			sum+=pre;
			p++;
		}
	}
	for(int i=0;i<tmp.size();i++)
	{
		a[i+s]=tmp[i];
	}
}
int main()
{
//	cin>>n;
//	for(int i=n;i>=1;i--) cin>>a[i];
//	sum=0;
//	msort(1,n);
//	cout<<sum<<endl;
//	return 0;
	while(cin>>n)
	{
		if(n==0) return 0;
		for(int i=1;i<=n;i++) cin>>a[i];
		sum=0;
		msort(1,n);
		cout<<sum<<endl;
	}
}
