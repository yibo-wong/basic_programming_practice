#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int n;
int le[1050],ri[1050],fa[1050],dep[1050];
queue<int>q;
void bfs()
{
	int s=0,tmp;
	cout<<"1"<<" ";
	q.push(1);
	while(!q.empty())
	{
		tmp=q.front();
		q.pop();
		if(ri[tmp]!=-1)
		{
			if(dep[ri[tmp]]>s)
			{
				s=dep[ri[tmp]];
				cout<<ri[tmp]<<" ";
			}
			q.push(ri[tmp]);
		}
		if(le[tmp]!=-1)
		{
			if(dep[le[tmp]]>s)
			{
				s=dep[le[tmp]];
				cout<<le[tmp]<<" ";
			}
			q.push(le[tmp]);
		}
	}
}
void get_depth(int i)
{
	if(dep[fa[i]]!=-1)
	{
		dep[i]=dep[fa[i]]+1;
		return;
	}
	else
	{
		get_depth(fa[i]);
		dep[i]=dep[fa[i] ]+1;
		return;
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>le[i]>>ri[i];
		if(le[i]!=-1) fa[le[i]]=i;
		if(ri[i]!=-1) fa[ri[i]]=i;
	}
	memset(dep,-1,sizeof(dep));
	dep[1]=0;
	for(int i=2;i<=n;i++) get_depth(i);
	bfs();
	return 0;
}
