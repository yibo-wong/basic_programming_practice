#include <iostream>
#include <cstring>
#include <string>
using namespace std;
string s;
int a[10050];
int n;
int cur;
int judge(int i,int j)
{
	bool zero=0,one=0;
	for(int k=i;k<=j;k++)
	{
		if(s[k]=='1') one=1;
		if(s[k]=='0') zero=1;
	}
	if(one && zero) return 2;
	else if(one) return 1;
	else return 0;
}
void make(int i,int j,int num)
{
	if(i==j)
	{
		a[num]=s[i]-'0';return;
	}
	a[num]=judge(i,j);
	make(i,(i+j-1)/2,num*2+1);
	make((i+j+1)/2,j,num*2+2);
}
void post(int i)
{
	if(a[i]==-1) return;
	post(2*i+1);
	post(2*i+2);
	if(a[i]==0) cout<<'B';
	else if(a[i]==1) cout<<'I';
	else cout<<'F';
}
int main()
{
	cin>>n;
	cin>>s;
	memset(a,-1,sizeof(a));
	make(0,(1<<n)-1,0);
	post(0);
	return 0;
}
