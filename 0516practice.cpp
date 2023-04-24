#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,x,y,z,casenum,lchild[110],rchild[110];
int search(int i)
{
	if(lchild[i]==-1) return i;
	return search(lchild[i]);
}
int main()
{
	cin>>casenum;
	while(casenum--)
	{
		cin>>n>>m;
		memset(lchild,-1,sizeof(lchild));
		memset(rchild,-1,sizeof(rchild));
		for(int i=0;i<n;i++)
		{
			cin>>x>>y>>z;
			lchild[x]=y;
			rchild[x]=z;
		}
		while(m--)
		{
			cin>>z;
			if(z==1)
			{
				cin>>x>>y;
				for(int i=0;i<n;i++)
				{
					if(lchild[i]==x) lchild[i]=y;
					else if(lchild[i]==y) lchild[i]=x;
					if(rchild[i]==x) rchild[i]=y;
					else if(rchild[i]==y) rchild[i]=x;	
				}
			}
			else
			{
				cin>>x;
				cout<<search(x)<<endl;
			}
		}
	}
	return 0;
}
