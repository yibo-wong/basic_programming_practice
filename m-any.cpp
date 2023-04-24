#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int m;
string a,b;
int f(int n)
{
	if(n==1) return 1;
	return n*f(n-1);
}
int c(int i,int j)//C_i^j
{
	int ans=1;
	for(int ii=i-j+1;ii<=i;ii++) ans*=ii;
	return ans/f(j);
}
int calc(int n1,int n2,int len)
{
	//cout<<n1<<" "<<n2<<" "<<len<<endl;
	if(len==1) return 1;
	int pre=0;
	int post=n2-1;
	pre=n1+1;
	int result=1;
	int sum=0;
	while(true)
	{
		int tmp=b.find(a[pre]);
		result*=calc(pre,post+1,tmp-post);
		pre+=tmp-post;
		post=tmp;
		sum++;
		if(pre>n1+len-1) break;
	}
	result*=c(m,sum);
	return result;
}
int main()
{
	while(cin>>m)
	{
		if(m==0) return 0;
		cin>>a>>b;
		cout<<calc(0,0,a.size())<<endl;;
	}
	return 0;
}
