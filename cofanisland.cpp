#include <iostream>
using namespace std;
int a[110][110];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	int counter=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==1)
			{
				if(i==1)
				{
					counter++;
				}
				else if(a[i-1][j]==0)
				{
					counter++;
				}
				//1
				if(i==n)
				{
					counter++;
				}
				else if(a[i+1][j]==0)
				{
					counter++;
				}
				//2
				if(j==1)
				{
					counter++;
				}
				else if(a[i][j-1]==0)
				{
					counter++;
				}
				//3
				if(j==m)
				{
					counter++;
				}
				else if(a[i][j+1]==0)
				{
					counter++;
				}
				//4
			}
		}
	}
	cout<<counter<<endl;
	return 0;
}
