#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
string s;
char ans[120];
vector<int>a,b;
int main()
{
	getline(cin,s);
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='(')
		{
			a.push_back(i);
		}
		if(s[i]==')')
		{
			if(!a.empty())
			{
				a.pop_back();
			}
			else
			{
				b.push_back(i);
			}
		}
	}
	memset(ans,' ',sizeof(ans));
	for(int i=0;i<a.size();i++) ans[a[i]]='$';
	for(int j=0;j<b.size();j++) ans[b[j]]='?';
	for(int i=0;i<s.size();i++) cout<<ans[i];
	return 0;
}
