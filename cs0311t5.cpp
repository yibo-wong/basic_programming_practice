#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110; 
class CHugeInt {
// 在此处补充你的代码
	public:
		bool is_big;
		int n,len;
		char s[210];
		CHugeInt(const char* a)
		{
			is_big=true;
			memset(s,0,sizeof(s));
			n=0;len=strlen(a);
			for(int i=0;i<len;i++)
			{
				s[i]=a[len-i-1];
			}
		}
		CHugeInt(int a)
		{
			is_big=false;
			n=a;
			int sum=0,tmp=a;
			while(tmp!=0)
			{
				tmp=tmp/10;
				sum++;
			}
			len=sum;
		}
		friend ostream& operator<<(ostream& os,const CHugeInt& chi)
		{
			if(chi.is_big)
			{
				for(int i=0;i<chi.len;i++) cout<<chi.s[chi.len-i-1];
			}
			else cout<<chi.n;
			return os;
		}
		int nlen(int n)
		{
			int sum=0;
			while(n!=0)
			{
				n/=10;
				sum++;
			}
			return sum;
		}
		int pos(int n,int i)
		{
			for(int j=0;j<=i-1;j++) n=n/10;
			return n%10;
		}
		void change(int num,int i,int len,CHugeInt& a)
		{
			int n[210];
			memset(n,0,sizeof(n));
			for(int j=0;j<210;j++) n[j]=max(a.s[j]-'0',0);
			//cout<<num<<" "<<i<<endl;
			int x=pos(num,i);
			//cout<<"x="<<x<<endl;
			//cout<<"max="<<max(nlen(num),len)<<endl;
			int last=0;
			for(int j=i;j<=max(nlen(num),a.len);j++)
			{
				n[j]+=x;
				x=n[j]/10;
				n[j]=n[j]%10;
				if(n[j]!=0) last=j;
			}
			a.len=last+1;
			for(int j=0;j<210;j++)
			{
				a.s[j]='0'+n[j];
			}
			//cout<<"length "<<a.len<<endl;
		}
		friend CHugeInt operator+(int r,CHugeInt a)
		{
			for(int i=0;i<a.nlen(r);i++)
			{
				a.change(r,i,a.len,a);
				//cout<<"tmp "<<a<<endl;
				//cout<<"tmp len "<<a.len<<endl;
			}
			return a;
		}
		friend CHugeInt operator+(CHugeInt a,int r)
		{
			for(int i=0;i<a.nlen(r);i++)
			{
				a.change(r,i,a.len,a);
				//cout<<"tmp2 "<<a<<endl;
			}
			return a;
		}
		friend CHugeInt operator+(CHugeInt a,const CHugeInt& b)
		{
			int r=b.n;
			for(int i=0;i<a.nlen(r);i++)
			{
				a.change(r,i,a.len,a);
			}
			return a;
		}
		CHugeInt & operator++()
		{
			n++;
			return *this;
		}
		CHugeInt operator++(int useless)
		{
			CHugeInt tmp(*this);
			n++;
			return tmp;
		}
		CHugeInt & operator+=(int x)
		{
			n+=x;
			return *this;
		}
};
int  main() 
{ 
	char s[210];
	int n;

	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);

		
		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout  << ++ b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}
