#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int dp0[100050][3];
int dp1[100050][3];
int n,totalcases,p[100050];
int main()
{
	cin>>totalcases;
	while(totalcases--)
	{
		cin>>n;
		memset(dp0,0,sizeof(dp0));
		memset(dp1,0,sizeof(dp1));
		memset(p,0,sizeof(p));
		for(int i=1;i<=n;i++) cin>>p[i];
		dp1[1][0]=-p[1];
		for(int i=2;i<=n;i++) dp1[i][0]=-min(-dp1[i-1][0],p[i]);
		dp0[1][1]=0;
		for(int i=2;i<=n;i++) dp0[i][1]=max(dp0[i-1][1],dp1[i][0]+p[i]);
		dp1[1][1]=-p[1];
		for(int i=2;i<=n;i++) dp1[i][1]=max(dp1[i-1][1],dp0[i][1]-p[i]);
		dp0[1][2]=0;
		for(int i=2;i<=n;i++) dp0[i][2]=max(dp0[i-1][2],dp1[i][1]+p[i]);
		/*
		for(int i=1;i<=n;i++) cout<<dp0[i][0]<<" ";
		cout<<endl;
		for(int i=1;i<=n;i++) cout<<dp1[i][0]<<" ";
		cout<<endl;
		for(int i=1;i<=n;i++) cout<<dp0[i][1]<<" ";
		cout<<endl;
		for(int i=1;i<=n;i++) cout<<dp1[i][1]<<" ";
		cout<<endl;
		for(int i=1;i<=n;i++) cout<<dp0[i][2]<<" ";
		cout<<endl;
		*/
		cout<<dp0[n][2]<<endl;
	}
}
