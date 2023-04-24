#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int a[1005],le[1005],ri[1005];
void f()
{
	queue<int>q;
	q.push(1);
	while(!q.empty())
	{
		int tmp=q.front();q.pop();
		cout<<a[tmp]<<" ";
		if(le[tmp]) q.push(le[tmp]);
		if(ri[tmp]) q.push(ri[tmp]);
	}
}
int main()
{
	int n;
	int i=0;
	while(cin>>n)
	{
		i++;a[i]=n;
		if(i==1) continue;
		int q=1;
		while(1)
		{
			if(n==a[q]) break;
			if(n<a[q] && le[q]==0)
			{
				le[q]=i;
				break;
			}
			if(n>a[q] && ri[q]==0)
			{
				ri[q]=i;
				break;
			}
			if(n<a[q] && le[q]!=0)
			{
				q=le[q];
			}
			if(n>a[q] && ri[q]!=0)
			{
				q=ri[q];
			}
		}
	}
	f();
	return 0;
}
