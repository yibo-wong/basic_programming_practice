#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
int Min;
class soilder;
class headq
{
	private:
		int life_s;			  //����Ԫ 
		string name;     	 //˾� 
		int num;			//���
	public:
		static int time;	 	//ʱ�� 
		void modify(int n);		//�޸�����Ԫ 
		int create(soilder* p);	//������ʿ 
		void substract(int n){ life_s -= n;}//��������Ԫ 
		int lifes_show(){return life_s;}	//show����Ԫ 
		headq(string name1="no",int n=0,int j=1):life_s(n),name(name1),num(j){}
};

class soilder
{
	private:
		int life;			//���� 
		string species;		//���� 
		int exit;			//���ڸ��� 
	public:
		friend int headq::create(soilder* p);
		soilder(string s="no",int n=0,int j=0):life(n),species(s),exit(0){}
		void edit(int n){life = n;}	//�������� 
		
};

int headq::time =0; 
void headq::modify(int n)
{
	life_s = n;
}
int headq::create(soilder* p)
{
	if(life_s>= p->life)
	{
		p->exit++;
		substract(p->life);
		
		cout<<setfill('0')<<setw(3)<<time<<" "<<name<<" "<<p->species<<" "
		<<num<<" born with strength "<<p->life<<","<<p->exit
		<<" "<<p->species<<" in "<<name<<" headquarter\n";
		num++;	
		return 0;
	}
	if(life_s<Min)
	{
		cout<<setfill('0')<<setw(3)<<time<<" "<<name<<
		 " headquarter stops making warriors\n";
		return 1;}
	if(life_s<p->life)
		return 2;
}

int main()
{
	int n,i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		Min=999999;
		headq::time=0;
		soilder m1("dragon"),m2("ninja"),m3("iceman"),m4("lion"),m5("wolf");
		soilder m6("dragon"),m7("ninja"),m8("iceman"),m9("lion"),m10("wolf");
		soilder m_r[5]={m1,m2,m3,m4,m5};
		soilder m_b[5]={m6,m7,m8,m9,m10};
		headq r("red"),b("blue");
		int tag=0;
		cout<<"Case:"<<i<<endl;
		int temp1;
		cin>>temp1; 		//����Ԫ
		r.modify(temp1) ;
		b.modify(temp1)	;
		for(int j=0;j<5;j++) //�޸�����ֵ 
		{
			int temp2;
			cin>>temp2;
			if(temp2<Min)
				Min=temp2;
			m_r[j].edit(temp2);
			m_b[j].edit(temp2);
		}
		int j=0,k=0;
		int time_r[5]={2,3,4,1,0};	//��ʿ����˳�� 
		int time_b[5]={3,0,1,2,4};
		int p1=1,p2=1;
//������ʿ���� 
		while(tag!=2)		//tag==2������˾�ֹͣ 
		{
			while(p1)
			{
				int temp3 = r.create(&m_r[time_r[j]]);  //temp3Ϊ������ʿ���ص�״ֵ̬ 
				if(temp3==0)
				{ 	j++;
					break;}	
				else if(temp3==2)
				{
					j++;
					if(j==5)
						j=0;
					continue; 
				}
				else if(temp3==1)
				{
					p1=0;tag++;
				}
			}
			while(p2)
			{
				int temp3 = b.create(&m_b[time_b[k]]);
				if(temp3==0)
				{
					k++;
					break;
				}
				else if(temp3==2)
				{
					k++;
					if(k==5)
						k=0;
					continue; 
				}
				else if(temp3==1)
				{
					p2=0;
					tag++;
				}
			}
			headq::time++;
			if(j==5)
				j=0;
			if(k==5)
				k=0;
		}
	}
 } 
