#include <iostream> 
using namespace std;
class Point { 
	private: 
		int x; 
		int y; 
	public: 
		Point() { };
// �ڴ˴�������Ĵ���
		friend ostream& operator<<(ostream & os,const Point& s)
		{
			os<<s.x<<","<<s.y;
			return os;
		}
		friend istream& operator>>(istream & is,Point& t)
		{
			is>>t.x>>t.y;
			return is;
		}
}; 
int main() 
{ 
 	Point p;
 	while(cin >> p) {
 		cout << p << endl;
	 }
	return 0;
}
