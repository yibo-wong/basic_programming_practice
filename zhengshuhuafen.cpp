#include <iostream>
#include <algorithm>
using namespace std;
int n,k;
int tot;
void f1(int s,int t,int temp)
{
	if(t==0)
	{
		if(s==0) 
		{
			tot++;
			return;
		}
		else
			return;
	}
	if(temp>s) return;
	for(int i=temp;i<=s;i++)
	{
		//cout<<"111 "<<i<<" "<<t<<" "<<s<<endl;
		f1(s-i,t-1,i);
	}
}
void f2(int s,int temp)
{
	if(s==0)
	{
		tot++;
		return;
	}
	if(temp>=s) return;
	for(int i=temp+1;i<=s;i++)
	{
		//cout<<"222 "<<i<<" "<<temp<<endl;
		f2(s-i,i);
	}
}
void f3(int s,int temp)
{
	if(s==0)
	{
		tot++;
		return;
	}
	if(temp>s) return;
	for(int i=temp;i<=s;i++)
	{
		if(i%2==1)
		{
			//cout<<"333 "<<i<<" "<<temp<<endl;
			f3(s-i,i);
		}
	}
}
int main()
{
	cin>>n>>k;
	
	tot=0;
	f1(n,k,1);
	cout<<tot<<endl;
	tot=0;
	f2(n,0);
	cout<<tot<<endl;
	tot=0;
	f3(n,1);
	cout<<tot<<endl;

	return 0;
}
