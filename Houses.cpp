#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <clocale>
#include <stdlib.h>
#include "Values.h"

using namespace std;

void cout_house(char real_house[5][5]) {
    //system("cls");
    //ruels();
    show_stats();
    for (int i = 0; i < 5; i++) {
        cout << "\t\t\t\t" << "  ";
        for (int j = 0; j < 5; j++) {
            cout << real_house[i][j] << " ";
        }
        cout << endl;
    }

}

char house_moving(char real_house[5][5], char house[5][5], char move) {
    real_house[hpositioni][hpositionj] = house[hpositioni][hpositionj];
    if (move == 'w') hpositioni--;
    if (move == 'a') hpositionj--;
    if (move == 's') hpositioni++;
    if (move == 'd') hpositionj++;
    char type = '_';
    type = house[hpositioni][hpositionj];
    real_house[hpositioni][hpositionj] = '0';
    return type;
}
