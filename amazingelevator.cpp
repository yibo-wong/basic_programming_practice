#include <iostream>
using namespace std;
int road[210];
int a[1000],b[1000];
bool s[210];
bool flag=false;
int n,r,t;
int tot=0;
void out(int d)
{
	if(d==1) cout<<tot<<endl;
	else
	{
		tot++;
		out(b[d]);
	}
}
void bfs()
{
	int head,tail,i;
	head=0;tail=1;
	a[1]=r;
	b[1]=0;
	s[r]=1;
	do
	{
		head++;
		for(i=-1;i<=1;i+=2)
		{
			if((a[head]+i*road[a[head]]>=1)&&(a[head]+i*road[a[head]]<=n)&&s[a[head]+i*road[a[head]]]==0)
			{
				tail++;
				//cout<<"iii"<<a[head]<<" "<<a[tail]<<endl;
				a[tail]=a[head]+i*road[a[head]];
				//cout<<"iii"<<a[head]<<" "<<a[tail]<<endl;
				b[tail]=head;
				s[a[head]+i*road[a[head]]]=1;
				if(a[head]+i*road[a[head]]==t)
				{
					//cout<<"gothere"<<endl;
					//cout<<tail<<" "<<b[tail]<<endl;
					out(tail);
					flag=1;
					head=tail;
					break;
				}
			}
		}
	}while(head<tail);
}
int main()
{
	cin>>n>>r>>t;
	if(r==t)
	{
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>road[i];
	flag=false;
	bfs();
	if(flag==false) cout<<-1;
	return 0;
}
