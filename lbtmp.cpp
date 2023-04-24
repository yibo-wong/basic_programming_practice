#include <iostream>
#include <algorithm>
using namespace std;
int a[]={0,1,2,3,4,5,6,7};
int main()
{
	cout<<lower_bound(a+4,a+4,2)-a<<endl;
}
