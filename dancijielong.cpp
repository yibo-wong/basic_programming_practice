#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
struct node
{
	char word[25];
	int len;
}a[25];
bool flag;
int tot,maxn;
char p[50];
char pp[50];
int use[25];
void check(int m,int n)
{
	if(a[m].len<=a[n].len)
	{
		cout<<"checking1"<<endl;
		flag=false;
		for(int i=0;i<a[m].len;i++)
		{
			if(a[m].word[i]!=a[n].word[i])
			{
				flag=true;
			}
		}
		cout<<"flag=  "<<flag<<endl;
		if(flag==false) return;
	}
	flag=false;
	for(int i=0;i<a[m].len;i++)
	{
		flag=true;
		if(a[m].len-i>a[n].len)
			continue;
		cout<<"i="<<i<<endl;
		for(int j=i;j<a[m].len;j++)
		{
			if(a[m].word[i]!=a[n].word[j-i])
			{
				flag=false;
				break;
			}
			cout<<"j="<<j<<endl;	
		}
		cout<<"theflag="<<flag<<endl;
		if(flag)
			{
				cout<<"gethere"<<endl;
				tot=a[n].len+i;
				if(tot==a[m].len)
				{
					flag=false;
					tot=0;
				}
				if(flag)
				{
					for(int k=0;k<i;k++) p[k]=a[m].word[k];
					for(int k=0;k<a[n].len;k++)p[k+i]=a[n].word[k];
				}
				return;
			}
	}
	return;
}
bool r;
int u;
/*void search(int m)
{
	r=true;
	
	for(u=1;u<=n;u++)
	{
		if(use[u]!=1)
		{
			r=false;
			break;
		}
	}
	if(r)
	{
		if(tot>maxn)
		{
			maxn=tot;
			strcpy(pp,p);
		}
	}
	else
	{
		
	}
}
*/
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].word;
		a[i].len=strlen(a[i].word);
	}
	check(1,2);
	//cout<<flag<<endl;
	if(flag) cout<<p<<endl;
	return 0;
}
