#include <iostream>
using namespace std;
int n;
int x[4]={0,1,0,-1};
int y[4]={1,0,-1,0};
char a[10000][10000];
void search(int,int);
bool flag=false;
int ha,la,hb,lb;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	cin>>ha>>la>>hb>>lb;
	search(ha,la);
	if(flag) cout<<"YES";
	else cout<<"NO";
	return 0;
}
void search(int s,int t)
{
	if(s==hb&&t==lb)
	{
		flag=true;
		return;
	}
	else
	{
		for(int i=0;i<=3;i++)
		{
			if(s+x[i]<=n&&s+x[i]>=0&&t+y[i]<=n&&t+y[i]>=0&&a[s+x[i]][t+y[i]]=='.')
			{
				a[s+x[i]][t+y[i]]='#';
				search(s+x[i],t+y[i]);
				a[s+x[i]][t+y[i]]='.';
			}
		}
	}
	
}
