#include <iostream>
#include <conio.h>
#include <ctime>
#include <math.h>

using namespace std;

//game
void game_menu();
void game_menu_print(int );
int game_menu_select();

void game_map();
void game_map_easy(int );
void game_map_midium();
void game_map_hard();
void game_map_print(int );
int game_map_select();
int game_map_menu_select();


void game_store();

void game_bag();

void game_stat();

enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };
static int getDirKey() { return _getche() == 224 ? _getche() : 0; }

int zero = 0;

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

enum ITEM{
	ITEM_none,
	ITEM_ironsword,
	ITEM_longbow,
	ITEM_shortsword,
	ITEM_magicstaff,
	ITEM_coin,
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

struct _tagPLAYER
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
	float PLAYER_speed;
};

struct _tagPLAYER PLAYER;

struct _tagMONSTER
{
	char MONSTER_name[20];
	int MONSTER_num;
	int MONSTER_attack;
	int MONSTER_health;
	int MONSTER_defense;
	float MONSTER_speed;
};

struct _tagMONSTER MONSTER;

void main()
{
	game_menu();






}

void game_menu()
{
	int pause;
	system("cls");
	switch (game_menu_select()+1)
	{
	case MENU_map:
		game_map();
		break;
	case MENU_store:
		game_store();
		break;
	case MENU_stat:
		game_stat();
		break;
	case MENU_bag:
		game_bag();
		break;
	case MENU_exit:
		system("exit");
		break;
	default:
		cout << "엔터 후 다시 입력해 주세요." << endl;
		cin>>pause;
		game_menu();
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

	switch (game_map_select()+1)
	{
	case MAP_easy:
		cout << "EASY";
		game_map_menu_select();
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

void game_map_easy(int point_potential)
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
	
	cout<<"\n\n";
	//PLAYER
	cout <<"PLAYER : "<<PLAYER.str_name<<"\tJOB : " << PLAYER.str_job<<endl;
	cout <<"HP : "<<PLAYER.PLAYER_health<<"\tMP : " << PLAYER.PLYAER_mana<<endl;
	cout<<"\n\n\n";
	//MONSTER
	cout <<"MONSTER : "<<MONSTER.MONSTER_name<<endl;
	cout <<"HP : "<<MONSTER.MONSTER_health<<endl;
}

int game_map_menu_select()
{
	int point_potential;
	point_potential = 0;
	game_map_easy(point_potential);	//map 난이도에 따라 return
	for (;;) {
		switch (getDirKey())
		{
		case Left:
			if (point_potential == 0 || point_potential==2)
			cout << "더이상 그 방향으로 갈 수 없습니다" << endl;
			else
				point_potential--;
			break;
		case Up:
			if (point_potential == 0 || point_potential==1)
				cout << "더이상 그 방향으로 갈 수 없습니다" << endl;
			else
				point_potential -= 2;
			break;
		case Right:
			if (point_potential == 1 || point_potential==3)
			cout << "더이상 그 방향으로 갈 수 없습니다" << endl;
			else
				point_potential++;
			break;
		case Down:
			if (point_potential == 2 || point_potential==3)
				cout << "더이상 그 방향으로 갈 수 없습니다" << endl;
			else
			{
				point_potential+=2;
			}
			break;
		default:
			return point_potential;
			break;
		}
		game_map_easy(point_potential);
	}

}


void game_map_midium()
{



}




void game_map_hard()
{



}




//
void game_store()
{


}

void game_stat()
{


}

void game_bag()
{


}