#ifndef VALUES
#define VALUES
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <clocale>
#include <stdlib.h>
#include <ctime>

using namespace std;

extern const int tree;
extern const int road;
extern const int mountain;
extern const int water;
extern const char trees;
extern const char roads;
extern const char mountains;
extern const char waters;
extern const char player;
extern const char house;
extern const char cities;
extern const char king_towers;
extern const char chest;
extern const char chest_with_lock;
extern const char hilka;
extern const char shop;

extern int upgrade_healht;
extern int upgrade_damage;
extern int experience;

extern bool elements[4];
extern bool mantra[4];

extern int sharpness;

extern int toxin;

extern int positioni;
extern int positionj;

extern int hpositioni;
extern int hpositionj;

extern int cpositioni;
extern int cpositionj;

extern int real_time;
extern int buff_time;
extern int health;
extern int max_health;
extern int buff_max_health;
extern int level;
extern int keys;
extern int rep;
extern int weapon; //0 - ничего, 1 - палочка (1), 2 - лук (1), 7 - меч (2)
extern int damage;
extern int buff_damage;
extern int money;
extern int buff_money;

extern vector<int> stats;
extern vector<int> quests;

extern const int HOME_SIZE;
extern const int CITY_SIZE;
extern const int MAP_SIZE;

extern char home_high[5][5];
extern char home_crossroads[5][5];
extern char home_water[5][5];
extern char home_mountain[5][5];
extern char home_forest[5][5];
extern char lake_city[8][8];
extern char forest_city[8][8];
extern char king_tower[8][8];

extern char map[10][10];   //10
extern char real_map[10][10];   //10

extern int days;

void ruels(void);
void show_stats(void);
char input_moving(int n, int real_positioni, int real_positionj);
int if_integer(void);
#endif