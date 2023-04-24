#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int a, v;
vector<int>point[100];
int pre[100];
bool used[100];
vector<int>q;
vector<int>tmp;
void dfs(int s)
{
	if (pre[s] == 0)
	{
		used[s] = 1;
		cout << "v" << s << " ";
		for (int i = 0; i < point[s].size(); i++)
		{
			pre[point[s][i]]--;
		}
		for (int i = 0; i < point[s].size(); i++)
		{
			if (pre[point[s][i]] == 0 && used[point[s][i]] == 0)
			{
				used[point[s][i]] = 1;
				dfs(point[s][i]);
			}
		}

	}
}
int main()
{
	cin >> v >> a;
	int p, q;
	for (int i = 1; i <= a; i++)
	{
		cin >> p >> q;
		point[p].push_back(q);
		pre[q]++;
	}
	for (int i = 1; i <= v; i++)
		if (pre[i] == 0)
			tmp.push_back(i);
	for (int i = 0; i < tmp.size(); i++)
		dfs(tmp[i]);
	return 0;
}
