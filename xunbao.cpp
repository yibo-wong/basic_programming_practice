#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;
int n,k;
int x1,y1,x2,y2,row,col;
int xx[4]={0,0,1,-1},yy[4]={1,-1,0,0};
int map[1001][1001];
bool vis[1001][1001];
bool flag;
int final;
int tt;
struct node
{
	int x,y,t;
};
void bfs(int x,int y,int t)
{
	queue<node>q;
	node now,net;
	now.x=x;now.y=y;now.t=t;
	q.push(now);
	while(!q.empty()) 
	{
		now=q.front();q.pop();
		int a=now.x;int b=now.y;int c=now.t;
		if(map[a][b]==1) 
		{
			flag=1;
			final=c;
			break;
		}
		for(int i=0;i<4;i++) 
			{ 
			//cout<<"uuu"<<endl;
			int dx=a+xx[i];int dy=b+yy[i];
			//cout<<dx<<","<<dy<<endl;
			if(dx>=1 && dx<=row && dy>=1 && dy<=col && map[dx][dy]!=2 && vis[dx][dy]==0) 
			{
				net.x=dx;
				net.y=dy;
				net.t=c+1;
				vis[dx][dy]=1;
				q.push(net);
			}
		}
	}
}
int main()
{
	k=1;
	while(k--) 
	{
		cin>>row>>col>>tt;
		memset(map,0,sizeof(map));
		for(int i=1;i<=row;i++)
		{
			for(int j=1;j<=col;j++)
			{
				cin>>map[i][j];
			}
		}
		for(int ii=1;ii<=tt;ii++)
		{
			cin>>y1>>x1;
			if(map[x1][y1]==2)
			{
				cout<<"NO"<<endl;
				continue;
			}
			memset(vis,0,sizeof(vis));
			flag=0;
        	vis[x1][y1]=1;
			bfs(x1,y1,0);
			if(flag==1)
				cout<<final<<endl;
			else
				printf("NO\n");
		}
	}
}
