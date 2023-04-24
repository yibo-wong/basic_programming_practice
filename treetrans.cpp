#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
vector<int>q[10050];
int fa[10050];
int cur,tot;
string s;
int sis[10050];
int lchild[10050],rchild[10050];
void make()
{
	for(int i=0;i<=tot;i++)
	{
		if(q[i].size())
		{
			lchild[i]=q[i][0];
		}
		if(sis[i]>=0) rchild[i]=sis[i]; 	
	}
}
int dep1(int i)
{
	if(q[i].empty()) return 0;
	int maxn=0;
	for(int k=0;k<q[i].size();k++) maxn=max(maxn,dep1(q[i][k]));
	return maxn+1;
}
int dep2(int i)
{
	if(i==-1) return -1;
	return max(dep2(lchild[i]),dep2(rchild[i]))+1;
}
int main()
{
	int testnum=0;
	while(cin>>s)
	{
		if(s=="#") return 0;
		testnum++;
		memset(lchild,-1,sizeof(lchild));
		memset(rchild,-1,sizeof(rchild));
		memset(sis,-1,sizeof(sis));
		memset(fa,0,sizeof(fa));
		for(int i=0;i<s.size();i++) q[i].clear();
		cur=0;tot=0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='d')
			{
				tot++;
				q[cur].push_back(tot);
				fa[tot]=cur;
				cur=tot;	
			}
			else
			{
				cur=fa[cur];
			}
		}
		//cout<<"1"<<endl;
		//cout<<tot<<"  "<<cur<<endl;
		for(int i=0;i<=tot;i++)
		{
			if(q[i].size())
				for(int j=0;j < q[i].size()-1;j++)
				{
					//cout<<i<<" "<<q[i][j]<<endl;
					sis[q[i][j]]=q[i][j+1];
				}
		}
		//cout<<"2"<<endl;
		make();
		//pre(0);
		cout<<"Tree "<<testnum<<": "<<dep1(0)<<" => "<<dep2(0)<<endl;
	}
}
