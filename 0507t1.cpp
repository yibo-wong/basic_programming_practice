#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int a,b,d;
bool flag;
bool is_end;
int main()
{
	while(cin>>a>>b>>d)
	{
		if(a==0 && b==0 && d==0) return 0;
		int tmp1=max(a,b);
		int tmp2=min(a,b);
		if(tmp1==a) flag=1;
		else flag=0;
		a=tmp1;b=tmp2;
		is_end=0;
		for(int i=1;;i++)
		{
			if(i*a<d) continue;
			for(int j=0;j<=i;j++)
			{
				if(j*a+(i-j)*b==d)
				{
					if(flag) cout<<j<<" "<<i-j<<endl;
					else cout<<i-j<<" "<<j<<endl;
					is_end=1;break;
				}
				else if(abs(j*a-(i-j)*b)==d)
				{
					if(flag) cout<<j<<" "<<i-j<<endl;
					else cout<<i-j<<" "<<j<<endl;
					is_end=1;break;
				}
			}
			if(is_end) break;
		}
	}
}
