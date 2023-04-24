#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#define maxn 10000
using namespace std;
int maze[maxn][maxn];
bool used[maxn][maxn];
int n;
struct node
{
	int x,y;
	int depth;
	node(){
	}
	node(int xx,int yy,int ll):x(xx),y(yy),depth(ll){
	}
};
bool in(int x,int y)
{
	if(1<=x && x<=n && 1<=y && y<=n && used[x][y]==0 && maze[x][y]==0) return true;
	else return false;
}
void putin()
{
	cin>>n;
	string tmp;
	for(int i=1;i<=n;i++)
	{
		cin>>tmp;
		for(int j=1;j<=n;j++) maze[i][j]=tmp[j-1]-'0';
	}
}
queue<node>q;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void dfs(int x,int y)
{
	//cout<<x<<" "<<y<<endl;
	maze[x][y]=2;
	for(int k=0;k<4;k++)
	{
		int i=x+dx[k];
		int j=y+dy[k];
		if(1<=i && i<=n && 1<=j && j<=n && maze[i][j]==1)
		{
			dfs(i,j);
		}
	}
}
int main()
{
	putin();
	bool end=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(maze[i][j])
			{
				dfs(i,j);
				end=1;
				break;
			}
		}
		if(end) break;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(maze[i][j]==1)
			{
				for(int k=0;k<4;k++)
				{
					if(in(i+dx[k],j+dy[k]))
					{
						q.push(node(i+dx[k],j+dy[k],1));
						used[i+dx[k]][j+dy[k]]=1;
					}
				}
			}
		}
	}
	while(!q.empty())
	{
		node cur=q.front();q.pop();
		//cout<<cur.x<<" "<<cur.y<<" "<<cur.depth<<endl;
		for(int k=0;k<4;k++)
		{
			if(1<=cur.x+dx[k] && cur.x+dx[k]<=n && 1<=cur.y+dy[k] && cur.y+dy[k]<=n)
			{
				if(maze[cur.x+dx[k]][cur.y+dy[k]]==2) 
				{
					cout<<cur.depth;
					return 0;
				}
			}
			if(in(cur.x+dx[k],cur.y+dy[k]))
			{
				used[cur.x+dx[k]][cur.y+dy[k]]=1;
				q.push(node(cur.x+dx[k],cur.y+dy[k],cur.depth+1));
			}
		}
	}
}
