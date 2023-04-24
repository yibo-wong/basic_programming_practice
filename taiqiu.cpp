#include <iostream>
using namespace std;
int dx,dy;
int x,y;
int x1,y1;
bool bs;
int e;
bool win=false;
void check()
{
	if(x==x1&&y==y1) bs=!bs;
}
void change()
{
	if((x==0&&y==0)||(x==8&&y==0)||(x==16&&y==0)||(x==0&&y==5)||(x==8&&y==5)||(x==16&&y==5))
	{
		if(bs)
		{
			cout<<-1;
			win=true;
			return;
		}
		else
		{
			cout<<1;
			win=true;
			return;
		}
	}
	if(x==0||x==16) dx=-dx;
	if(y==0||y==5) dy=-dy;
}
int main()
{
	cin>>x>>y;
	cin>>x1>>y1;
	cin>>dx>>dy;
	cin>>e;
	bs=true;
	while(e--)
	{
		x=x+dx;y=y+dy;
		//cout<<x<<" "<<y<<endl;
		check();
		change();
		if(win) return 0;
	}
	cout<<"0";
	return 0;
}
