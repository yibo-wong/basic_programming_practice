#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <cstring>
#define inf 0x3f3f3f3f
using namespace std;
int minn,maxn;
queue<int>q;
deque<int>minq;
deque<int>maxq;
vector<int>ansmax;
vector<int>ansmin;
int n,k;
int a[1000050];
int main()
{
	cin>>n>>k;
	if(k==1)
	{
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) cout<<a[i]<<" ";cout<<endl;
		for(int i=1;i<=n;i++) cout<<a[i]<<" ";
		return 0;
	}
	minn=inf;
	maxn=-inf;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=k;i>=1;i--)
	{
		if(a[i]>=maxn)
		{
			maxn=a[i];
			maxq.push_back(a[i]);
		}
		if(a[i]<=minn)
		{
			minn=a[i];
			minq.push_back(a[i]);
		}
	}
	ansmax.push_back(maxn);
	ansmin.push_back(minn);
	for(int i=k+1;i<=n;i++)
	{
		if(a[i-k]==maxn) maxq.pop_back();
		while(a[i]>maxq.front())
		{
			maxq.pop_front();
			if(maxq.empty()) break;
		}
		maxq.push_front(a[i]);
		maxn=maxq.back();
		ansmax.push_back(maxn);
		
		if(a[i-k]==minn) minq.pop_back();
		while(a[i]<minq.front())
		{
			minq.pop_front();
			if(minq.empty()) break;
		}
		minq.push_front(a[i]);
		minn=minq.back();
		ansmin.push_back(minn);
	}
	for(int i=0;i<ansmin.size();i++) cout<<ansmin[i]<<" ";
	cout<<endl;
	for(int i=0;i<ansmax.size();i++) cout<<ansmax[i]<<" ";
}
