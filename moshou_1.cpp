#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
class head;
class warrior
{
	private:
		int num;
		int total_num;
		int warrior_id;
		string name;
		static string all_name[5];
		
		static int order[2][5];
		int health;
		head* p;
	public:
		static int all_health[5];
		friend class head;
		warrior(head* _p,int _num,int _total_num,int _warrior_id)
		{
			p=_p;num=_num;total_num=_total_num;
			warrior_id=_warrior_id;
			name=all_name[_warrior_id];
			health=all_health[_warrior_id];
		}
		warrior(){};
};
string warrior::all_name[5]={"dragon","ninja","iceman","lion","wolf"};
//int warrior::order[2][5];
int warrior::order[2][5]={{2,3,4,1,0},{3,0,1,2,4}};
//int warrior::order[1]={1,4,3,0,2};
int warrior::all_health[5];
class head
{
	private:
		string name;
		int name_num;
		int value;
		int total_warrior;
		int warrior_num[5];
		
		int now;
		bool stopped;
		warrior* my_warrior[1000];
	public:
		static int time;
		head(int _value,string _name)
		{
			value=_value;
			name=_name;
			now=0;
			if(name=="red") name_num=0;
			else name_num=1;
			stopped=false;
			total_warrior=0;
			for(int i=0;i<=4;i++) warrior_num[i]=0;
		}
		head()
		{
		};
		~head()
		{
			for(int i=0;i<total_warrior;i++)
			{
				delete my_warrior[i];
			}
			//cout<<"used"<<endl;
		}
		int produce()
		{
			if(stopped) return 0;
			int i=5;
			bool have_made=false;
			int id=warrior::order[name_num][now];
			while(i--)
			{
				if(warrior::all_health[id] <= value)
				{
					have_made=true;
					//cout<<"value left "<<value<<endl<<" takes"<<warrior::all_health[id]<<endl;
					value-=warrior::all_health[id];
					my_warrior[total_warrior]=new warrior(this,warrior_num[id],total_warrior,id);
					warrior* tmp=my_warrior[total_warrior];
					printf("%03d %s %s %d born with strength %d,%d %s in %s headquarter",time,name.c_str(),tmp->name.c_str(),total_warrior+1,\
					tmp->health,warrior_num[id]+1,tmp->name.c_str(),name.c_str());
					cout<<endl;
					total_warrior++;
					warrior_num[id]++;
					now=(now+1)%5;
					break;
				}
				now=(now+1)%5;
				id=warrior::order[name_num][now];
			}
			if(have_made==false)
			{
				printf("%03d %s headquarter stops making warriors\n",time,name.c_str());
				stopped=true;
			}
			return 0;
		}
		bool is_stopped()
		{
			return stopped;
		}
};
int head::time=0;
int main()
{
	int casenum,case_now,m,n[5];
	//head r,b;
	string s[2]={"red","blue"};
	cin>>casenum;
	for(case_now=1;case_now<=casenum;case_now++)
	{
		cout<<"Case:"<<case_now<<endl;
		cin>>m;
		head::time=0;
		head* r=new head(m,s[0]);
		head* b=new head(m,s[1]);
		for(int i=0;i<5;i++)
		{
			cin>>n[i];
			warrior::all_health[i]=n[i];
		}
		
		while(true)
		{
			r->produce();
			b->produce();
			head::time++;
			//cout<<r.is_stopped()<<" "<<b.is_stopped()<<endl;
			if(r->is_stopped()==1 && b->is_stopped()==1) break;
		}
	}
	return 0;
}
