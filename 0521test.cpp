#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int a,int b)
{
	return a%b==0 ? b : gcd(b,a%b);
}
int main()
{
	int x,y;cin>>x>>y;cout<<gcd(max(x,y),min(x,y));return 0;
}
