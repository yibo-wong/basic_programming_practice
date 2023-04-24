#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cstdlib>
#include <map>
using namespace std;
class Solution
{
public:
	string Exp;
	map<char, int>VarToInt;
	map<char, int>Pri;
	vector<char>OriExp;
	vector<char>Post;
	vector<char>Temp;
	char IntToVar[100];
	int table[10000][2];
	int VarNum;
	vector<int>MakeTrue;
	vector<int>MakeFalse;

	void Ini()
	{
		//the order of the operation priority: ! & | > = (
		Pri['!'] = 4;
		Pri['&'] = 3;
		Pri['|'] = 3;
		Pri['>'] = 2;
		Pri['='] = 1;
		Pri['('] = 0;
		VarNum = 0;
		cin >> Exp;
	}
	bool IsOpe(char a)
	{
		if (a == '!' || a == '&' || a == '>' || a == '|' || a == '=' || a == '(' || a == ')') 
			return true;
		else 
			return false;
	}
	void IniVar()
	{
		for (int i = 0; i < Exp.size(); i++)
		{
			if (!IsOpe(Exp[i]))
			{
				if (VarToInt.find(Exp[i]) == VarToInt.end())
				{
					VarToInt[Exp[i]] = VarNum;
					IntToVar[VarNum] = Exp[i];
					VarNum++;
				}
			}
		}
	}
	void MakePost()
	{
		for (int i = 0; i < Exp.size(); i++)
		{
			if (!IsOpe(Exp[i]))
				Post.push_back(Exp[i]);
			else if (Exp[i] == '(')
				Temp.push_back(Exp[i]);
			else if (Exp[i] == ')')
			{
				while (true)
				{
					if (Temp.back() == '(')
					{
						Temp.pop_back();
						break;
					}
					else
					{
						Post.push_back(Temp.back());
						Temp.pop_back();
					}
				}
			}
			else
			{
				if (Temp.empty())
					Temp.push_back(Exp[i]);
				else
				{
					while (1)
					{
						if (Temp.empty() || Pri[Temp.back()] < Pri[Exp[i]])
							break;
						else
						{
							Post.push_back(Temp.back());
							Temp.pop_back();
						}
					}
					Temp.push_back(Exp[i]);
				}
			}
		}
		while (!Temp.empty())
		{
			Post.push_back(Temp.back());
			Temp.pop_back();
		}
	}
	bool Calc(int Value)
	{
		vector<bool>q;
		for (int i = 0; i < Post.size(); i++)
		{
			if (!IsOpe(Post[i]))
			{
				int x = (Value >> (VarToInt[Post[i]])) & 1;
				q.push_back(bool(x));
			}
			else
			{
				if (Post[i] == '!')
				{
					bool t = q.back();
					q.pop_back();
					q.push_back(!t);
				}
				else if (Post[i] == '&')
				{
					bool b = q.back();
					q.pop_back();
					bool a = q.back();
					q.pop_back();
					q.push_back(a && b);
				}
				else if (Post[i] == '|')
				{
					bool b = q.back();
					q.pop_back();
					bool a = q.back();
					q.pop_back();
					q.push_back(a || b);
				}
				else if (Post[i] == '>')
				{
					bool b = q.back();
					q.pop_back();
					bool a = q.back();
					q.pop_back();
					q.push_back((!a) || b);
				}
				else if (Post[i] == '=')
				{
					bool b = q.back();
					q.pop_back();
					bool a = q.back();
					q.pop_back();
					q.push_back(((!a) || b)&&((!b) || a));
				}
			}
		}
		return q.back();
	}
	void MakeTable()
	{
		cout << "The true table goes:" << endl;
		for (int i = 0; i < VarNum; i++) 
			cout << IntToVar[i] << " ";
		cout << "result" << endl;
		for (int i = 0; i <= (1 << VarNum) - 1; i++)
		{
			for (int j = 0; j < VarNum; j++)
				cout << ((i >> j) & 1) << " ";
			bool result = Calc(i);
			if (result == 1) MakeTrue.push_back(i);
			else MakeFalse.push_back(i);
			cout << result << endl;
		}
	}
	void MakeExp_1()
	{
		cout << endl << "Thus, the principal disjunctive normal form goes as follows:" << endl;

		for (int i = 0; i < MakeTrue.size() - 1; i++)
		{
			cout << "(";
			for (int j = 0; j < VarNum - 1; j++)
			{
				if (((MakeTrue[i] >> j) & 1) == 0)
					cout << "©´";
				cout << IntToVar[j]<<"¡Ä";
			}
			if ((MakeTrue[i] >> (VarNum - 1) & 1) == 0)
				cout << "©´";
			cout << IntToVar[VarNum - 1] << ")¡Å";
		}
		cout << "(";
		int i = MakeTrue.back();
		for (int j = 0; j < VarNum - 1; j++)
		{
			if (((i >> j) & 1) == 0) cout << "©´";
				cout << IntToVar[j] << "¡Ä";
		}
		if ((i >> (VarNum - 1) & 1) == 0) cout << "©´";
			cout << IntToVar[VarNum - 1] << ")"<<endl;
	}
	void MakeExp_2()
	{
		cout << endl << "Besides, the principal conjunctive normal form goes as follows:" << endl;

		for (int i = 0; i < MakeFalse.size() - 1; i++)
		{
			cout << "(";
			for (int j = 0; j < VarNum - 1; j++)
			{
				if (((MakeFalse[i] >> j) & 1) == 1)
					cout << "©´";
				cout << IntToVar[j] << "¡Å";
			}
			if ((MakeFalse[i] >> (VarNum - 1) & 1) == 1)
				cout << "©´";
			cout << IntToVar[VarNum - 1] << ")¡Ä";
		}
		cout << "(";
		int i = MakeFalse.back();
		for (int j = 0; j < VarNum - 1; j++)
		{
			if (((i >> j) & 1) == 1) cout << "©´";
			cout << IntToVar[j] << "¡Å";
		}
		if ((i >> (VarNum - 1) & 1) == 1) cout << "©´";
		cout << IntToVar[VarNum - 1] << ")" << endl;
	}
	void Start()
	{
		Ini();
		IniVar();
		MakePost();
		//cout << VarNum << endl;
		MakeTable();
		MakeExp_1();
		MakeExp_2();
	}
};
int main()
{
	Solution* solution = new Solution;
	solution->Start();
	return 0;
}
