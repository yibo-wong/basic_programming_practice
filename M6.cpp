#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int a[200050];
long long int sum;
int n;
void msort(int s,int e)
{
	if(s==e) return;
	int mid=(s+e)/2;
	msort(s,mid);
	msort(mid+1,e);
	//cout<<s<<" "<<e<<" "<<sum<<endl;
	int p=s,q=mid+1;
	int pre=0;
	vector<int>tmp;
	for(int i=mid+1;i<=e;i++) a[i]*=2;
	for(int i=s;i<=mid;i++)
	{
		if(a[e]<a[i]) sum+=e-mid;
		else
		{
			int y=lower_bound(a+mid+1,a+e,a[i])-a;
			sum+=y-(mid+1);
		}
	}
	for(int i=mid+1;i<=e;i++) a[i]/=2;
	for(int i=s;i<=mid;i++)
	{
		
	}
	while(1)
	{
		if(p>mid || q>e) break;
		if(a[p]<=a[q])
		{
			tmp.push_back(a[p]);
			p++;
		}
		else
		{
			tmp.push_back(a[q]);
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
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sum=0;
	msort(1,n);
	cout<<sum<<endl;
	return 0;
}
