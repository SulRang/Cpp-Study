#include <iostream>
#include <conio.h>
#include <ctime>
#include <math.h>

#define ITEMMAX 4
#define LEVELMAX 5

using namespace std;

//game
void game_menu();
void game_menu_print(int);
int game_menu_select();

void game_map();
void game_map_easy();
void game_map_easy_monster();
void game_map_easy_print(int);
void game_map_midium();
void game_map_hard();
void game_map_print(int);
int game_map_select();
int game_map_menu_select();

void game_store();

void game_bag();

void game_stat();
void game_stat_print();

void back_to_menu();

enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };
static int getDirKey() { return _getche() == 224 ? _getche() : 0; }


int LEVELUP_EXP[5] = { 0, 100, 200, 300, 400 };
int LEVELUP_HEALTH[5] = { 0, 20, 25, 30, 40 };
int LEVELUP_ATTACK[5] = { 0, 3, 5, 7, 10 };
int LEVELUP_DEFENSE[5] = { 0, 5, 7, 10, 15 };

enum MENU
{
	MENU_none,
	MENU_map,
	MENU_store,
	MENU_stat,
	MENU_bag,
	MENU_exit,
	MENU_end
};

enum MAP_KINDS
{
	MAP_none,
	MAP_easy,
	MAP_midium,
	MAP_hard,
	MAP_back,
	MAP_end
};

enum PLAYER_ACTION {
	PLAYER_attack,
	PLAYER_item,
	PLAYER_skill,
	PLAYER_end
};

enum ITEM {
	ITEM_none,
	ITEM_ironsword,
	ITEM_longbow,
	ITEM_shortsword,
	ITEM_magicstaff,
	ITEM_end
};

enum JOB
{
	JOB_none,
	JOB_warrior,
	JOB_archer,
	JOB_thief,
	JOB_wizard,
	JOB_end
};

struct tagPLAYER
{
	char str_name[20];
	char str_job[20];
	int job_num;
	int PLAYER_num;
	int PLAYER_minattack;
	int PLAYER_maxattack;
	int PLAYER_health;
	int PLYAER_mana;
	int PLAYER_defense;
	int PLAYER_exp;
	int PLAYER_level;
	float PLAYER_speed;
};

struct tagPLAYER PLAYER;

struct tagMONSTER
{
	char MONSTER_name[20];
	int MONSTER_num;
	int MONSTER_minattack;
	int MONSTER_maxattack;
	int MONSTER_health;
	int MONSTER_defense;
	float MONSTER_speed;
};

struct tagMONSTER MONSTER;

struct tagITEM {
	char str_name[50] = "";
	char str_info[1000]= "";
	int ITEM_ATTACK = 0;
	int ITEM_HEALTH = 0;
	int ITEM_DEFENSE = 0;
	int ITEM_FLAG = 0;
};

struct tagITEM itemarray[ITEMMAX];

void main()
{
	game_menu();
}

void game_menu()
{
	system("cls");
	switch (game_menu_select() + 1)
	{
	case MENU_map:
		game_map();
		break;
	case MENU_store:
		game_store();
		break;
	case MENU_stat:
		game_stat_print();
		break;
	case MENU_bag:
		game_bag();
		break;
	case MENU_exit:
		system("exit");
		break;
	default:
		break;
	}
}

int game_menu_select()
{
	int point_potential;
	point_potential = 0;
	game_menu_print(point_potential);
	for (;;) {
		switch (getDirKey())
		{
		case Left:
			cout << "더이상 그 방향으로 갈 수 없습니다" << endl;
			break;
		case Up:
			if (point_potential == 0)
				cout << "더이상 그 방향으로 갈 수 없습니다" << endl;
			else
				point_potential--;
			break;
		case Right:
			cout << "더이상 그 방향으로 갈 수 없습니다" << endl;
			break;
		case Down:
			if (point_potential == 4)
			{
				cout << "더이상 그 방향으로 갈 수 없습니다" << endl;
			}
			else
			{
				point_potential++;
			}
			break;
		default:
			return point_potential;
			break;
		}
		game_menu_print(point_potential);
	}
}

void game_menu_print(int point_potential)
{
	int i;
	system("cls");
	for (i = 0; i < 5; i++) {
		if (i == 0) {
			cout << "MAP";
			if (point_potential == 0)
			{
				cout << "\t<-";
			}
			cout << "\n";
		}
		if (i == 1) {
			cout << "STORE";
			if (point_potential == 1)
			{
				cout << "\t<-";
			}
			cout << "\n";
		}
		if (i == 2)
		{
			cout << "STAT";
			if (point_potential == 2)
			{
				cout << "\t<-";
			}
			cout << "\n";
		}
		if (i == 3) {
			cout << "BAG";
			if (point_potential == 3)
			{
				cout << "\t<-";
			}
			cout << "\n";
		}
		if (i == 4) {
			cout << "EXIT";
			if (point_potential == 4)
			{
				cout << "\t<-";
			}
			cout << "\n";
		}
	}
}

