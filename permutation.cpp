#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;
int x[20],n,k;
int temp[20];
int p=0;
void print()
{
	for(int i=0;i<k;i++) cout<<temp[i]<<" ";
	cout<<endl;
}

void rule(int leftnum,int start,int end)
{
    if(leftnum==0)
	{
		print();
		return;
	}
    for(int i=start;i<=end;i++)
	{
        temp[p]=x[i];
        p++;
        rule(leftnum-1,i+1,end);
        p--;
    }
    return;
}
int main()
{
    cin>>n>>k;
    for(int i =0;i<n;i++)x[i]=rand();
    rule(k,0,n-1);
    return 0;
}
