#include <iostream>
#include <cstring>
using namespace std;
int a[2050];
int lch[2050],rch[2050];
int n;
void crt(int le,int ri)
{
	if(le==ri)
	{
		lch[le]=rch[le]=-1;
		return;
	}
	else if(le+1==ri)
	{
		if(a[le]<a[ri])
		{
			lch[le]=-1;
			rch[le]=ri;
		}
		else
		{
			lch[le]=ri;
			rch[le]=-1;
		}
		return;
	}
	else
	{
		int p=0;
		for(int i=le+1;i<=ri;i++)
		{
			if(a[i]>a[le])
			{
				p=i;
				break;
			}
		}
		if(p==0)
		{
			lch[le]=le+1;
			rch[le]=-1;
			crt(le+1,ri);
		}
		else if(a[le+1]<a[le])
		{
			lch[le]=le+1;
			rch[le]=p;
			crt(le+1,p-1);
			crt(p,ri);
		}
		else
		{
			lch[le]=-1;
			rch[le]=p;
			crt(p,ri);
		}
	}
}
void pre(int i)
{
	if(i==-1) return;
	pre(lch[i]);
	pre(rch[i]);
	cout<<a[i]<<" ";
}
int main()
{
	memset(lch,-1,sizeof(lch));
	memset(rch,-1,sizeof(rch));
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	crt(1,n);
	pre(1);
	return 0;
}
