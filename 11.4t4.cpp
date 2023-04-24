#include <iostream>
using namespace std;
int m;
long long int n1,n2,n3,n4;
int a1[17]={0,1,1,1,1,1,1,1,1,-1,-1,-1,-1,-1,-1,-1,-1};
int a2[17]={0,1,1,1,1,-1,-1,-1,-1,1,1,1,1,-1,-1,-1,-1};
int a3[17]={0,1,1,-1,-1,1,1,-1,-1,1,1,-1,-1,1,1,-1,-1};
int a4[17]={0,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1};
long long int tot;
bool flag;
int main()
{
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>n1>>n2>>n3>>n4;
		flag=false;
		for(int j=1;j<=16;j++)
		{
			tot=a1[j]*n1+a2[j]*n2+a3[j]*n3+a4[j]*n4;
			if(tot==24)
			{
				cout<<"YES"<<endl;
				flag=true;
				break;
			}
		}
		if(flag==false) cout<<"NO"<<endl;
	}
	return 0;
}
