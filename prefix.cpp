#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#define maxn 100000
using namespace std;
vector<string>dic;
vector<string>pre;
char a[maxn];
vector<int>child[maxn];
vector<int>root;
int main()
{
	string tmp;
	int lt=0;
	bool flag=0;
	while(cin>>tmp)
	{
		dic.push_back(tmp);
		int p;
		for(int i=0;i<root.size();i++)
		{
			if(a[root[i]]==tmp[0])
			{
				p=root[i];flag=1;break;
			}
		}
		if(flag==0)
		{
			lt++;root.push_back(lt);a[lt]=tmp[0];p=lt;
		}
		for(int i=1;i<tmp.size();i++)
		{
			flag=0;
			for(int j=0;j<child[p].size();j++)
			{
				if(a[child[p][j]]==tmp[i])
				{
					p=child[p][j];flag=1;break;
				}
			}
			if(flag==0)
			{
				lt++;child[p].push_back(lt);a[lt]=tmp[i];p=lt;
			}
		}
	}
	for(int i=0;i<dic.size();i++)
	{
		int s=1;
		string cur=dic[i];
		int p;
		for(int j=0;j<root.size();j++)
		{
			if(a[root[j]]==cur[0])
			{
				p=root[j];break;
			}
		}
		
		for(int j=1;j<cur.size();j++)
		{
			if(child[p].size()>1) s=j+1;
			for(int k=0;k<child[p].size();k++)
			{
				if(a[child[p][k]]==cur[j])
				{
					p=child[p][k];break;
				}
			}
		}
		if(child[p].empty()) cout<<cur<<" "<<cur.substr(0,s)<<endl;
		else cout<<cur<<" "<<cur<<endl;
	}
	return 0;
}
