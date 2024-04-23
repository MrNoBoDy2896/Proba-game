#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <clocale>
#include <stdlib.h>
#include "Values.h"

using namespace std;

void cout_city(char city[8][8], bool clear) {
    if (clear){
    system("cls");
    ruels();
    }
	show_stats();
    for (int i = 0; i < 8; i++) {
        cout << "\t\t\t\t" << "  ";
        for (int j = 0; j < 8; j++) {
            cout << city[i][j] << " ";
        }
        cout << endl;
    }
}

char city_moving(char real_city[8][8], char city[8][8], char move) {
    real_city[cpositioni][cpositionj] = city[cpositioni][cpositionj];

    if (move == 'w') cpositioni--;
    if (move == 'a') cpositionj--;
    if (move == 's') cpositioni++;
    if (move == 'd') cpositionj++;
    
    char type = '_';
    type = city[cpositioni][cpositionj];
    real_city[cpositioni][cpositionj] = '0';
    return type;
}
