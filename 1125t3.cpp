#include <iostream>
using namespace std;
bool s1[6][6];
bool s2[6][6];
bool flag;
int a[6][6];
int temp;
int p;
int main()
{
	for(int i=1;i<=5;i++)
		for(int j=1;j<=5;j++)
			cin>>a[i][j];
	for(int i=1;i<=5;i++)
	{
		temp=a[i][1];p=1;
		for(int j=2;j<=5;j++)
		{
			if(a[i][j]>temp) 
			{
				temp=a[i][j];
				p=j;
			}
		}
		s1[i][p]=1;
	}
	for(int i=1;i<=5;i++)
	{
		temp=a[1][i];p=1;
		for(int j=2;j<=5;j++)
		{
			if(a[j][i]<temp) 
			{
				temp=a[j][i];
				p=j;
			}
		}
		s2[p][i]=1;
	}
	flag=0;
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=5;j++)
		{
			if(s1[i][j]==1&&s2[i][j]==1) 
			{
				flag=1;
				cout<<i<<" "<<j<<" "<<a[i][j]<<endl;
			}
		}
	}
	if(flag==0) cout<<"not found"<<endl;
	return 0;
}
