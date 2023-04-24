#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
string a[100050];
int n;
string get_s(string s)
{
	int p;
	for(int i=0;i<s.size();i++)
	{
		if('0'<=s[i] && s[i]<='9')
		{
			p=i;
			break;
		}
	}
	string tmp=s.substr(0,p);
	return tmp;
}
int get_i(string s)
{
	int p,q;
	for(int i=0;i<s.size();i++)
	{
		if('0'<=s[i] && s[i]<='9')
		{
			p=i;
			break;
		}
	}
	for(int i=p;i<s.size();i++)
	{
		if(i=='.')
		{
			q=i;break;
		}
	}
	string tmp=s.substr(p,q-p);
	int x=atoi(tmp.c_str());
	return x;
}
bool cmp(string a,string b)
{
	if(get_s(a)==get_s(b)) return get_i(a)<get_i(b);
	return get_s(a)<get_s(b);
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++) cout<<a[i]<<endl;
	return 0;
}
