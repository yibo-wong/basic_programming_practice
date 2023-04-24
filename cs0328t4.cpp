#include <iostream>
using namespace std;
class MyCin
{
	public:
		bool flag;
		operator bool()
		{
			return flag;
		}
		MyCin& operator >>(int& i)
		{
			cin>>i;
			if(i==-1) flag=false;
			return *this;
		}
		MyCin()
		{
			flag=true;
		}
};
int main()
{
    MyCin m;
    int n1,n2;
    while( m >> n1 >> n2) 
        cout  << n1 << " " << n2 << endl;
    return 0;
}
