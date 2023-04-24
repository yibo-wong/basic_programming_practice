#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#define inf 10000000
using namespace std;
int maze[80][80];
string str;
int w,h,x1,y1,x2,y2,tot,board,pairs;
bool flag;
bool vis[80][80];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool in(int x,int y)
{
	if(x>=0&&x<=w+1&&y>=0&&y<=h+1&&vis[x][y]==0) return true;
	return false;
}
bool available(int x,int y)
{
	if(maze[x][y]==0) return true;
	if(x==x2&&y==y2) return true;
	return false;
}
void dfs(int x,int y,int d,int cnt)//in(x+dx[d],y+dy[d])&&(available(x+dx[d],y+dy[d]))
{
	if(cnt>tot) return;
	//cout<<"ppp"<<x<<" "<<y<<" "<<d<<" "<<cnt<<endl;
	if(x==x2&&y==y2)
	{
		flag=1;
		if(cnt<tot) tot=cnt;
		return;
	}
	if(x==x1&&y==y1)
	{
		for(int i=0;i<=3;i++)
		{
			if(in(x+dx[i],y+dy[i])&&(available(x+dx[i],y+dy[i])))
			{
				vis[x+dx[i]][y+dy[i]]=1;
				dfs(x+dx[i],y+dy[i],i,0);
				vis[x+dx[i]][y+dy[i]]=0;
			}
		}
	}
	else
	{
		if(in(x+dx[d],y+dy[d])&&(available(x+dx[d],y+dy[d])))
		{
			vis[x+dx[d]][y+dy[d]]=1;
			dfs(x+dx[d],y+dy[d],d,cnt);
			vis[x+dx[d]][y+dy[d]]=0;
		}
		for(int i=1;i<=3;i++)
		{
			if(in(x+dx[(d+i)%4],y+dy[(d+i)%4])&&(available(x+dx[(d+i)%4],y+dy[(d+i)%4])))
			{
				vis[x+dx[(d+i)%4]][y+dy[(d+i)%4]]=1;
				dfs(x+dx[(d+i)%4],y+dy[(d+i)%4],(d+i)%4,cnt+1);
				vis[x+dx[(d+i)%4]][y+dy[(d+i)%4]]=0;
			}
		}
	}
}
int main()
{
	board=0;
	while(cin>>w>>h)
	{
		board++;
		memset(maze,0,sizeof(maze));
		if(w==0&&h==0) return 0;
		cout<<"Board #"<<board<<":"<<endl;
		cin.ignore();
		for(int i=1;i<=h;i++)
		{
			getline(cin,str);
			//cout<<"iii"<<endl;
			//cout<<str<<endl;
			for(int j=1;j<=w;j++)
			{
				if(str[j-1]=='X') maze[j][i]=1;
				else maze[j][i]=0;
			}
		}
		//cout<<"ooo"<<endl;
		/*for(int j=1;j<=w;j++)
		{
			for(int i=1;i<=h;i++)
			{
				cout<<maze[i][j];
			}
			cout<<endl;
		}*/
		pairs=0;
		while(cin>>x1>>y1>>x2>>y2)
		{
			pairs++;
			if(x1==0&&x2==0&&y1==0&&y2==0) break;
			tot=inf;
			flag=0;
			memset(vis,0,sizeof(vis));
			vis[x1][y1]=1;
			dfs(x1,y1,0,0);
			cout<<"Pair "<<pairs<<": ";
			if(flag) cout<<tot+1<<" segments."<<endl;
			else cout<<"impossible."<<endl;
		}
	}
}
