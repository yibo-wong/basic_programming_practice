#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int a[10][10],temp[10];
struct ans
{
	int p[10][10];
}q[100];
int ansnum,cnt;
bool check_row(int k)
{
	memset(temp,0,sizeof(temp));
	for(int j=1;j<=9;j++)
	{
		temp[a[k][j]]++;
	}
	for(int j=1;j<=9;j++)
	{
		if(temp[j]>1) return false;
	}
	return true;
}
bool check_col(int k)
{
	memset(temp,0,sizeof(temp));
	for(int j=1;j<=9;j++)
	{
		temp[a[j][k]]++;
	}
	for(int j=1;j<=9;j++)
	{
		if(temp[j]>1) return false;
	}
	return true;
}
bool check_block(int ix,int iy)
{
	memset(temp,0,sizeof(temp));
	if(1<=ix&&ix<=3) ix=1;
	if(4<=ix&&ix<=6) ix=4;
	if(7<=ix&&ix<=9) ix=7;
	if(1<=iy&&iy<=3) iy=1;
	if(4<=iy&&iy<=6) iy=4;
	if(7<=iy&&iy<=9) iy=7;
	for(int i=ix;i<=ix+2;i++)
	{
		for(int j=iy;j<=iy+2;j++)
		{
			temp[a[i][j]]++;
		}
	}
	for(int j=1;j<=9;j++)
	{
		if(temp[j]>1) return false;
	}
	return true;
}
int next_x(int s,int t)
{
	if(t==9) return s+1;
	else return s;
}
int next_y(int s,int t)
{
	if(t==9) return 1;
	else return t+1;
}
void dfs(int ix,int iy)
{
	if(cnt==81)
	{
	ansnum++;
	for(int ii=1;ii<=9;ii++)
		for(int iii=1;iii<=9;iii++)
		{
			q[ansnum].p[ii][iii]=a[ii][iii];
		}
		return;
	}
	if(a[ix][iy]!=0)
	{
		cnt++;
		dfs(next_x(ix,iy),next_y(ix,iy));
		cnt--;
	}
	else
	{
		for(int i=1;i<=9;i++)
		{
			a[ix][iy]=i;
			if(check_row(ix)&&check_col(iy)&&check_block(ix,iy))
			{
				cnt++;
				dfs(next_x(ix,iy),next_y(ix,iy));
				cnt--;
				a[ix][iy]=0;
			}
			a[ix][iy]=0;
		}
	}
}
void putin()
{
	char aa[10];
	for(int i=1;i<=9;i++)
	{
		cin>>aa;
		for(int j=0;j<9;j++)
		{
			a[i][j+1]=aa[j]-'0';
		}
	}
}
int main()
{
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=9;j++)
		{
			cin>>a[i][j];
		}
	}
	cnt=0;ansnum=0;
	dfs(1,1);
	for(int i=1;i<=ansnum;i++)
	{
		for(int ii=1;ii<=9;ii++)
		{
			for(int jj=1;jj<=9;jj++)
			{
				cout<<q[i].p[ii][jj]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}
