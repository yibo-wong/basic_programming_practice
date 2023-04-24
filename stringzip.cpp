#include <iostream>
#include <cstring>
using namespace std;
	char s[1010];
	struct node
	{
		char a;
		int data;
	}ans[1010];
int main()
{
	cin>>s;
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]>=65&&s[i]<=90) s[i]+=32;
	}
	int counter=0;
	ans[1].a=s[0];
	ans[1].data=1;
	counter=1;
	for(int i=1;i<strlen(s);i++)
	{
		if(s[i]==s[i-1])
		{
			ans[counter].data++;
		}
		else
		{
			counter++;
			ans[counter].a=s[i];
			ans[counter].data=1;
		}
	}
	for(int i=1;i<=counter;i++)
	{
		cout<<"("<<ans[i].a<<","<<ans[i].data<<")";
	}
	return 0;
}
