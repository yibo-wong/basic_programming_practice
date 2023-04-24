#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int counter=0;
	int temp;
	for(int i=1;i<=n/2+1;i++)
	{
		temp=n/i;
		counter+=i*temp*(temp+1)/2;
	}
	int k=n/2+2;
	counter+=(n+k)*(n-k+1)/2;
	cout<<counter;
	return 0;
}
