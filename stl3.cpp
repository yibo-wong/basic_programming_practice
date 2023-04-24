#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;
set<int>s;
map<int,int>dic;
int main()
{
	int casenum;
	int a;
	string tmp;
	cin>>casenum;
	while(casenum--)
	{
		cin>>tmp;
		if(tmp=="add")
		{
			cin>>a;
			if(dic.find(a)==dic.end())
			{
				dic[a]=1;
			}
			else dic[a]++;
			cout<<dic[a]<<endl;
		}
		if(tmp=="ask")
		{
			cin>>a;
			if(dic.find(a)==dic.end())
			{
				cout<<"0 0"<<endl;
			}
			else
			{
				cout<<"1 "<<dic[a]<<endl;
			}
		}
		if(tmp=="del")
		{
			cin>>a;
			if(dic.find(a)==dic.end()) cout<<"0"<<endl;
			else
			{
				cout<<dic[a]<<endl;
				dic[a]=0;
			}
		}
	}
}
