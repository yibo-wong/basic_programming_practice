#include <iostream>
using namespace std;
int a[10000];
int n;
void qsort(int s,int t)
{
	int mid=(s+t)/2;
	int le=s;
	int ri=t;
	int p;
	do
	{
		while(a[le]<a[mid]) le++;
		while(a[ri]>a[mid]) ri--;
		if(le<=ri)
		{
			p=a[le];a[le]=a[ri];a[ri]=p;
			le++;ri--;
		}
	}while(le<=ri);
	cout<<mid<<"=mid ";
	cout<<le<<"=le ";
	cout<<ri<<"=ri    ";
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	if(s<ri) qsort(s,ri);
	if(le<t) qsort(le,t);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	qsort(1,n);
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	return 0;
}
