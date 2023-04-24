#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
string s;
vector <char> q;
vector <char> opt;
vector <char> exp;
bool isnum(char x)
{
	return (x=='V' || x=='F');
}
int prt(char s)
{
	if(s=='!') return 3;
	else if(s=='&') return 2;
	else if(s=='|') return 1;
	else return 0;
}
bool cal()
{
	vector <bool> q1;
	while(!q1.empty()) q1.pop_back();
	for(int i=0;i<exp.size();i++)
	{
		if(exp[i]=='V') q1.push_back(true);
		else if(exp[i]=='F') q1.push_back(false);
		else
		{
			if(exp[i]=='!')
			{
				bool tmp=!q1.back();
				q1.pop_back();
				q1.push_back(tmp);
			}
			else if(exp[i]=='&')
			{
				bool tmp1=q1.back();
				q1.pop_back();
				bool tmp2=q1.back();
				q1.pop_back();
				q1.push_back(tmp1&&tmp2);
			}
			else if(exp[i]=='|')
			{
				bool tmp1=q1.back();
				q1.pop_back();
				bool tmp2=q1.back();
				q1.pop_back();
				q1.push_back(tmp1||tmp2);
			}
		}
	}
	return q1.back();
}
int main()
{
	int casenum=0;
	while(getline(cin,s))
	{
		casenum++;
		while(!q.empty()) q.pop_back();
		while(!opt.empty()) opt.pop_back();
		while(!exp.empty()) exp.pop_back();
		for(int i=0;i<s.size();i++)
		{
			if(s[i]!=' ') q.push_back(s[i]);
		}
		//for(int i=0;i<q.size();i++) cout<<q[i];
		//cout<<endl;
		for(int i=0;i<q.size();i++)
		{
			if(isnum(q[i]))
			{
				exp.push_back(q[i]);
			}
			else
			{
				if(q[i]=='&' || q[i]=='|')
				{
					if(opt.empty()) opt.push_back(q[i]);
					else
					{
						while(!opt.empty())
						{
							if(prt(opt.back())>=prt(q[i]))
							{
								exp.push_back(opt.back());
								opt.pop_back();
							}
							else break;
						}
						opt.push_back(q[i]);
					}
				}
				else if(q[i]=='!')
				{
					if(opt.empty()) opt.push_back(q[i]);
					else
					{
						while(!opt.empty())
						{
							if(prt(opt.back())>prt(q[i]))
							{
								exp.push_back(opt.back());
								opt.pop_back();
							}
							else break;
						}
						opt.push_back(q[i]);
					}
				}
				else if(q[i]=='(')
				{
					opt.push_back(q[i]);
				}
				else if(q[i]==')')
				{
					while(opt.back()!='(')
					{
						exp.push_back(opt.back());
						opt.pop_back();
					}
					opt.pop_back();
				}
			}
			/*
			for(int i=0;i<opt.size();i++) cout<<opt[i]<<" ";
			cout<<endl;
			for(int i=0;i<exp.size();i++) cout<<exp[i]<<" ";
			cout<<endl<<endl;
			*/
		}
		while(!opt.empty())
		{
			exp.push_back(opt.back());
			opt.pop_back();
		}
		//cout<<"end: ";
		//for(int i=0;i<exp.size();i++) cout<<exp[i]<<" ";
		//cout<<endl;
		if(cal()) cout<<"Expression "<<casenum<<": V"<<endl;
		else cout<<"Expression "<<casenum<<": F"<<endl;
	}
	return 0;
}
