#include "../system_rust/copy_rust.h"
#include <conio.h>
#include <iostream>
#include <string>

void kop_rast::free_mode() {
  std::cout << "w - x +" << std::endl;
  std::cout << "s - x -" << std::endl;
  std::cout << "d - y +" << std::endl;
  std::cout << "a - y -" << std::endl;
  std::cout << "e - inspection" << std::endl;
  std::cout << "q - exit" << std::endl;
  while (true) {

    random_ubdate_();

    char mode_chr = _getch();

    if (mode_chr == 'q') {
      system("cls");
    
      break;
    } else if (mode_chr == 'w') {
      system("cls");

      x++;
      std::cout << "x: " << x << std::endl;
      std::cout << "y: " << y << std::endl;
     
    

    } else if (mode_chr == 'a') {
      system("cls");
      y--;
      std::cout << "x: " << x << std::endl;
      std::cout << "y: " << y << std::endl;
     


    } else if (mode_chr == 's') {
      system("cls");

      x--;
      std::cout << "x: " << x << std::endl;
      std::cout << "y: " << y << std::endl;
     


    }
    else if (mode_chr == 'e') {
    

      system("cls");
      std::cout << "x: " << x << std::endl;
      std::cout << "y: " << y << std::endl;
      loc_shanc();
        while (_kbhit()) {
        _getch();
      }
    } 
    else if (mode_chr == 'd') {
      system("cls");

      y++;
      std::cout << "x: " << x << std::endl;
      std::cout << "y: " << y << std::endl;
     
     
    }
  }
}
