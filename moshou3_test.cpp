#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdio>
#define maxn 10000
using namespace std;
int hour, minute;
class head;
class warrior;
class weapon;
class city;
const string all_name[5] = { "dragon","ninja","iceman","lion","wolf" };
const string arm[3] = { "sword","bomb","arrow" };
int hp[5], fc[5];
int order[2][5] = { {2,3,4,1,0},{3,0,1,2,4} };
city* ct[22];
int tot_city;
int m, n, r, k, t;

class game
{
public:
	head* qhead[3];
	int hour = 0;
	game();
	~game();
	bool game_start();
};

class city
{
public:
	int num;
	static int total_num;

	int warrior_num;
	warrior* pwarrior_red;
	warrior* pwarrior_blue;

	void war();
	void run();
	city() {};
	city(int n)
	{
		num = n;
		warrior_num = 0;
		pwarrior_red = NULL;
		pwarrior_blue = NULL;
	}
	virtual ~city() {};
};

class weapon
{
public:
	//string name;
	//int name_num;
	int weapon_id;
	warrior* pwarrior;

	weapon() {}
	weapon(int id, warrior* pwarrior_) :weapon_id(id), pwarrior(pwarrior_) {}
	virtual void attack(warrior* enemy) {}
	virtual ~weapon(){}
};

class arrow :public weapon
{
public:
	virtual void attack(warrior* enemy);
	arrow() {}
	~arrow(){}
	arrow(warrior* owner) :weapon(0, owner) {}
};
class bomb :public weapon
{
public:
	virtual void attack(warrior* enemy);
	bomb() {}
	~bomb(){}
	bomb(warrior* owner) :weapon(1, owner) {}
};
class sword :public weapon
{
public:
	virtual void attack(warrior* enemy);
	sword() {}
	~sword(){}
	sword(warrior* owner) :weapon(2, owner) {}
};


class warrior
{
public:
	int total_num;
	int warrior_id;
	int head_id;//1 for red,2 for blue
	int health;
	int force;

	bool turn;

	bool win;
	bool changed;

	int tot_weapon;
	int weapon_num[3];//0 a,1 b,2 s.
	arrow parrow;
	int used;
	bomb pbomb;
	sword psword;

	city* pcity;

	int position;
	string name;

	head* phead;
	warrior() {}
	virtual void hurt(int n)
	{
		health = health - n >= 0 ? health - n : 0;
	}
	void get_weapon(warrior* enemy);
	virtual void attack(warrior* enemy);
	virtual void move();
	virtual double get_morale() { return -1; }
	virtual int get_loyalty() { return -1; }
	warrior(int id, int num, head* p);
	virtual ~warrior() {}
};
class dragon :public warrior
{
public:
	double morale;
	double get_morale() { return morale; }
	dragon() {}
	dragon(int id, int num, head* p);
	~dragon() {}
	virtual void hurt(int n)
	{
		health -= n;
		//undone(delete?
	}
	virtual void attack() {}
};
class ninja :public warrior
{
public:
	ninja() {}
	ninja(int id, int num, head* p) :warrior(id, num, p)
	{
		tot_weapon = 2;
		weapon_num[num % 3]++;
		weapon_num[(num + 1) % 3]++;
	}
	virtual void hurt(int n) {}
	virtual void attack() {}
};
class iceman :public warrior
{
public:
	iceman() {}
	iceman(int id, int num, head* p) : warrior(id, num, p)
	{
		tot_weapon = 1;
		weapon_num[num % 3]++;
	}
	virtual void move();
	virtual void hurt(int n) {}
	virtual void attack() {}
};
class lion :public warrior
{
public:
	int loyalty;
	int get_loyalty() { return loyalty; }
	lion() {}
	lion(int id, int num, head* p);
	virtual void move();
	virtual void hurt(int n) {}
	virtual void attack() {}
};
class wolf :public warrior
{
public:
	wolf() {}
	wolf(int id, int num, head* p) : warrior(id, num, p)
	{
		tot_weapon = 0;
	}
	virtual void hurt(int n) {}
	virtual void attack() {}
};

