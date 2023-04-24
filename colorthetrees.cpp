#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int n,r,v1,v2;
int c[1050];
vector <int> q[1050];
struct node
{
	int big,cost,size;
	double rate;
}a[1050];
bool cmp(node a,node b){
	return a.rate>b.rate;
}
int fbig(int x)
{
	if(q[x].size()==0)
	{
		a[x].big=c[x];
		return c[x];
	} 
	else
	{
		int sum=0;
		for(int i=0;i<q[x].size();i++)
		{
			sum+=fbig(q[x][i]);
		}
		sum+=c[x];
		a[x].big=sum;
		return sum;
	}
}
int fsize(int x)
{
	if(q[x].size()==0)
	{
		a[x].size=1;
		return 1;
	} 
	else
	{
		int sum=0;
		for(int i=0;i<q[x].size();i++)
		{
			sum+=fsize(q[x][i]);
		}
		sum+=1;
		a[x].size=sum;
		return sum;
	}
}
int mincost(int x)
{
	node tmp[1050];
	if(q[x].size()==0)
	{
		a[x].cost=c[x];
		return c[x];
	}
	else
	{
		cout<<"in function "<<x<<endl;
		for(int i=0;i<q[x].size();i++)
		{
			tmp[i].cost=mincost(q[x][i]);
			cout<<x<<" cost "<<tmp[i].cost<<endl;
			tmp[i].size= i==0 ? 1 : a[q[x][i-1]].size;
			tmp[i].big=a[q[x][i]].big;
			tmp[i].rate=1.0*tmp[i].size/tmp[i].big;
			
		}
		//for(int i=0;i<q[x].size();i++) cout<<tmp[i].big<<" "<<tmp[i].size<<" "<<tmp[i].rate<<" "<<tmp[i].cost<<endl;
		sort(tmp,tmp+q[x].size(),cmp);
		
		
		for(int i=0;i<q[x].size();i++) cout<<tmp[i].big<<" "<<tmp[i].size<<" "<<tmp[i].rate<<" "<<tmp[i].cost<<endl;
		
		
		int sum1=0,sum2=0,t=0,sum=0;
		for(int i=0;i<q[x].size();i++)
		{
			t+=tmp[i].size;
			sum1+=tmp[i].big*t;
			sum2+=tmp[i].cost;
			
		}
		cout<<sum1<<" "<<sum2<<endl;
		sum=sum1+sum2;
		sum+=c[x];
		a[x].cost=sum;
		cout<<x<<" return "<<sum<<endl;
		cout<<"out function"<<endl;
		return sum;
	}
}

int main()
{
	while(true)
	{
		cin>>n>>r;
		if(n==0 && r==0) return 0;
		for(int i=1;i<=n;i++) cin>>c[i];
		for(int i=1;i<n;i++)
		{
			cin>>v1>>v2;
			q[v1].push_back(v2);
		}
		int whatever=fbig(r);
		whatever=fsize(r);
		whatever=mincost(r);
		for(int i=1;i<=n;i++) cout<<a[i].big<<" "<<a[i].cost<<" "<<a[i].size<<endl;
		cout<<whatever<<endl;
	}
}

