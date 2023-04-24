#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
bool cmp(int xx,int yy)
{
	return xx>yy;
}
struct node
{
	int t[50];
	int x;
	//int all;
	//int px,py;
	//int num;
}a[1000][1000];
int all[10000];
bool flag;
struct p
{
	int px,py;
}b[10000];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int w[10000];
int tot;
int cnt1,cnt2;
int main()
{
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j].x;
			b[a[i][j].x].px=i;
			b[a[i][j].x].py=j;
		}
	}
	int k=1;
	while((scanf("%d",&w[k]))!=EOF) k++;
	k--;
	tot=k/(m*n);
	//cout<<tot<<"yyy"<<k<<endl;
	for(int i=0;i<k;i+=tot)
	{
		all[i/tot]=0;
		for(int j=1;j<=tot;j++) 
		{
			a[b[i/tot].px][b[i/tot].py].t[j]=w[i+j];
			all[i/tot]+=w[i+j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int q=0;q<=3;q++)
			{
				if(i+dx[q]>=1&&i+dx[q]<=m&&j+dy[q]>=1&&j+dy[q]<=n)
				{
					flag=1;
					for(int qq=1;qq<=tot;qq++)
					{
						if(a[i][j].t[qq]!=a[i+dx[q]][j+dy[q]].t[qq])
						{
							//cout<<"ppp "<<i<<" "<<j<<endl;
							flag=0;break;
						}
					}
					if(flag)
					{
						cnt1++;
						break;
					}
				}
				
			}
		}
	}
	cout<<cnt1<<" ";
	sort(all,all+m*n,cmp);
	int temp=m*n*4/10;
	//cout<<"ooo"<<temp<<endl;
	if(all[temp-1]!=all[temp]) cout<<temp<<endl;
	else
	{
		int p=temp-1;int r=1;
		while(all[p]==all[p-1]&&p>=1)
		{
			r++;p--;
		}
		cout<<temp-r<<endl;
	}
	//for(int i=0;i<m*n;i++) cout<<all[i]<<" ";
	return 0;
}
