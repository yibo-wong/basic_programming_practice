#include <iostream>
#include <cstring>
#define maxn 1000
using namespace std;
int len;
int heap[maxn];
void print()
{
	cout<<"test ";
	for(int i=1;i<=len;i++) cout<<heap[i]<<" ";
	cout<<endl;
}
void ini()
{
	len=0;memset(heap,0,sizeof(heap));
}
void put_in(int i)
{
	len++;
	heap[len]=i;
	int cur=len;
	while(cur>1)
	{
		if(heap[cur]>heap[cur/2])
		{
			swap(heap[cur],heap[cur/2]);
			cur=cur/2;
		}
		else break;
	}
}
int get_out()
{
	int ans=heap[1];
	heap[1]=heap[len];
	len--;
	int cur=1;
	while(cur<len)
	{
		if(cur*2>len) break;
		if(cur*2==len)
		{
			if(heap[cur]<heap[cur*2]) swap(heap[cur],heap[cur*2]);
			break;
		}
		else
		{
			if(heap[cur]>heap[cur*2] && heap[cur]>heap[cur*2+1]) break;
			else
			{
				int maxnum=heap[cur*2]<heap[cur*2+1] ? cur*2+1 : cur*2;
				swap(heap[maxnum],heap[cur]);
				cur=maxnum;
			}
		}
	}
	return ans;
}
int main()
{
	int n;
	cin>>n;
	int t;
	ini();
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		put_in(t);
		print();
	}
	for(int i=1;i<=n;i++)
	{
		cout<<get_out()<<" ";
		print();
	}
	return 0;
}
