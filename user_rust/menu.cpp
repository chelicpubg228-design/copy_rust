#include "../system_rust/copy_rust.h"

void kop_rast::print_menu() {
  std::cout << "=============menu===========" << std::endl;
  std::cout << "1 for print information" << std::endl;
  std::cout << "2 for exit" << std::endl;
  std::cout << "3 to locate big tree" << std::endl;
  std::cout << "4 for find berries" << std::endl;
  std::cout << "5 eat 5 berries" << std::endl;
  std::cout << "6 to sleep" << std::endl;
  std::cout << "7 to help" << std::endl;
  std::cout << "8 to craft" << std::endl;
  std::cout << "9 to locate stone " << std::endl;
  std::cout << "10 to locate sera" << std::endl;
  std::cout << "11 to locate iron" << std::endl;
  std::cout << "12 to locate normal tree" << std::endl;
  std::cout << "13 to locate small tree" << std::endl;
  std::cout << "14 to hunting         " << std::endl;
  std::cout << "15 to locate tkan     " << std::endl;
  std::cout << "16 to  donning armor     " << std::endl;
  std::cout << "17 to  undonning armor    " << std::endl;
  std::cout << "18 to statistic user" << std::endl;
  std::cout << "19 to statistic axe" << std::endl;
  std::cout << "20 to free mode" << std::endl;
  std::cout << "=============menu===========" << std::endl;
  std::cout << "x = " << x << "\n" << "y = " << y << std::endl;
  std::cout << "                            " << std::endl;
}

void kop_rast::vstr_mouse() {
  if (x < 10000 and x > -10000 and y < 10000 and y > -10000) {
    fight(y_small_mouse, hp_mouse, x_small_mouse, damage_mouse, 12, "mouse");

  } else if (x < 1000000 and x > -1000000 and y < 1000000 and y > -1000000) {
    fight(y_normal_mouse, hp_mouse, x_normal_mouse, damage_mouse, 12, "mouse");

  } else {
    fight(y_big_mouse, hp_mouse, x_big_mouse, damage_mouse, 12, "mouse");
  }
}

void kop_rast::vstr_bear() {
  if (x < 10000 and x > -10000 and y < 10000 and y > -10000) {
    fight(y_small_bear, hp_bear, x_small_bear, damage_bear, 120, "bear");

  } else if (x < 1000000 and x > -1000000 and y < 1000000 and y > -1000000) {
    fight(y_normal_bear, hp_bear, x_normal_bear, damage_bear, 120, "bear");

  } else {
    fight(y_big_bear, hp_bear, x_big_bear, damage_bear, 120, "bear");
  }
}
void kop_rast::vstr_olen() {

  if (x < 10000 and x > -10000 and y < 10000 and y > -10000) {
    fight(y_small_olen, hp_olen, x_small_olen, damage_olen, 80, "olen");

  } else if (x < 1000000 and x > -1000000 and y < 1000000 and y > -1000000) {
    fight(y_normal_olen, hp_olen, x_normal_olen, damage_olen, 80, "olen");

  } else {
    fight(y_big_olen, hp_olen, x_big_olen, damage_olen, 80, "olen");
  }
}
// уроны предметов  по существам
/*//топоры
int damage_stone_axe_for_animal = 15;
int damage_iron_axe_for_animal = 25;
// кирка
int damage_iron_pick_for_animal = 35;
// факел
int damage_fakel_for_animal = 10;
//волк
int damage_wolf = 10;
//медведь
int damage_bear = 15;
//олень
int damage_olen = 1;
//мышь
int damage_mouse = 5;*/
void kop_rast::menu() {
  load_json();
  std::cout << "v 4.2" << std::endl;

  if (name_user == "None") {
    std::cout << "enter name user~# ";
    update_coordinats();
    std::getline(std::cin, name_user);
  }

  print_menu();
  update_coordinats();

  while (true) {
    regeneration();

    prov_instryments();

    random_ubdate_();
    prov_bron();
    prov_alive();

    std::getline(std::cin, cin_menu);

    if (cin_menu == "1") {
      continue_enter();
      print_info();
      print_menu();
      continue_enter();

    } else if (cin_menu.find_first_not_of(" \t") == std::string::npos) {

      continue;
      ignore();

    } else if (cin_menu == "10") {
      continue_enter();

      locate_sera();
      print_menu();

      continue_enter();

    } else if (cin_menu == "help") {
      continue_enter();

      print(help_text);
      print_menu();
      continue_enter();

    } else if (cin_menu == "14") {
      continue_enter();

      hunting();
      print_menu();
      continue_enter();

    } else if (cin_menu == "18") {
      print_statisc_user();
      continue_enter();

      print_statisc_user();
      print_menu();
      continue_enter();

    } else if (cin_menu == "20") {
      free_mode();
      print_menu();
      continue_enter();

    }

    else if (cin_menu == "19") {
      continue_enter();

      print_statistic_axe();
      print_menu();
      continue_enter();

    } else if (cin_menu == "9") {
      continue_enter();

      stone_process();
      print_menu();
      continue_enter();

    } else if (cin_menu == "clear") {

      system("cls");
    } else if (cin_menu == "8") {
      continue_enter();

      craft();
      print_menu();
      continue_enter();

    } else if (cin_menu == "16") {
      continue_enter();

      donning_armor();
      print_menu();
      continue_enter();

    } else if (cin_menu == "17") {
      continue_enter();

      undonning_armor();
      print_menu();
      continue_enter();

    } else if (cin_menu == "15") {
      continue_enter();

      locate_tkan();
      print_menu();
      continue_enter();

    }

    else if (cin_menu == "4") {
      continue_enter();

      locate_berry();
      print_menu();
      continue_enter();

    } else if (cin_menu == "5") {
      continue_enter();

      ate_berry();
      print_menu();
      continue_enter();

    } else if (cin_menu == "11") {
      continue_enter();

      resurs_mine(metal, hp_iron, metal_shans, 5, time_to_iron, hp_iron,
                  " iron ", 2, &kop_rast::update_coordinats_iron);
      print_menu();
      continue_enter();

    } else if (cin_menu == "2") {
      continue_enter();

      ubdate_json();

      break;
    } else if (cin_menu == "12") {
      continue_enter();

      rybka_tree_kamen_topor_normal();
      print_menu();
      continue_enter();

    } else if (cin_menu == "13") {
      continue_enter();

      rybka_tree_kamen_topor_small();
      print_menu();
      continue_enter();

    } else if (cin_menu == "6") {
      continue_enter();

      sleep();
      print_menu();
      continue_enter();

    } else if (cin_menu == "7") {
      continue_enter();

      std::cout << help_text;
      print_menu();
      continue_enter();

    } else if (cin_menu == "3") {
      continue_enter();

      rybka_tree_kamen_topor_big();
      print_menu();
      continue_enter();

    } else {
      std::cin.ignore();
      system("cls");
      hp_minys();
      std::cout << "error " << std::endl;
      print_menu();
      std::cin.ignore();
    }
    ubdate_json();
  }
}
