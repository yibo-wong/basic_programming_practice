#include <iostream>
#include <cstring>
using namespace std;
char a[200];
char b[200];
bool p;
int main()
{
	cin>>a;
	cin>>b;
	int ans=0;
	for(int i=0;i<strlen(a);i++)
	{
		p=true;
		for(int j=i;j<strlen(a);j++)
		{
			if(a[j]!=b[j-i])
			{
				p=false;
				break;
			}
		}
		if(p)
		{
			ans=i;
			break;
		}
	}
	cout<<ans;
	return 0;
}
