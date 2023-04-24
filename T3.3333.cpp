#include <iostream>
#include <cstring>
using namespace std;
char a[9];
int w,c,y,m,d;
int temp;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		for(int j=0;j<8;j++)
		{
			a[j]-=48;
		}
		c=10*a[0]+a[1];
		y=10*a[2]+a[3];
		m=10*a[4]+a[5];
		d=10*a[6]+a[7];
		if(m==1)
		{
			m=13;
			if(y==0)
			{
				y=99;
				c--;
			}
			else
			{
				y--;
			}
		}
		if(m==2)
		{
			m=14;
			if(y==0)
			{
				y=99;
				c--;
			}
			else
			{
				y--;
			}
		}
		w=y+y/4;
		w+=c/4;
		w-=2*c;
		temp=(26*(m+1))/10;
		w+=temp;
		w+=d;
		w--;
		w=w%7;
		if(w<0) w+=7;
		if(w==0) cout<<"Sunday"<<endl;
		if(w==1) cout<<"Monday"<<endl;
		if(w==2) cout<<"Tuesday"<<endl;
		if(w==3) cout<<"Wednesday"<<endl;
		if(w==4) cout<<"Thursday"<<endl;
		if(w==5) cout<<"Friday"<<endl;
		if(w==6) cout<<"Saturday"<<endl;
	}
	return 0;
}
