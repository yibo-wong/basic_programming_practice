#include <iostream>
#define ll long long
using namespace std;
ll int a[500050];
ll int b[500050];
ll int c[500050];
ll int d[500050];
ll int n;
ll int p;
int main()
{
	cin>>n;
	ll int tot=0;
	ll int final=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		tot+=a[i];
		b[i]=tot;
	}
	ll int r=tot/3;
	if(r*3!=tot)
	{
		cout<<"0"<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==r)
		{
			c[0]++;
			c[c[0]]=i;
		}
		if(b[i]==2*r)
		{
			d[0]++;
			d[d[0]]=i;
		}
	}
	if(r==0) d[0]--;
	//for(int i=1;i<=c[0];i++) cout<<c[i]<<" ";
	//cout<<endl;
	//for(int i=1;i<=d[0];i++) cout<<d[i]<<" ";
	//cout<<endl;
	p=1;
	for(ll int i=1;i<=c[0];i++)
	{
		for(ll int j=p;j<=d[0];j++)
		{
			if(d[j]>c[i])
			{
				final+=d[0]-j+1;
				p=j-1>1?j-1:1;
				break;
			}
		}
	}
	cout<<final<<endl;
	return 0;
}
