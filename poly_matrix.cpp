#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <string>
#define maxn 32
using namespace std;
inline int gcd(int m, int n)
{
	if (m < 0 || n < 0)
	{
		cerr << "negative in gcd" << endl;
		return 0;
	}
	return n > 0 ? gcd(n, m % n) : m;
}
class frac
{
public:
	int p, q;
	frac(int pp, int qq)
	{
		if (pp == 0)
		{
			p = 0; q = 1;
		}
		else
		{
			p = pp / (gcd(abs(pp), abs(qq)));
			q = qq / (gcd(abs(pp), abs(qq)));
		}
		
	}
	friend frac operator + (frac a, frac b)
	{
		return frac(a.p * b.q + a.q * b.p, a.q * b.q);
	}
	friend frac operator - (frac a, frac b)
	{
		return frac(a.p * b.q - a.q * b.p, a.q * b.q);
	}
	friend frac operator * (frac a, frac b)
	{
		return frac(a.p * b.p, a.q * b.q);
	}
	friend frac operator * (frac a, int b)
	{
		return frac(a.p * b, a.q);
	}
	friend frac operator * (int b, frac a)
	{
		return frac(a.p * b, a.q);
	}
	friend frac operator / (frac a, frac b)
	{
		if (b.p == 0)
		{
			cerr << "zero-frac in division" << endl;
			return frac(0,1);
		}
		return frac(a.p * b.q, a.q * b.p);
	}
	void print() 
	{ 
		if (q == 1) cout << "(" << p << ")";
		else cout << "(" << p << "/" << q << ")"; 
	}
	void check()
	{
		p = p / (gcd(abs(p), abs(q)));
		q = q / (gcd(abs(p), abs(q)));
		if (q < 0) { p = -p; q = -q; }
	}
};
class poly
{
public:
	vector<frac>q;
	poly()
	{
		q.clear();
	}
	int deg()
	{
		if (q.empty()) return -1;
		while (q.back().p == 0)
		{
			q.pop_back();
			if (q.empty()) break;
		}
		for (int i = 0; i < q.size(); i++) q[i].check();
		return q.size() - 1;
	}
	void print()
	{
		if (q.size() == 0) { cout << "0"; return; }
		for (int i = 0; i < q.size(); i++)
		{
			q[i].print();
			cout << " [x^" << i << "] ";
		}
	}
	friend poly operator + (poly a, poly b)
	{
		poly tmp;
		int d = max(a.deg(), b.deg());
		for (int i = 0; i <= d; i++)
		{
			if (i < a.q.size() && i < b.q.size()) 
				tmp.q.push_back(a.q[i] + b.q[i]);
			else
			{
				if (i < a.q.size()) 
					tmp.q.push_back(a.q[i]);
				else
					tmp.q.push_back(b.q[i]);
			}
		}
		tmp.deg();
		return tmp;
	}
	friend poly operator - (poly a, poly b)
	{
		poly tmp;
		int d = max(a.deg(), b.deg());
		for (int i = 0; i <= d; i++)
		{
			if (i < a.q.size() && i < b.q.size())
				tmp.q.push_back(a.q[i] - b.q[i]);
			else
			{
				if (i < a.q.size())
					tmp.q.push_back(a.q[i]);
				else
					tmp.q.push_back(frac(0,1)-b.q[i]);
			}
		}
		tmp.deg();
		return tmp;
	}
	friend poly operator * (poly a, poly b)
	{
		
		int d1 = a.deg(), d2 = b.deg();
		poly t;
		t.q.clear();
		if (a.q.size() == 0 || b.q.size() == 0)
		{
			return t;
		}
		for (int i = 0; i <= d1 + d2; i++)
		{
			frac tmp(0, 1);
			for (int j = 0; j <= i; j++)
			{
				if (j <= d1 && i - j <= d2)
				{
					tmp = tmp + a.q[j]*b.q[i - j];
				}
			}
			t.q.push_back(tmp);
		}
		t.deg();
		return t;
	}
	friend poly operator * (frac n, poly a)
	{
		a.deg();
		for (int i = 0; i < a.q.size(); i++) a.q[i] = a.q[i] * n;
		a.deg();
		return a;
	}
	void normalize()
	{
		deg();
		if (q.empty()) return;
		frac tmp = q[q.size()-1];
		q[q.size()-1] = frac(1,1);
		for (int i = 0; i < q.size() - 1; i++) { q[i] = q[i] / tmp; q[i].check(); }
	}
	friend poly div(poly p, poly r)
	{
		if (p.deg()<0) return p;
		if (r.q.empty())
		{
			cerr << "zero-poly in div" << endl;
		}
		if (p.deg() < r.deg()) return p;
		else
		{
			while (p.deg() >= r.deg())
			{
				frac coe = p.q.back() / r.q.back();
				int n = p.deg() - r.deg();
				poly t;
				for (int i = 0; i < n; i++) t.q.push_back(frac(0, 1));
				for (int i = 0; i < r.q.size(); i++) t.q.push_back(r.q[i]);
				p = p - coe * t;
			}
		}
		p.deg();
		return p;
	}
	friend bool no_rem(poly p, poly r)
	{
		if (p.deg() < 0) return true;
		if (p.deg() < r.deg()) return false;
		return div(p, r).deg() < 0;
	}
	friend poly rem(poly p, poly r)//p = rem * r + div
	{
		vector<frac>x;
		if (p.q.empty()) return p;
		if (r.q.empty())
		{
			cerr << "zero-poly in div" << endl;
		}
		if (p.deg() < r.deg()) return p;
		else
		{
			while (p.deg() >= r.deg())
			{
				frac coe = p.q.back() / r.q.back();
				x.push_back(coe);
				int n = p.deg() - r.deg();
				poly t;
				for (int i = 0; i < n; i++) t.q.push_back(frac(0, 1));
				for (int i = 0; i < r.q.size(); i++) t.q.push_back(r.q[i]);
				p = p - coe*t;
			}
		}
		poly t;
		while (!x.empty())
		{
			t.q.push_back(x.back());
			x.pop_back();
		}
		t.deg();
		return t;
	}
	void push(int a, int b=1)
	{
		q.push_back(frac(a, b));
	}
};
class poly_matrix
{
public:
	int n;
	poly* a[maxn][maxn];
	poly_matrix(int n_):n(n_)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				a[i][j] = new poly;
	}
	void ini()
	{
		int s, t;
		string tmp;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> tmp;
				if (tmp.find('/') == string::npos)
				{
					s = atoi(tmp.c_str());
					a[i][j]->push(s);
				}
				else
				{
					int pos = tmp.find('/');
					s = atoi(tmp.substr(0, n).c_str());
					t = atoi(tmp.substr(n + 1).c_str());
					a[i][j]->push(s);
				}
				//a[i][j]->push(s, t);
				if (i == j) a[i][j]->push(-1);
			}
		}
	}
	void change_row(int i, int j)
	{
		if (i == j) return;
		for (int k = 1; k <= n; k++)
		{
			poly* tmp = a[i][k];
			a[i][k] = a[j][k];
			a[j][k] = tmp;
		}
	}
	void change_col(int i, int j)
	{
		if (i == j) return;
		for (int k = 1; k <= n; k++)
		{
			poly* tmp = a[k][i];
			a[k][i] = a[k][j];
			a[k][j] = tmp;
		}
	}
	void elim_row(int row)
	{
		for (int i = row+1; i <= n; i++)
		{
			poly s = rem(*a[i][row], *a[row][row]);
			for (int j = row; j <= n; j++)
			{
				*a[i][j] = *a[i][j] - s * (*a[row][j]);
			}
		}
	}
	void elim_col(int row)
	{
		for (int i = row + 1; i <= n; i++)
		{
			poly s = rem(*a[row][i], *a[row][row]);
			for (int j = row; j <= n; j++)
			{
				*a[j][i] = *a[j][i] - s * (*a[j][row]);
			}
		}
	}
	void elim_once(int row)
	{
		int mindeg = 1 << 30;
		int im=0, jm=0;
		for (int i = row; i <= n; i++)
		{
			for (int j = row; j <= n; j++)
			{
				if (a[i][j]->deg() >= 0 && a[i][j]->deg() < mindeg)
				{
					mindeg = a[i][j]->deg();
					im = i; jm = j;
				}
			}
		}
		change_row(im, row);
		change_col(jm, row);
		print();
		elim_row(row);
		elim_col(row);
	}
	bool end_1(int row)
	{
		for (int i = row + 1; i <= n; i++)
		{
			if (a[row][i]->deg() >= 0) return false;
		}
		for (int i = row + 1; i <= n; i++)
		{
			if (a[i][row]->deg() >= 0) return false;
		}
		
		return true;
	}
	bool end_2(int row)
	{
		for (int i = row ; i <= n; i++)
		{
			for (int j = row ; j <= n; j++)
			{
				if (i == row && j == row) continue;
				if (!no_rem(*a[i][j], *a[row][row])) return false;
			}
		}
		return true;
	}
	void elim_once_2(int row)
	{
		for (int i = row ; i <= n; i++)
		{
			for (int j = row ; j <= n; j++)
			{
				if (i == row && j == row) continue;
				if (!no_rem(*a[i][j], *a[row][row]))
				{
					for (int k = row ; k <= n; k++)
					{
						*a[row][k] = *a[row][k] + (*a[i][k]);
					}
					elim_col(row);
					change_col(row, i);
					return;
				}
			}
		}
	}
	void elim()
	{
		for (int i = 1; i < n; i++)
		{
			while (!end_1(i))
			{
				elim_once(i);
				print();
			}
			while (!end_2(i))
			{
				elim_once_2(i);
				while (!end_1(i))
				{
					elim_once(i);
					print();
				}
			}
		}
		for (int i = 1; i <= n; i++) a[i][i]->normalize();
		print();
	}
	void print()
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				a[i][j]->print(); cout << "   |||   ";
			}
			cout << endl;
		}
		cout << endl << endl;
	}
};
int main()
{
	int n;
	cout<<"input the row of the rational matrix."<<endl;
	cout<<"input integers in form of q,and input fractions in form of p/q"<<endl;
	cin >> n;
	poly_matrix a(n);
	a.ini();
	a.print();
	a.elim();
	cout << "the minimal polynomial of the matrix is:" << endl;
	a.a[n][n]->print();
	system("pause");
	return 0;
}
