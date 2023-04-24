#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
priority_queue<int,vector<int>, greater<int> >q;
void f(int n)
{
	for(int i=1;i<=n;i++)
	{
		if(n%i==0) 
		{
			//cout<<i<<endl;
			q.push_back(i);
			while(n%i==0) n=n/i;
			f(n);
		}
	}
}
bool flag=false;
int temp=1;
int main()
{
	int m;
	cin>>m;
	f(m);
	//cout<<q[3]<<endl;
	for(int i=0;i<q.size();i++)
	{
		//cout<<q[i]<<" ";
		if(q[i]>6)
		{
			flag=true;
			temp=q[i];
			break;
		}
	}
	//cout<<temp<<endl;
	int final=m/temp;
	if(flag==false) cout<<1<<endl;
	else cout<<final<<endl;
	return 0;
}
