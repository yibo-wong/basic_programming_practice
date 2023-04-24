#include <iostream>
using namespace std;
int n,m,len;
int a[50050];
bool f(int k)
{
	int d=k;
	int cnt=0;
	int cur=0;
	for(int i=1;i<=n+1;i++)
	{
		if(a[i]-a[cur]>=k)
		{
			cnt++;
			cur=i;
		} 
	}
	if(cnt>n-m) return true;
	else return false;
}
int main()
{
	cin>>len>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	a[0]=0;a[n+1]=len;
	int le=0;
	int ri=len;
	int mid;
	int final;
	while(le<=ri)
	{
		mid=le+(ri-le)/2;
		if(f(mid)==true)
		{
			if(f(mid+1)==false)
			{
				final=mid;break;
			}
			else
			{
				le=mid+1;
			}
		}
		else
		{
			ri=mid-1;
		}
	}
	//for(int i=1;i<=25;i++) cout<<i<<" "<<f(i)<<"\\ ";
	//cout<<endl;
	cout<<final;
	return 0;
}
