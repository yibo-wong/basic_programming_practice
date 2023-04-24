#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n,north[30],east[30],west[30];
int main()
{
	cin>>n;
	north[1]=1;east[1]=1;west[1]=1;
	for(int i=2;i<=n;i++)
	{
		north[i]=north[i-1]+east[i-1]+west[i-1];
		east[i]=east[i-1]+north[i-1];
		west[i]=west[i-1]+north[i-1];
	}
	cout<<north[n]+east[n]+west[n]<<endl;
	return 0;
}
