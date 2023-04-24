#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[5][4050],n;
bool bi(int i)
{
	int le=1,ri=n;
	int mid=(le+ri)/2;
	while(le<=ri)
	{
		//cout<<"in bi "<<le<<" "<<ri<<endl;
		mid=(le+ri)/2;
		if(a[1][mid]==i)
		{
			return 1;
		}
		else if(a[1][mid]>i)
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
	int sum=0,tmp=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=4;j++)
			cin>>a[j][i];
	sort(a[1]+1,a[1]+n+1);
	sort(a[2]+1,a[2]+n+1);
	int minx=a[1][1]+a[2][1];
	int maxx=a[1][n]+a[2][n];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			tmp=-a[3][i]-a[4][j];
			if(tmp<minx || tmp>maxx) continue;
			for(int k=1;k<=n;k++)
				if(bi(tmp-a[2][k]))
				{
					sum++;
					cout<<tmp-a[2][k]<<"  "<<a[2][k]<<"  "<<a[3][i]<<"  "<<a[4][j]<<endl;
				}
		}
	}
	cout<<sum<<endl;
	return 0;
}
