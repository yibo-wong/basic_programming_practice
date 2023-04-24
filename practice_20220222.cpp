#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	string s,s1;
	while(cin>>s)
	{
	cin>>s1;
	char tmp=0;
	int p=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>tmp)
		{
			tmp=s[i];
			p=i;
		}
	}
	for(int i=0;i<=p;i++) cout<<s[i];
	cout<<s1;
	for(int i=p+1;i<s.length();i++) cout<<s[i];
	cout<<endl;
	}
	
	return 0;
}
