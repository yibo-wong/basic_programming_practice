#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
vector<string>a;
string s;
int n;
int p,len;
int mylength(int s,int t)
{
	int tot=0;
	for(int i=s;i<=t;i++)
	{
		tot+=a[i].size();
	}
	tot+=t-s;
	return tot;
}
void myprint(int s,int t)
{
	if(s==t)
	{
		cout<<a[s]<<endl;
		return;
	}
	for(int i=s;i<=t-1;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<a[t]<<endl;
	return;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		a.push_back(s);
	}
	p=0;len=a[0].size();
	while(true)
	{
		if(mylength(p,n-1)<=80)
		{
			myprint(p,n-1);
			break;
		}
		for(int i=p;i<n;i++)
		{
			if(mylength(p,i)<=80&&mylength(p,i+1)>80)
			{
				myprint(p,i);
				p=i+1;
				break;
			}
		}
	}
	return 0;
}
