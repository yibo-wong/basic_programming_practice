#include <iostream>
using namespace std;
int a[1000][1000];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	int tot=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==1)
			{
				for(int k=0;k<=3;k++)
				{
					if(a[i+dx[k]][j+dy[k]]==0) tot++;
				}
			}
		}
	}
	cout<<tot<<endl;
	return 0;
}
