#include <iostream>
using namespace std;
int  trans(int n,int m)
{
	int temp=n;
	int final=0;
	int x;
	int i=1;
	int length=0;
	while(temp!=0)
	{
		x=temp%m;
		temp=temp/m;
		final+=x*i;
		i*=10;
	}
	return final;
}
int main()
{
	int n;
	cin>>n;
	cout<<"0b"<<trans(n,2)<<" "<<"0o"<<trans(n,8)<<" "<<"0x"<<trans(n,16)<<endl;
	return 0;
}
