#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#define inf 0x3f3f3f3f
using namespace std;
int casenum,n,a;
bool used[40];
bool flag;
double road[40][40];
map<string,int>id;
//void ini()
//{
//	string name,name1;
//	id.clear();
//	for(int i=0;i<n;i++)
//	{
//		cin>>name;
//		id[name]=i;
//	}
//	cin>>a;
//	memset(road,0,sizeof(road));
//	double v;
//	for(int i=0;i<a;i++)
//	{
//		cin>>name>>v>>name1;
//		road[id[name]][id[name1]]=v;
//	}
//	for(int i=0;i<n;i++) road[i][i]=1;
//	flag=false;
//	memset(used,0,sizeof(used));
//}

void calc()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				if(road[j][k]<road[j][i]*road[i][k])
					road[j][k]=road[j][i]*road[i][k];
}
int main()
{
	casenum=1;
	while(cin>>n)
	{
		string name,name1;
		id.clear();
		if(n==0) return 0;
		memset(road,0,sizeof(road));
		for(int i=0;i<n;i++) road[i][i]=1;
		for(int i=0;i<n;i++)
		{
			cin>>name;
			id[name]=i;
		}
		cin>>a;
		double v;
		for(int i=0;i<a;i++)
		{
			cin>>name>>v>>name1;
			road[id[name]][id[name1]]=v;
		}
		flag=false;
		calc();
		for(int i=0;i<n;i++)
		{
			if(road[i][i]>1) flag=true;
		}
		cout<<"Case "<<casenum<<": ";
		if(flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		casenum++;
	}
	return 0;
}
