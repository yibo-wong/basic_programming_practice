#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[5][4050],n;
int sum1[4050*4050],sum2[4050*4050];
int bi(int i)
{
	return upper_bound(sum1+1,sum1+n*n+1,i)-lower_bound(sum1+1,sum1+n*n+1,i);
}
int main()
{
	cin>>n;
	int num=0,tmp=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=4;j++)
			cin>>a[j][i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			sum1[tmp]=a[1][i]+a[2][j];
			sum2[tmp]=a[3][i]+a[4][j];
			tmp++;
		}
	sort(sum1+1,sum1+n*n+1);
	for(int i=1;i<=n*n;i++)
		num+=upper_bound(sum1+1,sum1+n*n+1,-sum2[i])-lower_bound(sum1+1,sum1+n*n+1,-sum2[i]);
	cout<<num<<endl;
	return 0;
}
