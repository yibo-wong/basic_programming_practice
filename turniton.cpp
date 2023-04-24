#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int a[100050];
int b[100050];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	a[0]=0;
	a[n+1]=m;
	int s=1;
	for(int i=1;i<=n+1;i++)
	{
		b[i]=s*(a[i]-a[i-1]);
		s=s*(-1);
		//cout<<b[i]<<" ";
	}
	//cout<<endl;
	int temp=0;
	int tot=0;
	int sum=100000;
	for(int i=n+1;i>=1;i--)
	{
		temp+=b[i];
		//cout<<temp<<" ";
		sum=min(sum,temp);
	}
	//cout<<endl;
	//cout<<sum<<endl;
	for(int i=1;i<=n+1;i++)
	{
		if(b[i]>0)
		{
			tot+=b[i];
		}
	}
	if(sum<0)
	{
		tot-=sum;
		tot--;
		cout<<tot;
	}
	else
		cout<<tot<<endl;
	return 0;
}
