#include <iostream>
using namespace std;
int a[22][22];
int tot;
int m[4]={1,0,-1,0};
int n[4]={0,1,0,-1};
int main()
{
	cin>>tot;
	int j=0;
	int x=1;
	int y=1;
	for(int i=0;i<=21;i++) a[0][i]=-1;
	for(int i=0;i<=21;i++) a[21][i]=-1;
	for(int i=0;i<=21;i++) a[i][0]=-1;
	for(int i=0;i<=21;i++) a[i][21]=-1;
	for(int i=1;i<=tot*tot;i++)
	{
		if(a[x][y]==0&&1<=x&&x<=tot&&1<=y&&y<=tot)
		{
			a[x][y]=i;
			x+=m[j];
			y+=n[j];
		}
		else
		{
			x-=m[j];
			y-=n[j];
			j=(j+1)%4;
			x+=m[j];
			y+=n[j];
			a[x][y]=i;
			x+=m[j];
			y+=n[j];
		}
	}
	for(int i=1;i<=tot;i++)
	{
		for(int j=1;j<=tot;j++)
		{
			cout<<a[j][i]<<" ";
		}
		cout<<endl;
	}
}
