#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
int d[100050];
string sswap(const string& s,int i)
{
	string tmp="";
	for(int j=0;j<i;j++) tmp+=s[j];
	tmp+=s[i+1];tmp+=s[i];
	for(int j=i+2;j<5;j++) tmp+=s[j];
	return tmp;
}
string splus(const string& s)
{
	string tmp="";
	for(int i=0;i<4;i++) tmp+=s[i];
	if(s[4]=='9') tmp+='0';
	else tmp+=s[4]+1;
	return tmp;
}
string time(const string& s)
{
	string tmp="";
	for(int i=0;i<4;i++) tmp+=s[i];
	tmp+=((s[4]-'0')*2)%10+'0';
	return tmp;
}
struct node
{
	string s;
	int tot,num2,num3;
	node(string s_,int tot_,int num2_,int num3_):s(s_),tot(tot_),num2(num2_),num3(num3_){}
};
queue<node>q;
string s0;
void bfs()
{
	memset(d,0,sizeof(d));
	node n0(s0,0,3,2);
	q.push(n0);
	while(!q.empty())
	{
		node tmp=q.front();
		
		//cout<<endl<<"pop "<<tmp.s<<endl;
		
		q.pop();
		int t;
		sscanf(tmp.s.c_str(),"%d",&t);
		for(int i=0;i<4;i++)
		{
			string stmp=sswap(tmp.s,i);
			node tmp1(stmp,tmp.tot+1,tmp.num2,tmp.num3);
			int ttmp;
			sscanf(stmp.c_str(),"%d",&ttmp);
			if(d[ttmp]==0)
			{
				d[ttmp]=tmp1.tot;
				//cout<<"push "<<tmp1.s;
				q.push(tmp1);
			}
		}
		//cout<<"gethere"<<endl;
		
		string stmp2=splus(tmp.s);
		int ttmp2;
		sscanf(stmp2.c_str(),"%d",&ttmp2);
		if(tmp.num2>0&&d[ttmp2]==0)
		{
			node tmp2(stmp2,tmp.tot+1,tmp.num2-1,tmp.num3);
			d[ttmp2]=tmp2.tot;
			//cout<<"push "<<tmp2.s;
			q.push(tmp2);
		}
		//cout<<"gethere"<<endl;
		
		string stmp3=time(tmp.s);
		int ttmp3;
		sscanf(stmp3.c_str(),"%d",&ttmp3);
		if(tmp.num3>0&&d[ttmp3]==0)
		{
			node tmp3(stmp3,tmp.tot+1,tmp.num2,tmp.num3-1);
			d[ttmp3]=tmp3.tot;
			//cout<<"push "<<tmp3.s;
			q.push(tmp3);
		}
	}
}
int main()
{
	s0="12345";
	bfs();
	string s1;
	while(cin>>s1)
	{
		int y;
		sscanf(s1.c_str(),"%d",&y);
		if(d[y]==0) cout<<"-1"<<endl;
		else cout<<d[y]<<endl;
	}
	return 0;
}
