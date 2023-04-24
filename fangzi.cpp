#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[21][21],m,n,temp,x;
bool in(int x,int y)
{
	if(x>=1 && x<=m &&y>=1 &&y<=n) return true;
	else return false;
}
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
void dfs(int i,int j)
{
	a[i][j]=1;temp++;
	//cout<<i<<" "<<j<<endl;
	for(int k=0;k<=3;k++)
	{
		if(a[i+dx[k]][j+dy[k]]==0&&in(i+dx[k],j+dy[k]))
		{
			dfs(i+dx[k],j+dy[k]);
		}
	}
}
int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	x=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==0)
			{
				temp=0;
				dfs(i,j);
				x=max(x,temp);
			}
		}
	}
	cout<<x<<endl;
	return 0;
}