void arrow::attack(warrior* enemy)
{
	enemy->hurt(3 * pwarrior->force / 10);
}
void bomb::attack(warrior* enemy)
{
	enemy->hurt(4 * pwarrior->force / 10);
	if (pwarrior->warrior_id != 1) pwarrior->hurt((4 * pwarrior->force / 10) / 2);
}
void sword::attack(warrior* enemy)
{
	enemy->hurt(2 * pwarrior->force / 10);
}


class head
{
public:
	string name;
	int name_num;
	int value;
	int total_warrior;
	int now;
	warrior* pwarrior[maxn];

	game* pgame;
	bool stopped;

	int to_cnt;
	bool win;

	head() {}
	head(int _value, string _name)
	{
		value = _value;
		name = _name;
		now = 0;
		if (name == "red") name_num = 0;
		else name_num = 1;
		total_warrior = 0;
		win = false;
		to_cnt = 0;
		stopped = false;
	}

	void produce();
};

void head::produce()
{
	int i = 5;
	if (stopped == true) return;
	bool have_made = false;
	int id = order[name_num][now];
	if (hp[id] <= value)
	{
		have_made = true;
		total_warrior++;
		value -= hp[id];
		if (all_name[id] == "dragon") pwarrior[total_warrior] = new dragon(0, total_warrior, this);
		else if (all_name[id] == "ninja") pwarrior[total_warrior] = new ninja(1, total_warrior, this);
		else if (all_name[id] == "iceman") pwarrior[total_warrior] = new iceman(2, total_warrior, this);
		else if (all_name[id] == "lion") pwarrior[total_warrior] = new lion(3, total_warrior, this);
		else if (all_name[id] == "wolf") pwarrior[total_warrior] = new wolf(4, total_warrior, this);
		now = (now + 1) % 5;
		printf("%03d:00 %s %s %d born\n", hour, name.c_str(), all_name[id].c_str(), total_warrior);
		if (id == 3) printf("Its loyalty is %d\n", pwarrior[total_warrior]->get_loyalty());
	}
	now = (now + 1) % 5;
	id = order[name_num][now];
	if (have_made == false) stopped = true;
	return;
}
warrior::warrior(int id, int num, head* p)
{
	warrior_id = id;
	total_num = num;
	phead = p;

	if (p->name == "red") head_id = 1;
	else head_id = 2;

	tot_weapon = 0;
	memset(weapon_num, 0, sizeof(weapon_num));
	health = hp[id];
	force = fc[id];
	if (id == 0) position = 0;
	else position = tot_city + 1;
	name = all_name[id];
	win = false;
	changed = false;
	used = 0;
}

void warrior::get_weapon(warrior* enemy)
{
	int tmp = 10;
	while (tmp--)
	{
		if (enemy->weapon_num[0] > 0)
		{
			enemy->weapon_num[0]--;
			weapon_num[0]++;
			enemy->tot_weapon--;
			tot_weapon++;
		}
		else if (enemy->weapon_num[1] > 0)
		{
			enemy->weapon_num[1]--;
			weapon_num[1]++;
			enemy->tot_weapon--;
			tot_weapon++;
		}
		else if (enemy->used > 0)
		{
			enemy->weapon_num[2]--;
			weapon_num[2]++;
			enemy->used--;
			used++;
			enemy->tot_weapon--;
			tot_weapon++;
		}
		else if (enemy->weapon_num[2] - enemy->used > 0)
		{
			enemy->weapon_num[2]--;
			weapon_num[2]++;
			enemy->tot_weapon--;
			tot_weapon++;
		}
	}
}

void warrior::attack(warrior* enemy)
{
	if (tot_weapon > 0)
	{
		if (weapon_num[0] > 0)
		{
			psword.attack(enemy);
			weapon_num[0]--;
			tot_weapon--;
		}
		else if (weapon_num[1] > 0)
		{
			pbomb.attack(enemy);
			weapon_num[1]--;
			tot_weapon--;
		}
		else if (weapon_num[2] > 0 && used < weapon_num[2])
		{
			parrow.attack(enemy);
			used++;
		}
		else if (weapon_num[2] == used)
		{
			parrow.attack(enemy);
			weapon_num[2]--;
			tot_weapon--;
		}
	}
}

