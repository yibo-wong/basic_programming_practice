#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
	long long int t;
	long long int x;
}a[1050];
bool cmp(node p,node q)
{
	return p.t<q.t;
}
long long int timen[1050];
long long int ti[1050];
long long int tot=0;
long long int total=0;
long long int final;
bool cmp2(node p,node q)
{
	return p.x<q.x;
}
int cases;
long long int n,m,b;
long long int temp=0;
int main()
{
	cin>>cases;
	for(int  w=1;w<=cases;w++)
	{
		cin>>n>>m>>b;
		total=0;
		for(int ww=1;ww<=n;ww++)
		{
			cin>>a[ww].t>>a[ww].x;
		}
		sort(a+1,a+n+1,cmp);
		tot=1;
		ti[1]=a[1].t;
		timen[1]=1;
		//cout<<"got so far"<<endl;
		for(int i=2;i<=n;i++)
		{
			if(a[i].t!=a[i-1].t)
			{
				tot++;
				timen[tot]=1;
				ti[tot]=a[i].t;
			 } 
			 else
			 {
			 	timen[tot]++;
			 }
		}
		temp=0;
		//cout<<"got so far1"<<endl;
		for(int i=1;i<=tot;i++)
		{
			sort(a+temp+1,a+temp+timen[i]+1,cmp2);
			//cout<<"got so far2"<<endl;
			temp+=timen[i];
			//cout<<"got so far3"<<endl;
		}
		temp=1;
		//cout<<"got so far4"<<endl;
		for(int i=1;i<=tot;i++)
		{
			if(m>=timen[i]) 
			{
				for(int j=temp;j<=temp+timen[i]-1;j++)
					total+=a[j].x;
			}
			else
			{
				for(int j=temp+timen[i]-m;j<=temp+timen[i]-1;j++)
					total+=a[j].x;
			}
			
			//cout<<"ttt"<<total<<endl;
			temp+=timen[i];
			if(total>=b)
			{
				final=ti[i];
				break;
			}
		}
		if(total<b) cout<<"alive"<<endl;
		else cout<<final<<endl;
	}
	return 0;
}
