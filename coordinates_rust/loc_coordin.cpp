#include "../system_rust/copy_rust.h"
#include <string>
#include <conio.h>
#include <iostream>

bool kop_rast::loc_shanc_auto(long long x_plus,
                              long long y_plus,
                              int shanc_what, int big_whanc_what,
                              long long &x_what, long long &y_what,
                              std::string name_object,
                              char char_for_auto) {

  if (x < x_plus && x > -x_plus && y < y_plus && y > -y_plus) {
    if (shanc_what < big_whanc_what) {
      
      // Сбрасываем фантомные нажатия клавиш
      while (_kbhit()) {
        _getch();
      }

      std::cout << "you meet " << name_object << std::endl;
      std::cout << "y or n " << name_object << std::endl;

      while (true) {
        char input = _getch();

        if (input == 'y' || input == 'Y') {
          x_what = x;
          y_what = y;
          // Запускаем ровно те функции, которые объявлены в твоем коде:
          switch (char_for_auto) {
            case 'b': // ягоды
              locate_berry(); //[cite: 3]
              break;
            case 't': // ткань
              locate_tkan(); //[cite: 3]
              break;
            case 'w': // волк
              vstr_wolf(); //[cite: 8]
              break;
            case 'm': // мышь
              vstr_mouse(); //[cite: 8]
              break;
            case 'r': // медведь
              vstr_bear(); //[cite: 8]
              break;
            case 'o': // олень
              vstr_olen(); //[cite: 8]
              break;
            case 'B': // большое дерево
              rybka_tree_kamen_topor_big(); //[cite: 3]
              break;
            case 'N': // обычное дерево
              rybka_tree_kamen_topor_normal(); //[cite: 3]
              break;
            case 'S': // маленькое дерево
              rybka_tree_kamen_topor_small(); //[cite: 3]
              break;
            case 's': // камень
              stone_process(); //[cite: 3]
              break;
            case 'f': // сера
              locate_sera(); //[cite: 3]
              break;
            case 'i': // железо
              locate_iron(); //[cite: 3]
              break;
            default:
              break;
          }
          system("cls");
          std::cout << "x: " << x << std::endl;
          std::cout << "y: " << y << std::endl;
          return true; // Игрок согласился — прекращаем дальнейший осмотр
        } 
        else if (input == 'n' || input == 'N') {
          system("cls");
          std::cout << "x: " << x << std::endl;
          std::cout << "y: " << y << std::endl;
          return false; // Игрок отказался — переходим к следующим объектам
        }
      }
    }
  }
 
  return false;
}

