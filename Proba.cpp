#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <clocale>
#include <stdlib.h>
#include <ctime>
#include "Maps.h"
#include "Houses.h"
#include "Load_Save.h"
#include "Values.h"
#include "Cities.h"
#include "Shops.h"

int time_after_moving(char type) {
    char tree = 'R';
    char mountain = 'M';
    char water = '~';
    char road = '_';
    int k = 1;
    if (real_time >= 24)
        k = 2;
    if (type == tree)
        real_time += 3*k;
    if (type == mountain)
        real_time += 7*k;
    if (type == water)
        real_time += 12*k;
    if (type == road)
        real_time += 2*k;
    if (real_time > 48 + buff_time) {
        real_time -= (48 + buff_time);
        days++;
    }
    return real_time;
}

int main(void) {
    srand(time(0));
    setlocale(LC_CTYPE, "rus");

    char move = 'z';
    char type = '_';
    string file_name = " ";
    int tmp = 0;

    //ruels();
    cout_map(real_map);
    move = input_moving(MAP_SIZE, positioni,positionj);
    while (move == 'n') {
        cin.clear();
        move = input_moving(MAP_SIZE, positioni, positionj);
    }

    enum MOVE { up = 'w', left = 'a', down = 's', right = 'd', save = 'z', load = 'l', attack = 'e', quit = 'q' };

    while (move != quit) {
        if (move == up || move == down || move == left || move == right) {
            type = moving(real_map, move);
            if (type == trees || type == mountains || type == roads || type == waters) {
                real_time = time_after_moving(type);
                cout_map(real_map);
            }
            if (type == house) {
                string home_type = "";
                char house[5][5];
                char real_house[5][5];
                if (positioni == 0 && positionj == 9) {
                    cout << "\t------------------ HIEST HOUSE ------------------" << endl;
                    home_type = "high";
                    for (int i = 0; i < 5; i++) {
                        for (int j = 0; j < 5; j++) {
                            house[i][j] = home_high[i][j];
                            real_house[i][j] = home_high[i][j];
                        }
                    }
                }
                if (positioni == 2 && positionj == 5) {
                    cout << "\t---------------- CROSSROAD HOUSE ----------------" << endl;
                    home_type = "crossroad";
                    for (int i = 0; i < 5; i++) {
                        for (int j = 0; j < 5; j++) {
                            house[i][j] = home_crossroads[i][j];
                            real_house[i][j] = home_crossroads[i][j];
                        }
                    }

                }
                if (positioni == 5 && positionj == 4) {
                    cout << "\t---------------- HOUSE NEAR LAKE ----------------" << endl;
                    home_type = "lake";
                    for (int i = 0; i < 5; i++) {
                        for (int j = 0; j < 5; j++) {
                            house[i][j] = home_water[i][j];
                            real_house[i][j] = home_water[i][j];
                        }
                    }

                }
                if (positioni == 7 && positionj == 9) {
                    cout << "\t----------- HOUSE NEAR LONELY MOUNTAIN ----------" << endl;
                    home_type = "mountain";
                    for (int i = 0; i < 5; i++) {
                        for (int j = 0; j < 5; j++) {
                            house[i][j] = home_mountain[i][j];
                            real_house[i][j] = home_mountain[i][j];
                        }
                    }
                }
                if (positioni == 9 && positionj == 0) {
                    cout << "\t---------------- HOUSE IN FOREST ----------------" << endl;
                    home_type = "forest";
                    for (int i = 0; i < 5; i++) {
                        for (int j = 0; j < 5; j++) {
                            house[i][j] = home_forest[i][j];
                            real_house[i][j] = home_forest[i][j];
                        }
                    }
                }

                hpositioni = 0;
                hpositionj = 0;
                real_house[0][0] = '0';

                cout_house(real_house);
                move = input_moving(HOME_SIZE, hpositioni, hpositionj);
                real_house[hpositioni][hpositionj] = house[hpositioni][hpositionj];
                type = house_moving(real_house, house, move);
                cout_house(real_house);
                while (move != 'q') {
                    if (type == chest) {
                        money++;
                        cout << " You got +1 money" << endl;
                        if (rand() % 5 == 0) {
                            money += 2;
                            cout << " You got +2 money" << endl;
                        }
                        if (rand() % 7 == 0) {
                            upgrade_healht++;
                            cout << " You got +1 upgrade healht" << endl;
                        }
                        if (rand() % 13 == 0) {
                            upgrade_damage++;
                            cout << " You got +1 upgrade damage" << endl;
                        }
                        house[hpositioni][hpositionj] = '_';
                    }
                    if (type == roads) {
                        real_house[hpositioni][hpositionj] = '0';
                    }
                    if (type == chest_with_lock && keys > 0) {
                        cout << " You used key " << endl;
                        keys--;
                        money += 3;
                        if (rand() % 2 == 0) {
                            upgrade_damage++;
                            cout << " You got +1 upgrade damage" << endl;
                        }
                        else {
                            upgrade_healht++;
                            cout << " You got +1 upgrade healht" << endl;
                        }
                        if (rand() % 5 == 0) {
                            keys++;
                            cout << " You got +1 key" << endl;
                        }
                        house[hpositioni][hpositionj] = '_';
                    }

                    move = input_moving(HOME_SIZE, hpositioni , hpositionj);
                    real_house[hpositioni][hpositionj] = house[hpositioni][hpositionj];
                    type = house_moving(real_house, house, move);
                    cout_house(real_house);
                }
                if (home_type == "high") {
                    for (int i = 0; i < 5; i++) {
                        for (int j = 0; j < 5; j++) {
                            home_high[i][j] = real_house[i][j];
                        }
                    }
                }
                if (home_type == "crossroad") {
                    for (int i = 0; i < 5; i++) {
                        for (int j = 0; j < 5; j++) {
                            home_crossroads[i][j] = real_house[i][j];
                        }
                    }
                }
                if (home_type == "lake") {
                    for (int i = 0; i < 5; i++) {
                        for (int j = 0; j < 5; j++) {
                            home_water[i][j] = real_house[i][j];
                        }
                    }
                }

                if (home_type == "mountain") {
                    for (int i = 0; i < 5; i++) {
                        for (int j = 0; j < 5; j++) {
                            home_mountain[i][j] = real_house[i][j];
                        }
                    }
                }
                if (home_type == "forest") {
                    for (int i = 0; i < 5; i++) {
                        for (int j = 0; j < 5; j++) {
                            home_forest[i][j] = real_house[i][j];
                        }
                    }
                }

                cout_map(real_map);
            }
            if (type == cities) {
                string city_name = "";
                char city[8][8];
                char real_city[8][8];

                if (positioni == 2 && positionj == 2) {
                    cout << "\t\t------------------- LAKE CITY -------------------" << endl;
                    city_name = "lake";
                    for (int i = 0; i < 8; i++) {
                        for (int j = 0; j < 8; j++) {
                            city[i][j] = lake_city[i][j];
                            real_city[i][j] = lake_city[i][j];
                        }
                    }
                }
                if (positioni == 4 && positionj == 9) {
                    cout << "\t\t------------------ FOREST CITY -----------------" << endl;
                    city_name = "forest";
                    for (int i = 0; i < 8; i++) {
                        for (int j = 0; j < 8; j++) {
                            city[i][j] = forest_city[i][j];
                            real_city[i][j] = forest_city[i][j];
                        }
                    }
                }
                cpositioni = 0;
                cpositionj = 0;
                real_city[0][0] = '0';

                cout_city(real_city, true);
                move = input_moving(CITY_SIZE, cpositioni, cpositionj);
                real_city[cpositioni][cpositionj] = city[cpositioni][cpositionj];
                type = city_moving(real_city, city, move);
                while (move != 'q') {
                    bool stirka = true;
                    if (type == chest) {
                        money++;
                        cout << " You got +1 money" << endl;
                        if (rand() % 5 == 0) {
                            money += 2;
                            cout << " You got +2 money" << endl;
                        }
                        if (rand() % 11 == 0) {
                            upgrade_healht++;
                            cout << " You got +1 upgrade healht" << endl;
                        }
                        if (rand() % 13 == 0) {
                            upgrade_damage++;
                            cout << " You got +1 upgrade damage" << endl;
                        }
                        city[cpositioni][cpositionj] = '_';
                    }
                    if (type == chest_with_lock && keys > 0) {
                        cout << " You used key " << endl;
                        keys--;
                        money += 3;
                        if (rand() % 2 == 0) {
                            upgrade_damage++;
                            cout << " You got +1 upgrade damage" << endl;
                        }
                        else {
                            upgrade_healht++;
                            cout << " You got +1 upgrade healht" << endl;
                        }
                        if (rand() % 5 == 0) {
                            keys++;
                            cout << " You got +1 key" << endl;
                        }
                        city[cpositioni][cpositionj] = '_';
                    }
                    // i = 0; j = 1 - hillka
                    // i = 3; j = 0 - оружейная;
                    // i = 5; j = 0 - для магов; 
                    // i = 6; j = 0 - для лучников;
                    // i = 7; j = 0 - для мечников
                    if (type == hilka && money > 1 && health == max_health) {
                        cout << endl << " \t\t\t\t\t You are healthy" << endl << endl;
                    }
                    if (type == hilka && money > 1 && health < max_health) {
                        health = max_health;
                        money -= 2;
                        cout << endl << " \t\t\t\t\t You are healthy" << endl << endl;
                    }
                    if (type == hilka && money < 2 && health < max_health) {
                        cout << "\t\t\tYou don't have enough money for treatment" << endl;
                    }
                    if (type == shop && cpositioni == 3 && cpositionj == 0) {
                        cout<< endl << endl << "\t\t--------------------- WEAPON SHOP --------------------" << endl;
                        weapon_shop();
                    }
                    if (type == shop && cpositioni == 5 && cpositionj == 0) {
                        cout << endl << endl<< "\t\t--------------------- WIZARD SHOP --------------------" << endl;
                        if (weapon != 1) {
                            cout << "\t\t\t You are not a wizard! Go away, bumpkin! " << endl << "\t\t\t And don't come back without a magic wand!" << endl << endl;
                            stirka = false;
                        }
                        else {
                            wizard_shop();
                            stirka = true;
                        }
                    }
                    if (type == shop && cpositioni == 6 && cpositionj == 0) {
                        cout << "\t--------------------- ARCHER SHOP --------------------" << endl;
                        if (weapon == 1) {
                            cout << "\t\t\t You are not an archer! Go away, fucking exorcist! " << endl << "\t\t\t And don't come back without a hunter bow!" << endl << endl;
                            stirka = false;
                        }
                        if (weapon == 3) {
                            cout << "\t\t\t You are not an archer! Go away, fucking swardsman! " << endl << "\t\t\t And don't come back without a hunter bow!" << endl << endl;
                            stirka = false;
                        }

                        if (weapon == 2) {
                            archer_shop();
                            stirka = true;
                        }
                    }
                    if (type == shop && cpositioni == 7 && cpositionj == 0) {
                        cout << "\t-------------------- SWORDSMAN SHOP --------------------" << endl;
                    }

                    cout_city(real_city, stirka);
                    real_city[cpositioni][cpositionj] = city[cpositioni][cpositionj];
                    move = input_moving(CITY_SIZE, cpositioni, cpositionj);
                    while (move == 'n') {
                        cin.clear();
                        move = input_moving(CITY_SIZE, cpositioni, cpositionj);
                    }
                    type = city_moving(real_city, city, move);
                }
                real_city[cpositioni][cpositionj] = city[cpositioni][cpositionj];
                if (positioni == 2 && positionj == 2) {
                    for (int i = 0; i < 8; i++) {
                        for (int j = 0; j < 8; j++) {
                            lake_city[i][j] = real_city[i][j];
                        }
                    }
                }
                if (positioni == 4 && positionj == 9) {
                    for (int i = 0; i < 8; i++) {
                        for (int j = 0; j < 8; j++) {
                            forest_city[i][j] = real_city[i][j];
                        }
                    }
                }
                cout_map(real_map);
            }
            if (move == load) {
                string file_name = "";
                cout << " Input name of file from which you want to load data ";
                cin >> file_name;
                load_stats(file_name);
                cout_map(real_map);
            }
            if (move == save) {
                cout << " Input name of file ";
                cin >> file_name;
                tmp = save_stats(file_name);
                while (tmp == 1) {
                    cout << " Input new name of file ";
                    tmp = save_stats(file_name);
                }
                cout << " Save complited successfuly " << endl;
            }

            move = input_moving(MAP_SIZE, positioni, positionj);
            while (move == 'n') {
                cin.clear();
                move = input_moving(MAP_SIZE, positioni, positionj);
            }
            cout_map(real_map);
        }
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.