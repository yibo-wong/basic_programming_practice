#include <iostream>
#include <cstring>
using namespace std;
int a[10000][10000];
int b[10000][10000];
int m,n,temp,cnt;
bool in(int x,int y)
{
	if(x>=1&&x<=m&&y>=1&&y<=n) return true;
	else return false;
}
int dx[]={-1,0,1,-1,0,1,-1,0,1};
int dy[]={-1,-1,-1,0,0,0,1,1,1};
int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cnt=0;temp=0;
			for(int k=0;k<=8;k++)
			{
				if(in(i+dx[k],j+dy[k]))
				{
					cnt++;temp+=a[i+dx[k]][j+dy[k]];
				}
			}
			b[i][j]=temp/cnt;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
