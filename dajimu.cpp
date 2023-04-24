#include <iostream>
#include <cstring>
using namespace std;
int n,a[100050];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int tot=a[1],cur;
	for(int i=2;i<=n;i++)
	{
		if(a[i]>a[i-1]) tot+=a[i]-a[i-1];
	}
	cout<<tot<<endl;return 0;
}
