#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
// 在此处补充你的代码
	public:
		int m,n;
		int** a;
		Array2(){
			a=NULL;
			m=0;n=0;
		};
		Array2(int m_,int n_)
		{
			m=m_,n=n_;
			a=new int*[m];
			for(int i=0;i<m;i++) a[i]=new int[n];
		}
		~Array2()
		{
			if(a==NULL) return;
			for(int i=0;i<m;i++) delete [] a[i];
			delete a;
		}
		int* operator[](int i)
		{
			return a[i];
		}
		int& operator()(int x,int y)
		{
			return *(*(a+x)+y);
		}
		Array2& operator=(const Array2& s)
		{
			if(a==s.a) return *this;
			if(a)
			{
				for(int i=0;i<m;i++) delete [] a[i];
				delete a;
			}
			if(s.a)
			{
				m=s.m;
				n=s.n;
				a=new int*[m];
				for(int i=0;i<m;i++) a[i]=new int[n];
				//cout<<"used"<<endl;
				for(int i=0;i<m;i++)
				{
					for(int j=0;j<n;j++)
					{
						a[i][j]=s.a[i][j];
					}
				}
			}
			else
				a=NULL;
			return *this;
		}
		
};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    Array2 b;     b = a;
    cout<<"next"<<endl;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}
