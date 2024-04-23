#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <clocale>
#include <stdlib.h>
#include <ctime>
#include "Values.h"

using namespace std;

const int tree = 3;
const int road = 2;
const int mountain = 7;
const int water = 12;
const char trees = 'R';
const char roads = '_';
const char mountains = 'M';
const char waters = '~';
const char player = '0';
const char house = '4';
const char cities = '&';
const char king_towers = '8';
const char chest = 'c';
const char chest_with_lock = 'u';
const char hilka = 'h';
const char shop = '^';

int upgrade_healht = 0;
int upgrade_damage = 2;
int experience = 0;


bool elements[4] = { 0,0,0,0 }; // земля вода огонь воздух
bool mantra[4] =   { 0,0,0,0 };

int toxin = 0; 

int sharpness = 0;


int cpositioni = 0;
int cpositionj = 0;

int hpositioni = 0;
int hpositionj = 0;

int positioni = 0;
int positionj = 0;

int real_time = 0;
int buff_time = 0;
int health = 100;
int max_health = 100;
int buff_max_health = 0;
int level = 1;
int keys = 100;
int rep = 1;
int weapon = 0; //0 - ничего, 1 - палочка (1), 2 - лук (1), 7 - меч (2)
int damage = 0;
int buff_damage = 0;
int money = 100;
int buff_money = 0;
vector<int> stats;
vector<int> quests;

const int HOME_SIZE = 5;
const int CITY_SIZE = 8;
const int MAP_SIZE = 10;

char home_high[5][5] =       { {'_','_','_','_','_'}, // positioni = 0 positionj = 9
                               {'u','_','_','p','_'}, // Hinigun
                               {'_','_','_','_','_'}, // квесты 4,10
                               {'_','_','_','_','_'},
                               {'c','c','c','_','u'} };

char home_crossroads[5][5] = { {'_','_','_','_','u'}, // positioni = 2 positionj = 5
                               {'_','_','_','_','c'}, // mrs Pikul
                               {'p','_','_','_','c'}, // квесты 6,7
                               {'_','_','_','_','c'},
                               {'_','u','_','_','_'} };

char home_water[5][5] =      { {'_','_','c','c','c'}, // positioni = 5 positionj = 4
                               {'_','_','_','_','_'}, // mr Alevandr
                               {'_','_','_','u','_'}, //квесты 8,12
                               {'u','_','_','_','p'},
                               {'_','_','_','_','_'} };

char home_mountain[5][5] =   { {'_','_','_','c','c'}, // positioni = 7 positionj = 9
                               {'_','_','_','_','c'}, // mr Doorsle
                               {'u','_','_','_','u'}, // квесты  5,13
                               {'_','_','_','_','_'},
                               {'_','_','_','_','p'} };

char home_forest[5][5] =     { {'_','_','_','c','_'}, // positioni = 9 positionj = 0
                               {'u','_','p','_','c'}, // forester Ien
                               {'_','_','_','_','_'}, // квесты 14,15
                               {'c','_','_','_','u'},
                               {'_','_','_','_','_'} };
char lake_city[8][8] =     { {'_','h','_','_','_','_','_','u'},
                             {'_','_','_','_','_','_','_','_'},
                             {'_','p','_','_','_','_','_','_'},
                             {'^','_','_','_','_','_','p','_'},
                             {'_','_','_','u','_','_','_','_'},
                             {'^','_','_','_','_','_','_','_'},
                             {'^','_','_','p','_','_','_','c'},
                             {'^','_','u','_','_','u','_','c'} };

int days = 1;


// i = 0; j = 1 - hillka
// i=0; j = 2 - оружейная;
// i = 1;j = 4 - для магов;  i = 1;j = 6 - для лучников; i = 1;j = 7 - для мечников
// i = 2 j = 0 - бедняк, квесты 1,2,3
// i = 3 j = 6 - лакей, квесты 11,9 (у тебя недостаточносилы, lvl>2, rep>3, damage>4)
// i = 7 j = 0 - городской стражник, квесты 16,17 (у тебя недостаточносилы, lvl>4, rep>6, damage>6)
// i=2 j=2

char forest_city[8][8] =     { {'_','h','_','_','_','_','_','_'}, // i = 4; j = 7
                               {'_','_','u','_','_','_','u','_'},
                               {'_','_','_','_','_','_','_','_'},
                               {'^','_','_','_','_','c','_','_'}, // i = 3; j = 0 - оружейная
                               {'_','_','_','p','_','c','_','_'}, //i = 4; j = 3 cвященник, квесты 18
                               {'^','_','_','_','_','c','_','_'}, // i = 5; j = 0 - для магов, i = 6; j = 0 - лучники, i = 7; j = 0 - мечники
                               {'^','_','_','_','_','_','_','p'}, //i = 6; j = 7 монах, квесты 19,20
                               {'^','_','u','_','_','p','_','_'} };//i = 7; j = 5 уборшик, просто +1 репутации

char king_tower[8][8] = { {'_','h','_','_','_','_','_','_'},
                          {'_','_','_','R','R','~','_','R'},
                          {'_','_','_','R','R','~','_','R'},
                          {'_','_','_','~','~','~','p','_'},
                          {'p','_','_','_','_','_','_','_'},
                          {'R','_','_','_','_','_','_','R'},
                          {'R','R','_','_','_','_','R','R'},
                          {'R','R','R','q','K','R','R','R'}};


