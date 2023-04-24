#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
	int le,ri;
	int x;
}a[50050];
int b[50050];
bool cmp(node s,node t)
{
	if(s.le==t.le) return s.ri<t.ri;
	else return s.le<t.le;
}
int n,p,temp;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].le>>a[i].ri;
		a[i].x=i;
	}
	sort(a+1,a+n+1,cmp);
	temp=a[1].le;p=1;b[a[1].x]=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i].le>temp)
		{
			temp=a[i].le;
			cout<<temp<<endl;
			b[a[i].x]=p;
		}
		else if(a[i].le<=temp && temp+1<=a[i].ri)
		{
			temp+=1;
			cout<<temp<<endl;
			b[a[i].x]=p;
		}
		else
		{
			temp=a[i].le;
			cout<<temp<<endl;
			p++;
			b[a[i].x]=p;
		}
	}
	cout<<p<<endl;
	for(int i=1;i<=p;i++)
	{
		cout<<b[i]<<endl;
	}
	return 0;
}
