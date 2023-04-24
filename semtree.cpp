#include <iostream>
#include <cstring>
using namespace std;
string s;
bool f(int i)
{
	if(i>=s.size()) return false;
	if(s[i]=='#') return false;
	return true;
}
bool is_sem(int i)
{
	if(f(2*i+1)==true && f(2*i+2)==false) return false;
	else if(f(2*i+1)==false && f(2*i+2)==true) return false;
	else if(f(2*i+1)==false && f(2*i+2)==false) return true;
	else return is_sem(2*i+1) & is_sem(2*i+2);
}
int main()
{
	cin>>s;
	if(is_sem(0)) cout<<"Yes";
	else cout<<"No";
	return 0;
}
