#include <iostream>
#include <string>
#include <chrono>
#include  <thread>
#include <fstream>
#include <nlohmann/json.hpp>
#include <cstdio>
#include "../system_rust/copy_rust.h"


#include <iso646.h>
void kop_rast::resurs_mine(int& resours, int& hp_resours, long long x_resurs, long long y_result, int time_to_find, int reset_hp, std::string resours_name, int instr, void (kop_rast::*func_update)()) {
    // проверка
    if (x_resurs != x or y_result != y) {
        std::cout << "you didn't find it " << resours_name << std::endl;
        eda -= 5;
        water -= 3;
        energy -= 4;
        return;
    }

    random_ubdate_();
    prov_instryments();

    int speshel_peremen;
    // 1 это топоры
    // 2 это кирки
    // 3 это ничего
    if (instr == 1) {
        std::cout << "Enter topor (1 stown, 2 iron, 3 MVK, 4 chainsaw) -> ";
        std::cin >> speshel_peremen;
        if (speshel_peremen == 1) {
            if (stown_topor >= 1) {
                std::cout << "Great! you found " << resours_name << ", wait " << time_to_find << " time to get there and get it....." << std::endl;
                time(time_to_find);
                for (int i = 0; i < hp_resours; i += stown_stown_topor) {
                    if (stown_topor >= 1) {
                        random_ubdate_();
                        prov_instryments();
                        time(3);
                        eda -= 1;
                        energy -= 1;
                        water -= 1;
                        resours += stown_stown_topor;
                        hp_resours -= stown_stown_topor;
                        hp_stown_topor -= 1;
                        std::cout << "+ " << stown_stown_topor << std::endl;
                        std::cout << "hp " << hp_resours << std::endl;
                    }
                    else {
                        print("error, stone axe = 0!");
                    }
                }
                system("cls");
                (this->*func_update)();
                hp_resours = reset_hp;
            }
            else {
                std::cout << "axe is note!" << std::endl;
            }
        }
        else if (speshel_peremen == 2) {
            if (iron_topor >= 1) {
                std::cout << "Great! you found " << resours_name << ", wait " << time_to_find << " time to get there and get it....." << std::endl;
                time(time_to_find);
                for (int i = 0; i < hp_resours; i += tree_rand_iron_topor) {
                    if (iron_topor >= 1) {
                        random_ubdate_();
                        prov_instryments();
                        time(5);
                        eda -= 2;
                        energy -= 2;
                        water -= 2;
                        resours += tree_rand_iron_topor;
                        hp_resours -= tree_rand_iron_topor;
                        hp_iron_exa -= 1;
                        std::cout << "+ " << tree_rand_iron_topor << std::endl;
                        std::cout << "hp " << hp_resours << std::endl;
                    }
                    else {
                        std::cout << "axe is note!" << std::endl;
                    }
                }
                system("cls");
                (this->*func_update)();
                hp_resours = reset_hp;
            }
            else {
                std::cout << "axe is note!" << std::endl;
            }
        }
    }
    else if (instr == 2) {
        std::cout << "Enter pick (1 stown topor, 2 iron pick,  3 MVK_pick) -> ";
        std::cin >> speshel_peremen;
        if (speshel_peremen == 1) {
            if (stown_topor >= 1) {
                std::cout << "Great! you found " << resours_name << ", wait " << time_to_find << " time to get there and get it....." << std::endl;
                time(time_to_find);
                for (int i = 0; i < hp_resours; i += stown_stown_topor) {
                    if (stown_topor >= 1) {
                        random_ubdate_();
                        prov_instryments();
                        time(3);
                        eda -= 1;
                        energy -= 1;
                        water -= 1;
                        resours += stown_stown_topor;
                        hp_resours -= stown_stown_topor;
                        hp_stown_topor -= 1;
                        std::cout << "+ " << stown_stown_topor << std::endl;
                        std::cout << "hp " << hp_resours << std::endl;
                    }
                    else {
                        print("axe is note");
                    }
                }
                system("cls");
                (this->*func_update)();
                hp_resours = reset_hp;
            }
            else {
                std::cout << "axe is note!" << std::endl;
            }
        }
        else if (speshel_peremen == 2) {
            if (iron_pick >= 1) {
                std::cout << "Great! you found " << resours_name << ", wait " << time_to_find << " time to get there and get it.....";
                time(time_to_find);
                for (int i = 0; i < hp_resours; i += stown_iron_pick) {
                    if (iron_pick >= 1) {
                        random_ubdate_();
                        prov_instryments();
                        time(3);
                        eda -= 1;
                        energy -= 1;
                        water -= 1;
                        resours += stown_iron_pick;
                        hp_resours -= stown_iron_pick;
                        hp_pick -= 1;
                        std::cout << "+ " << stown_iron_pick << std::endl;
                        std::cout << "hp " << hp_resours << std::endl;
                    }
                    else {
                        print("pick is note");
                    }
                }
                system("cls");
                (this->*func_update)();
                hp_resours = reset_hp;
            }
            else {
                std::cout << "pick is note!" << std::endl;
            }
        }
    }
    else if (instr == 3) {
        std::cout << "Great! you found " << resours_name << ", wait " << time_to_find << " time to get there and get it.....";
        time(time_to_find);
        resours += 5;
        water -= 3;
        eda -= 1;
        energy -= 2;
        std::cout << "+ 5 " << resours_name << std::endl;
        hp_resours -= 5;
        if (hp_resours <= 0) {
            (this->*func_update)();
            hp_resours = reset_hp;
        }
    }
    else {
        std::cout << " " << std::endl;
        system("cls");
    }
}