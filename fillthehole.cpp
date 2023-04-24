#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int a[100050];//thie is really cool
//and im rubbish
int n;
int counter=0;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)     
		cin>>a[i];
	for(int i=2;i<=n;i++)     
		if(a[i]>a[i-1]) 
			counter+=a[i]-a[i-1];
	cout<<counter+a[1];
	return 0;
}
