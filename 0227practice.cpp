#include <iostream>
#include <string>
using namespace std;
// �ڴ˴�������Ĵ���

string Print1="****";
string Print2="100";

string Print1() 
{
	return "****";	
}
int Print2() 
{
	return 100;	
}

int main()
{
	cout << Print1 << Print2 << endl; 
	return 0;
}
