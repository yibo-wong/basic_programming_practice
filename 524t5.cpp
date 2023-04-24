#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define eps 1e-7
using namespace std;
double le[4],ri[4];
int rootnum;
double a,b,c,d;
double f(double x)
{
	return a*x*x*x+b*x*x+c*x+d;
}
void make()
{
	double num[660];
	int cur=0;
	num[0]=f(-102);
	rootnum=0;
	for(double i=-101;i<=101;i+=0.3333)
	{
		cur++;
		//cout<<i<<" "<<f(i)<<endl;
		num[cur]=f(i);
		if((num[cur-1]<=0 && num[cur]>=0) || num[cur-1]>=0 && num[cur]<=0)
		{
			rootnum++;
			le[rootnum]=i-0.3333;
			ri[rootnum]=i;
		}
	}
}
bool judge(double x,bool sign)//1 for +
{
	double tmp=f(x);
	if((tmp>=0 && sign==1) || (tmp<=0 && sign==0)) return true;
	else return false;
}
int main()
{
	while(cin>>a>>b>>c>>d)
	{
		make();
		cout<<rootnum<<" ";
		for(int i=1;i<=rootnum;i++)
		{
			double nle=le[i];
			double nri=ri[i];
			bool flag= f(nri)>=0 ? 1:0;
//			cout<<"test "<<nle<<" "<<nri<<endl;
//			cout<<"flag "<<flag<<endl;
			while(nri-nle>eps)
			{
				double mid=(nri+nle)/2;
				if(judge(mid,flag)) nri=mid;
				else nle=mid;
				//cout<<judge(mid,flag)<<" "<<mid<<endl;
			}
			printf("%.6f ",nri);
		}
		printf("\n");
	}
	return 0;
}
