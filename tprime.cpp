#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int isp(long long int n)
{
	if(n==1||n==2||n==3) return 1;//6,671,132,329
	if(n%6!=1&&n%6!=5) return 0;
else
{
	for(long long int i=5;i<=sqrt(n)+1;i+=5)
	{
		if(n%i==0||n%(i+2)==0) return 0;
	}
	return 1;
}
}
int main()
{
	long long int n,x,t;
	cin>>x;
	for(long long int i=1;i<=x;i++)
	{
		cin>>n;
		t=sqrt(n);
		if(n!=t*t||n==1) cout<<"NO"<<endl;
		else
		{
			if(isp(t)) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
	return 0;
}
