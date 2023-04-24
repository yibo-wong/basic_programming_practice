#include <iostream>
#include <cstring>
#include <string>
using namespace std;
/*
int main()
{
	char c[]="helloworld";
	cout<<strlen(c)<<endl;
	cout<<c<<endl;
	return 0;
}
*/
int main()
{
	string str1("abcd");
	string str2("efgh");
	string str3=str1+str2;
	cout<<str3<<endl;
	//str1.append(3,'r');
	//cout<<str1<<endl;
	//str2.insert(1,str1,1,3);
	str2.replace(0,1,"www");
	cout<<str2<<endl;
	return 0;
}
