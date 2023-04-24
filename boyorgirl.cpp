#include <iostream>
#include <cstring>
using namespace std;
char a[105];
int b[26];
int main()
{
	cin>>a;
	int counter=0;
	for(int i=0;i<strlen(a);i++)
	{
		if(b[a[i]-'a']==0)
		{
			b[a[i]-'a']=1;
			counter++;
		}
	}
	if(counter%2==0)
	{
		cout<<"CHAT WITH HER!";
	}
	else
	{
		cout<<"IGNORE HIM!";
	}
	return 0;
}
