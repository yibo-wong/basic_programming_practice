#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int lcd[27],rcd[27];
string tmp;
vector <string> q;
void init()
{
	memset(lcd,-1,sizeof(lcd));
	memset(rcd,-1,sizeof(rcd));
	while(!q.empty()) q.pop_back();
}
void pre(int i)
{
	if(i==-1) return;
	cout<<char(i+'A');
	pre(lcd[i]);
	pre(rcd[i]);
}
void add(int x,int y)
{
	if(x<y)
	{
		if(lcd[y]==-1) lcd[y]=x;
		else add(x,lcd[y]);
	}
	else
	{
		if(rcd[y]==-1) rcd[y]=x;
		else add(x,rcd[y]);
	}
}
int main()
{
	init();
	while(cin>>tmp)
	{
		if(tmp=="*" || tmp=="$")
		{
			char t=q[q.size()-1][0];
			for(int i=q.size()-2;i>=0;i--)
			{
				for(int j=0;j<q[i].size();j++)
				{
					add(q[i][j]-'A',t-'A');
				}
			}
			pre(t-'A');
			cout<<endl;
			init();
		}
		else
		{
			q.push_back(tmp);
		}
		if(tmp=="$") return 0;
	}
}
