#include <iostream>
#include <cstdio>
using namespace std;
int heap_size=0;
int heap[300000];
void swap(int &a,int &b)
{
	int t;
	t=a;a=b;b=t;
}
void put(int d)
{
	int now,next;
	heap_size++;
	heap[heap_size]=d;
	now=heap_size;
	while(now>1)
	{
		next=now>>1;
		if(heap[now]>=heap[next]) return;
		else
		{
			swap(heap[now],heap[next]);
			now=next;
		}
	}
}
int get()
{
	int now,next,res;
	res=heap[1];
	heap[1]=heap[heap_size--];
	now=1;
	while(now<<1 <= heap_size)
	{
		next=now<<1;
		if(next<heap_size && heap[next+1]<heap[next]) next++;
		if(heap[now]<=heap[next]) return res;
		swap(heap[now],heap[next]);
		now=next;
	}
	return res;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int s;
		cin>>s;
		put(s);
	}
	for(int i=1;i<=heap_size;i++)
		cout<<heap[i]<<" ";
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<get()<<endl;
		for(int i=1;i<=heap_size;i++)
			cout<<heap[i]<<" ";
		cout<<endl;
	}
	return 0;
}
