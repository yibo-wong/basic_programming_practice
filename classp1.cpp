#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
class rectangle
{
	public:
		int w,h;
		void init(int w_,int h_);
		int area();
		int perimeter();
};
void rectangle::init(int w_,int h_)
{
	w=w_;h=h_;
}
int rectangle::area()
{
	return w*h;
}
int rectangle::perimeter()
{
	return 2*(w+h);
}
int main()
{
	rectangle rec;
	int w,h;
	cin>>w>>h;
	rec.init(w,h);
	cout<<rec.area()<<endl;
	cout<<rec.perimeter()<<endl;
	cout<<sizeof(rectangle)<<endl;
	return 0;
}
