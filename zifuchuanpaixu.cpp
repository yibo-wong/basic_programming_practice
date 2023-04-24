#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
//int a[10000];
//string s;
struct node
{
	char s[10000];
	int len;
}a[10000];
bool cmp(node x,node y)
{
	return x.len<y.len;
}
int main()
{
	int n;
	while((scanf("%d",&n))!=EOF)
	{
		getchar();
		int p=0;
		for(int u=1;u<=n;u++)
		{
			p++;
			fgets(a[p].s,10000,stdin);
			if(a[p].s[0]==)
			{
				p-=2;
				cout<<"ooo"<<endl;
				break;
			}
			a[p].len=strlen(a[p].s);
		}
		sort(a+1,a+p+1,cmp);
		for(int i=1;i<=p;i++) cout<<a[i].s;
	}
	return 0;
}
