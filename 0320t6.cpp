#include <iostream>
#include <cmath>
#include <algorithm>
#define inf 10000005
using namespace std;
int n,m;
int w[1050];
bool judge(int x)
{
	int sum=0;
	for(int i=1;i<=n;i++) sum+=ceil(1.0*w[i]/x);
	if(sum<=m) return true;
	else return false;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>w[i];
	int le=1,ri=inf;
	int mid;
	while(le<ri)
	{
		mid=le+(ri-le)/2;
		if(judge(mid)) ri=mid;
		else le=mid+1;
	}
	cout<<le<<endl;
	//for(int i=1;i<=30;i++) cout<<judge(i)<<" ";
	return 0;
}
