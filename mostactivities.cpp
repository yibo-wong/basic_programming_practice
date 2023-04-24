#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
struct node
{
	string l,r;
	int left;
	int right;
	int p;
}a[10010];
bool cmp(node &x,node &y)
{
	return x.right<y.right;
}
int ch[10010];
int f(string s)
{
	if(s.size()==3 && s[1]=='.')
	{
		if(s[0]=='1' && s[2]>'6')
		{
			return s[2]-'7';
		}
		else if(s[0]=='2')
		{
			return 30+s[2]-'7';
		}
		else return 10000;
	}
	else if(s.size()==4 && s[1]=='.')
	{
		if(s[0]=='1')
		{
			int x=0;
			x+=(s[2]-'0')*10+(s[3]-'7');
			return x;
		}
		else if(s[0]=='2')
		{
			int x=0;
			x+=(s[2]-'0')*10+(s[3]-'7');
			x+=31;
			return x;
		}
		else return 1000;
	}
	else return 100000;
}
int temp1,temp2,x3;
string x1,x2;
int main()
{
	int n=0;
	int tot=0;
	int s=0;
	int t=0;
	int pointer=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x1>>x2>>x3;
		temp1=f(x1);
		temp2=f(x2);
		if(temp2>43)
		{
			continue;
		}
		else
		{
			a[pointer].left=temp1;a[pointer].right=temp2;a[pointer].p=x3;
			pointer++;
		}
		//cout<<a[i].left<<" "<<a[i].right<<endl;
	}
	if(pointer==0) 
	{
		cout<<0<<endl;
		return 0;
	}
	else if(pointer==1)
	{
		cout<<a[0].p<<endl;
		return 0;
	}
	sort(a,a+pointer,cmp);
	ch[0]=a[0].p;
	for(int j=1;j<pointer;j++)
	{
		s=ch[j-1];
		t=a[j].p;
		for(int i=j;i>=0;i--)
		{
			if(a[i].right<a[j].left)
			{
				t=max(t,ch[i]+a[j].p);
			}
		}
		ch[j]=max(s,t);
		//cout<<ch[j]<<endl;
	}/*
	for(int i=0;i<pointer;i++)
	{
		cout<<a[i].left<<" "<<a[i].right<<endl;
	}
	for(int i=0;i<pointer;i++)
	{
		cout<<ch[i]<<endl;
	}*/
	cout<<ch[pointer-1]<<endl;
	return 0;
}

