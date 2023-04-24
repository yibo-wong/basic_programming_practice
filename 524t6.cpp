#include <iostream>
#include <cstring>
using namespace std;
int n,m;
int fa[50050];
void ini()
{
	for(int i=1;i<=m;i++)
	{
		fa[i]=i;
	}
}
int got(int i)
{
	if(fa[i]==i) return i;
	return fa[i]=got(fa[i]);
}
void merge(int i,int j)
{
	fa[got(i)]=got(j);
}
bool same(int i,int j)
{
	return got(i)==got(j);
}
int a[20050];
bool count[50050];
int main()
{
	scanf("%d%d",&n,&m);
	int tmp;
	ini();
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&tmp);
		for(int j=1;j<=tmp;j++)
		{
			scanf("%d",&a[j]);
			//cout<<"get"<<endl;
		}
		for(int j=2;j<=tmp;j++)
		{
			merge(a[j-1],a[j]);
			//cout<<"got"<<endl;
		}
	}
	int sum=0;
	for(int i=1;i<=m;i++)
	{
//		cout<<fa[i]<<endl;
//		cout<<i<<" "<<got(i)<<endl;
		if(count[got(i)]==0)
		{
			count[got(i)]=1;
			sum++;
		}
	}
	cout<<sum-1<<endl;
	return 0;
}
