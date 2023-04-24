#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
string a,b,ans;
int n;
int num[26];
bool used[26];
bool have_done;
vector<char>letter;
void make_order()
{
	bool ok[26];
	memset(ok,0,sizeof(ok));
	for(int i=n-1;i>=0;i--)
	{
		if(ok[a[i]-'A']==0)
		{
			ok[a[i]-'A']=1;
			letter.push_back(a[i]);
		}
		if(ok[b[i]-'A']==0)
		{
			ok[b[i]-'A']=1;
			letter.push_back(b[i]);
		}
		if(ok[ans[i]-'A']==0)
		{
			ok[ans[i]-'A']=1;
			letter.push_back(ans[i]);
		}
	}
}
int make_num(string s)
{
	int len=s.size();
	long long int ans=0;
	for(int i=len-1;i>=0;i--)
	{
		ans+=(num[s[i]-'A'])*pow(n,len-i-1);
	}
	return ans;
}
bool check()
{
	int j;
	for(j=n-1;j>=0;j--)
	{
		if(num[a[j]-'A']==-1 || num[b[j]-'A']==-1 || num[ans[j]-'A']==-1) break;
	}
	int p=j+1;
	if(p==n) return true;
	else
	{
		int x=0;
		if(p!=0)
		{
			for(int i=n-1;i>=p;i--)
			{
				if((num[a[i]-'A'] + num[b[i]-'A']+x)%n!=num[ans[i]-'A']) return false;
				else x=(num[a[i]-'A'] + num[b[i]-'A']+x)/n;
			}
			return true;
		}
		else
		{
			for(int i=n-1;i>=1;i--)
			{
				if((num[a[i]-'A'] + num[b[i]-'A']+x)%n!=num[ans[i]-'A']) return false;
				else x=(num[a[i]-'A'] + num[b[i]-'A']+x)/n;
			}
			if(num[a[0]-'A'] + num[b[0]-'A']+x!=num[ans[0]-'A']) return false;
			else return true;
		}
	}
}
void dfs(int pos)
{
	if(!check()) return;
	if(have_done) return;
	if(pos==n)
	{
		for(int i=0;i<n;i++) cout<<num[i]<<" ";
		have_done=true;
		return;
	}
	cout<<"test "<<pos<<endl;
	for(int i=0;i<=2;i++) cout<<letter[i]<<"="<<num[letter[i]-'A']<<" ";
	cout<<endl;
	for(int i=n-1;i>=0;i--)
	{
		if(used[i]==0)
		{
			used[i]=1;
			num[letter[pos]-'A']=i;
			dfs(pos+1);
			num[letter[pos]-'A']=-1;
			used[i]=0;
		}
	}
}
int main()
{
	cin>>n>>a>>b>>ans;
	have_done=false;
	memset(used,0,sizeof(used));
	memset(num,-1,sizeof(num));
	make_order();
	dfs(0);
	return 0;
}
