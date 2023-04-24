#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;
string s;
vector <string> ex;
vector <string> q,tmp;
void split(string s)
{
	stringstream ss(s);
	string item;
	while(getline(ss,item,' '))
	{
		//<<"there"<<endl;
		//cout<<item<<endl;
		ex.push_back(item);
	}
}
int pri(string x)
{
	if(x=="^") return 3;
	else if(x=="*" || x=="/") return 2;
	else if(x=="+" || x=="-") return 1;
	else return 0;
}
bool isnum(string x)
{
	if(x=="(" || x==")" || x=="+" || x=="-" || x=="*" || x=="/" || x=="^" ) return false;
	else return true;
}
void make()
{
	for(int i=0;i<ex.size();i++)
	{
		if(isnum(ex[i])) q.push_back(ex[i]);
		else
		{
			string a=ex[i];
			if(a=="(" || tmp.empty()) tmp.push_back(a);
			else if(a==")")
			{
				while(tmp.back()!="(")
				{
					q.push_back(tmp.back());
					tmp.pop_back();
				}
				tmp.pop_back();
				//cout<<"case 1"<<endl;
			} 
			else
			{
				if(pri(a)>pri(tmp.back())) tmp.push_back(a);
				else
				{
					while(true)
					{
						q.push_back(tmp.back());
						tmp.pop_back();
						if(tmp.empty()) break;
						else if(tmp.back()=="(") break;
						else if(pri(a)>pri(tmp.back())) break;
					}
					tmp.push_back(a);
					//cout<<"this"<<tmp.back()<<endl;
				}
			}
		}
		/*
		for(int i=0;i<tmp.size();i++) cout<<tmp[i]<<" ";
		cout<<endl;
		for(int i=0;i<q.size();i++) cout<<q[i]<<" ";
		cout<<endl<<endl;
		*/
		
	}
	while(!tmp.empty())
	{
		q.push_back(tmp.back());
		tmp.pop_back();
	}
}
int poland()
{
	vector<int>stk;
	int t1,t2;
	for(int i=0;i<q.size();i++)
	{
		if(isnum(q[i])) stk.push_back(atoi(q[i].c_str()));
		else
		{
			if(q[i]=="+")
			{
				t1=stk.back();
				stk.pop_back();
				t2=stk.back();
				stk.pop_back();
				stk.push_back(t1+t2);
			}
			if(q[i]=="-")
			{
				t1=stk.back();
				stk.pop_back();
				t2=stk.back();
				stk.pop_back();
				stk.push_back(t2-t1);
			}
			if(q[i]=="*")
			{
				t1=stk.back();
				stk.pop_back();
				t2=stk.back();
				stk.pop_back();
				stk.push_back(t1*t2);
			}
			if(q[i]=="/")
			{
				t1=stk.back();
				stk.pop_back();
				t2=stk.back();
				stk.pop_back();
				stk.push_back(t2/t1);
			}
			if(q[i]=="^")
			{
				t1=stk.back();
				stk.pop_back();
				t2=stk.back();
				stk.pop_back();
				stk.push_back(pow(t2,t1));
			}
		}
	}
	return stk.back();
}
int main()
{
	int n;
	string casenum;
	getline(cin,casenum);
	n=atoi(casenum.c_str());
	while(n--)
	{
		getline(cin,s);
		while(!ex.empty()) ex.pop_back();
		while(!q.empty()) q.pop_back();
		while(!tmp.empty()) tmp.pop_back();
		split(s);
		make();
		//for(int i=0;i<q.size();i++) cout<<q[i]<<" ";
		//cout<<endl;
		cout<<poland()<<endl;
	}
	return 0;
}
