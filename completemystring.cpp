#include <cstdlib>
#include <iostream>
using namespace std;
int strlen(const char * s) 
{	int i = 0;
	for(; s[i]; ++i);
	return i;
}
void strcpy(char * d,const char * s)
{
	int i = 0;
	for( i = 0; s[i]; ++i)
		d[i] = s[i];
	d[i] = 0;
		
}
int strcmp(const char * s1,const char * s2)
{
	for(int i = 0; s1[i] && s2[i] ; ++i) {
		if( s1[i] < s2[i] )
			return -1;
		else if( s1[i] > s2[i])
			return 1;
	}
	return 0;
}
void strcat(char * d,const char * s)
{
	int len = strlen(d);
	strcpy(d+len,s);
}
class MyString
{
	public:
		char* p;
		MyString(const char * s=NULL) {
		if( s) {
			p = new char[strlen(s) + 1];
			strcpy(p,s);
		}
		else
		{
			p=new char[1];
			p[0]='\0';
		}

		}	
		MyString(const MyString& s)
		{
			if(s.p)
			{
				p = new char[strlen(s.p) + 1];
				strcpy(p,s.p);
			}
			else p=NULL;
		}
		~MyString() { if(p) delete [] p; }
		MyString & operator=(const MyString& s)
		{
			if(p==s.p) return *this;
			if(p) delete []p;
			if(s.p)
			{
				p=new char[strlen(s.p)+1];
				strcpy(p,s.p);
			}
			else
			{
				p=new char[1];
				p[0]='\0';
			}
			return *this;
		}
		
		MyString & operator=(const char* s)
		{
			if(p) delete []p;
			if(s)
			{
				p=new char[strlen(s)+1];
				strcpy(p,s);
			}
			else p=NULL;
			return *this;
		}
		
		MyString & operator=(const char& s)
		{
			if(p) delete []p;
			if(s)
			{
				p=new char[2];
				p[0]=s;
			}
			else p=NULL;
			return *this;
		}
		
		char& operator[] (int i)
		{
			return p[i];
		}
		friend ostream& operator<<(ostream& os,MyString& s)
		{
			os<<s.p;
			return os;
		}
		friend MyString operator+(MyString a,const MyString b)
		{
			char *tmp=new char[strlen(a.p)+strlen(b.p)+1];
			strcpy(tmp,a.p);
			strcat(tmp,b.p);
			return MyString(tmp);
		}
		friend MyString operator+(MyString a,const char* b)
		{
			char *tmp=new char[strlen(a.p)+strlen(b)+1];
			strcpy(tmp,a.p);
			strcat(tmp,b);
			return MyString(tmp);
		}
		
		MyString& operator +=(const char* s)
		{
			char* tmp=new char[strlen(p)+1];
			strcpy(tmp,p);
			delete []p;
			p=new char[strlen(tmp)+strlen(s)+1];
			strcpy(p,tmp);
			strcat(p,s);
			return *this;
		}
		
		friend MyString operator+(const char* b,MyString a)
		{
			char *tmp=new char[strlen(a.p)+strlen(b)+1];
			strcpy(tmp,b);
			strcat(tmp,a.p);
			return MyString(tmp);
		}
		friend bool operator <(const MyString& a,const MyString& b)
		{
			if(strcmp(a.p,b.p)<0) return true;
			else return false; 
		}
		friend bool operator >(const MyString& a,const MyString& b)
		{
			if(strcmp(a.p,b.p)>0) return true;
			else return false; 
		}
		friend bool operator ==(const MyString& a,const MyString& b)
		{
			if(strcmp(a.p,b.p)==0) return true;
			else return false; 
		}
		char* operator () (int start,int len)
		{
			char* tmp=new char[len+1];
			for(int i=start;i<start+len;i++)
			{
				tmp[i-start]=p[i];
			}
			tmp[len]='\0';
			return tmp;
		}
};


int CompareString( const void * e1, const void * e2)
{
	MyString * s1 = (MyString * ) e1;
	MyString * s2 = (MyString * ) e2;
	if( * s1 < *s2 )
	return -1;
	else if( *s1 == *s2)
	return 0;
	else if( *s1 > *s2 )
	return 1;
}
int main()
{
	MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
	MyString SArray[4] = {"big","me","about","take"};
	cout << "1. " << s1 << s2 << s3<< s4<< endl;
	s4 = s3;
	s3 = s1 + s3;
	cout << "2. " << s1 << endl;
	cout << "3. " << s2 << endl;
	cout << "4. " << s3 << endl;
	cout << "5. " << s4 << endl;
	cout << "6. " << s1[2] << endl;
	s2 = s1;
	s1 = "ijkl-";
	s1[2] = 'A' ;
	cout << "7. " << s2 << endl;
	cout << "8. " << s1 << endl;
	s1 += "mnop";
	cout << "9. " << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10. " << s4 << endl;
	s1 = s2 + s4 + " uvw " + "xyz";
	cout << "11. " << s1 << endl;
	qsort(SArray,4,sizeof(MyString),CompareString);
	for( int i = 0;i < 4;i ++ )
	cout << SArray[i] << endl;
	//s1的从下标0开始长度为4的子串
	cout << s1(0,4) << endl;
	//s1的从下标5开始长度为10的子串
	cout << s1(5,10) << endl;
	return 0;
}
