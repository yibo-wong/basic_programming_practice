#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
//bool from[210][210];
int num[210];
bool used[210];
int n,m;
int sum;
vector<int>q;
int ans[210];
vector<int>to[210];
int main()
{
	cin>>n>>m;
	int a,b;
	sum=1;
	while(m--)
	{
		cin>>a>>b;
		num[a]++;
		////from[b][a]=1;
		to[b].push_back(a);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=n;j>=1;j--)
		{
			if(num[j]==0 && used[j]==0)
			{
				ans[j]=(n+1-sum);
				sum++;
				used[j]=1;
				for(int k=0;k<to[j].size();k++)
				{
					//from[to[j][k]][j]=0;
					num[to[j][k]]--;
				}
			}
		}
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
}
