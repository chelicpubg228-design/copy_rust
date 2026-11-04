#include "../system_rust/copy_rust.h"
 
bool kop_rast::loc_shanc_auto(long long x_plus,
                              long long y_plus,
                              int shanc_what, int big_whanc_what,
                              long long &x_what, long long &y_what,
                              std::string name_object,
                              char char_for_auto) {
 
  if (x < x_plus && x > -x_plus && y < y_plus && y > -y_plus) {
    if (shanc_what < big_whanc_what) {
 
      // сбрасываем фантомные нажатия клавиш
      while (_kbhit()) {
        _getch();
      }
 
      std::cout << "you meet " << name_object << std::endl;
      std::cout << "y or n" << std::endl;
 
      while (true) {
        char input = _getch();
 
        if (input == 'y' || input == 'Y') {
          x_what = x;
          y_what = y;
 
          switch (char_for_auto) {
            case 'b': locate_berry(); break;
            case 't': locate_tkan(); break;
            case 'w': vstr_wolf(); break;
            case 'm': vstr_mouse(); break;
            case 'r': vstr_bear(); break;
            case 'o': vstr_olen(); break;
            case 'B': rybka_tree_kamen_topor_big(); break;
            case 'N': rybka_tree_kamen_topor_normal(); break;
            case 'S': rybka_tree_kamen_topor_small(); break;
            case 's': stone_process(); break;
            case 'f': locate_sera(); break;
            case 'i': locate_iron(); break;
            default: break;
          }
 
          // пауза, чтобы успеть прочитать результат добычи
          std::cout << "press w......" << std::endl;
          while (_kbhit()) _getch();
          _getch();
 
          system("cls");
          std::cout << "x: " << x << std::endl;
          std::cout << "y: " << y << std::endl;
          return true;
        }
        else if (input == 'n' || input == 'N') {
          system("cls");
          std::cout << "x: " << x << std::endl;
          std::cout << "y: " << y << std::endl;
          return false;
        }
      }
    }
  }
 
  return false;
}
 
void kop_rast::loc_shanc() {
  // зона определяется в одном месте: 10 000 / 1 000 000 / остальное
  // (те же границы, что в locate_* и vstr_*)
  auto inside = [&](long long lim) {
    return x < lim && x > -lim && y < lim && y > -lim;
  };
 
  auto pick = [&](int roll, int need,
                  long long& xs, long long& ys,
                  long long& xn, long long& yn,
                  long long& xb, long long& yb,
                  const char* name, char key) -> bool {
    if (inside(10000))
      return loc_shanc_auto(10000, 10000, roll, need, xs, ys, name, key);
    if (inside(1000000))
      return loc_shanc_auto(1000000, 1000000, roll, need, xn, yn, name, key);
    return loc_shanc_auto(10000000, 10000000, roll, need, xb, yb, name, key);
  };
 
  if (pick(shans_berry, 2, x_small_berries, y_small_berries, x_normal_berries, y_normal_berries, x_big_berries, y_big_berries, "berries", 'b')) return;
  if (pick(shans_tkan, 2, x_small_tkan, y_small_tkan, x_normal_tkan, y_normal_tkan, x_big_tkan, y_big_tkan, "tkan", 't')) return;
  if (pick(shans_wolf, 4, x_small_wolf, y_small_wolf, x_normal_wolf, y_normal_wolf, x_big_wolf, y_big_wolf, "wolf", 'w')) return;
  if (pick(shans_mouse, 3, x_small_mouse, y_small_mouse, x_normal_mouse, y_normal_mouse, x_big_mouse, y_big_mouse, "mouse", 'm')) return;
  if (pick(shans_bear, 4, x_small_bear, y_small_bear, x_normal_bear, y_normal_bear, x_big_bear, y_big_bear, "bear", 'r')) return;
  if (pick(shanc_olen, 3, x_small_olen, y_small_olen, x_normal_olen, y_normal_olen, x_big_olen, y_big_olen, "olen", 'o')) return;
  if (pick(tree__big_shans, 3, x_small_big_tree, y_small_big_tree, x_normal_big_tree, y_normal_big_tree, x_big_big_tree, y_big_big_tree, "big tree", 'B')) return;
  if (pick(tree_normal_shans, 3, x_small_normal_tree, y_small_normal_tree, x_normal_normal_tree, y_normal_normal_tree, x_big_normal_tree, y_big_normal_tree, "normal tree", 'N')) return;
  if (pick(tree_small_shans, 2, x_small_small_tree, y_small_small_tree, x_normal_small_tree, y_normal_small_tree, x_big_small_tree, y_big_small_tree, "small tree", 'S')) return;
  if (pick(stown_shans, 3, x_small_stone, y_small_stone, x_normal_stone, y_normal_stone, x_big_stone, y_big_stone, "stone", 's')) return;
  if (pick(sera_shans, 3, x_small_sulfur, y_small_sulfur, x_normal_sulfur, y_normal_sulfur, x_big_sulfur, y_big_sulfur, "sulfur", 'f')) return;
  if (pick(metal_shans, 2, x_small_iron, y_small_iron, x_normal_iron, y_normal_iron, x_big_iron, y_big_iron, "iron", 'i')) return;
 
  std::cout << "resours is note, press w to continue" << std::endl;
}
