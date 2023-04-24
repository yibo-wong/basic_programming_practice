#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
class bug
{
	int legnum,color;
	public:
		bug(int ln,int c):legnum(ln),color(c){cout<<"bug con"<<endl;};
		~bug(){cout<<"bug des"<<endl;}
		void printinfo()
		{
			cout<<legnum<<","<<color<<endl;
		}
};
class flyingbug:public bug
{
	int wingnum;
	public:
		void printinfo()
		{
			bug::printinfo();
			cout<<wingnum<<endl;
		}
		flyingbug(int nl,int cl,int wn):bug(nl,cl),wingnum(wn)
		{
			cout<<"flying con"<<endl;
		}
		~flyingbug()
		{
			cout<<"flying des"<<endl;
		}
};
int main()
{
	flyingbug fb(2,3,4);
	fb.printinfo();
	return 0;
}
