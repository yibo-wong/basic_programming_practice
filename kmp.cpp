#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
char s[200],t[10000];
int next[200];
vector<int> ans;
void getnext(char s[])
{
	next[0]=-1;//or is it?
	int p=0,j=-1;
	for(p=1;p<strlen(s);p++)
	{
		while(j!=-1 && s[p]!=s[j+1])
		{
			j=next[j];
		}
		if(s[p]==s[j+1]) j++;
		next[p]=j;
		
	}
}
void find(char s[],char t[])
{
	int q=0,i=0;
	cout<<"size "<<strlen(s)<<endl;
	while(q<=strlen(t)-strlen(s))
	{
		for(i=0;i<strlen(s);i++)
		{
			if(s[i]!=t[i+q])
			{
				break;
			}
		}
		i--;
		cout<<"find "<<q<<" "<<i<<endl;
		if(i==strlen(s)-1)
		{
			ans.push_back(q);
		}
		if(i!=-1) q+=i-next[i];
		else q+=1;
	}
}
int main()
{
	cin>>t;
	cin>>s;
	cout<<"size "<<strlen(s)<<endl;
	getnext(s);
	for(int i=0;i<strlen(s);i++) cout<<next[i]<<" ";
	cout<<endl;
	cout<<strlen(t)-strlen(s)<<endl;
	find(s,t);
	cout<<ans.size()<<endl;
	if(!ans.empty())
	{
		for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
	}
	return 0;
}