char map[10][10] =     { {'_','R','R','R','R','_','_','R','_','4'},     //1
                         {'_','R','R','R','R','R','_','_','_','R'},     //2
                         {'_','_','&','_','_','4','_','R','R','R'},     //3
                         {'M','M','_','~','~','_','_','R','R','R'},     //4
                         {'M','M','M','~','~','~','_','M','M','&'},     //5
                         {'M','R','M','~','4','_','_','M','M','R'},     //6
                         {'M','M','M','M','R','_','R','R','R','R'},     //7
                         {'R','R','R','R','_','~','_','_','R','4'},     //8
                         {'R','R','R','4','_','~','_','R','R','M'},     //9
                         {'4','R','R','_','8','~','~','R','R','R'} };   //10

char real_map[10][10] =   { {'0','R','R','R','R','_','_','R','_','4'},     //1
                            {'_','R','R','R','R','R','_','_','_','R'},     //2
                            {'_','_','&','_','_','4','_','R','R','R'},     //3
                            {'M','M','_','~','~','_','_','R','R','R'},     //4
                            {'M','M','M','~','~','~','_','M','M','&'},     //5
                            {'M','R','M','~','4','_','_','M','M','R'},     //6
                            {'M','M','M','M','R','_','R','R','R','R'},     //7
                            {'R','R','R','R','_','~','_','_','R','4'},     //8
                            {'R','R','R','4','_','~','_','R','R','M'},     //9
                            {'4','R','R','_','8','~','~','R','R','R'} };   //10


void show_stats(void) {
    string dayornight = " DAY ";
    if (real_time > ((48 + buff_time) / 2)) {
        dayornight =    "NIGHT";
    }
    string real_weapon = "  NO WEAPON";
    if (weapon == 1) {
        real_weapon =    "MAGIC WAND";
    }
    if (weapon == 2) {
        real_weapon = "HUNTER BOW";
    }
    if (weapon == 3) {
        real_weapon = "  SWARD   ";
    }
    cout << "\t\t\t--- TIME: " << real_time << "   XP:" << health << "/" << max_health<< "   LEVEL: " << level << " ---" << endl;
    cout << "\t\t  --- KEYS: " << keys << "   REP:" << rep << "   DAMAGE: " << damage << "   MONEY: " << money << " ---" << endl;
    cout << "\t\t\t "<< "--- WEAPON: "<< real_weapon << "\t  " << dayornight << " #" << days << " ---" << endl;
}
char input_moving(int n, int real_positioni, int real_positionj) {
    char move = 'n';
    cout << " Move ";
    cin >> move;
    while (!cin) {
        cin.clear();
        while (cin.get() != '\n');
        cout << " Input letter ";
        cin >> move;
    }
    if (move != 'w' && move != 'a' && move != 's' && move != 'd' &&
        move != 'z' && move != 'l' && move != 'e' && move != 'q') {
        cout << " Input only 'w','a','s','d','z','l','e','q' ";
    }
    if (real_positioni == 0 && move == 'w') {
        cout << " You can't go up, input another command " << endl;
        move = 'n';
    }
    if ((real_positioni == n-1) && move == 's') {
        cout << " You can't go up, input another command " << endl;
        move = 'n';
    }
    if (real_positionj == 0 && move == 'a') {
        cout << " You can't go left, input another command " << endl;
        move = 'n';
    }
    if (real_positionj == n-1 && move == 'd') {
        cout << " You can't go right, input another command " << endl;
        move = 'n';
    }
    return move;

}

void ruels(void) {
    cout << " -------------------------  Welcome to the my first game!  --------------------------" << endl;
    cout << " ----------------------------- Welcome, dear player! -------------------------------- " << endl
        << "   Ther is a game about poeple, who lived many and many years ago in world of magic" << endl
        << " In this world you can see trees 'R', rocks 'M', water '~' and roads '_'. You are '0'" << endl
        << " It will take you different amounts of real_time to overcome this:" << endl
        << "\t\t\t      roads     -  2 units of time" << endl
        << "\t\t\t      trees     -  3 units of time" << endl
        << "\t\t\t      mountains -  7 units of time" << endl
        << "\t\t\t      water     - 12 units of time" << endl << endl
        << " The map also contains king tower '8', cities '&' and houses '4' where you can receive and" << endl
        << "\t\t        complete different intersting missions" << endl
        << " \t\t      Moving inside these spends 0 units of real_time" << endl
        << " In city you can buy or upgrade weapons, heal and take a break from a long journey." << endl
        << "\t\t\t Hotkeys: " << endl << "\t\t\t\t -- 'w','a','s','d' for moving" << endl
        << "\t\t\t\t -- 'z' to save" << endl << "\t\t\t\t -- 'l' to load" << endl << "\t\t\t\t -- 'e' to attack" << endl
        << "\t\t\t\t -- 'q' to quit the game" << endl
        << " To select place to attack, enter 'w'/'a'/'s'/'d' point by point and add 'e' at the end" << endl
        << " In the Game you will have to fight monsters, upgrade your character and make friends" << endl
        << "\t\t\t         Have a nice time!" << endl << endl;
}

int if_integer(void) {
    int value = 0;
    cin >> value;
    while (!cin) {
        cin.clear();
        while (cin.get() != '\n');
        cout << "\t\t Input integer ";
        cin >> value;
    }
    while (cin.get() != '\n');
    ;
    return value;
}