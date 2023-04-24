#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
set<string>dic;
vector<string>q;
vector<string>order;
int pos(string s)
{
	for(int i=0;i<order.size();i++)
	{
		if(order[i]==s) return i;
	}
}
bool cmp(string a,string b)
{
	return pos(a)<pos(b);
}
void myfind(string s)
{
	if(dic.find(s)!=dic.end())
	{
		printf("%s is correct\n",s.c_str());
		return;
	}
	else
	{
		while(!q.empty()) q.pop_back();
		printf("%s: ",s.c_str());
		for(int i=0;i<s.size();i++)
		{
			string ss=s.substr(0,i)+s.substr(i+1);
			if(dic.find(ss)!=dic.end()) q.push_back(ss);
		}
		for(int i=0;i<s.size();i++)
		{
			for(int j='a';j<='z';j++)
			{
				string ss=s.substr(0,i)+char(j)+s.substr(i+1);
				if(dic.find(ss)!=dic.end()) q.push_back(ss);
			}
		}
		for(int i=0;i<=s.size();i++)
		{
			for(int j='a';j<='z';j++)
			{
				string ss=s.substr(0,i)+char(j)+s.substr(i);
				if(dic.find(ss)!=dic.end()) q.push_back(ss);
			}
		}
		sort(q.begin(),q.end(),cmp);
		for(int i=0;i<q.size();i++) printf("%s ",q[i].c_str());
		printf("\n");
	}
}
int main()
{
	string tmp;
	while(cin>>tmp)
	{
		if(tmp=="#") break;
		order.push_back(tmp);
		dic.insert(tmp);
	}
	while(cin>>tmp)
	{
		if(tmp=="#") break;
		myfind(tmp);
	}
	return 0;
}
