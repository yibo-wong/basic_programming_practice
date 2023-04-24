#include <iostream>
#include <algorithm>
#include <cstring>
#define maxn 5000000
using namespace std;
int r,c,n;
bool maze[5010][5010];
int x[5010],y[5010],dx,dy,cnt,p,tot;
int main()
{
	cin>>r>>c>>n;
	memset(maze,0,sizeof(maze));
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		maze[x[i]][y[i]]=1;
	}
	tot=0;
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			cnt=2;
			dx=x[j]-x[i];dy=y[j]-y[i];
			p=1;
			//cout<<x[i]<<" "<<y[i]<<endl;
			//cout<<x[j]<<" "<<y[j]<<endl;
			//cout<<"dxdy"<<dx<<" "<<dy<<endl;
			while(1<=x[j]+dx*p&&x[j]+dx*p<=r&&1<=y[j]+dy*p&&y[j]+dy*p<=c&&maze[x[j]+dx*p][y[j]+dy*p])
			{
				cnt++;
				//cout<<x[j]+dx*p<<" "<<y[j]+dy*p<<endl;
				p++;
			}
			dx=-dx;dy=-dy;
			p=1;
			while(1<=x[i]+dx*p&&x[i]+dx*p<=r&&1<=y[i]+dy*p&&y[i]+dy*p<=c&&maze[x[i]+dx*p][y[i]+dy*p])
			{
				cnt++;
				//cout<<x[i]+dx*p<<" "<<y[i]+dy*p<<endl;
				p++;
			}
			if(cnt!=2) tot=max(tot,cnt);
			//cout<<endl<<endl<<endl;
			//cout<<cnt<<" "<<i<<" "<<j<<endl;
		}
	}
	cout<<tot<<endl;return 0;
}
