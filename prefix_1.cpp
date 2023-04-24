#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#define maxn 100000
using namespace std;
vector<string>dic;
vector<string>pre;
char a[maxn];
vector<int>child[maxn];
vector<int>root;
int main()
{
	string tmp;
	int lt=0;
	bool flag=0;
	while(cin>>tmp)
	{
		dic.push_back(tmp);
	}
	for(int ii=0;ii<dic.size();ii++)
	{
		string cur=dic[ii];
		int sum=0;
		int p=-1;
		for(int j=1;j<=cur.size();j++)
		{
			sum=0;
			for(int i=0;i<dic.size();i++)
			{
				if(dic[i].substr(0,j)==cur.substr(0,j)) sum++;
			}
			if(sum==1)
			{
				p=j;
				break;
			}
		}
		if(p) cout<<cur<<" "<<cur.substr(0,p)<<endl;
		else cout<<cur<<" "<<cur<<endl;
	}
	return 0;
}
