#include <iostream>
#include <cmath>
using namespace std;
double a[9][9];
int main()
{
	for(int i=1;i<=6;i++)
	{
		cin>>a[i][1];
	}
	for(int i=2;i<=6;i++)
	{
		for(int j=i;j<=6;j++)
		{
			a[j][i]=10*(a[j][i-1]-a[j-1][i-1])/(i-1);
		}
	}
	for(int i=1;i<=6;i++)
	{
		for(int j=1;j<=6;j++)
		{
			cout<<a[i][j]<<"	";
		}
		cout<<endl;
	}
}
