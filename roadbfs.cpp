#include <iostream>
#include <cstring>
using namespace std;
int ju[9][9];
int a[101],b[101];
bool s[9];
void out(int d)
{
	cout<<char(a[d]+64);
	while(b[d])
	{
		d=b[d];
		cout<<"--"<<char(a[d]+64);
	}
	cout<<endl;
}
void doit()
{
	int head,tail,i;
	head=0;tail=1;
	a[1]=1;//a:the sequence to visit all nodes
	b[1]=0;//b:to mark the links between the nodes - though its from last to first
	s[1]=1;//to mark that the node has been visited
	do
	{
		head++;
		for(i=1;i<=8;i++)
		{
			if((ju[a[head]][i]==0)&&(s[i]==0))
			{
				tail++;
				a[tail]=i;
				b[tail]=head;
				s[i]=1;
				if(i==8)
				{
					out(tail);
					head=tail;
					break;
				}
			}
		}
	}while(head<tail);
}
	int main()
	{
		for(int i=1;i<=8;i++)
			for(int j=1;j<=8;j++)
				cin>>ju[i][j];
		memset(s,false,sizeof(s));
		doit();
		return 0;
	}
