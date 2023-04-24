#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int flip[10];
int sum=0,tmp;
int a[4][4],a_0[4][4];
bool ok()
{
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			if(a[i][j]!=0) return false;
		}
	}
	return true;
}
void change(int& x,const int y)
{
	x=(x+y)%4;
}
int main()
{
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>a_0[i][j];
		}
	}
	tmp=1<<8;
	int n,y;
	
	for(int i=0;i< 1<<19;i++)
	{
		for(int ii=1;ii<=3;ii++)
			for(int jj=1;jj<=3;jj++)
				a[ii][jj]=a_0[ii][jj];
		
		//int n;
		sum=0;
		y=0;
		n=(((i>>(y+1))&1)<<1)+((i>>y)&1);
		change(a[1][1],n);
		change(a[1][2],n);
		change(a[2][1],n);
		change(a[2][2],n);
		//cout<<n<<endl;
		sum+=n;
		
		y+=2;
		n=(((i>>(y+1))&1)<<1)+((i>>y)&1);
		change(a[1][1],n);
		change(a[1][2],n);
		change(a[1][3],n);
		//cout<<n<<endl;
		sum+=n;
		
		y+=2;
		n=(((i>>(y+1))&1)<<1)+((i>>y)&1);
		change(a[1][3],n);
		change(a[1][2],n);
		change(a[2][2],n);
		change(a[2][3],n);
		//cout<<n<<endl;
		sum+=n;
		
		y+=2;
		n=(((i>>(y+1))&1)<<1)+((i>>y)&1);
		change(a[1][1],n);
		change(a[2][1],n);
		change(a[3][1],n);
		sum+=n;
		
		y+=2;
		n=(((i>>(y+1))&1)<<1)+((i>>y)&1);
		change(a[1][2],n);
		change(a[2][1],n);
		change(a[2][2],n);
		change(a[2][3],n);
		change(a[3][2],n);
		sum+=n;
		
		
		y+=2;
		n=(((i>>(y+1))&1)<<1)+((i>>y)&1);
		change(a[1][3],n);
		change(a[2][3],n);
		change(a[3][3],n);
		sum+=n;
		
		y+=2;
		n=(((i>>(y+1))&1)<<1)+((i>>y)&1);
		change(a[3][1],n);
		change(a[3][2],n);
		change(a[2][1],n);
		change(a[2][2],n);
		sum+=n;
		
		y+=2;
		n=(((i>>(y+1))&1)<<1)+((i>>y)&1);
		change(a[3][1],n);
		change(a[3][2],n);
		change(a[3][3],n);
		sum+=n;
		
		y+=2;
		n=(((i>>(y+1))&1)<<1)+((i>>y)&1);
		change(a[2][2],n);
		change(a[2][3],n);
		change(a[3][2],n);
		change(a[3][3],n);
		sum+=n;
		
		if(ok())
		{
			//cout<<"sum "<<sum<<endl;
			if(sum<tmp)
			{
				tmp=sum;
				for(int ii=1;ii<=9;ii++)
				{
					flip[ii]=(((i>>(2*ii-1))&1)<<1)+((i>>(2*ii-2))&1);
				}
			}
		}
	}
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=flip[i];j++)
		{
			cout<<i<<" ";
		}
	}
	return 0;
}
