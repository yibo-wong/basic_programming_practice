#include <iostream>
#include <cstring>
#include <algorithm>
#define maxn 260
#define ll long long
using namespace std;
ll int f[maxn+2][maxn+2],g[maxn+2][maxn+2];
void init()
{
	f[0][0]=1;g[0][0]=1;
	for(int i=1;i<maxn;i++)
	{
		for(int j=1;j<=i;j++)
		{
			g[i][j]=f[i-j][j];
			f[i][j]=f[i-1][j-1]+g[i-j][j];
		}
	}
}
int main()
{
	int n;
	init();
	while(cin>>n)
	{
		if(n==0) break;
		ll int sum=0;
		for(int i=1;i<=n;i++) sum+=f[n][i]+g[n][i];
		cout<<n<<" "<<sum<<endl;
	}
	return 0;
}
