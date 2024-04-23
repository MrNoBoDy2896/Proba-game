#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <clocale>
#include <stdlib.h>
#include "Values.h"

using namespace std;

void weapon_shop(void) {
    int prices[3] = { 0,0,0 };
    int wdamage[3] = { 1,2,3 };
    bool buy = false;
    cout << "\t\t  Welcome to the weapons shop, traveler. The higher your level, the"
        << endl << "\t\t          better weapons I will offer you!" << endl;
    if (level == 1) {
        cout << "\t\t\t       name          damage      price " << endl;
        cout << "\t\t\t 1. Magic wand         1           2   " << endl;
        cout << "\t\t\t 2. Hunter bow         1           1   " << endl;
        cout << "\t\t\t 3.    Sword           2           1   " << endl;
        int wdamage[3] = { 1, 1, 2 };
        prices[0] = 2;
        prices[1] = 1;
        prices[2] = 1;
    }
    if (level == 2) {
        cout << "\t\t\t       name          damage      price " << endl;
        cout << "\t\t\t 1. Magic wand         2           2   " << endl;
        cout << "\t\t\t 2. Hunter bow         2           2   " << endl;
        cout << "\t\t\t 3.    Sword           3           2   " << endl;
        int wdamage[3] = { 2, 2, 3 };
        int prices[3] = { 2,2,2 };
    }
    if (level == 3) {
        cout << "\t\t\t       name          damage      price " << endl;
        cout << "\t\t\t 1. Magic wand         4           3   " << endl;
        cout << "\t\t\t 2. Hunter bow         4           3   " << endl;
        cout << "\t\t\t 3.    Sword           5           3   " << endl;
        int wdamage[3] = { 4, 4, 5 };
        int prices[3] = { 3,3,3 };
    }
    if (level == 4) {
        cout << "\t\t\t       name          damage      price " << endl;
        cout << "\t\t\t 1. Magic wand         5           4   " << endl;
        cout << "\t\t\t 2. Hunter bow         5           4   " << endl;
        cout << "\t\t\t 3.    Sword           6           4   " << endl;
        int wdamage[3] = { 5, 5, 6 };
        int prices[3] = { 4, 4, 4 };
    }
    if (level == 5) {
        cout << "\t\t\t       name          damage      price " << endl;
        cout << "\t\t\t 1. Magic wand         9           6   " << endl;
        cout << "\t\t\t 2. Hunter bow         8           5   " << endl;
        cout << "\t\t\t 3.    Sword           9           5   " << endl;
        int wdamage[3] = { 9, 8, 9 };
        int prices[3] = { 6, 5, 5 };
    }
    if (level == 6) {
        cout << "\t\t\t       name          damage      price " << endl;
        cout << "\t\t\t 1. Magic wand         10          7   " << endl;
        cout << "\t\t\t 2. Hunter bow         9           5   " << endl;
        cout << "\t\t\t 3.    Sword           11          7   " << endl;
        int wdamage[3] = { 10, 9, 11 };
        int prices[3] = { 7, 5, 7 };
    }
    if (level == 7) {
        cout << "\t\t\t       name          damage      price " << endl;
        cout << "\t\t\t 1. Magic wand         12          8   " << endl;
        cout << "\t\t\t 2. Hunter bow         12          8   " << endl;
        cout << "\t\t\t 3.    Sword           13          8   " << endl;
        int wdamage[3] = { 12, 12, 13 };
        int prices[3] = { 8, 8, 8 };
    }
    if (level == 8) {
        cout << "\t\t\t       name          damage      price " << endl;
        cout << "\t\t\t 1. Magic wand         17          9   " << endl;
        cout << "\t\t\t 2. Hunter bow         19          7   " << endl;
        cout << "\t\t\t 3.    Sword           15          9   " << endl;
        int wdamage[3] = { 17, 19, 15 };
        int prices[3] = { 9, 7, 9 };
    }
    if (level == 9) {
        cout << "\t\t\t       name          damage      price " << endl;
        cout << "\t\t\t 1. Magic wand         18          10   " << endl;
        cout << "\t\t\t 2. Hunter bow         20          10   " << endl;
        cout << "\t\t\t 3.    Sword           19          10   " << endl;
        int wdamage[3] = { 18, 20, 19 };
        int prices[3] = { 10, 10, 10 };
    }
    if (level == 10) {
        cout << "\t\t\t       name          damage      price " << endl;
        cout << "\t\t\t 1. Magic wand         25          11   " << endl;
        cout << "\t\t\t 2. Hunter bow         23          11   " << endl;
        cout << "\t\t\t 3.    Sword           22          11   " << endl;
        int wdamage[3] = { 25, 23, 22 };
        int prices[3] = { 11, 11, 11 };
    }
    cout << "\t\t\tIf you don’t want anything, enter 0" << endl << "\t\t Enter the number of the weapon you want to buy ";
    int bying = if_integer();
    while (bying < 0 || bying >3) {
        cout << endl << " Input '0' or '1' or '2' or '3' ";
        bying = if_integer();
    }

    while (money < prices[bying - 1]) {
        cout << " You don't have enough money! Choose enother weapon or go away ('0')! ";
        bying = if_integer();
        while (bying < 0 || bying >3) {
            cout << endl << " Input '0' or '1' or '2' or '3' ";
            bying = if_integer();
        }
        if (bying == 0) { return; }
    }
    weapon = bying;
    damage = wdamage[bying];
    money = money - prices[bying - 1];
    buy = true;

    if (buy && weapon == 1) {
        cout << endl << "\t\t\t\tYou bought the magic wand" << endl;
    }
    if (buy && weapon == 2) {
        cout << endl << "\t\t\t\tYou bought the hunter bow" << endl;
    }
    if (buy && weapon == 3) {
        cout << endl << "\t\t\t\tYou bought the sword" << endl;
    }
    max_health -= buff_max_health;

    elements[0] = 0;
    elements[1] = 0;
    elements[2] = 0;
    elements[3] = 0;

    mantra[0] = 0;
    mantra[1] = 0;
    mantra[2] = 0;
    mantra[3] = 0;

    sharpness = 0;

    toxin = 0;

    buff_damage = 0;
    buff_max_health = 0;
    buff_time = 0;
    buff_money = 0;
    cout << "\t\t\t Have a good trip, traveler. Come again!" << endl << endl;
}

