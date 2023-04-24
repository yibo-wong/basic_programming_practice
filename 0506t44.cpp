#include <iostream>
#include <cstring>
#include <string>
#define maxn 5000
using namespace std;
char a[maxn];
int lch[maxn],rch[maxn];
string s;
int cur;
int p;
int crt()
{
	if(s[cur]=='.')
	{
		cur++;return 0;
	}
	else
	{
		int tmp=p;
		a[p]=s[cur];
		cur++;p++;
		lch[tmp]=crt();
		rch[tmp]=crt();
		return tmp;
	}
}
void mid(int i)
{
	if(a[i]==0) return;
	mid(lch[i]);
	cout<<a[i];
	mid(rch[i]);
}
void post(int i)
{
	if(a[i]==0) return;
	post(lch[i]);
	post(rch[i]);
	cout<<a[i];
}
int main()
{
	cin>>s;
	p=1;cur=0;
	crt();
	for(int i=0;i<s.size();i++) cout<<i<<" "<<a[i]<<" "<<lch[i]<<" "<<rch[i]<<endl;
	mid(1);
	cout<<endl;
	post(1);
	return 0;
}