void warrior::move()
{
	if (position == 0)
	{
		position++;
		pcity = ct[position];
		if (head_id == 1) pcity->pwarrior_red = this;
		else pcity->pwarrior_blue = this;
		pcity->warrior_num++;
		return;
	}
	else if (position == tot_city + 1)
	{
		position--;
		pcity = ct[position];
		if (head_id == 1) pcity->pwarrior_red = this;
		else pcity->pwarrior_blue = this;
		pcity->warrior_num++;
		return;
	}
	pcity->warrior_num--;
	if (head_id == 1) pcity->pwarrior_red = NULL;
	else pcity->pwarrior_blue = NULL;
	if (head_id == 1)
	{
		position++;
		if (position == tot_city + 1)
		{
			phead->to_cnt++;
			phead->win = true;
			return;
		}
		pcity=ct[position];
	}
	else
	{
		position--;
		if (position == 0)
		{
			phead->to_cnt++;
			phead->win = true;
			return;
		}
		pcity=ct[position];
	}
	if (head_id == 1) pcity->pwarrior_red = this;
	else pcity->pwarrior_blue = this;
	pcity->warrior_num++;

}

lion::lion(int id, int num, head* p) : warrior(id, num, p)
{
	tot_weapon = 1;
	weapon_num[num % 3]++;
	loyalty = phead->value;
}

void lion::move()
{
	if (position == 0)
	{
		position++;
		pcity = ct[position];
		if (head_id == 1) pcity->pwarrior_red = this;
		else pcity->pwarrior_blue = this;
		pcity->warrior_num++;
		loyalty--;
		return;
	}
	else if (position == tot_city + 1)
	{
		position--;
		pcity = ct[position];
		if (head_id == 1) pcity->pwarrior_red = this;
		else pcity->pwarrior_blue = this;
		pcity->warrior_num++;
		loyalty--;
		return;
	}
	pcity->warrior_num--;
	if (head_id == 1) pcity->pwarrior_red = NULL;
	else pcity->pwarrior_blue = NULL;
	if (head_id == 1)
	{
		position++;
		if (position == tot_city + 1)
		{
			phead->to_cnt++;
			phead->win = true;
			return;
		}
		pcity=ct[position];
	}
	else
	{
		position--;
		if (position == 0)
		{
			phead->to_cnt++;
			phead->win = true;
			return;
		}
		pcity = ct[position];
	}
	if (head_id == 1) pcity->pwarrior_red = this;
	else pcity->pwarrior_blue = this;
	pcity->warrior_num++;
	loyalty--;
}

void city::war()
{
	if (warrior_num == 2)
	{
		if (pwarrior_red->warrior_id == 4 && pwarrior_blue->warrior_id != 4)
			pwarrior_red->get_weapon(pwarrior_blue);
		if (pwarrior_blue->warrior_id == 4 && pwarrior_red->warrior_id != 4)
			pwarrior_blue->get_weapon(pwarrior_red);
		if (num % 2 == 1)
		{
			while (true)
			{
				pwarrior_red->attack(pwarrior_blue);
				if (pwarrior_red->health == 0) break;
				if (pwarrior_blue->health == 0) break;
				pwarrior_blue->attack(pwarrior_blue);
				if (pwarrior_red->health == 0) break;
				if (pwarrior_blue->health == 0) break;
				if (pwarrior_red->tot_weapon == 0 && pwarrior_blue->tot_weapon == 0) break;
			}
		}
		else
		{
			while (true)
			{
				pwarrior_blue->attack(pwarrior_blue);
				if (pwarrior_red->health == 0) break;
				if (pwarrior_blue->health == 0) break;
				pwarrior_red->attack(pwarrior_blue);
				if (pwarrior_red->health == 0) break;
				if (pwarrior_blue->health == 0) break;
				if (pwarrior_red->tot_weapon == 0 && pwarrior_blue->tot_weapon == 0) break;
			}
		}
		if (pwarrior_red->health == 0 && pwarrior_blue->health == 0)//print?
		{
			delete pwarrior_red; pwarrior_red = NULL;
			delete pwarrior_blue; pwarrior_blue = NULL;
		}
		else if (pwarrior_red->health != 0 && pwarrior_blue->health == 0)//print?
		{
			pwarrior_red->get_weapon(pwarrior_blue);
			delete pwarrior_blue; pwarrior_blue = NULL;
		}
		else if (pwarrior_red->health == 0 && pwarrior_blue->health != 0)//print?
		{
			pwarrior_blue->get_weapon(pwarrior_red);
			delete pwarrior_red; pwarrior_red = NULL;
		}
	}
}

