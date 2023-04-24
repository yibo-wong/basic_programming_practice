#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
string s;
vector<string>v;
vector<int>num;
int main()
{
	cin>>s;
	int p=0,q=0;
	string n="";
	v.push_back(n);
	for(int i=0;i<s.size();i++)
	{
		if('0'<=s[i] && s[i]<='9')
		{
			v.back()+=s[i];
		}
		else
		{
			if(v.back()!=n)
			{
				v.push_back(n);
			}
		}
	}
	for(int i=0;i<v.size();i++)
	{
		if(v[i]!=n)
		{
			num.push_back(atoi(v[i].c_str()));
		}
	}
	sort(num.begin(),num.end());
	for(int i=0;i<num.size()-1;i++)
	{
		cout<<num[i]<<",";
	}
	cout<<num.back()<<endl;
	return 0;
}
