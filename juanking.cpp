#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
int n,m;
int len;
int maxn; 
int sum1;
string king;
bool flag;
struct node
{
	string lesson;
	int score;
	node(){}
	node(string l,int s):lesson(l),score(s){}
};
map<string,int>score[100050];
map<string,int>id;
string name[100050];
string tmp1,tmp2;
int tmp3;
string a[12];
int main()
{
	cin>>n;
	int num=0;
	for(int i=0;i<n;i++)
	{
		cin>>tmp1>>tmp2>>tmp3;
		if(id.find(tmp2)!=id.end())
		{
			int myid=id[tmp2];
			score[myid].insert(pair<string,int>(tmp1,tmp3));
		}
		else
		{
			num++;
			name[num]=tmp2;
			id.insert(pair<string,int>(tmp2,num));
			score[num].insert(pair<string,int>(tmp1,tmp3));
		}
	}
//	cout<<" test"<<endl;
//	for(int i=1;i<num;i++)
//	{
//		cout<<name[i]<<" ";
//		cout<<score[i].size()<<" ";
//		map<string,int>::iterator it=score[i].begin();
//		for(;it!=score[i].end();it++) cout<<it->first<<" "<<it->second<<"  ";
//		cout<<endl;
//	}
//	
	cin>>m;
	for(int k=0;k<m;k++)
	{
		cin>>len;
		maxn=0;
		king="zzzzz";
		for(int j=0;j<len;j++) cin>>a[j];
		for(int i=1;i<=num;i++)
		{
			sum1=0;
			flag=1;
			for(int j=0;j<len;j++)
			{
				if(score[i].find(a[j])==score[i].end())
				{
					flag=0;
					break;
				}
				else sum1+=score[i][a[j]];
			}
			if(flag)
			{
				if(sum1>maxn || (sum1==maxn && name[i]<king))
				{
					maxn=sum1;
					king=name[i];
				}
			}
		}
		cout<<king<<endl;
	}
	return 0;
}
