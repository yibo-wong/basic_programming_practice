#include <iostream>
#include <cstdio>
using namespace std;
class carray
{
		int size;
		int* ptr;
	public:
		carray();
		carray(int x);
		carray(carray &a);
		~carray();
		void push_back(int a);
		carray &operator =(const carray &a);
		int length(){ return size;}
		int& operator [](int i)
		{
			return ptr[i];
		}
		
};
carray::carray()
{
	size=0;
	ptr=NULL;
	//cout<<"used"<<endl;
}
carray::carray(int x)
{
	if(x==0)
	{
		size=0;
		ptr=NULL;
	}
	else
	{
		ptr=new int[x];
		size=x;
	}
}
carray::carray(carray &a)
{
	if(!a.ptr)
	{
		ptr=NULL;
		size=0;
	}
	else
	{
		if(ptr) delete [] ptr;
		ptr=new int[a.size];
		memcpy(ptr,a.ptr,sizeof(int)*a.size);
		size=a.size;
	}
}
carray::~carray()
{
	if(ptr) delete [] ptr;
}
carray& carray::operator=(const carray& a)
{
	if(ptr==a.ptr) return *this;
	if(ptr) delete [] ptr;
	if(a.ptr==NULL)
	{
		size=0;
	}
	else
	{
		ptr=new int[a.size];
		memcpy(ptr,a.ptr,sizeof(int)*a.size);
		size=a.size;
	}
	return *this;
}
void carray::push_back(int a)
{
	if(ptr)
	{
		int *tmp=new int[size+1];
		memcpy(tmp,ptr,sizeof(int)*size);
		delete [] ptr;
	}
	else
	{
		ptr=new int[1];
	}
	size++;
	ptr[size-1]=a;
}
int main()
{
	carray a1;
	cout<<a1.length()<<endl;
	//a1=4;
	carray a2(3);
	cout<<a2.length()<<endl;
	carray a3;
	a3=a2;
	
	a1.push_back(3);
	cout<<a1.length()<<endl;
	for(int i=0;i<a1.length();i++) cout<<a1[i]<<" ";
	return 0;
}
