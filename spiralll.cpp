#include <iostream>
using namespace std;
int a[23][23];
bool s[23][23];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int main()
{
	int n;cin>>n;
	int p=0;
	int x=1;
	int y=1;
	for(int i=1;i<=n*n;i++)
	{
		a[x][y]=i;s[x][y]=1;
		if(s[x+dx[p]][y+dy[p]]==0&&x+dx[p]>=1&&x+dx[p]<=n&&y+dy[p]>=1&&y+dy[p]<=n) 
		{
			x=x+dx[p];y=y+dy[p];
			//cout<<x<<" "<<y<<endl;
		}
		else 
		{
			p=(p+1)%4;
			x=x+dx[p];y=y+dy[p];
			//cout<<x<<" "<<y<<endl;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
