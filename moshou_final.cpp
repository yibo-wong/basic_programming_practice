#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;
// http://cxsjsxmooc.openjudge.cn/test/R/
int time,minute;
class head;
class warrior;
class weapon;
class city;
class warrior
{
	public:
		int total_num;
		int warrior_id;
		int health;
		int force;
		int weapon_num;
		int position;
		string name;
		static int all_health[5];
		head* phead;
		warrior(){}
		virtual 
		//gouzao
};
class head
{
	public:
		string name;
		int name_num;
		int value;
		int total_warrior;
		int warrior_num[5];
		int now;
		
		bool taken;
		
		head(){}
		//gouzao
		void produce();		
};

class weapon
{
	public:
		//string name;
		//int name_num;
		int damage;
		int used;
		warrior* pwarrior;
		weapon(){}
		weapon(warrior* pwarrior_,int damage_):pwarrior(pwarrior_),damage(damage_){}
		virtual void use();
};

class city
{
	public:
		int num;
		static int total_num;
		
		bool have_flag;
		int flag;//1 for red,2 for blue;
		int last_win;//1 for red,2 for blue;
		
		int value;
		int warrior_num;
		warrior* pwarrior[2];
		
		void war();
		void produce();
		city(){};
		//gouzao hanshu
};

class game
{
	
};
class dragon:public warrior
{
	double morale;
	
}
