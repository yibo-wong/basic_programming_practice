#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int s=1;
	if(n==1)
	{
		cout<<"I hate it";
		return 0;
	}
	for(int i=1;i<=n-1;i++)
	{
		if(s==1) cout<<"I hate that ";
		if(s==-1) cout<<"I love that ";
		s=s*(-1);
	}
	if(s==1) cout<<"I hate it";
	if(s==-1) cout<<"I love it";
	return 0;
}
