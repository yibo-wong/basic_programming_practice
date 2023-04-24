#include <iostream>
using namespace std;
int check(int n)
{
	if(n%7==0)
	{
		return 1;
	}
	int temp=n;
	if(temp%10==7)
	{
		return 1;
	}
	temp=temp/10;
	if(temp%10==7)
	{
		return 1;
	}
	return 0;
}
int main()
{
	int m;
	int tot=0;
	cin>>m;
	for(int j=1;j<=m;j++)
	{
		if(check(j)==0)
		{
			tot+=j*j;
		}
	}
	cout<<tot;
	return 0;
}
