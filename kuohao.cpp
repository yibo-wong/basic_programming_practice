#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>a;
char s[150],ans[150];
int main()
{
	while(cin>>s)
	{
		a.clear();
		for(int i=0;i<sizeof(s);i++)
		{
			if(s[i]=='(')
			{
				a.push_back(i);
				ans[i]=' ';
			}
			else if(s[i]==')')
			{
				if(!a.empty())
				{
					a.pop_back();
					ans[i]=' ';
				}
				else
				{
					ans[i]='?';
				}
			}
			else
			{
				ans[i]=' ';
			}
		}
		if(!a.empty())
		{
			for(int i=0;i<a.size();i++)
			{
				ans[a[i]]='$';
			}
		}
		cout<<s<<endl;
		cout<<ans<<endl;
	}
	return 0;
}
