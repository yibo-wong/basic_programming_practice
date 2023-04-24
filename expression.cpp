#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;
vector <string> a,b,init;
vector <bool> type;//1 for number
string cur,exp;
void initial()
{
	a.clear();
	b.clear();
	init.clear();
	type.clear();
}
bool isnum(char ch)
{
	if('0'<=ch&&ch<='9')return true;
	else return false;
}
int poland()
{
	vector <int> num;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=="+" || a[i]=="-" || a[i]=="*" || a[i]=="/")
		{
			int x=num.back();
			num.pop_back();
			int y=num.back();
			num.pop_back();
			if(a[i]=="+") num.push_back(x+y);
			if(a[i]=="-") num.push_back(x-y);
			if(a[i]=="*") num.push_back(x*y);
			if(a[i]=="/") num.push_back(y/x);
		}
		else
		{
			num.push_back(atoi(a[i].c_str()));
		}
	}
	return num.back();
}
void div()
{
	int p=0,q=0;
	while(p<exp.size())
	{
		if(!(isnum(exp[p])))
		{
			init.push_back(exp.substr(p,1));
			type.push_back(0);
			p++;
		}
		else
		{
			for(q=0;;q++)
			{
				if(p+q==exp.size()-1) break;
				else if(!isnum(exp[p+q+1]))break;
			}
			init.push_back(exp.substr(p,q+1));
			type.push_back(1);
			p+=q+1;
		}
	}
}
int main()
{
	int casenum;
	cin>>casenum;
	while(casenum--)
	{
		
	initial();
	cin>>exp;
	div();
	/*
	for(int i=0;i<init.size();i++)
		cout<<init[i]<<" ";
	cout<<endl;
	*/
	int len=init.size();
	for(int i=0;i<len;i++)
	{
		if(type[i])
		{
			a.push_back(init[i]);
		}
		else
		{
			if(init[i]=="(") b.push_back(init[i]);
			else if(init[i]==")")
			{
				while(1)
				{
					if(b.back()=="(")
					{
						b.pop_back();
						break;
					}
					else
					{
						a.push_back(b.back());
						b.pop_back();
					}
				}
			}
			else if(init[i]=="+" || init[i]=="-")
			{
				if(b.empty())
				{
					b.push_back(init[i]);
				}
				else
				{
				while(1)
				{
					if(b.back()=="(")
					{
						break;
					}
					else
					{
						a.push_back(b.back());
						b.pop_back();
					}
				}
				b.push_back(init[i]);
			    }
			}
			else
			{
				if(b.empty())
				{
					b.push_back(init[i]);
				}
				else
				{
				while(1)
				{
					if(b.back()=="(" || b.back()=="+" || b.back()=="-")
					{
						break;
					}
					else
					{
						a.push_back(b.back());
						b.pop_back();
					}
				}
				b.push_back(init[i]);
			    }
			}
		}
	}
	while(!b.empty())
	{
		a.push_back(b.back());
		b.pop_back();
	}
	/*
	for(int i=0;i<a.size();i++)
	{
		cout<<a[i]<<" ";
	}
	*/
	int ans=poland();
	cout<<ans<<endl;
	}
	return 0;
}
