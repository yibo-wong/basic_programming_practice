#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
priority_queue<int,vector<int>,greater<int> >q;
int n,x,cnt,a,b;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		q.push(x);
	} 
	cnt=0;
	for(int i=1;i<=n-1;i++)
	{
		a=q.top();
		q.pop();
		//cout<<a<<endl;
		b=q.top();
		q.pop();
		//cout<<b<<endl;
		cnt+=a+b;
		q.push(a+b);
	}
	cout<<cnt<<endl;
	return 0;
}
