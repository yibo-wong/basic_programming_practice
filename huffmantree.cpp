#include <iostream>
#include <queue>
#define ll long long
using namespace std;
int n,a;
int x,y;
ll int tot=0;
int main()
{
	cin>>n;
	priority_queue<ll int,vector<ll int>,greater<ll int> >q;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		q.push(a);
	}
	while(q.size()>=2)
	{
		x=q.top();
		q.pop();
		y=q.top();
		q.pop();
		q.push(x+y);
		tot+=x+y;
	}
	cout<<tot<<endl;
	return 0;
}
