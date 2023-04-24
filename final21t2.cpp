#include <iostream>
#include <cstring>
#include <string>
using namespace std;
string a,b;
bool is_letter(char c)
{
	if('A'<=c && c<='Z') return true;
	return false;
}
int main()
{
	cin>>a>>b;
	for(int i=0;i<a.size();i++)
	{
		if(is_letter(a[i])) a[i]+=('a'-'A');
	}
	for(int i=0;i<b.size();i++)
	{
		if(is_letter(b[i])) b[i]+=('a'-'A');
	}
	if(a.find(b)==string::npos) cout<<"No";
	else cout<<"Yes";
	return 0;
}
