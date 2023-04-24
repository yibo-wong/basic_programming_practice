#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main()
{
	char word[50];
	string s;
	bool flag;
	bool f;
	int cnt=0;
	int p;
	cin>>word;
	cin.ignore();
	getline(cin,s);
	f=0;
	for(int i=0;i<s.length()-strlen(word);i++)
	{
		flag=1;
		if(i==0||s[i-1]==' ')
		{
			if(i+strlen(word)==s.length()||s[i+strlen(word)]==' ') 
			{
				for(int j=i;j<i+strlen(word);j++)
				{
				if(word[j-i]!=s[j]&&word[j-i]!=s[j]+32&&word[j-i]!=s[j]-32)
				{
					flag=0;
					break;
				}
				}
			}
		}
		if(flag==1) cnt++;
		if(flag==1 && f==0)
		{
			f=1;p=i;
		}
	}
	if(cnt==0) cout<<"-1"<<endl;
	else cout<<cnt<<" "<<p<<endl;
	return 0;
}
