#include <iostream>
using namespace std;
int x[9]={0,-2,-1,1,2,2,1,-1,-2};
int y[9]={0,1,2,2,1,-1,-2,-2,-1};
long long int f[40][40];
bool a[40][40];
int main()
{
	int n,m,s,t;
	cin>>n>>m>>s>>t;
	n+=2;m+=2;s+=2;t+=2;
	a[s][t]=1;
	for(int i=1;i<=8;i++) a[s+x[i]][t+y[i]]=1;
	f[2][1]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=m;j++)
		{
			if(a[i][j]) continue;
			f[i][j]=f[i][j-1]+f[i-1][j];
		}
	}
	cout<<f[n][m];
	return 0;
}

