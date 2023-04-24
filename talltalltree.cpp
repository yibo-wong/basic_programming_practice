#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
int n,casenum;
int a,h[10050],sum;
int m[10050],x1,x2,top;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	cin>>casenum;
	while(casenum--)
	{
		memset(m,0,sizeof(m));
		top=0;
		sum=0;
		cin>>n>>a;
		for(int i=1;i<=n;i++) cin>>h[i];
		sort(h+1,h+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			x1=h[i]/a;
			x2=h[i]%a;
			for(int j=i;j<=x1+i-1;j++) m[j]=max(m[j],a);
			m[x1+i]=max(m[x1+i],x2);
			top=max(top,x1+i);
		}
		for(int i=1;i<=top+1;i++) sum+=m[i];
		cout<<sum<<endl;
	}
	return 0;
}