void wizard_shop(void) {

    int bying = 100;
    int earth = 0;
    int water = 1;
    int fire = 2;
    int air = 3;
    system("cls");
    ruels();
    cout << "\t\t\t Welcome to the wizard shop, traveler!" << endl;

    while (bying != 0) {
        cout << endl;
        show_stats();
        cout << "\t\t\t 0. Go away" << endl;
        cout << "\t\t\t 1. Used upgrade damage " << endl;
        cout << "\t\t\t 2. Add element to magic wand " << endl;
        cout << "\t\t\t 3. Delete element from magec wand " << endl;
        cout << "\t\t\t 4. To learn new mantra " << endl;
        cout << "\t\t Input numger ";

        bying = if_integer();
        while (bying < 0 || bying >4) {
            cout << "\t\t Input '0' or '1' or '2' or '3' or '4' ";
            bying = if_integer();
        }
        system("cls");
        ruels();
        if (bying == 1) {
            if (upgrade_damage < 1) {
                cout << "\t\t\t   You have no upgrade damage" << endl;
            }
            if (upgrade_damage > 0) {
                upgrade_damage--;
                if (level > 5) {
                    damage += 2;
                    cout << "\t\t\t\t +2 to your damage" << endl;
                }
                else {
                    damage += 1;
                    cout << "\t\t\t\t +1 to your damage" << endl;
                }
            }
        }
        if (bying == 2) {
            cout << "\t\t  Remember, you can add only 2 elements to magic wand" << endl << endl;
            int elem = 0;
            for (auto i : elements) {
                if (i) elem++;
            }
            if (elem > 1) {
                system("cls");
                ruels();
                cout << endl << "\tYou already have 2 elements on your magic wand";
            }
            else {
                while (bying != 0)
                {
                    //cout << endl;
                    //ruels();
                    show_stats();
                    cout << "\t\t\t\t All elements costs 5 money " << endl;
                    cout << "\t\t\t 0. Go to hall" << endl;
                    cout << "\t\t\t 1. Add earth\t +10 for max health" << endl;
                    cout << "\t\t\t 2. Add water\t +10 for time in day" << endl;
                    cout << "\t\t\t 3. Add fire \t + 5 for damage" << endl;
                    cout << "\t\t\t 4. Add air  \t + 1 money for each mission" << endl;
                    cout << "\t\t Input: ";
                    int byingw = if_integer();

                    while (byingw < 0 || byingw >4) {
                        cout << "\t\t Input '0' or '1' or '2' or '3' or '4' ";
                        byingw = if_integer();
                    }
                    elem = 0;
                    for (auto i : elements) {
                        if (i) elem++;
                    }
                    system("cls");
                    ruels();
                    if (byingw == 0) {
                        break;
                    }
                    if (elem > 1) {
                        cout << "\t\t\tYou already have 2 elements on your magic wand" << endl << endl;
                        continue;
                    }

                    //show_stats();
                    if (money < 5) {
                        cout << "\t\t\t You haven't enoth money, poor fool! " << endl << endl;
                    }

                    bool neweath = false;
                    bool newwater = false;
                    bool newfire = false;
                    bool newair = false;
                    if (byingw == 1 && money > 4) {
                        if (!elements[earth]) {
                            elements[earth] = true;
                            money -= 5;
                            cout << "\t\t\t\tYou bought earth element" << endl << endl;
                            neweath = true;
                        }
                        else cout << "\t\t You are already have earth element! Choose another one" << endl << endl;
                    }
                    if (byingw == 2 && money > 4) {
                        if (!elements[water]) {
                            elements[water] = true;
                            money -= 5;
                            cout << "\t\t\t\tYou bought water element" << endl << endl;
                            newwater = true;
                        }
                        else cout << "\t\t You are already have water element! Choose another one" << endl << endl;
                    }
                    if (byingw == 3 && money > 4) {
                        if (!elements[fire]) {
                            elements[fire] = true;
                            money -= 5;
                            cout << "\t\t\t\tYou bought fire element" << endl << endl;
                            newfire = true;
                        }
                        else cout << "\t\t You are already have fire element! Choose another one" << endl << endl;
                    }
                    if (byingw == 4 && money > 4) {
                        if (!elements[air]) {
                            elements[air] = true;
                            money -= 5;
                            cout << "\t\t\t\tYou bought air element" << endl << endl;
                            newair = true;
                        }
                        else cout << "\t\t You are already have air element! Choose another one" << endl << endl;
                    }
                    if (elements[earth] && neweath) {
                        buff_max_health += 10;
                    }
                    if (elements[water] && newwater) {
                        buff_time += 10;
                    }
                    if (elements[fire] && newfire) {
                        buff_damage += 5;
                    }
                    if (elements[air] && newair) {
                        buff_money += 1;
                    }
                    max_health += buff_max_health;
                    damage += buff_damage;

                    buff_max_health = 0;
                    buff_time = 0;
                    buff_damage = 0;
                    buff_money = 0;
                }
            }
        }
        if (bying == 3) {
            cout << endl;
            system("cls");
            ruels();
            show_stats();
            string elchoice = "yes";
            system("cls");
            ruels();
            while (true) {
                cout << "\t\t\t   Deleting element costs 3 money" << endl;
                cout << "\t\t You have: " << endl;
                if (elements[earth]) {
                    cout << "\t\t\t Earht element" << endl;
                }
                if (elements[water]) {
                    cout << "\t\t\t Water element" << endl;
                }
                if (elements[fire]) {
                    cout << "\t\t\t Fire element" << endl;
                }
                if (elements[air]) {
                    cout << "\t\t\t Air element" << endl;
                }
                cout << endl << "\t Input which one do you want to delete ('earth'/'water'/'fire'/'air'/'no') ";
                string elchoice = "";
                cin >> elchoice;
                while ((elchoice != "earth") && (elchoice != "water") && (elchoice != "fire") && (elchoice != "air") && (elchoice != "no")) {
                    cout << endl << "\t\t Input only 'earth'/'water'/'fire'/'air'/'no' ";
                    cin >> elchoice;
                }
                system("cls");
                ruels();
                if (money < 3) {
                    cout << "\t\t\t You haven't enoth money, poor sily! ";
                }
                if (elchoice == "earth" && (elements[earth]) && money > 2) {
                    elements[earth] = false;
                    money -= 3;
                    cout << " \t\t\t You are delete earth element" << endl << endl;
                    buff_max_health -= 10;
                    max_health -= 10;
                }
                if (elchoice == "water" && elements[water] && money > 2) {
                    elements[water] = false;
                    money -= 3;
                    cout << " \t\t\t You are delete water element" << endl << endl;
                    buff_time -= 10;
                }
                if (elchoice == "fire" && elements[fire] && money > 2) {
                    elements[fire] = false;
                    money -= 3;
                    cout << " \t\t\t You are delete fire element" << endl << endl;
                    buff_damage -= 5;
                    damage -= 5;
                }
                if (elchoice == "air" && elements[air] && money > 2) {
                    elements[air] = false;
                    money -= 3;
                    cout << " \t\t\t You are delete air element" << endl << endl;
                    buff_money += 1;
                }
                if (elchoice == "no") { break; }
                show_stats();
            }
        }
        int mantrasch = 0;
        if (bying == 4) {
            mantrasch = 0;
            cout << endl;
            show_stats();
            cout << "\t\t\t  Remember, you can have only 1 mantra" << endl << endl;
            cout << "\t\t\t\t     All mantras costs 5 money" << endl;
            int sch = 0;
            for (auto i : mantra) {
                if (i) sch++;
            }
            int byingw = 1;
            if (sch > 0) {
                cout << endl << "\t\t\t\t You already have mantra" << endl << endl;
            }
            else {
                while (byingw != 0) {
                    cout << "\t\t\t 0. Go to hall" << endl;
                    cout << "\t\t\t 1. Earth mantra \t +10 for max health" << endl;
                    cout << "\t\t\t 2. Woter mantra \t +10 for time in day" << endl;
                    cout << "\t\t\t 3. Fire  mantra \t + 5 for damage" << endl;
                    cout << "\t\t\t 4. Air mantra   \t + 1 money for each mission" << endl;
                    cout << "\t\t Input: ";
                    byingw = if_integer();

                    while (byingw < 0 || byingw >4) {
                        cout << "\t\t Input '0' or '1' or '2' or '3' or '4' ";
                        byingw = if_integer();
                    }

                    system("cls");
                    ruels();

                    if (money < 5) {
                        cout << endl << "\t\t\t\t You haven't enoth money, poor fool! " << endl;
                    }
                    if (byingw == 1 && money > 4) {
                        mantra[earth] = true;
                        money -= 5;
                        cout << endl << " \t\t\t\t\t You bought earth mantra " << endl << endl;
                    }
                    if (byingw == 2 && money > 4) {
                        mantra[water] = true;
                        money -= 5;
                        cout << endl << " \t\t\t\t\t You bought water mantra " << endl << endl;
                    }
                    if (byingw == 3 && money > 4) {
                        mantra[fire] = true;
                        money -= 5;
                        cout << endl << " \t\t\t\t\t You bought fire mantra " << endl << endl;
                    }
                    if (byingw == 4 && money > 4) {
                        mantra[air] = true;
                        money -= 5;
                        cout << endl << " \t\t\t\t\t You bought air mantra " << endl << endl;
                    }
                    show_stats();
                    mantrasch = 0;
                }
            }
        }

        buff_max_health = 0;
        buff_damage = 0;

        if (mantrasch == 0) {
            if (mantra[earth]) {
                buff_max_health += 10;
            }
            if (mantra[water]) {
                buff_time += 10;
            }
            if (mantra[fire]) {
                buff_damage += 5;
            }
            if (mantra[air]) {
                buff_money += 1;
            }

        }
        max_health += buff_max_health;
        damage += buff_damage;
    }

    if (bying == 0) {
        cout << "\t\t\tHave a good trip, traveler. Come again!" << endl;
        return;
    }
}

