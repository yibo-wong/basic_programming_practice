#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[50050],n,k;
bool used[50050];
bool bi(int i)
{
	int le=0,ri=n-1;
	int mid=(le+ri)/2;
	while(le<=ri)
	{
		//cout<<"in bi "<<le<<" "<<ri<<endl;
		mid=(le+ri)/2;
		if(a[mid]==i)
		{
			if(used[mid]==0) return 1;
			else
			{
				used[mid]=1;return 0;
			}
		}
		else if(a[mid]>i)
		{
			ri=mid-1;
		}
		else le=mid+1;
	}
	return 0;
}
int main()
{
	bool flag=0;
	cin>>k>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		used[i]=1;
		if(bi(k-a[i]))
		{
			flag=1;
			cout<<a[i]<<" "<<k-a[i]<<endl;
		}
	}
	if(flag==0) cout<<"No Solution"<<endl;
}
