#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define maxn 10000050
using namespace std;
vector<int>prime;
bool isp[maxn];
void sieve(int n)
{
	memset(isp,1,n);
	isp[0]=0;
	for(int i=2;i<=n;i++)
	{
		if(isp[i])
		{
			prime.push_back(i);
			for(int j=i;j<=n;j+=i) isp[j]=0;
		}
	}
}
int prime_num(int n)
{
	int sum=0;
	for(int i=0;prime[i]<n;i++)
	{
		if(n%prime[i]==0) sum++;
	}
	return sum;
}
struct cmp1
{
	bool operator()(int x,int y)
	{
		if(prime_num(x)==prime_num(y)) return x<y;
		return prime_num(x)<prime_num(y);
	}	
};
struct cmp2
{
	bool operator()(int x,int y)
	{
		if(prime_num(x)==prime_num(y)) return x>y;
		return prime_num(x)>prime_num(y);
	}	
};
priority_queue<int,vector<int>,cmp1>q1;
priority_queue<int,vector<int>,cmp2>q2;
int main()
{
	sieve(10000050);
	//for(int i=0;i<20;i++) cout<<prime[i]<<" ";
	int num;
	cin>>num;
	while(num--)
	{
		int x;
		for(int i=0;i<10;i++)
		{
			cin>>x;
			//cout<<x<<":"<<prime_num(x)<<endl;
			q1.push(x);
			q2.push(x);
		}
		cout<<q1.top()<<" "<<q2.top()<<endl;
		q1.pop();q2.pop();
	}
	return 0;
}
