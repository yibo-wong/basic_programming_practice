#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int main()
{
	vector<int>left;
	vector<int>right;
	int lenl=0;
	int lenr=0;
	char a[1000];
	cin>>a;
	for(int i=0;i<strlen(a);i++)
	{
		if(lenl==0)
		{
			if(a[i]=='(')
			{
				lenl++;
				left.push_back(i);
			}
			if(a[i]==')')
			{
				right.push_back(i);
			}
		}
		else
		{
			if(a[i]=='(')
			{
				lenl++;
				left.push_back(i);
			}
			if(a[i]==')')
			{
				lenl--;
				left.pop_back();
			}
		}
	}
	for(int j=0;j<left.size();j++)
	{
		cout<<left[j]<<" ";
	}
	cout<<endl;
	for(int j=0;j<right.size();j++)
	{
		cout<<right[j]<<" ";
	}
	cout<<endl;
	return 0;
}
