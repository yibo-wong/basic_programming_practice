#include <iostream>
#include <cstring>
using namespace std;
char a[1000];
int n;
int counter;
int flag;
int main()
{
	cin>>n;
	counter=0;
	for(int i=1;i<=n;i++)
	{
		flag=0;
		while(cin>>a&&a[0]!='.')
		{
			if(strlen(a)>=7)
			{
				if(a[0]=='#'&&a[1]=='#'&&a[2]=='#'&&a[strlen(a)-1]=='#'&&a[strlen(a)-2]=='#'&&a[strlen(a)-3]=='#')
				{
					if(flag==0) counter++;
					flag=1;
				}
				else
				{
					flag=0;
				}
			}
			else
			{
				flag=0;
			}
		};
	}
	cout<<counter;
	return 0;
}
