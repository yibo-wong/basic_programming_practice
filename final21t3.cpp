#include <iostream>
#include <vector>
using namespace std;
vector<int>a[110];
int n,type,x,y;
int main()
{
	cin>>n;
	while(n--)
	{
		cin>>type;
		if(type==1)
		{
			cin>>x>>y;
			a[x].push_back(y);
		}
		else if(type==2)
		{
			cin>>x;
			if(a[x].empty()) cout<<"-1"<<endl;
			else
			{
				cout<<a[x].back()<<endl;
				a[x].pop_back();
			}
		}
		else
		{
			cin>>x>>y;
			if(a[x].empty()) cout<<"-1"<<endl;
			else
			{
				a[y].push_back(a[x].back());
				cout<<a[x].back()<<endl;
				a[x].pop_back();
			}
		}
	}
	return 0;
}
