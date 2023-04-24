#include <iostream>
#include <cstring>
#include <string>
using namespace std;
string a;
int n;
int counter;
int x,y;
int main()
{
	cin>>n;
	//cin.ignore();
	getchar();
	counter=0;
	for(int j=1;j<=n;j++)
	{
		getline(cin,a);
		x=0;y=0;
		for(int i=0;i<a.length()-3;i++)
		{
			if(a[i]=='#'&&a[i+1]=='#'&&a[i+2]=='#') x++;
		}
		for(int i=0;i<a.length()-7;i++)
		{
			if(a[i]=='#'&&a[i+1]=='#'&&a[i+2]=='#')
			{
				if(a[i+4]=='#'&&a[i+5]=='#'&&a[i+6]=='#'&&a[i+3]==' ') y++;
			}
		}
		counter+=x/2-y;
	}
	cout<<counter;
	return 0;
}
