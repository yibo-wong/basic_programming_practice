#include <iostream>
using namespace std;
int x[15][15];
int p[15];
int a[15];
int b[30];
int c[30];
int n,tot=0;
int m,pp;
int test[100];
bool flag;
int temp=0;
bool final;
void print()
{
	temp++;
	if(pp>m) return;
	if(temp==test[pp])
	{
		pp++;
		for(int i=1;i<=n;i++)
		{
			cout<<p[i];
		}
		cout<<endl;
	}
}
void dfs(int i)
{
	if(i==n)
	{
		//cout<<"finally"<<endl;
		
		for(int j=1;j<=n;j++)
		{
			//cout<<a[j]==0&&b[i+j]==0&&c[i-j+15]<<endl;
			if(a[j]==0&&b[i+j]==0&&c[i-j+15]==0)
			{
				final=true;
				//cout<<"fi...finally"<<endl;
				tot++;
				p[n]=j;
				print();
				return;
			}
		}
	}
	for(int j=1;j<=n;j++)
	{
		//flag=false;
		if(a[j]==0&&b[i+j]==0&&c[i-j+15]==0)
		{
			//flag=true;
			p[i]=j;
			a[j]=1;
			b[i+j]=1;
			c[i-j+15]=1;
			//cout<<"gothere"<<endl;
			dfs(i+1);
			p[i]=0;
			a[j]=0;
			b[i+j]=0;
			c[i-j+15]=0;
		}
		//if(flag==false) return;
	}
}
int main()
{
	cin>>m;
	//int test[100];
	n=8;
	//int temp=0;
	pp=1;
	for(int i=1;i<=m;i++) cin>>test[i];
	dfs(1);
	return 0;
}
