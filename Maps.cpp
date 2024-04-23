#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <clocale>
#include <stdlib.h>
#include "Values.h"

using namespace std; 

void cout_map(char map[10][10]) {
    system("cls");
    ruels();
    show_stats();
    for (int i = 0; i < 10; i++) {
        cout << "\t\t\t\t" << "  ";
        for (int j = 0; j < 10; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

char moving(char real_map[][10], char move) {
    real_map[positioni][positionj] = map[positioni][positionj];
    if (move == 'w') positioni--;
    if (move == 'a') positionj--;
    if (move == 's') positioni++;
    if (move == 'd') positionj++;
    char type = '_';
    type = map[positioni][positionj];
    real_map[positioni][positionj] = '0';
    return type;
}