dragon::dragon(int id, int num, head* p) :warrior(id, num, p)
{
	morale = 1.0 * p->value / hp[warrior_id];
	tot_weapon = 1;
	weapon_num[num % 3]++;
}

void iceman::move()
{
	if (position == 0)
	{
		position++;
		pcity = ct[position];
		if (head_id == 1) pcity->pwarrior_red = this;
		else pcity->pwarrior_blue = this;
		pcity->warrior_num++;
		health -= health / 10;
		return;
	}
	else if (position == tot_city + 1)
	{
		position--;
		pcity = ct[position];
		if (head_id == 1) pcity->pwarrior_red = this;
		else pcity->pwarrior_blue = this;
		pcity->warrior_num++;
		health -= health / 10;
		return;
	}
	pcity->warrior_num--;
	if (head_id == 1) pcity->pwarrior_red = NULL;
	else pcity->pwarrior_blue = NULL;
	health -= health / 10;
	if (head_id == 1)
	{
		position++;
		if (position == tot_city + 1)
		{
			phead->to_cnt++;
			phead->win = true;
			return;
		}
		pcity=ct[position];
	}
	else
	{
		position--;
		if (position == 0)
		{
			phead->to_cnt++;
			phead->win = true;
			return;
		}
		pcity=ct[position];
	}
	if (head_id == 1) pcity->pwarrior_red = this;
	else pcity->pwarrior_blue = this;
	pcity->warrior_num++;
}

void city::run()
{
	if (pwarrior_red)
	{
		if (pwarrior_red->warrior_id == 3 && pwarrior_red->get_morale() == 0)
		{
			delete pwarrior_red;
			pwarrior_red = NULL;
			warrior_num--;
		}
	}
}

game::game()
{
	cin >> m >> n >> k >> t;
	tot_city = n;
	for (int i = 0; i < 5; i++) cin >> hp[i];
	for (int i = 0; i < 5; i++) cin >> fc[i];
	for (int i = 1; i <= n; i++)
		if (ct[i]) delete ct[i];
	for (int i = 1; i <= n; i++) ct[i] = new city(i);
	qhead[1] = new head(m, "red");
	qhead[2] = new head(m, "blue");
}
game::~game()
{
	for (int i = 0; i < 3; i++) delete qhead[i];
	for (int i = 1; i <= n; i++) delete ct[i];
}
bool game::game_start()
{
	for (int i = 1; i <= 2; i++) qhead[i]->produce();
	for (int i = 1; i <= 2; i++) qhead[i]->pgame = this;
	for (int j = 1; j <= 2; j++)
		for (int i = 1; i <= qhead[j]->total_warrior; i++)
			if (qhead[j]->pwarrior[i]) qhead[j]->pwarrior[i]->move();
	if (qhead[1]->win || qhead[2]->win) return false;
	for (int i = 1; i <= tot_city; i++) ct[i]->war();
	return true;
}

int main()
{
	int casenum;
	cin >> casenum;
	for (int cases = 1; cases <= casenum; cases++)
	{
		cout << "Case " << cases << ":" << endl;
		game mygame;
		while (mygame.game_start()) { hour++; }
	}
}
