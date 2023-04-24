#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
int a[30];
string s;
int main()
{
	getline(cin,s);
	for(int i=0;i<s.size();i++)
	{
		if('A'<=s[i]&&s[i]<='Z')
		{
			s[i]=s[i]-'A'+'a';
		}
		a[s[i]-'a']++;
	}
	//cout<<s<<endl;
	int temp=0;int p=0;
	for(int i=0;i<=25;i++)
	{
		if(a[i]>temp)
		{
			temp=a[i];
			p=i;
		}
	}
	char x;
	x=char(p+'a');
	cout<<x<<" "<<temp;
	return 0;
}
