#include <iostream>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
int m,n;
char maze[110][110];
struct node
{
	int x,y;
	bool flag;
	int id;
	int pre;
	node(){
	}
	node(int xx,int yy,bool f,int i=0,int p=0):x(xx),y(yy),flag(f),id(i),pre(p){}
	
}a[20050];
queue<node>q;
bool used[110][110][2];
node s,e,key;
void getin()
{
	cin>>m>>n;
	string tmp;
	for(int i=1;i<=m;i++)
	{
		cin>>tmp;
		for(int j=1;j<=n;j++)
		{
			maze[i][j]=tmp[j-1];
			if(maze[i][j]=='R') s=node(i,j,0);
			else if(maze[i][j]=='C') e=node(i,j,0);
			else if(maze[i][j]=='Y') key=node(i,j,0);
		} 
	}
	memset(used,0,sizeof(used));
}
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int cur;
bool in(int x,int y)
{
	if(1<=x&&x<=m&&1<=y&&y<=n&&maze[x][y]!='1') return true;
	else return false;
}
void print(node& now)
{
	if(now.id==0)
	{
		cout<<now.x<<" "<<now.y<<endl;
		return;
	}
	else
	{
		print(a[now.pre]);
	}
	cout<<now.x<<" "<<now.y<<endl;
}
void bfs()
{
	cur=0;
	a[cur]=s;
	a[cur].pre=0;
	a[cur].id=0;
	used[a[0].x][a[0].y][0]=1;
	q.push(a[cur]);
	while(!q.empty())
	{
		node tmp=q.front();q.pop();
		//cout<<"test "<<tmp.x<<" "<<tmp.y<<endl;
		if(maze[tmp.x][tmp.y]=='C' && tmp.flag)
		{
			print(tmp);
			return;
		}
		else if(maze[tmp.x][tmp.y]=='Y')
		{
			for(int k=0;k<4;k++)
			{
				if(in(tmp.x+dx[k],tmp.y+dy[k]) && used[tmp.x+dx[k]][tmp.y+dy[k]][tmp.flag]==0)
				{
					used[tmp.x+dx[k]][tmp.y+dy[k]][1]=1;
					cur++;a[cur]=node(tmp.x+dx[k],tmp.y+dy[k],1,cur,tmp.id);
					q.push(a[cur]);
				}
			}
		}
		else
		for(int k=0;k<4;k++)
		{
			if(in(tmp.x+dx[k],tmp.y+dy[k]) && used[tmp.x+dx[k]][tmp.y+dy[k]][tmp.flag]==0)
			{
				//cout<<"in"<<endl;
				used[tmp.x+dx[k]][tmp.y+dy[k]][tmp.flag]=1;
				cur++;a[cur]=node(tmp.x+dx[k],tmp.y+dy[k],tmp.flag,cur,tmp.id);
				q.push(a[cur]);
			}
		}
	}
}
int main()
{
	getin();
	bfs();
	return 0;
}
