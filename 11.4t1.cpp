#include <iostream>
#include <cstring>
using namespace std;
int m,n;
int p,num;
int count;
int b[305];
int main()
{
	while(true)
	{
		cin>>n>>m;
		if(m==0&&n==0) return 0;
		memset(b,0,sizeof(b));
		num=0;
		count=0;
		while(count<n)
		{
			for(int i=1;i<=n;i++)
			{
				if(b[i]==0)
				{
					num++;
				}
				if(num==m)
				{
					b[i]=1;
					count++;
					num=0;
					p=i;
				}
			}
		}
		cout<<p<<endl;	
	}	
}
