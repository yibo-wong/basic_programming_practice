#include <iostream>
using namespace std;
int main()
{
	int n;cin>>n;
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=n;j++)
		{
			for(int k=j;k<=n;k++)
			{
				for(int s=k;s<=n;s++)
				{
					if(i*i*i==j*j*j+k*k*k+s*s*s) 
						cout<<"Cube = "<<i<<", Triple = ("<<j<<","<<k<<","<<s<<")"<<endl;
				}
			}
		}
	}
	return 0;
}
