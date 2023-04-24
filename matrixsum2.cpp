#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[5][4050],n;
int sum1[4050*4050],sum2[4050*4050];
int bi(int i)
{
	int le=1,ri=n*n;
	int mid=(le+ri)/2;
	while(le<=ri)
	{
		//cout<<"in bi "<<le<<" "<<ri<<endl;
		mid=(le+ri)/2;
		if(sum1[mid]==i)
		{
			int s=1;
			for(int i=mid+1;i<=n*n;i++)
				if(sum1[i]!=sum1[mid]) break;
				else s++;
			for(int i=mid-1;i>0;i--)
				if(sum1[i]!=sum1[mid]) break;
				else s++;
			return s;
		}
		else if(sum1[mid]>i)
		{
			ri=mid-1;
		}
		else le=mid+1;
	}
	return 0;
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
			tmp++;
		}
	tmp=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			sum2[tmp]=a[3][i]+a[4][j];
			tmp++;
		}
	sort(sum1+1,sum1+n*n+1);
	for(int i=1;i<=n*n;i++)
	{
		num+=bi(-sum2[i]);
	}
	cout<<num<<endl;
	return 0;
}