void kop_rast::loc_shanc() {

  //*berry ('b')
  if (x < 10000 && x > -10000 && y < 10000 && y > -10000) {
    if (loc_shanc_auto(10000, 10000, shans_berry, 2, x_small_berries, y_small_berries, "berries", 'b')) return;
  }
  else if (x < 100000 && x > -100000 && y < 100000 && y > -100000) {
    if (loc_shanc_auto(100000, 100000, shans_berry, 2, x_normal_berries, y_normal_berries, "berries", 'b')) return;
  }
  else {
    if (loc_shanc_auto(10000000, 10000000, shans_berry, 2, x_big_berries, y_big_berries, "berries", 'b')) return;
  }

  //*tkan ('t')
  if (x < 10000 && x > -10000 && y < 10000 && y > -10000) {
    if (loc_shanc_auto(10000, 10000, shans_tkan, 2, x_small_tkan, y_small_tkan, "tkan", 't')) return;
  }
  else if (x < 100000 && x > -100000 && y < 100000 && y > -100000) {
    if (loc_shanc_auto(100000, 100000, shans_tkan, 2, x_normal_tkan, y_normal_tkan, "tkan", 't')) return;
  }
  else {
    if (loc_shanc_auto(10000000, 10000000, shans_tkan, 2, x_big_tkan, y_big_tkan, "tkan", 't')) return;
  }

  //*wolf ('w')
  if (x < 10000 && x > -10000 && y < 10000 && y > -10000) {
    if (loc_shanc_auto(10000, 10000, shans_wolf, 4, x_small_wolf, y_small_wolf, "wolf", 'w')) return;
  }
  else if (x < 100000 && x > -100000 && y < 100000 && y > -100000) {
    if (loc_shanc_auto(100000, 100000, shans_wolf, 4, x_normal_wolf, y_normal_wolf, "wolf", 'w')) return;
  }
  else {
    if (loc_shanc_auto(10000000, 10000000, shans_wolf, 4, x_big_wolf, y_big_wolf, "wolf", 'w')) return;
  }

  //*mouse ('m')
  if (x < 10000 && x > -10000 && y < 10000 && y > -10000) {
    if (loc_shanc_auto(10000, 10000, shans_mouse, 3, x_small_mouse, y_small_mouse, "mouse", 'm')) return;
  }
  else if (x < 100000 && x > -100000 && y < 100000 && y > -100000) {
    if (loc_shanc_auto(100000, 100000, shans_mouse, 3, x_normal_mouse, y_normal_mouse, "mouse", 'm')) return;
  }
  else {
    if (loc_shanc_auto(10000000, 10000000, shans_mouse, 3, x_big_mouse, y_big_mouse, "mouse", 'm')) return;
  }

  //*bear ('r')
  if (x < 10000 && x > -10000 && y < 10000 && y > -10000) {
    if (loc_shanc_auto(10000, 10000, shans_bear, 4, x_small_bear, y_small_bear, "bear", 'r')) return;
  }
  else if (x < 100000 && x > -100000 && y < 100000 && y > -100000) {
    if (loc_shanc_auto(100000, 100000, shans_bear, 4, x_normal_bear, y_normal_bear, "bear", 'r')) return;
  }
  else {
    if (loc_shanc_auto(10000000, 10000000, shans_bear, 4, x_big_bear, y_big_bear, "bear", 'r')) return;
  }

  //*olen ('o')
  if (x < 10000 && x > -10000 && y < 10000 && y > -10000) {
    if (loc_shanc_auto(10000, 10000, shanc_olen, 3, x_small_olen, y_small_olen, "olen", 'o')) return;
  }
  else if (x < 100000 && x > -100000 && y < 100000 && y > -100000) {
    if (loc_shanc_auto(100000, 100000, shanc_olen, 3, x_normal_olen, y_normal_olen, "olen", 'o')) return;
  }
  else {
    if (loc_shanc_auto(10000000, 10000000, shanc_olen, 3, x_big_olen, y_big_olen, "olen", 'o')) return;
  }

  //*big tree ('B')
  if (x < 10000 && x > -10000 && y < 10000 && y > -10000) {
    if (loc_shanc_auto(10000, 10000, tree__big_shans, 3, x_small_big_tree, y_small_big_tree, "big tree", 'B')) return;
  }
  else if (x < 1000000 && x > -1000000 && y < 1000000 && y > -1000000) {
    if (loc_shanc_auto(1000000, 1000000, tree__big_shans, 3, x_normal_big_tree, y_normal_big_tree, "big tree", 'B')) return;
  }
  else {
    if (loc_shanc_auto(10000000, 10000000, tree__big_shans, 3, x_big_big_tree, y_big_big_tree, "big tree", 'B')) return;
  }

  //*normal tree ('N')
  if (x < 10000 && x > -10000 && y < 10000 && y > -10000) {
    if (loc_shanc_auto(10000, 10000, tree_normal_shans, 3, x_small_normal_tree, y_small_normal_tree, "normal tree", 'N')) return;
  }
  else if (x < 1000000 && x > -1000000 && y < 1000000 && y > -1000000) {
    if (loc_shanc_auto(1000000, 1000000, tree_normal_shans, 3, x_normal_normal_tree, y_normal_normal_tree, "normal tree", 'N')) return;
  }
  else {
    if (loc_shanc_auto(10000000, 10000000, tree_normal_shans, 3, x_big_normal_tree, y_big_normal_tree, "normal tree", 'N')) return;
  }

  //*small tree ('S')
  if (x < 10000 && x > -10000 && y < 10000 && y > -10000) {
    if (loc_shanc_auto(10000, 10000, tree_small_shans, 2, x_small_small_tree, y_small_small_tree, "small tree", 'S')) return;
  }
  else if (x < 1000000 && x > -1000000 && y < 1000000 && y > -1000000) {
    if (loc_shanc_auto(1000000, 1000000, tree_small_shans, 2, x_normal_small_tree, y_normal_small_tree, "small tree", 'S')) return;
  }
  else {
    if (loc_shanc_auto(10000000, 10000000, tree_small_shans, 2, x_big_small_tree, y_big_small_tree, "small tree", 'S')) return;
  }

  //*stone ('s')
  if (x < 10000 && x > -10000 && y < 10000 && y > -10000) {
    if (loc_shanc_auto(10000, 10000, stown_shans, 3, x_small_stone, y_small_stone, "stone", 's')) return;
  }
  else if (x < 1000000 && x > -1000000 && y < 1000000 && y > -1000000) {
    if (loc_shanc_auto(1000000, 1000000, stown_shans, 3, x_normal_stone, y_normal_stone, "stone", 's')) return;
  }
  else {
    if (loc_shanc_auto(10000000, 10000000, stown_shans, 3, x_big_stone, y_big_stone, "stone", 's')) return;
  }

  //*sulfur ('f')
  if (x < 10000 && x > -10000 && y < 10000 && y > -10000) {
    if (loc_shanc_auto(10000, 10000, sera_shans, 3, x_small_sulfur, y_small_sulfur, "sulfur", 'f')) return;
  }
  else if (x < 1000000 && x > -1000000 && y < 1000000 && y > -1000000) {
    if (loc_shanc_auto(1000000, 1000000, sera_shans, 3, x_normal_sulfur, y_normal_sulfur, "sulfur", 'f')) return;
  }
  else {
    if (loc_shanc_auto(10000000, 10000000, sera_shans, 3, x_big_sulfur, y_big_sulfur, "sulfur", 'f')) return;
  }

  //*iron ('i')
  if (x < 10000 && x > -10000 && y < 10000 && y > -10000) {
    if (loc_shanc_auto(10000, 10000, metal_shans, 2, x_small_iron, y_small_iron, "iron", 'i')) return;
  }
  else if (x < 1000000 && x > -1000000 && y < 1000000 && y > -1000000) {
    if (loc_shanc_auto(1000000, 1000000, metal_shans, 2, x_normal_iron, y_normal_iron, "iron", 'i')) return;
  }
  else {
    if (loc_shanc_auto(10000000, 10000000, metal_shans, 2, x_big_iron, y_big_iron, "iron", 'i')) return;
  }
  std::cout << "objects are over, click w to continue" << std::endl;
  free_mode_auto();
  
}
