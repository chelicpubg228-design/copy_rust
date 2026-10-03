#include <iostream>
#include <string>
#include <conio.h>
#include "../system_rust/copy_rust.h"




void kop_rast::free_mode() {
    std::cout << "w - x +" << std::endl;
    std::cout << "s - x +" << std::endl;
    std::cout << "d - y +" << std::endl;
    std::cout << "a - y -" << std::endl;
    std::cout << "q - exit" << std::endl;
    while (true) {
        random_ubdate_();


        char mode_chr = _getch();
        
        if (mode_chr  == 'q') {
            system("cls");
            prov_coord();
            break;
        }
        else if (mode_chr == 'w') {
            system("cls");

            x++;
            std::cout << "x: " << x << std::endl;
            std::cout << "y: " << y << std::endl;
            loc_shanc();
            prov_coord();

        }
         else if (mode_chr == 'a') {
            system("cls");
            y--;
            std::cout << "x: " << x << std::endl;
            std::cout << "y: " << y << std::endl;
            loc_shanc();
            prov_coord();

        }
         else if (mode_chr == 's') {
            system("cls");
            
            x--;
            std::cout << "x: " << x << std::endl;
            std::cout << "y: " << y << std::endl;
            loc_shanc();
            prov_coord();
        }
         else if (mode_chr == 'd') {
            system("cls");

            y++;
            std::cout << "x: " << x << std::endl;
            std::cout << "y: " << y << std::endl;
            loc_shanc();
            prov_coord();
            
        }
    }
}