#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[10000];
int main()
{
	int p;
	int temp;
	int counter=0;
	int i=0;
	int le,ri;
	cin>>p;
	while(scanf("%d",temp)!=EOF)
	{
		i++;
		a[i]=temp;
	}
	sort(a,a+i+2);
	le=1;
	ri=i;
	while(le<=ri)
	{
		if(p>=a[le])
		{
			p-=a[le];
			le++;
			counter++;
		}
		else
		{
			p+=a[ri];
			ri--;
			counter--;
		}
		if(counter<=0)
		{
			counter=0;
			break;
		}
	}
	cout<<counter;
	return 0;
}