void game_map()
{
	game_stat();
	switch (game_map_select() + 1)
	{
	case MAP_easy:
		cout << "EASY";
		game_map_easy();
		break;
	case MAP_midium:
		cout << "MIDIUM";
		game_map_midium();
		break;
	case MAP_hard:
		cout << "HARD";
		game_map_hard();
		break;
	case MAP_back:
		cout << "BACK";
		game_menu();
	default:
		break;
	}
}

int game_map_select()
{
	int point_potential;
	point_potential = 0;
	game_map_print(point_potential);
	for (;;) {
		switch (getDirKey())
		{
		case Left:
			cout << "더이상 그 방향으로 갈 수 없습니다" << endl;
			break;
		case Up:
			if (point_potential == 0)
				cout << "더이상 그 방향으로 갈 수 없습니다" << endl;
			else
				point_potential--;
			break;
		case Right:
			cout << "더이상 그 방향으로 갈 수 없습니다" << endl;
			break;
		case Down:
			if (point_potential == 3)
			{
				cout << "더이상 그 방향으로 갈 수 없습니다" << endl;
			}
			else
			{
				point_potential++;
			}
			break;
		default:
			return point_potential;
			break;
		}
		game_map_print(point_potential);
	}
}

void game_map_print(int point_potential)
{
	int i;
	system("cls");
	for (i = 0; i < 4; i++) {
		if (i == 0) {
			cout << "EASY";
			if (point_potential == 0)
			{
				cout << "\t<-";
			}
			cout << "\n";
		}
		if (i == 1) {
			cout << "MIDIUM";
			if (point_potential == 1)
			{
				cout << "\t<-";
			}
			cout << "\n";
		}
		if (i == 2)
		{
			cout << "HARD";
			if (point_potential == 2)
			{
				cout << "\t<-";
			}
			cout << "\n";
		}
		if (i == 3) {
			cout << "BACK";
			if (point_potential == 3)
			{
				cout << "\t<-";
			}
			cout << "\n";
		}
	}
}

void game_map_easy()
{
	int playerattack;
	switch (game_map_menu_select())
	{
	case PLAYER_attack:
		playerattack = rand() % (PLAYER.PLAYER_maxattack - PLAYER.PLAYER_minattack) + 1;
		MONSTER.MONSTER_health -= playerattack;
		cout << "ATTACK!! " << "Damage : " << playerattack << endl;
		break;
	case PLAYER_item:
		cout << "item!!";
		break;
	case PLAYER_skill:
		cout << "skill!!";
		break;
	case PLAYER_end:
		cout << "BACK";
		game_menu();
		break;
	default:
		break;
	}
		//MONSTER ACTION
	game_map_easy_monster();
		//재귀 or 반복문 사용
	if (MONSTER.MONSTER_health <= 0)
	{
		cout << "몬스터 사냥에 성공하였습니다!!";
		PLAYER.PLAYER_exp += 10;
		_getch();
		game_menu();
	}
	else if (PLAYER.PLAYER_health <= 0)
	{
		cout << "몬스터 사냥에 실패했습니다...";
		_getch();
		game_menu();
	}
	else {
		_getch();
		game_map_easy();
	}
}

void game_map_easy_monster()
{
	int monsterattack;
	monsterattack = rand() % (MONSTER.MONSTER_maxattack - MONSTER.MONSTER_minattack);
	PLAYER.PLAYER_health -= monsterattack;
	cout <<"MONSTER ATTACK "<< "DAMAGED : " << monsterattack << endl;
}

void game_map_easy_print(int point_potential)
{
	int i;
	//MENU
	system("cls");
	for (i = 0; i < 4; i++) {
		if (i == 0) {
			cout << "ATTACK";
			if (point_potential == 0)
			{
				cout << "\t<-\t";
			}
			else
				cout << "\t\t";
		}
		if (i == 1) {
			cout << "ITEM";
			if (point_potential == 1)
			{
				cout << "\t<-\n";
			}
			else
				cout << "\t\n";
		}
		if (i == 2)
		{
			cout << "SKILL";
			if (point_potential == 2)
			{
				cout << "\t<-\t";
			}
			else
				cout << "\t\t";
		}
		if (i == 3) {
			cout << "BACK";
			if (point_potential == 3)
			{
				cout << "\t<-\n";
			}
			else
				cout << "\t\n";
		}
	}
	cout << "\n\n";
	//PLAYER
	cout << "PLAYER : " << PLAYER.str_name << "\tJOB : " << PLAYER.str_job << endl;
	cout << "HP : " << PLAYER.PLAYER_health << endl;
	cout << "\n\n";
	//MONSTER
	cout << "MONSTER : " << MONSTER.MONSTER_name << endl;
	cout << "HP : " << MONSTER.MONSTER_health << endl;
}

