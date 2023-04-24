#include <iostream>
#include <deque>
using namespace std;
deque<int>q;
int main()
{
	int tests,n,type,tmp;
	cin>>tests;
	while(tests--)
	{
		cin>>n;
		q.clear();
		while(n--)
		{
			cin>>type>>tmp;
			if(type==1) q.push_back(tmp);
			else if(type==2)
			{
				if(tmp==0) q.pop_front();
				else q.pop_back();
			}
		}
		if(q.size()==0) cout<<"NULL"<<endl;
		else
		{
			for(int i=0;i<q.size();i++) cout<<q[i]<<" ";
			cout<<endl;
		}
	}
	return 0;
}
