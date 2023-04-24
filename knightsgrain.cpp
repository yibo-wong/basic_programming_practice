#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n,p[12000],tot=0,temp,start,ans;
int main()
{
	temp=1;start=1;
	while(tot<=11000)
	{
		for(int i=start;i<=start+temp-1;i++)
		{
			p[i]=temp;
		}
		start=start+temp;
		temp++;
		tot=start+temp+2;
	}
	//for(int i=1;i<=100;i++) cout<<p[i]<<" ";
	//cout<<endl;
	while(true)
	{
		cin>>n;
		ans=0;
		if(n==0) return 0;
		cout<<n<<" ";
		for(int i=1;i<=n;i++) ans+=p[i];
		cout<<ans<<endl;
	}
	
}
