#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#define maxn 1000
using namespace std;
int maze[maxn][maxn],m,n;
int pre[10*maxn];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool flag;
struct node
{
	int x,y;
	node():x(),y(){}
	node(int _x,int _y)
	{
		x=_x;y=_y;
	}
};
node s,e;
bool vis[maxn][maxn];
queue <node>q;
void init()
{
	q=queue<node>();
	flag=false;
	memset(vis,0,sizeof(vis));
	memset(maze,0,sizeof(maze));
}
int num(node xx)
{
	return xx.x*n+xx.y;
}
bool ok(int x,int y)
{
	if(0<=x && x<m && 0<=y && y<n)
	{
		if(maze[x][y]==0 || vis[x][y]==1) return false;
		else return true;
	}
	return false;
}
void input()
{
	cin>>m>>n;
	string tmp;
	for(int i=0;i<m;i++)
	{
		cin>>tmp;
		for(int j=0;j<n;j++)
		{
			if(tmp[j]=='.' || tmp[j]=='s' || tmp[j]=='e') maze[i][j]=1;
			if(tmp[j]=='#') maze[i][j]=0;
			if(tmp[j]=='s') s=node(i,j);
			if(tmp[j]=='e') e=node(i,j);
		}
	}
}
void output()
{
	node cur=e;
	maze[cur.x][cur.y]=2;
	do
	{
		//cout<<pre[num(cur)]<<" ";
		int tmp=pre[num(cur)];
		cur.x=tmp/n;
		cur.y=tmp-cur.x*n;
		//cout<<cur.x<<" "<<cur.y<<endl;
		maze[cur.x][cur.y]=2;
	}while(pre[num(cur)]!=num(cur));
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(s.x==i && s.y==j) cout<<"s";
			else if(e.x==i && e.y==j) cout<<"e";
			else if(maze[i][j]==0) cout<<"#";
			else if(maze[i][j]==1) cout<<".";
			else cout<<"*";
		}
		cout<<endl;
	}
}
void bfs()
{
	node cur=s;
	node next;
	pre[num(cur)]=num(cur);
	vis[cur.x][cur.y]=1;
	for(int i=0;i<4;i++)
	{
		if(ok(cur.x+dx[i],cur.y+dy[i]))
		{
			next=node(cur.x+dx[i],cur.y+dy[i]);
			pre[num(next)]=num(cur);
			q.push(next);
			vis[next.x][next.y]=1;
		}
	}
	while(!q.empty())
	{
		cur=q.front();
		q.pop();
		//cout<<cur.x<<" "<<cur.y<<endl;
		if(cur.x==e.x && cur.y==e.y)
		{
			flag=1;
			break;
		}
		for(int i=0;i<4;i++)
		{
			if(ok(cur.x+dx[i],cur.y+dy[i]))
			{
				next=node(cur.x+dx[i],cur.y+dy[i]);
				pre[num(next)]=num(cur);
				q.push(next);
				vis[next.x][next.y]=1;
			}
		}
	}
	//cout<<"got here"<<endl;
}
int main()
{
	input();
	bfs();
	if(flag) output();
	else cout<<"NO"<<endl;
	return 0;
}
