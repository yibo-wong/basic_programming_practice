#include <iostream>
#include <queue>
#include <cstdlib>
#include <cstdio>
using namespace std;
//int a,b;
/////
/*
int main()
{
	priority_queue<int,vector<int>,greater<int> > q;
	for(int i=0;i<10;i++) 
	{
		a=rand();
		q.push(a);
	}
	while(!q.empty()) 
	{
		cout<<q.top()<<" "<<q.size()<<endl;
		q.pop();
	}
	return 0;
}
*/
////////
struct node
{
	int x;
	int y;
};
node a;
bool operator < (node m,node n)
{
	if(m.x==n.x) return m.y>n.y;
	return m.x>n.x;
}
int main()
{
	priority_queue<node>q;
	for(int i=1;i<=10;i++)
	{
		cin>>a.x>>a.y;
		q.push(a);
	}
	while(!q.empty())
	{
		cout<<q.top().x<<" "<<q.top().y<<endl;
		q.pop();
	}
	return 0;
}
