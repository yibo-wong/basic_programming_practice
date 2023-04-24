#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
	string a,s;
	int temp,cnt=0;
	int p;
	getline(cin,a);
	getline(cin,s);
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='A'&&a[i]<='Z') a[i]+='a'-'A';
	}
	for(int i=0;i<s.size();i++)
	{
		if(a[i]>='A'&&a[i]<='Z') s[i]+='a'-'A';
	}
	a=" "+a+" ";
	s=" "+s+" ";
	if(s.find(a,0)==string::npos)
	{
		cout<<"-1"<<endl;return 0;
	}
	else
	{
		cnt++;
		temp=s.find(a,0);
		p=temp;
		while(s.find(a,p+1)!=string::npos)
		{
			cnt++;
			p=s.find(a,p+1);
		}
		cout<<temp<<" "<<cnt<<endl;
	}
	return 0;
}
