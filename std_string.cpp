#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <iomanip>
using namespace std;
int n;
vector<string>q;
vector<string>exp;
string s[30];
string tmp;
void split(string s)
{
	stringstream ss(s);
	string item;
	while(getline(ss,item,' '))
	{
//		cout<<"there"<<endl;
//		cout<<item<<endl;
		q.push_back(item);
	}
}
bool isnum(string s)
{
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<'0' || s[i]>'9') return false;
	}
	return true;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i];
	while(getline(cin,tmp))
	{
		q.clear();
		exp.clear();
		split(tmp);
		for(int i=q.size()-1;i>=0;i--)
		{
			//if(isnum(q[i])) exp.push_back(q[i]);
			if(q[i]=="copy")
			{
				string s1=exp.back();
				exp.pop_back();
				string s2=exp.back();
				exp.pop_back();
				string s3=exp.back();
				exp.pop_back();
				exp.push_back(s[atoi(s1.c_str())].substr(atoi(s2.c_str()),atoi(s3.c_str())));
			}
			else if(q[i]=="add")
			{
				string s1=exp.back();
				exp.pop_back();
				string s2=exp.back();
				exp.pop_back();
				if(isnum(s[atoi(s1.c_str())]) || isnum(s[atoi(s2.c_str())]))
				{
					int x=atoi(s1.c_str()) + atoi(s2.c_str());
					string t;
					sprintf(t,"%d",x);
					exp.push_back(t);
				}
				else
				{
					string t=s[atoi(s1.c_str())]) + s[atoi(s2.c_str())];
					exp.push_back(t);
				}
			}
			else if(q[i]=="find")
			{
				s1=exp.back();
				exp.pop_back();
				s2=exp.back();
				exp.pop_back();
				int a=s[atoi(s1.c_str())].find(s2);
				if(a==-1) a=s[atoi(s1.c_str())].size();
				string t;
				sprintf(t,"%d",a);
				exp.push_back(t);
			}
			else if(q[i]=="rfind")
			{
				
			}
		}
	}
	return 0;
}
