#include <iostream>
#define ll long long
using namespace std;
int m,n;
ll int a[100050];
//int sum=0;mon=1;int dp[10050];
bool judge(int k)
{
	int sum=0;int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>k) return false;
		sum+=a[i];
		if(sum>k)
		{
			cnt++;sum=a[i];
		}
		else if(sum==k)
		{
			cnt++;sum=0;
		}
	}
	if(sum!=0) cnt++;
	if(cnt<=m) return true;
	else return false;
}
int main()
{
	cin>>n>>m;
	ll int tot=0;
	ll int temp=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		tot+=a[i];
		if(a[i]>temp) temp=a[i];
	}
	ll int final;
	ll int le,ri;
	le=temp;ri=tot;
	ll int mid;
	while(le<=ri)
	{
		mid=le+(ri-le)/2;
		if(judge(mid)==true)
		{
			if(judge(mid-1)==false)
			{
				final=mid;break;
			}
			else
			{
				ri=mid-1;
			}
		}
		else
		{
			le=mid+1;
		}
	}
	//for(int i=0;i<=200;i+=10) cout<<i<<" "<<judge(i)<<" # ";
	//cout<<endl;
	cout<<final;
	return 0;
}

