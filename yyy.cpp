#include <iostream>
#include <cstring>
using namespace std;
int a[7],b[7],c[7];
int d[7];
int e[7],f[7],g[7];
int t;
int m,n;
char word[1000];
int s(int m)
{
	int temp=m;
	temp=a[temp];temp=b[temp];temp=c[temp];
	temp=d[temp];
	temp=g[temp];temp=f[temp];temp=e[temp];
	return temp;
}
void turn1()
{
	t=a[6];
	for(int i=6;i>=2;i--) 
	{
		a[i]=(a[i-1]+1)%6;
		if(a[i]==0) a[i]=6;
	}
	a[1]=(t+1)%6;
	t=e[6];
	for(int i=6;i>=2;i--) 
	{
		e[i]=(e[i-1]+1)%6;
		if(e[i]==0) e[i]=6;
	}
	e[1]=(t+1)%6;
}
void turn3()
{
	t=c[6];
	for(int i=6;i>=2;i--) 
	{
		c[i]=(c[i-1]+1)%6;
		if(c[i]==0) c[i]=6;
	}
	c[1]=(t+1)%6;
	t=g[6];
	for(int i=6;i>=2;i--) 
	{
		g[i]=(g[i-1]+1)%6;
		if(g[i]==0) g[i]=6;
	}
	g[1]=(t+1)%6;
}
void turn2()
{
	t=b[6];
	for(int i=6;i>=2;i--) 
	{
		b[i]=(b[i-1]+1)%6;
		if(b[i]==0) b[i]=6;
	}
	b[1]=(t+1)%6;
	t=f[6];
	for(int i=6;i>=2;i--) 
	{
		f[i]=(f[i-1]+1)%6;
		if(f[i]==0) f[i]=6;
	}
	f[1]=(t+1)%6;
}
int main()
{
	for(int i=1;i<=6;i++)
	{
		cin>>m>>n;
		a[m]=n;
		e[n]=m;
	}
	for(int i=1;i<=6;i++)
	{
		cin>>m>>n;
		b[m]=n;
		f[n]=m;
	}
	for(int i=1;i<=6;i++)
	{
		cin>>m>>n;
		c[m]=n;
		g[n]=m;
	}
	for(int i=1;i<=3;i++)
	{
		cin>>m>>n;
		d[m]=n;d[n]=m;
	}
	cin>>word;
	//for(int i=1;i<=6;i++) cout<<"fff"<<a[i]<<" ";
	//cout<<endl;
	//turn1();
	//for(int i=1;i<=6;i++) cout<<"fff"<<a[i]<<" ";
	cout<<endl;
	int counter=0;
	int r;
	cout<<"uuu"<<s(1)<<endl;
	for(int i=0;i<strlen(word);i++)
	{
		cout<<char('a'+s(word[i]-'a'+1)-1);
		counter++;
		r=counter/6;
		if(r%3==0) turn1();
		if(r%3==1) turn2();
		if(r%3==2) turn3();
	}
	return 0;
}
