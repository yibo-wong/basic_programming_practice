#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,f;
double maxn;
double a[10050];
double e=0.00001;
bool judge(double p)
{
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=(int) (a[i]/p);
	}
	//cout<<"in judge "<<sum<<endl;
	if(sum>f) return true;
	else return false;
}
double binary()
{
	double le=e;
	double ri=maxn;
	double mid;
	while(ri-le>e)
	{
		mid=le+(ri-le)/2;
		if(judge(mid)) le=mid;
		else ri=mid;
		//cout<<mid<<endl;
	}
	return ri;
}
int main()
{
	cin>>n>>f;
	maxn=0;
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		a[i]=3.1415926*k*k;
		maxn=max(maxn,a[i]);
	}
	double ans=binary();
	printf("%.3f",ans);
	return 0;
}
