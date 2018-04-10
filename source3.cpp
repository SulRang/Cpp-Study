#include <iostream>
#include <conio.h>
#include <ctime>


using namespace std;

//game
void game_menu();
void game_menu_print(int );
int game_menu_select();

void game_map();
void game_map_easy();
void game_map_midium();
void game_map_hard();
void game_map_print(int );
int game_map_select();

void game_store();

void game_bag();

void game_stat();

enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };
static int getDirKey() { return _getche() == 224 ? _getche() : 0; } //특수키를 받기 위해 getche를 두번 부른다.


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

enum JOB
{
	JOB_none,
	JOB_warrior,
	JOB_archer,
	JOB_thief,
	JOB_wizard,
	JOB_end
};


struct PLAYER
{
	char str_name[20];
	char str_job[20];
	int job_num;
	int player_num;
	int PLAYER_attack;
	int PLAYER_health;
	int PLAYER_defense;
	float PLAYER_SPEED;
};

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