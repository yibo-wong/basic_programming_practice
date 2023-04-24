#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int m,n;
int maze[52][52];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int num[3000];
struct node
{
	int x,y;
	node(){
	}
	node(int x_,int y_):x(x_),y(y_){
	}
};
struct wall
{
	int x,y;
	char p;
	int num;
	wall(){
	}
	wall(int x_,int y_,char p_,int num_):x(x_),y(y_),p(p_),num(num_){
	}
};
bool operator < (const wall& a,const wall& b)
{
	if(a.num==b.num)
	{
		if(a.y==b.y)
		{
			if(a.x==b.x)
			{
				if(b.p=='N' && a.p=='E') return true;
				return false;
			}
			return a.x<b.x;
		}
		return a.y>b.y;
	}
	return a.num<b.num;
}
queue <node> q;
priority_queue <wall> pri;
int vis[52][52];
void bfs(int x,int y,const int t)
{
	while(!q.empty()) q.pop();
	q.push(node(x,y));
	vis[x][y]=t;
	int sum=1;
	while(!q.empty())
	{
		//cout<<"q "<<q.size()<<endl;
		node tmp=q.front();
		q.pop();
		//cout<<"q "<< (maze[tmp.x][tmp.y]&1) << (maze[tmp.x][tmp.y]&2) << (maze[tmp.x][tmp.y]&4) << (maze[tmp.x][tmp.y]&8) <<endl;
		if((maze[tmp.x][tmp.y]&1)==0 && vis[tmp.x][tmp.y-1]==0)
		{
			vis[tmp.x][tmp.y-1]=t;
			sum++;
			q.push(node(tmp.x,tmp.y-1));
		}
		if((maze[tmp.x][tmp.y]&2)==0 && vis[tmp.x-1][tmp.y]==0)
		{
			vis[tmp.x-1][tmp.y]=t;
			sum++;
			q.push(node(tmp.x-1,tmp.y));
		}
		if((maze[tmp.x][tmp.y]&4)==0 && vis[tmp.x][tmp.y+1]==0)
		{
			vis[tmp.x][tmp.y+1]=t;
			sum++;
			q.push(node(tmp.x,tmp.y+1));
		}
		if((maze[tmp.x][tmp.y]&8)==0 && vis[tmp.x+1][tmp.y]==0)
		{
			vis[tmp.x+1][tmp.y]=t;
			sum++;
			q.push(node(tmp.x+1,tmp.y));
		}
	}
	num[t]=sum;
}

int main()
{
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>maze[i][j];
		}
	}
	int r=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(vis[i][j]==0)
			{
				r++;
				bfs(i,j,r);
			}
		}
	}
	cout<<r<<endl;
	int minx=0;
	for(int i=1;i<=r;i++)
		if(num[i]>minx) minx=num[i];
	cout<<minx<<endl;
	for(int i=2;i<=n;i++)//N
	{
		for(int j=1;j<=m;j++)
		{
			if(maze[i][j]&2 && vis[i][j]!=vis[i-1][j])
			{
				pri.push(wall(i,j,'N',num[vis[i][j]]+num[vis[i-1][j]]));
			}
		}
	}
	for(int i=1;i<=n;i++)//N
	{
		for(int j=1;j<m;j++)
		{
			if(maze[i][j]&4 && vis[i][j]!=vis[i][j+1])
			{
				pri.push(wall(i,j,'E',num[vis[i][j]]+num[vis[i][j+1]]));
			}
		}
	}
	cout<<pri.top().num<<endl;
	cout<<pri.top().x<<" "<<pri.top().y<<" "<<pri.top().p;
	return 0;
}
