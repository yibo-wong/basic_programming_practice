#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
struct node
{
	int le,ri;
	int x;
	bool operator <(const node &a)const
	{
		return ri>a.ri;
	}
}a[50050];
priority_queue<node> q;
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
	p=1;
	q.push(a[1]);
	b[a[1].x]=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i].le>q.top().ri)
		{
			b[a[i].x]=b[q.top().x];
			q.pop();
			q.push(a[i]);
		}
		else
		{
			p++;
			q.push(a[i]);
			b[a[i].x]=p;
		}
	}
	cout<<p<<endl;
	for(int i=1;i<=n;i++) cout<<b[i]<<endl;
}