int game_map_menu_select()
{
	int point_potential;
	point_potential = 0;
	game_map_easy_print(point_potential);	//map 난이도에 따라 return
	for (;;) {
		switch (getDirKey())
		{
		case Left:
			if (point_potential == 0 || point_potential == 2)
				cout << "더이상 그 방향으로 갈 수 없습니다" << endl;
			else
				point_potential--;
			break;
		case Up:
			if (point_potential == 0 || point_potential == 1)
				cout << "더이상 그 방향으로 갈 수 없습니다" << endl;
			else
				point_potential -= 2;
			break;
		case Right:
			if (point_potential == 1 || point_potential == 3)
				cout << "더이상 그 방향으로 갈 수 없습니다" << endl;
			else
				point_potential++;
			break;
		case Down:
			if (point_potential == 2 || point_potential == 3)
				cout << "더이상 그 방향으로 갈 수 없습니다" << endl;
			else
			{
				point_potential += 2;
			}
			break;
		default:
			return point_potential;
			break;
		}
		game_map_easy_print(point_potential);
	}
}

void game_map_midium()
{



}

void game_map_hard()
{



}

void game_store()
{
	int i, item_num;
	cout << "-------------------------------- STORE --------------------------------\n";
	for (i = 0; i < ITEMMAX; i++)
	{
		cout << "NUM : \t" << i+1 << endl;
		cout << "NAME : \t" << itemarray[i].str_name << endl;
		cout << "INFO : \t" << itemarray[i].str_info << endl;
		cout << "ATTACK : \t" << itemarray[i].ITEM_ATTACK << endl;
		cout << "HEALTH : \t" << itemarray[i].ITEM_HEALTH << endl;
		cout << "DEFENSE : \t" << itemarray[i].ITEM_DEFENSE << endl;
	}
	//sell
	cout << "구매하실 물건을 입력하십시오. 1~4";
	cin >> item_num;
	//인벤토리로 + 돈
	switch (item_num)
	{
	case ITEM_ironsword:
		//일단은 장착
		itemarray[ITEM_ironsword-1].ITEM_FLAG = 1;
		break;
	case ITEM_longbow:
		itemarray[ITEM_longbow-1].ITEM_FLAG = 1;
		break;
	case ITEM_shortsword:
		itemarray[ITEM_shortsword-1].ITEM_FLAG = 1;
		break;
	case ITEM_magicstaff:
		itemarray[ITEM_magicstaff-1].ITEM_FLAG = 1;
		break;
	default:
		break;
	}
	back_to_menu();
}

void game_stat()
{
	int i = 0;
	MONSTER.MONSTER_health = 100;
	MONSTER.MONSTER_maxattack = 20;
	MONSTER.MONSTER_minattack = 10;
	PLAYER.PLAYER_health = 100;
	PLAYER.PLAYER_maxattack = 25;
	PLAYER.PLAYER_minattack = 15;
	//item 유무
	for(i=0 ;i<ITEMMAX;i++)
		if (itemarray[i].ITEM_FLAG == 1)
		{
			PLAYER.PLAYER_maxattack += itemarray[i].ITEM_ATTACK;
			PLAYER.PLAYER_minattack += itemarray[i].ITEM_ATTACK;
			PLAYER.PLAYER_health += itemarray[i].ITEM_HEALTH;
			PLAYER.PLAYER_defense += itemarray[i].ITEM_DEFENSE;
		}
	//level
	for (i = 1; i < LEVELMAX; i++)
	{
		if (PLAYER.PLAYER_exp >= LEVELUP_EXP[i]) {
			PLAYER.PLAYER_level++;
			PLAYER.PLAYER_exp -= LEVELUP_EXP[i];
			PLAYER.PLAYER_health += LEVELUP_HEALTH[i];
			PLAYER.PLAYER_maxattack += LEVELUP_ATTACK[i];
			PLAYER.PLAYER_minattack += LEVELUP_ATTACK[i];
			PLAYER.PLAYER_defense += LEVELUP_DEFENSE[i];
		}
		else
			break;
	}
}

void game_stat_print()
{
	system("cls");
	game_stat();
	cout << "NAME : \t" << PLAYER.str_name << endl;
	cout << "JOB : \t" << PLAYER.str_job << endl;
	cout << "HEALTH :\t" << PLAYER.PLAYER_health << endl;
	cout << "MANA :\t" << PLAYER.PLYAER_mana << endl;
	cout << "ATTACK :\t" << PLAYER.PLAYER_minattack << " ~ " << PLAYER.PLAYER_maxattack << endl;
	cout << "DEFENSE :\t" << PLAYER.PLAYER_defense << endl;
	back_to_menu();
}

void game_bag()
{
	int i;
	for (i = 0; i < ITEMMAX; i++)
	{
		if (itemarray[i].ITEM_FLAG == 1) {
			cout << "NUM : \t" << i+1 << endl;
			cout << "NAME : \t" << itemarray[i].str_name << endl;
			cout << "INFO : \t" << itemarray[i].str_info << endl;
			cout << "ATTACK : \t" << itemarray[i].ITEM_ATTACK << endl;
			cout << "HEALTH : \t" << itemarray[i].ITEM_HEALTH << endl;
			cout << "DEFENSE : \t" << itemarray[i].ITEM_DEFENSE << endl;
		}
	}
	back_to_menu();
}

void back_to_menu()
{
	int back;
	cout << "돌아가시겠습니까? back : 1" << endl;
	cin >> back;

	if (back == 1)
		game_menu();
}
