#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
    Complex(){
		cout<<"f1 called"<<endl;
	}
    Complex(const char*s)
    {
    	if(s)
    	{
    		r=s[0]-'0';
    		i=s[2]-'0';
		}
		else
		{
			r=0;
			i=0;
		}
		cout<<"f2 called"<<endl;
	}
	Complex(const Complex& c)
	{
		r=c.r;
		i=c.i;
		cout<<"f3 called"<<endl;
	}
};
int main() {
    Complex a,b;
    a = "3+4i"; a.Print();
    b = "5+6i"; b.Print();
    cout<<"step1"<<endl;
    a=b;
    cout<<"step2"<<endl;
    Complex c(a);
    c.Print();
    return 0;
}
