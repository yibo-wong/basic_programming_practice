#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int n;
bool s;
int a[1050];
vector<int>q;
vector<int>res;
int main()
{
	s=0;
	while(cin>>n)
	{
		if(n==0) return 0;
		while(cin>>a[1])
		{
			if(a[1]==0) break;
			for(int i=2;i<=n;i++) cin>>a[i];
			q.clear();
			res.clear();
			int k=1;
			for(int i=1;i<=n;i++)
			{
				q.push_back(i);
				while(1)
				{
					if(!q.empty())
					{
						if(q.back()==a[k])
						{
							q.pop_back();k++;
						}
					}
					if(q.empty()) break;
					else if(q.back()!=a[k]) break;
				}
			}
			if(k==n+1) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
		cout<<endl;
	}
}
