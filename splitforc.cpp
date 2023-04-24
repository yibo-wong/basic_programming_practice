#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
using namespace std;
string s;
vector<string>tot;
void split(string s)
{
	stringstream ss(s);
	string item;
	while(getline(ss,item,' '))
	{
		//<<"there"<<endl;
		//cout<<item<<endl;
		tot.push_back(item);
	}
}
int main()
{
	getline(cin,s);
	split(s);
	//blah blah blah
}


