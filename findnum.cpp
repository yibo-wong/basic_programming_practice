#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
int n,t;
int a;
map<int,int>dic;
int main()
{
	cin>>n>>t;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		if(dic.find(a)==dic.end()) dic.insert(make_pair(a,1));
		else dic[a]++;
	}
	int sum=0;
	if(t!=0)
	{
		for(int i=-1000011;i<=1000011;i++)
		{
			if(dic.find(i)!=dic.end() && dic.find(i+t)!=dic.end()) sum++;
		}
	}	
	else
	{
		for(int i=-1000011;i<=1000011;i++)
		{
			if(dic.find(i)!=dic.end())
				if(dic[i]>1) sum++;
		}
	}
	cout<<sum<<endl;
}
