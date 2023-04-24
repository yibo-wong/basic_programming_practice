#include <iostream>
using namespace std;
class Sample {
public:
	int v;
// 在此处补充你的代码
	Sample(int n)
	{
		v=n;
		cout<<"use 1 "<<endl;
	}
	Sample(){
		cout<<"use 2"<<endl;
	};
	Sample(const Sample& a)
	{
		v=a.v+2;
		cout<<"use 3"<<endl;
	}
};
class Sample_1
{
	public:
	int v;
	Sample_1(int n)
	{
		v=n;
		cout<<"use 1 "<<endl;
	}
	Sample_1(){
		cout<<"use 2"<<endl;
	};
};
void PrintAndDouble(Sample o)
{
	cout << o.v;
	cout << endl;
}
int main()
{
	cout<<"line 1"<<endl;
	Sample a(5);
	cout<<"line 2"<<endl;
	Sample b = a;
	cout<<&b<<endl;
	cout<<&a<<endl;
	cout<<"line 3"<<endl;
	PrintAndDouble(b);
	cout<<"line 4"<<endl;
	Sample c;
	//c(21);
	cout<<"line 5"<<endl;
	PrintAndDouble(c);
	cout<<"line 6"<<endl;
	Sample d;
	cout<<"line 7"<<endl;
	d = a;
	cout<<"line 8"<<endl;
	cout << d.v<<endl;
	cout<<"line 9"<<endl;
	Sample* p=new Sample;
	cout<<"line 10"<<endl;
	Sample* q=new Sample(2);
	cout<<"line 11"<<endl;
	Sample_1 s1;
	Sample_1 s2=s1;
	cout<<&s1<<endl;
	cout<<&s2<<endl;
	return 0;
}
