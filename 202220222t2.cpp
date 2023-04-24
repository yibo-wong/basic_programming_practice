#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;
struct node
{
	string ori;
	string s;
	int num;
}a[10050];
int n;
string name,s1,s2;
bool cmp(node x,node y)
{
	if(x.s==y.s) return x.num<y.num;
	return x.s<y.s;
}
bool isnum(char s)
{
	if('0'<=s&&s<='9') return true;
	return false;
}
int main()
{
	cin>>n;
	int p,q;
	for(int i=1;i<=n;i++)
	{
		cin>>name;
		a[i].ori=name;
		for(int j=1;j<name.length();j++)
		{
			if(isnum(name[j]) && (!isnum(name[j-1]))) p=j;
			if(name[j]=='.') q=j-1;
		}
		//cout<<"iii "<<p<<" "<<q<<endl;
		s1=name.substr(0,p);
		s2=name.substr(p,q-p+1);
		//cout<<s1<<" "<<s2<<endl;
		sscanf(s2.c_str(),"%d",&a[i].num);
		//cout<<"iiii";
		a[i].s=s1;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) cout<<a[i].ori<<" "<<a[i].s<<" "<<a[i].num<<endl;
	return 0;
}
