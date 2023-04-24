#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;
priority_queue<double,vector<double>,greater<double> >q;
vector<double>lst;
int n;
string s;
int main()
{
	cin>>n;
	lst.clear();
	double tmp,a,b;
	for(int i=0;i<n;i++) 
	{
		cin>>tmp;
		q.push(tmp);
	}
	while(cin>>s)
	{
		if(s=="+")
		{
			a=lst.back();
			lst.pop_back();
			b=lst.back();
			lst.pop_back();
			lst.push_back(a+b);
		}
		else if(s=="-")
		{
			a=lst.back();
			lst.pop_back();
			b=lst.back();
			lst.pop_back();
			lst.push_back(b-a);
		}
		else if(s=="*")
		{
			a=lst.back();
			lst.pop_back();
			b=lst.back();
			lst.pop_back();
			lst.push_back(b*a);
		}
		else if(s=="/")
		{
			a=lst.back();
			lst.pop_back();
			b=lst.back();
			lst.pop_back();
			lst.push_back(b/a);
		}
		else if(s=="^")
		{
			a=lst.back();
			lst.pop_back();
			b=lst.back();
			lst.pop_back();
			lst.push_back(pow(b,a));
		}
		else if(s=="=")
		{
			if(lst.back()>q.top())
			{
				q.pop();
				q.push(lst.back());
			}
			printf("%e\n",lst.back());
			lst.clear();
		}
		else
		{
			tmp=double(atof(s.c_str()));
			lst.push_back(tmp);
		}
	}
	putchar('\n');
	int sum=0;
	while(!q.empty())
	{
		printf("%e ",q.top());
		sum++;
		if(sum==10)
		{
			sum=0;
			putchar('\n');
		}
		q.pop();
	}
	return 0;
}
