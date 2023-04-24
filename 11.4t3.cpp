#include <iostream>
using namespace std;
int a[13]={0,0,31,59,90,120,151,181,212,243,273,304,334};
int m1,m2,d1,d2;
int num;
int len;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m1>>d1>>num>>m2>>d2;
		len=a[m2]+d2-a[m1]-d1;;
		for(int j=1;j<=len;j++)
		{
			num=num*2;
		}
		cout<<num<<endl;
	}
	return 0;
}
