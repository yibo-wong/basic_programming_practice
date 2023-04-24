#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#define maxn 10000
using namespace std;
struct point
{
	int x,y;
	point(){
	}
	point(int x1,int y1):x(x1),y(y1){
	}
};
int ab(int x)
{
	if(x<0) return -x;
	return x;
}
struct rec
{
	int x,y;
	int dx,dy;
	rec(){
	}
	rec(int xx,int yy,int ddx,int ddy):x(xx),y(yy),dx(ddx),dy(ddy){
	}
};
bool operator <(const rec& a,const rec& b)
{
	if(a.x==b.x)
	{
		if(a.y==b.y)
		{
			if(a.dx==b.dx)
			{
				return a.dy<b.dy;
			}
			return a.dx<b.dx;
		}
		return a.y<b.y;
	}
	return a.x<b.x;
}
vector<point>p;
set<rec>r;
int n,x,y;
int main()
{
	int casenum;
	cin>>casenum;
	while(casenum--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>x>>y;
			p.push_back(point(x,y));
		}
		for(int i=0;i<p.size()-1;i++)
		{
			for(int j=i+1;j<p.size();j++)
			{
				if(p[i].x==p[j].x || p[i].y==p[j].y) continue;
				else
				{
					r.insert(rec(min(p[i].x,p[j].x) , min(p[i].y,p[j].y) , ab(p[i].x-p[j].x) , ab(p[i].y-p[j].y)));
					//cout<<min(p[i].x,p[j].x) << min(p[i].y,p[j].y) << ab(p[i].x-p[j].x) << ab(p[i].y-p[j].y)<<endl;
				}
			}
		}
		cout<<r.size()<<endl;
	}
	return 0;
}
