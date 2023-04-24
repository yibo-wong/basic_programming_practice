#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
char maze[4000][4000];
void make(int x,int y,int size)
{
	if(size==1)
	{
		maze[x][y]='/';maze[x][y+1]='_';maze[x][y+2]='_';maze[x][y+3]='\\';
		maze[x-1][y+1]='/';maze[x-1][y+2]='\\';
		return;
	}
	else
	{
		int len=1<<(size-1);
		make(x,y,size-1);
		make(x,len*2+y,size-1);
		make(x-len,y+len,size-1);
	}
}
int main()
{
	int n,length,last;
	while(cin>>n)
	{
		memset(maze,0,sizeof(maze));
		if(n==0) return 0;
		length=1<<n;
		make(length,1,n);
		for(int i=1;i<=length;i++)
		{
			for(int j=1;j<=length*2;j++)
			{
				if(maze[i][j]) last=j;
			}
			for(int j=1;j<=last;j++)
			{
				if(!maze[i][j]) maze[i][j]=' ';
			}
			for(int j=1;j<=last;j++)
			{
				cout<<maze[i][j];
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}

