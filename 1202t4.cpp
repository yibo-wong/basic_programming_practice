#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int cases;
int m,n;
int x,y;
int dx[]={1,2,2,1,-1,-2,-2,-1};
int dy[]={2,1,-1,-2,2,1,-1,-2};
int maze[12][12];
bool s[12][12];
int tot;
void dfs(int k,int x1,int y1)
{
	if(k==m*n) 
	{
		tot++;return;
	}
	for(int i=0;i<8;i++)
	{
		if(x1+dx[i]>=0&&x1+dx[i]<n&&y1+dy[i]>=0&&y1+dy[i]<m)
		{
			if(s[x1+dx[i]][y1+dy[i]]==0)
			{
				s[x1+dx[i]][y1+dy[i]]=1;
				dfs(k+1,x1+dx[i],y1+dy[i]);
				s[x1+dx[i]][y1+dy[i]]=0;
			}
		}
	}
}
int main()
{
	cin>>cases;
	while(cases--)
	{
		tot=0;
		memset(s,0,sizeof(s));
		cin>>n>>m>>x>>y;
		s[x][y]=1;
		dfs(1,x,y);
		cout<<tot<<endl;
	}
	return 0;
}
