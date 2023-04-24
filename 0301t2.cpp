#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[50][50];
int x,y,n;
int main()
{
	cin>>n;
	x=0;
	y=n-1;
	for(int i=1;i<=(2*n-1)*(2*n-1);i++)
	{
		a[x][y]=i;
		if(x==0 && y!=2*n-2)
		{
			x=2*n-2;
			y++;
		}
		else if(x!=0 && y==2*n-2)
		{
			y=0;
			x--;
		}
		else if(x==0 && y==2*n-2)
		{
			x++;
		}
		else if(a[x-1][y+1]!=0)
		{
			x++;
		}
		else 
		{
			x--;
			y++;
		}
	}
	for(int i=0;i<=2*n-2;i++)
	{
		for(int j=0;j<=2*n-2;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
