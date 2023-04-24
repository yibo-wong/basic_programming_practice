#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#define ll long long
using namespace std;
ll int f(int i)
{
	if(i==1) return 1;
	return i*f(i-1);
}
vector<string>s;
vector<int>tmp;
int main()
{
	string t;
	while(cin>>t)
	{
		s.push_back(t);
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=="-")
		{
			int a=tmp.back();tmp.pop_back();
			int b=tmp.back();tmp.pop_back();
			tmp.push_back(b-a);
		}
		else if(s[i]=="+")
		{
			int a=tmp.back();tmp.pop_back();
			int b=tmp.back();tmp.pop_back();
			tmp.push_back(b+a);
		}
		else if(s[i]=="*")
		{
			int a=tmp.back();tmp.pop_back();
			int b=tmp.back();tmp.pop_back();
			tmp.push_back(b*a);
		}
		else if(s[i]=="/")
		{
			int a=tmp.back();tmp.pop_back();
			int b=tmp.back();tmp.pop_back();
			tmp.push_back(b/a);
		}
		else if(s[i]=="%")
		{
			int a=tmp.back();tmp.pop_back();
			int b=tmp.back();tmp.pop_back();
			tmp.push_back(b%a);
		}
		else if(s[i]=="!")
		{
			int a=tmp.back();tmp.pop_back();
			tmp.push_back(f(a));
		}
		else
		{
			tmp.push_back(atoi(s[i].c_str()));
		}
	}
	cout<<tmp.back();
}
