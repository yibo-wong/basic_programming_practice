#include <iostream>
using namespace std;
struct node
{
	int left;
	int right;
}b[103];
int x[103];
int len;
int m;
int counter=0;
int main()
{
	cin>>len>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>b[i].left>>b[i].right;
	}
	for(int i=2;i<=m;i++)
	{
		for(int j=1;j<=i-1;j++)
		{
			if(x[j]==0)
			{
			if(b[j].left<=b[i].left&&b[j].right>=b[i].right)
			{
				b[i].left=b[j].left;
				b[i].right=b[j].right;
				x[j]=1;
				continue;
			}
			if(b[j].left>=b[i].left&&b[j].right<=b[i].right)
			{
				x[j]=1;
				continue;
			}
			if(b[j].left<=b[i].left&&b[j].right<=b[i].right&&b[j].right>=b[i].left)
			{
				b[i].left=b[j].left;
				x[j]=1;
				continue;
			}
			if(b[j].left>=b[i].left&&b[j].right>=b[i].right&&b[j].left<=b[i].right)
			{
				b[i].right=b[j].right;
				x[j]=1;
				continue;
			}	
			}
		}
	}
	int counter=0;
	int temp;
	for(int i=1;i<=m;i++)
	{
		if(x[i]==0)
		{
			temp=b[i].right-b[i].left+1;
			counter+=temp;
			//cout<<i<<" "<<b[i].left<<" "<<b[i].right<<endl;
		}
	}
	int finally=len+1-counter;
	cout<<finally;
	return 0;
}
