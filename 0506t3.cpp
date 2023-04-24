#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;
string exp;
vector<char>q;
int cal()
{
	if(q.back()=='+')
	{
		q.pop_back();
		return cal()+cal();
	}
	else if(q.back()=='-')
	{
		q.pop_back();
		return cal()-cal();
	}
	else if(q.back()=='*')
	{
		q.pop_back();
		return cal()*cal();
	}
	else if(q.back()=='/')
	{
		q.pop_back();
		return cal()/cal();
	}
	else
	{
		int t=q.back()-'0';
		q.pop_back();
		return t;
	}
}
int main()
{
	cin>>exp;
	for(int i=exp.size()-1;i>=0;i--)
	{
		q.push_back(exp[i]);
	}
	cout<<cal()<<endl;
	return 0;
}
