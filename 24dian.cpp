#include <iostream>
#include <cstring>
#include <algorithm>
#define inf 10000000
using namespace std;
double a,b,c,d;
double y1[4];
double y2[4];
double y3[4];
bool flag;
bool equal(double x,double y)
{
	if(x-y<0.001 && x-y>-0.001) return true;
	return false;
}
bool check1(double x1,double x2,double x3)//(x1*x2)*x3
{
	double a=1.0*(x1+x2);
	if(equal(a+x3,24)) return true;
	if(equal(a-x3,24)) return true;
	if(equal(a*x3,24)) return true;
	if(x3!=0)
	{
		if(equal(1.0*a/x3,24)) return true;
	}
	a=1.0*(x1+x2);
	if(equal(a+x3,24)) return true;
	if(equal(a-x3,24)) return true;
	if(equal(a*x3,24)) return true;
	if(x3!=0)
	{
		if(equal(1.0*a/x3,24)) return true;
	}
	a=1.0*(x1-x2);
	if(equal(a+x3,24)) return true;
	if(equal(a-x3,24)) return true;
	if(equal(a*x3,24)) return true;
	if(x3!=0)
	{
		if(equal(1.0*a/x3,24)) return true;
	}
	a=1.0*(x1*x2);
	if(equal(a+x3,24)) return true;
	if(equal(a-x3,24)) return true;
	if(equal(a*x3,24)) return true;
	if(x3!=0)
	{
		if(equal(1.0*a/x3,24)) return true;
	}
	if(x2!=0)
	{
		a=1.0*x1/x2;
		if(equal(a+x3,24)) return true;
		if(equal(a-x3,24)) return true;
		if(equal(a*x3,24)) return true;
		if(x3!=0)
		{
			if(equal(1.0*a/x3,24)) return true;
		}
	}
	return false;
}
bool check2(double x1,double x2,double x3)//x1*(x2*x3)
{
	double a=1.0*(x2+x3);
	if(equal(x1+a,24)) return true;
	if(equal(x1-a,24)) return true;
	if(equal(x1*a,24)) return true;
	if(a!=0)
	{
		if(equal(1.0*x1/a,24)) return true;
	}
	a=1.0*(x2+x3);
	if(equal(x1+a,24)) return true;
	if(equal(x1-a,24)) return true;
	if(equal(x1*a,24)) return true;
	if(a!=0)
	{
		if(equal(1.0*x1/a,24)) return true;
	}
	a=1.0*(x2+x3);
	if(equal(x1+a,24)) return true;
	if(equal(x1-a,24)) return true;
	if(equal(x1*a,24)) return true;
	if(a!=0)
	{
		if(equal(1.0*x1/a,24)) return true;
	}
	if(x3!=0)
	{
		a=1.0*x2/x3;
		if(equal(x1+a,24)) return true;
		if(equal(x1-a,24)) return true;
		if(equal(x1*a,24)) return true;
		if(a!=0)
		{
			if(equal(1.0*x1/a,24)) return true;
		}
	}
	return false;
}
int main()
{
	while(cin>>a>>b>>c>>d)
	{
		flag=0;
		if(a==0&&b==0&&c==0&&d==0) return 0;
		a=1.00*a;
		b=1.00*b;
		c=1.00*c;
		d=1.00*d;
		y1[0]=a+b;
		y1[1]=a-b;
		y1[2]=a*b;
		if(b!=0)
		{
			y1[3]=a/b;
		}
		else
		{
			y1[3]=inf;
		}
		y2[0]=b+c;y2[1]=b-c;y2[2]=b*c;
		if(c!=0)
		{
			y2[3]=b/c;
		}
		else
		{
			y2[3]=inf;
		}
		y3[0]=c+d;y3[1]=c-d;y3[2]=c*d;
		if(d!=0)
		{
			y3[3]=c/d;
		}
		else
		{
			y3[3]=inf;
		}
		for(int i=0;i<=3;i++)
		{
			cout<<y1[i]<<" "<<y2[i]<<" "<<y3[i]<<endl;
		}
		for(int i=0;i<=3;i++)
		{
			cout<<check1(y1[i],c,d)<<" "<<check1(a,y2[i],d)<<" "<<check1(a,b,y3[i])<<endl;
		}
		for(int i=0;i<=3;i++)
		{
			cout<<check2(y1[i],c,d)<<" "<<check2(a,y2[i],d)<<" "<<check2(a,b,y3[i])<<endl;
		}
		for(int i=0;i<=3;i++)
		{
			if(y1[i]!=inf)
			{
				if(check1(y1[i],c,d)) flag=true;
				if(check2(y1[i],c,d)) flag=true;
			}
			if(y2[i]!=inf)
			{
				if(check1(a,y2[i],d)) flag=true;
				if(check2(a,y2[i],d)) flag=true;
			}
			if(y3[i]!=inf)
			{
				if(check1(a,b,y3[i])) flag=true;
				if(check2(a,b,y3[i])) flag=true;
			}
			if(flag) break;
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
