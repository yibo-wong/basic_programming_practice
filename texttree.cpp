#include <iostream>
#include <cstring>
#include <string>
#include <deque>
#define maxn 100
using namespace std;
int casenum;
int lchild[maxn], rchild[maxn];
char a[maxn];
deque<string>q;
int make()
{
	if (q.empty()) return -1;
	int root = q.front()[q.front().size() - 1] - 'A';
	//cout << q.front() << " " << root << endl;
	int len = q.front().size();
	q.pop_front();
	if (root == '*' - 'A') return -1;
	else if (q.empty())
	{
		lchild[root] = -1;
		rchild[root] = -1;
		return root;
	}
	else if (q.front().size() <= len)
	{
		lchild[root] = -1;
		rchild[root] = -1;
		return root;
	}
	else
	{
		lchild[root] = make();
		rchild[root] = make();
		return root;
	}
}
void pre(int i)
{
	if (i == -1) return;
	cout << char(i + 'A');
	pre(lchild[i]);
	pre(rchild[i]);
}
void mid(int i)
{
	if (i == -1) return;
	mid(lchild[i]);
	cout << char(i + 'A');
	mid(rchild[i]);
}
void post(int i)
{
	if (i == -1) return;
	post(lchild[i]);
	post(rchild[i]);
	cout << char(i + 'A');
}
int main()
{
	string tmp;
	cin >> casenum;
	while (casenum--)
	{
		q.clear();
		while (cin >> tmp)
		{
			if (tmp == "0") break;
			q.push_back(tmp);
		}
		int r = q.front()[q.front().size() - 1] - 'A';
		make();
		//for (int i = 0; i <= 10; i++) cout << "tree " << lchild[i] << " " << rchild[i] << endl;
		pre(r); cout << endl;
		post(r); cout << endl;
		mid(r); cout << endl << endl;
	}
	return 0;
}
