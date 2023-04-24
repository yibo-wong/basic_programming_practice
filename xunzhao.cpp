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
		if(s[i]>='A'&&s[i]<='Z') s[i]+='a'-'A';
	}
	//cout<<int(a[2])<<endl;
	a=" "+a+" ";
	s=" "+s+" ";
	//cout<<a.size()<<endl;
	if(a[a.size()-1]=='\n' ||a[a.size()-1]=='\r' ||a[a.size()-1]=='\0') a.erase(a.size()-1,1);
	if(s[s.size()-1]=='\n' ||s[s.size()-1]=='\r' ||s[s.size()-1]=='\0') s.erase(s.size()-1,1);
	if(s.find(a,0)==string::npos)
	{
		cout<<"-1"<<endl;return 0;
	}
	else
	{
		temp=s.find(a,0);
		p=temp;
		while(p!=string::npos)
		{
			cnt++;
			p=s.find(a,p+1);
		}
		cout<<cnt<<" "<<temp<<endl;
	}
	return 0;
}