void archer_shop(void) {
    int abying = 100;
    system("cls");
    ruels();
    cout << "\t\t\t Welcome to the archer shop, traveler!" << endl;

    while (abying != 0) {
        cout << endl;
        show_stats();
        cout << "\t\t\t 0. Go away" << endl;
        cout << "\t\t\t 1. Used upgrade damage" << endl;
        cout << "\t\t\t 2. Add toxin to your bow" << endl;
        cout << "\t\t\t 3. Delete toxin to your bow" << endl;
        cout << "\t\t\t 4. Increase firing range" << endl;
        cout << "\t\t Input numger ";

        abying = if_integer();
        while (abying < 0 || abying >4) {
            cout << "\t\t Input '0' or '1' or '2' or '3' or '4' ";
            abying = if_integer();
        }

        if (abying == 0) {
            cout << "\t\t\tHave a good trip, traveler. Come again!" << endl;
            return;
        }

        if (abying == 1) {
            if (upgrade_damage < 1) {
                cout << "\t\t\t   You have no upgrade damage" << endl;
            }
            if (upgrade_damage > 0) {
                upgrade_damage--;
                if (level > 5) {
                    damage += 2;
                    cout << "\t\t\t\t +2 to your damage" << endl;
                }
                else {
                    damage += 1;
                    cout << "\t\t\t\t +1 to your damage" << endl;
                }
            }
        }

        if (abying == 2) {
            cout << "\t\t  Remember, you can add only 2 toxins to bow" << endl << endl;
            cout << "\t\t\t\t All toxins costs 5 money " << endl;

        }

        if (abying == 3) {}

        if (abying == 4) {}
    }
}