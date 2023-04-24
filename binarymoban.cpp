#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
//int a[1000];
int main()
{
	int a[]={1,2,3,3,3,4,5,6}; 
	int n=sizeof(a)/sizeof(a[0]);
	cout<<n<<" "<<sizeof(a)<<" "<<sizeof(a[0])<<endl;
	cout<<a<<" "<<a+8<<" "<<&a[7]<<endl;
	sort(a,a+n);
	cout<<lower_bound(a,a+n,3)<<endl;
	cout<<upper_bound(a,a+n,3)<<endl;
	cout<<lower_bound(a,a+n,3)-a<<endl;
	cout<<upper_bound(a,a+n,3)-a<<endl;
}
