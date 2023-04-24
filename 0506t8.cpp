#include <iostream>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
int m,n;
char a[110][10];
int dp[110][2500];
int num[110];
vector<int>q;
int ith(int n,int i)
{
	return (n>>i)&1;
}
void crt()
{
	bool flag;
	for(int i=0;i<(1<<(m));i++)
	{
		flag=1;
		for(int j=0;j<m;j++)
		{
			if((ith(i,j)==1 && ith(i,j+1)==1) || (ith(i,j)==1 && ith(i,j+2)==1))
			{
				flag=false;break;
			}
		}
		if(flag) q.push_back(i);
	}
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	crt();
	for(int i=0;i<q.size();i++) cout<<q[i]<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]=='H') num[i]+=(1<<j);
		}
	}
	
}
