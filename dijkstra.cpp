#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int maze[18][18],d[18];
int totalcases,n;
bool vis[18];
int main()
{
	cin>>totalcases;
	while(totalcases--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>maze[i][j];
			}
		}
		memset(d,0,sizeof(d));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++) d[i]=maze[1][i];
		vis[1]=1;
		for(int t=1;t<n;t++)
		{
			int minn=100000;int temp;
			for(int i=1;i<=n;i++)
			{
				if(!vis[i]&&d[i]<minn)
				{
					temp=i;minn=d[i];
				} 
			}
			vis[temp]=1;
			for(int i=1;i<=n;i++)
			{
				if(maze[temp][i]+d[temp]<d[i]) d[i]=maze[temp][i]+d[temp];
			}
		}
		cout<<d[n]<<endl;
	}
}
