#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int main()
{
	string a,b;
	getline(cin,a);
	getline(cin,b);
	a=" "+a+" ";
	b=" "+b+" ";
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='A'&&a[i]<='Z') a[i]+='a'-'A';
	}
	for(int i=0;i<b.size();i++)
	{
		if(a[i]>='A'&&a[i]<='Z') s[i]+='a'-'A';
	}
	cout<<a<<endl;
	cout<<b<<endl;
	return 0;
}
