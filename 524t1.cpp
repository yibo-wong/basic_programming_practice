#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main()
{
	int n;
	string a,b;
	cin>>n;
	while(n--)
	{
		cin>>a>>b;
		int p=0;
		int q=0;
		while(q<b.size())
		{
			if(a[p]==b[q])
			{
				p++;q++;
			}
			else
			{
				q++;
			}
		}
		if(p==a.size()) cout<<"T"<<endl;
		else cout<<"F"<<endl;
	}
	return 0;
}
