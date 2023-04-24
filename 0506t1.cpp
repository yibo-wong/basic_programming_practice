#include <iostream>
#include <vector>
using namespace std;
int sum;
vector<int>q;
int main()
{
	int n;
	sum=0;
	while(cin>>n)
	{
		if(n==0) break;
		q.push_back(n);
		sum+=n*q.size();
	}
	cout<<sum<<endl;
	while(!q.empty())
	{
		cout<<q.back()<<" ";
		q.pop_back();
	}
	return 0;
}
