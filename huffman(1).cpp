#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<int>a,b;
int n,x,y;
int tmp;
int main()
{
	cin>>n;
	tmp=0;
	while(n--)
	{
		cin>>x;
		if(x==1)
		{
			cin>>y;
			if(y>=tmp)
			{
				b.push_back(y);
				tmp=y;
			}
			a.push_back(y);
		}
		else if(x==2 && (!a.empty()))
		{
			if(a.back()==b.back())
			{
				a.pop_back();
				b.pop_back();
				if(b.size()) tmp=b.back();
				else tmp=0;
			}
			else
			{
				a.pop_back();
			}
		}
		else if(x==3)
		{
			cout<<"ans "<<tmp<<endl;
		}
	}
	return 0;
}
