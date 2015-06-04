#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Hero
{
protected:
	char* name;
	int base_attack;
	int health;

public:
	Hero(const char* _n="no name", int _h=100, int _b_a=50)
	{
		name = new char[strlen(_n) + 1];
		strcpy(name, _n);
		health = _h;
		base_attack = _b_a;
	}

	Hero(const Hero& other)
	{
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		base_attack = other.base_attack;
		health = other.health;
	}

	void operator=(const Hero& other)
	{
		delete[] name;
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		base_attack = other.base_attack;
		health = other.health;
	}

	void take_healing(int heal)
	{
		health += heal;
	}

	int get_health()
	{
		if (health<0)
		{
			return 0;
		}
		return health;
	}

	void change_health(int change)
	{
	    health-=change;
	}

	char* get_name()
	{
		return name;
	}

	virtual int get_attack()
	{
		return base_attack;
	}

	virtual ~Hero()
	{
		delete[] name;
	}
};

class Warrior : public Hero
{
	int crit;
	char* clan;
public:
	Warrior(const char* _n="Stupid warrior", int _h=100, int _b_a=20, int cr=50, const char* cl="Stupid clan") : Hero(_n, _h, _b_a)
	{
		crit = cr;
		clan = new char[strlen(cl) + 1];
		strcpy(clan, cl);
	}

	Warrior(const Warrior& other) : Hero(other)
	{	
        clan = new char[strlen(other.clan)+1];
        strcpy(clan,other.clan);
        crit=other.crit;
	}

	void operator=(const Warrior& other)
	{
	    Hero::operator=(other);
	    delete [] clan;
        clan = new char[strlen(other.clan)+1];
        strcpy(clan,other.clan);
        crit=other.crit;

	}

	int get_attack()
	{
		int b_a=base_attack;
	    if(rand()%(100/crit)==0)
        {
            b_a *= 2;
            cout<<get_name()<<" critical hit! Double damage!\n";
        }
		return b_a;
	}

	~Warrior()
	{
		delete[] clan;
	}
};

class Wizard : public Hero
{
    int drain;
    char* rang;
public:
    Wizard(const char* _n="Stupid wizard", int _h=100, int _b_a=20, int d=50, const char* r="Stupid rang") : Hero(_n, _h, _b_a)
	{
		drain = d;
		rang = new char[strlen(r) + 1];
		strcpy(rang, r);
	}

	Wizard(const Wizard& other) : Hero(other)
	{
		drain = other.drain;
		rang = new char[strlen(other.rang) + 1];
		strcpy(rang, other.rang);
	}

    void operator=(const Wizard& other)
    {
        Hero::operator=(other);
        drain = other.drain;
        delete [] rang;
		rang = new char[strlen(other.rang) + 1];
		strcpy(rang, other.rang);
    }

    int get_attack()
    {
    	int b_a=base_attack;
        if(rand()%(100/drain)==0)
        {
            take_healing(b_a/2);
            cout<<get_name()<<" drained "<<b_a/2<<" health from the enemy!\n";
        }
        return b_a;
    }

    ~Wizard()
    {
        delete[] rang;
    }
};

class Game
{
    Hero *good, *bad;
public:
    Game(Hero* g, Hero* b)
    {
        good=g;
        bad=b;
    }
     void run()
     {
        bool turn = rand()%2;
        int dmg;
        while((good->get_health()>0) && (bad->get_health()	>0))
        {
            if(turn)
            {
            	cout<<bad->get_name()<<" attacks!\n";
                dmg=bad->get_attack();
                good->change_health(dmg);
                cout<<good->get_name()<<" lost "<<dmg<<" health!"<<endl;
                turn=0;	
            }
            else
            {
            	cout<<good->get_name()<<" attacks!\n";
                dmg=good->get_attack();
                bad->change_health(dmg);
                cout<<bad->get_name()<<" lost "<<dmg<<" health!"<<endl;
                turn=1;
            }
            cout<<"Status:\n";

         	cout<<bad->get_name()<<"'s health: "<<bad->get_health()<<endl;
         	cout<<good->get_name()<<"'s health: "<<good->get_health()<<endl;
         	cout<<endl;
        }

        if(good->get_health()>0) cout<<good->get_name()<<" is the winner!\n";
        else cout<<bad->get_name()<<" is the winner!\n";
    }
};

int main()
{
	srand(time(NULL));

	Wizard b;

	Warrior a;

	Game play(&a,&b); 

	play.run();
	
	return 0;
}
