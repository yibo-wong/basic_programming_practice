#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;
int n,zx[2000],zy[2000],k;
int x1,y1,x2,y2,row,col;
int xx[4]={0,0,1,-1},yy[4]={1,-1,0,0};
char map[1001][1001];
bool vis[1001][1001];
bool flag;
int final;
struct node
{
	int x,y,t;
	bool s;
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
		if(a==x2 && b==y2) 
		{
			flag=1;
			final=c;
			break;
		}
		if(now.s==1)
		{
			net.x=a;net.y=b;net.t=c+1;
			net.s=0;
			q.push(net);
			continue;
		}
		for(int i=0;i<4;i++) 
			{ 
			int dx=a+xx[i];int dy=b+yy[i];
			if(dx>=1 && dx<=row && dy>=1 && dy<=col && map[dx][dy]=='@' && vis[dx][dy]==0) 
			{
				net.x=dx;
				net.y=dy;
				net.t=c+1;
				net.s=0;
				vis[dx][dy]=1;
				q.push(net);
		 	}
		 	if(dx>=1 && dx<=row && dy>=1 && dy<=col && map[dx][dy]=='x' && vis[dx][dy]==0) 
			{
				net.x=dx;
				net.y=dy;
				net.t=c+1;
				net.s=1;
				vis[dx][dy]=1;
				q.push(net);
		 	}
		}
	}
}
int main()
{
	cin>>k;
	while(k--) 
	{
		cin>>row>>col;
		memset(map,0,sizeof(map));
		memset(vis,0,sizeof(vis));
		flag=0;
		for(int i=1;i<=row;i++)
		{
			for(int j=1;j<=col;j++)
			{
				cin>>map[i][j];
				if(map[i][j]=='r')
				{
					x1=i;y1=j;
				}
				if(map[i][j]=='a')
				{
					x2=i;y2=j;
				}
			}
		}
        vis[x1][y1]=1;
		bfs(x1,y1,0);
		if(flag==1)
			cout<<final<<endl;
		else
			printf("No\n");
	}
}
