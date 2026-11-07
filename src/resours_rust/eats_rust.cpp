#include "../system_rust/copy_rust.h"

void kop_rast::auto_eda_and_water(long long ed, long long wat) {
    eda += ed;
    water += wat;
}

void kop_rast::funct_for_eat() {
    while(true) {
    std::cout << "1 - berryes (- 5)" << std::endl;
    std::cout << "2 - meet (- 5)" << std::endl;
    std::cout << "3 - exit (- 5)" << std::endl;
    std::string cin_for_eeeat;
    std::getline(std::cin, cin_for_eeeat);
    if (cin_for_eeeat == "1") {
      auto_eda_and_water(4, 8);
      berry -= 5;
      std::cout << "ok, berry -5, food + 3, and woter + 6" << std::endl;
        
    }
    else if (cin_for_eeeat == "2") {
      auto_eda_and_water(10, 2);
      meet -= 5;
      std::cout << "ok, meet -5, food + 10, and woter + 2" << std::endl;
        
    }
   
     else if (cin_for_eeeat == "3") {
        continue_enter();
        return;
        
    } }
    
}