#include <iostream>
#include <cstring>
#include <string>
#include <list>
using namespace std;
list<int>n[10050];
bool id[10050];
int cases;
int main()
{
	cin>>cases;
	string tmp;
	int a,b;
	while(cases--)
	{
		cin>>tmp;
		if(tmp=="new")
		{
			cin>>a;
			id[a]=1;
		}
		if(tmp=="add")
		{
			cin>>a>>b;
			n[a].push_back(b);
		}
		if(tmp=="merge")
		{
			cin>>a>>b;
			if(a!=b)
			{
				n[a].sort();
				n[b].sort();
				n[a].merge(n[b]);
				id[b]=0;
			}
		}
		if(tmp=="unique")
		{
			cin>>a;
			n[a].sort();
			n[a].unique();
		}
		if(tmp=="out")
		{
			cin>>a;
			n[a].sort();
			list<int>::iterator it=n[a].begin();
			while(it!=n[a].end())
			{
				cout<<*it<<" ";
				it++;
			}
			cout<<endl;
		}
	}
}

