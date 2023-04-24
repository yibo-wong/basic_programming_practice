#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,stk=0;
vector <char> q;
void dfs(int depth)
{
	if(depth==2*n)
	{
		if(stk) return;
		else
		{
			for(int i=0;i<2*n;i++) cout<<q[i];
			cout<<endl;
			return;
		}
	}
	if(stk==0)
	{
		q.push_back('(');
		stk++;
		dfs(depth+1);
		stk--;
		q.pop_back();
	}
	else
	{
		q.push_back('(');
		stk++;
		dfs(depth+1);
		stk--;
		q.pop_back();
		
		q.push_back(')');
		stk--;
		dfs(depth+1);
		stk++;
		q.pop_back();
	}
}
int main()
{
	cin>>n;
	dfs(0);
	return 0;
}
