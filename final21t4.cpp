#include <iostream>
#include <cstring>
using namespace std;
int a[2100],le[2100],ri[2100];
void pre(int i)
{
	if(i==0) return;
	pre(le[i]);
	pre(ri[i]);
	cout<<a[i]<<" ";
}
int main()
{
	int n;
	int num;
	int i=0;
	cin>>num;
	while(num--)
	{
		cin>>n;
		i++;a[i]=n;
		if(i==1) continue;
		int q=1;
		while(1)
		{
			if(n==a[q]) break;
			if(n<a[q] && le[q]==0)
			{
				le[q]=i;
				break;
			}
			if(n>a[q] && ri[q]==0)
			{
				ri[q]=i;
				break;
			}
			if(n<a[q] && le[q]!=0)
			{
				q=le[q];
			}
			if(n>a[q] && ri[q]!=0)
			{
				q=ri[q];
			}
		}
	}
	pre(1);
	return 0;
}
