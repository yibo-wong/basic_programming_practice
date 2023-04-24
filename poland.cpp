#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
using namespace std;
string s;
queue <string> q;
double poland()
{
	string s0=q.front();
	q.pop();
	if(s0=="+") return poland()+poland();
	if(s0=="-") return poland()-poland();
	if(s0=="*") return poland()*poland();
	if(s0=="/") return poland()/poland();
	return atof(s0.c_str());
}
int main()
{
	//cout<<poland()<<endl;
	double v;
	while(cin>>s) q.push(s);
	v=poland();
	printf("%f\n",v);
	return 0;
}
