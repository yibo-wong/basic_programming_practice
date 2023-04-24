#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;
int cnt[26];
string a;
int casenum;
int main()
{
	cin>>casenum;
	while(casenum--)
	{
		cin>>a;
		if(casenum) getchar();
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<a.size();i++)
		{
			cnt[a[i]-'a']++;
		}
		int tmp=0;
		char p;
		for(int i=0;i<26;i++)
		{
			if(cnt[i]>tmp)
			{
				tmp=cnt[i];
				p=char('a'+i);
			}
		}
		cout<<p<<" "<<tmp<<endl;
	}
	return 0;
}
