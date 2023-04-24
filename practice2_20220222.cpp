#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	//vector <char> q;
	int n;
	int a[1050],b[1050];
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++)
	{
		a[i]+=b[n-i+1];
		cout<<a[i]<<" ";
	}
	return 0;
}
