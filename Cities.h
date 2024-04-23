#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <clocale>
#include <stdlib.h>
#include <ctime>

using namespace std;

void cout_city(char city[8][8], bool clear);
char city_moving(char real_city[8][8], char city[8][8], char move);