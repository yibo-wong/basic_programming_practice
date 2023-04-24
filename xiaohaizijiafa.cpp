#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
char a[105];
int w,y,c,m,d;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		c=(a[0]-'0')*10+a[1]-'0';
		y=(a[2]-'0')*10+a[3]-'0';
		m=(a[4]-'0')*10+a[5]-'0';
		d=(a[6]-'0')*10+a[7]-'0';
		if(m==1||m==2)
		{
			m+=12;
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
		w=y+y/4+c/4-2*c;
		w+=(26*(m+1))/10;
		w+=d-1;
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
