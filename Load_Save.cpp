#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <clocale>
#include <stdlib.h>
#include "Values.h"

using namespace std;


bool _check(string file_name) {
    ifstream ch(file_name);
    return ch.good();
}
void load_stats(string file_name) {  //vector <int> downloading = load_stats('') real_time = downloading[0] health = downloading[1] и тд и тп не забыть потом cout_map()
    vector<int> stats = {};
    int size = 10;
    if (!_check(file_name)) {
        cout << " The file name is invalid or is not readable" << endl;
    }
    ifstream from_file(file_name);
    int int_buff = 0;

    from_file >> int_buff;
    real_time = int_buff;

    from_file >> int_buff;
    health = int_buff;

    from_file >> int_buff;
    max_health = int_buff;

    from_file >> int_buff;
    level = int_buff;

    from_file >> int_buff;
    keys = int_buff;

    from_file >> int_buff;
    rep = int_buff;

    from_file >> int_buff;
    weapon = int_buff;

    from_file >> int_buff;
    damage = int_buff;

    from_file >> int_buff;
    money = int_buff;

    from_file >> int_buff;
    positioni = int_buff;

    from_file >> int_buff;
    positionj = int_buff;

    if (from_file.eof()) {
        cout << " Not enough data here " << endl;
    }

    char buff = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            from_file >> buff;
            real_map[i][j] = buff;
        }
    }
    //for (int i = 0; i < 25; i++) {
    //    from_file >> buff;
    //    quests[i] = buff;
    //}
}

int save_stats(string file_name) {
    ofstream to_file(file_name);                        /*std::ofstream::app*/
    if (to_file.fail()) return 1;                       //запись невозможнa

    to_file << real_time << " ";
    to_file << health << " ";
    to_file << max_health << " ";
    to_file << level << " ";
    to_file << keys << " ";
    to_file << rep << " ";
    to_file << weapon << " ";
    to_file << damage << " ";
    to_file << money << " ";
    to_file << positioni << " ";
    to_file << positionj << " ";

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            to_file << real_map[i][j] << " ";
        }
    }
    //for (int i = 0; i < 25; i++) {
    //    to_file << quests[i] << " ";
    //}
    return 0;
}