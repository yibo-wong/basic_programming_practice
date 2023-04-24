#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
//bool from[210][210];
int num[210];
bool used[210];
int n,m;
vector<int>q;
vector<int>to[210];
int main()
{
	cin>>n>>m;
	int a,b;
	while(m--)
	{
		cin>>a>>b;
		num[b]++;
		////from[b][a]=1;
		to[a].push_back(b);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(num[j]==0 && used[j]==0)
			{
				q.push_back(j);
				used[j]=1;
				for(int k=0;k<to[j].size();k++)
				{
					//from[to[j][k]][j]=0;
					num[to[j][k]]--;
				}
			}
		}
	}
	for(int i=0;i<n;i++) cout<<q[i]<<" ";
}
