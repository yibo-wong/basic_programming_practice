#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;
int n,cases;
int x1,y1,x2,y2,row,col,k;
int xx[4]={0,0,1,-1},yy[4]={1,-1,0,0};
char map[1001][1001];
bool vis[1001][1001];
bool flag;
int final;
struct node
{
	int x,y,t;
};
void bfs(int x,int y,int t)
{
	queue<node>q;
	node now,net;
	now.x=x;now.y=y;now.t=t;
	vis[x][y]=1;
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
		for(int i=0;i<4;i++) 
			{ 
			int dx=a+xx[i];int dy=b+yy[i];
			if(dx<=0 || dx>row ||dy<=0 || dy>col) continue;
			if(vis[dx][dy]) continue;
			if((now.t+1)%k && map[dx][dy]=='#') continue;
			net.x=dx;
			net.y=dy;
			net.t=c+1;
			vis[dx][dy]=1;
			q.push(net);
			
		}
	}
}
int main()
{
	cin>>cases;
	while(cases--) 
	{
		cin>>row>>col>>k;
		memset(map,0,sizeof(map));
		memset(vis,0,sizeof(vis));
		flag=0;
		for(int i=1;i<=row;i++)
		{
			for(int j=1;j<=col;j++)
			{
				cin>>map[i][j];
				if(map[i][j]=='S')
				{
					x1=i;y1=j;
				}
				if(map[i][j]=='E')
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
			printf("Oop!\n");
	}
}
