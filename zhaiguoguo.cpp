#include <iostream>
#include <algorithm>
using namespace std;
int a[20050];
bool b[20050];
int main()
{
	int n;
	int i;
	int tot=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=1;
	}
	for(int i=n;i<=2*n;i++) b[i]=1;
	sort(a+1,a+n+1);
	for(int j=1;j<=n-1;j++)
	{
		i=0;
		for(i=1;;i++)
		{
			if(b[i]==1) break;
		}
		//cout<<i<<endl;
		tot+=a[i];
		tot+=a[i+1];
		a[i+1]+=a[i];
		//cout<<" "<<a[i+1]<<endl;
		//cout<<"   "<<tot<<endl;
		b[i]=0;
		for(int k=i+1;k<=n-1;k++)
		{
			if(a[k]>a[k+1]) swap(a[k],a[k+1]);
			else break;
		}
		//for(int y=1;y<=2*n;y++) cout<<a[y]*b[y]<<" ";
		//cout<<endl;
	}
	cout<<tot;
	return 0;
}
