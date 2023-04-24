#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
struct node
{
	int data;
	node* le;
	node* ri;
};
typedef struct node* tree;
void crt(tree& p)
{
	int n;
	cin >> n;
	if (n == -1)
	{
		p = NULL;
		return;
	}
	else
	{
		p = new node;
		p->data = n;
		crt(p->le);
		crt(p->ri);
	}
}
void mid(tree p)
{
	vector<tree>q;
	tree tmp = p;
	while (!q.empty() || tmp)
	{
		if (tmp)
		{
			q.push_back(tmp);
			tmp = tmp->le;
		}
		else
		{
			tmp = q.back();
			q.pop_back();
			cout << (tmp->data) << " ";
			tmp = tmp->ri;
		}
	}
	cout << endl;
}
void mid_trd(tree p)
{
	if (p == NULL) return;
	mid_trd(p->le);
	cout << p->data << " ";
	mid_trd(p->ri);
}
void pre(tree p)
{
	vector<tree>q;
	tree tmp = p;
	while (!q.empty() || tmp)
	{
		if (tmp)
		{
			cout << (tmp->data) << " ";
			q.push_back(tmp);
			tmp = tmp->le;
		}
		else
		{
			tmp = q.back();
			q.pop_back();
			tmp = tmp->ri;
		}
	}
	cout << endl;
}
void pre_trd(tree p)
{
	if (p == NULL) return;
	cout << p->data << " ";
	pre_trd(p->le);
	pre_trd(p->ri);
}
void post(tree p)
{
	vector<tree>q;
	tree tmp = p;
	tree pre = NULL;
	bool flag = 0;
	while(tmp)
	{
		while(tmp)
		{
			q.push_back(tmp);
			tmp = tmp->le;
		}
		flag = 1;
		while (!q.empty() && flag == 1)
		{
			tmp = q.back();
			if (tmp->ri == NULL || tmp->ri == pre)
			{
				pre = tmp;
				cout << tmp->data << " ";
				q.pop_back();
			}
			else
			{
				tmp = tmp->ri;
				flag = 0;
				break;
			}
		}
		if (q.empty()) break;
	}
	cout << endl;
}
void post_trd(tree p)
{
	if (p == NULL) return;
	post_trd(p->le);
	post_trd(p->ri);
	cout << p->data << " ";
}
int main()
{
	tree bt;
	crt(bt);
	mid(bt); mid_trd(bt); cout << endl;
	pre(bt); pre_trd(bt); cout << endl;
	post(bt); post_trd(bt); cout << endl;
	return 0;
}
