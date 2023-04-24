#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
bool maze[16][16],maze_0[16][16];
int n;
string s;
int sum=0;
bool in(int x,int y)
{
	if(1<=x && x<=n && 1<=y && y<=n) return 1;
	return 0;
}

void print()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<maze[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
}

void change(int x,int y)
{
	maze[x][y]^=1;
	if(in(x+1,y)) maze[x+1][y]^=1;
	if(in(x-1,y)) maze[x-1][y]^=1;
	if(in(x,y+1)) maze[x][y+1]^=1;
	if(in(x,y-1)) maze[x][y-1]^=1;
	//sum++;
}
void deal(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(maze[x][i]==0)
		{
			 change(x+1,i);
			 sum++;
		}
	}
	//print();
}

void deal_all()
{
	for(int i=1;i<n;i++)
	{
		deal(i);
	}
}

bool ok()
{
	for(int i=1;i<=n;i++)
	{
		if(maze[n][i]==0) return false;
	}
	return true;
}


int main()
{
	cin>>n;
	int tmp=1<<8;
	bool cando=false;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		for(int j=0;j<n;j++)
		{
			if(s[j]=='w') maze_0[i][j+1]=0;
			else maze_0[i][j+1]=1;
		}
	}
	for(int i=0;i<(1<<(n+1))-1;i++)
	{
		for(int ii=1;ii<=n;ii++)
			for(int j=1;j<=n;j++)
				maze[ii][j]=maze_0[ii][j];
		sum=0;
		for(int j=1;j<=n;j++)
		{
			if((i>>(j-1)) & 1)
			{
				change(1,j);
				sum++;
			}
		}
		deal_all();
		if(ok())
		{
			cando=true;
			tmp=min(tmp,sum);
		}
	}
	/*
	print();
	for(int i=1;i<n;i++)
	{
		deal(i);
		print();
	}
	bool flag=true;
	for(int i=1;i<=n;i++)
	{
		if(maze[n][i]==0)
		{
			flag=false;
			break;
		}
	}
	if(!flag) cout<<"inf"<<endl;
	else cout<<sum<<endl;
	*/
	if(cando==0) cout<<"inf"<<endl;
	else cout<<tmp<<endl;
	return 0;
}
