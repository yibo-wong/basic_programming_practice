#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n,p1,p2,q1,q2;
int a[1050],b[1050];
bool s[1050];
int win,lose;
int main()
{
	while(1)
	{
		cin>>n;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(s,0,sizeof(s));
		win=0;lose=0;
		p1=n;q1=1;p2=n;q2=1;//p max,q min
		if(n==0) return 0;
		for(int i=1;i<=n;i++) cin>>a[i];//tian
		for(int i=1;i<=n;i++) cin>>b[i];//king
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		for(int i=1;i<=n;i++)
		{
			if(a[p1]>b[p2])
			{
				win++;
				p1--;p2--;
			}
			else if(a[p1]<b[p2])
			{
				lose++;
				q1++;p2--;
			}
			else
			{
				if(a[q1]>b[q2])
				{
					win++;
					q1++;q2++;
				}
				else if(a[q1]<b[q2])
				{
					lose++;
					q1++;p2--;
				}
				else
				{
					if(a[q1]<b[p2]) lose++;
					q1++;p2--;
				}
			}
		}
		cout<<(win-lose)*200<<endl;
	}
}
