#include <iostream>
using namespace std;
int f1[210],f2[210];//f1 no black,f2 black
int main()
{
	f1[1]=2;
	f1[2]=6;
	f2[1]=1;
	f2[2]=2;
	for(int i=3;i<=209;i++)
	{
		f1[i]=2*(f1[i-1]+f2[i-1]);
		f2[i]=f1[i-1];
	}
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n;
		cin>>n;
		cout<<f1[n]+f2[n]<<endl;
	}
	return 0;
}
