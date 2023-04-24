#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int m,n;
int myexp;
bool isfirst=1;
struct node
{
	int exp;
	int coef;
	struct node *next;
};
typedef node* poly;
poly add(const poly& A,const poly &B)
{
	poly t;
	if(A==NULL && B==NULL)
	{
		t=NULL;
		return t;
	}
	t=new node;
	if(A==NULL && B!=NULL)
	{
		t->exp=B->exp;
		t->coef=B->coef;
		poly B_tmp=B->next;
		t->next=add(A,B_tmp);
		return t;
	}
	else if(A!=NULL && B==NULL)
	{
		t->exp=A->exp;
		t->coef=A->coef;
		poly A_tmp=A->next;
		t->next=add(A_tmp,B);
		return t;
	}
	else if(A->exp==B->exp)
	{
		t->exp=A->exp;
		t->coef=A->coef+B->coef;
		poly A_tmp=A->next;
		poly B_tmp=B->next;
		t->next=add(A_tmp,B_tmp);
		return t;
	}
	else if((A->exp < B->exp))
	{
		t->exp=B->exp;
		t->coef=B->coef;
		poly B_tmp=B->next;
		t->next=add(A,B_tmp);
		return t;
	}
	else if(A->exp > B->exp)
	{
		t->exp=A->exp;
		t->coef=A->coef;
		poly A_tmp=A->next;
		t->next=add(A_tmp,B);
		return t;
	}
}

poly mul(const poly& A,const poly& B)
{
	poly s,t;
	poly ans;
	ans=new node;
	if(myexp<0)
	{
		ans=NULL;
		return ans;
	}
	int sum=0;
	s=A;t=B;
	do
	{
		t=B;
		do
		{
			if(s->exp + t->exp==myexp)
			{
				sum+=s->coef*t->coef;
			}
			t=t->next;
		}while(t!=NULL);
		s=s->next;
	}while(s!=NULL);
	ans->exp=myexp;
	ans->coef=sum;
	//ans->next=new node;
	//cout<<myexp<<" "<<ans->exp<<" "<<ans->coef<<endl;
	myexp--;
	ans->next=mul(A,B);
	return ans;
}

void printPolynomial(const poly& A)
{
	if(A==NULL) return;
	if(!isfirst)
	{
		if(A->coef>0) cout<<"+";
	}
	if(A->coef==0)
	{
		printPolynomial(A->next);
	}
	else
	{
		isfirst=0;
		if(A->coef==1 && A->exp!=0)
		{}
		else if(A->coef==-1 && A->exp!=0)
		{
			cout<<"-";
		}
		else
		{
			cout<<A->coef;
		}
		
		if(A->exp==0)
		{
			return;
		}
		else if(A->exp==1)
		{
			cout<<"x";
		}
		else
		{
			cout<<"x^"<<A->exp;
		}
		printPolynomial(A->next);
	}
}

bool not_zero(const poly& A)
{
	if(A==NULL) return false;
	else if(A->coef!=0) return true;
	else return not_zero(A->next);
}

poly crt()
{
	cin>>m>>n;
	poly t;
	if(m==0&&n==0)
	{
		t=NULL;
		return t;
	}
	else
	{
		t=new node;
		t->coef=m;
		t->exp=n;
		t->next=crt();
		return t;
	}
}

void odn_print(poly x)
{
	if(x==NULL) return;
	cout<<x->coef<<" "<<x->exp<<"  ";
	odn_print(x->next);
}

int main()
{
	poly x,y;
	x=crt();
	y=crt();
	poly x1=add(x,y);
	
	//cout<<"x1 "<<is_zero(x1)<<endl;
	//odn_print(x1);cout<<endl;
	if(!not_zero(x1)) cout<<"0";
	else printPolynomial(x1);
	
	cout<<endl;
	isfirst=1;
	myexp=x->exp + y->exp;
	poly x2=mul(x,y);
	
	if(!not_zero(x2)) cout<<"0";
	else printPolynomial(x2);
	
	cout<<endl;
	//odn_print(x2);
	return 0;
}
