#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,p;
int a,b;
int s,t;
int x[1000];
int main()
{
	cin>>p;
	int i=1;
	while((scanf("%d",&x[i]))!=EOF) i++;
	n=--i;
	sort(x+1,x+n+1);
	//cout<<"iii"<<endl;
	s=1;t=n;a=b=0;
	while(s<t)
	{
		if(p>=x[s])
		{
			p-=x[s];s++;a++;
		}
		else
		{
			if(a==b) break;
			else
			{
				p+=x[t];t--;b++;
			}
		}
	}
	if(s==t&&p>=x[s]) a++;
	cout<<a-b<<endl;
	return 0;
}
