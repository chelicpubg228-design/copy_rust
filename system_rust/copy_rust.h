#pragma once
#include <chrono>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <iso646.h>
#include <nlohmann/json.hpp>
#include <string>
#include <thread>

class kop_rast {
public:
std::string help_text = R"(

+==========================================================+
|                   HELP - SURVIVAL GAME                   |
|                       version 4.2                        |
+==========================================================+

------------------------------------------------------------
  MAIN MENU (type the number and press Enter)
------------------------------------------------------------
  1  - Show all information about resources and status
  2  - Exit the game (progress is saved automatically)
  3  - Chop a big tree             (needs an axe)
  4  - Find berries
  5  - Eat 5 berries               (+food, +water, +energy, +HP)
  6  - Sleep for 10 sec            (+75 energy)
  7  - Show this help message
  8  - Open craft menu
  9  - Mine stone                  (needs a pickaxe)
  10 - Find sulfur                 (needs a pickaxe)
  11 - Find iron                   (needs a pickaxe)
  12 - Chop a normal tree          (needs an axe)
  13 - Chop a small tree           (needs an axe)
  14 - Hunting (deer / bear / wolf)
  15 - Find cloth
  16 - Put on armor
  17 - Take off armor
  18 - Player statistics
  19 - Axe statistics
  20 - FREE MODE (walk around the world)

  Extra commands:
  "help"  - show this help
  "clear" - clear the screen

------------------------------------------------------------
  FREE MODE (option 20)
------------------------------------------------------------
  w - move forward  (x+)
  s - move backward (x-)
  d - move right    (y+)
  a - move left     (y-)
  e - inspect the area (look for objects nearby)
  q - return to main menu
  x - refresh the world (regenerate coordinates)

  When the game asks "y or n":
    y - accept (interact with the object)
    n - decline (keep searching)

------------------------------------------------------------
  CHARACTER STATUS
------------------------------------------------------------
  HP       - health. Reaching 0 = death.
  Food     - drops over time. Reaching 0 = death.
  Water    - drops over time. Reaching 0 = death.
  Energy   - spent on actions, restored by sleeping.
             Reaching -100 = death.
  Tool durability - drops with use. At 0 the tool breaks.

  HP regeneration: works when food >= 70 AND water >= 70.

------------------------------------------------------------
  RESOURCES
------------------------------------------------------------
  tree     - wood        (base crafting material)
  stown    - stone       (for stone axe)
  metal    - iron        (for advanced tools)
  sera     - sulfur      (rare resource)
  berry    - berries     (restore stats)
  tkan     - cloth       (for leather armor)
  nitki    - threads     (crafted from cloth)
  bone     - bones       (from hunting)
  meet     - meat        (from hunting)
  kosha    - leather     (from hunting)
  MVK      - advanced material

------------------------------------------------------------
  TOOLS
------------------------------------------------------------
  Stone axe    - basic, chops trees
  Iron axe     - faster and more durable
  Iron pick    - for stone, sulfur, iron
  MVK pick     - maximum efficiency
  Chainsaw     - top mining speed
  Torch        - weak weapon, but always with you

------------------------------------------------------------
  CRAFTING (option 8)
------------------------------------------------------------
  1. Stone axe     = 5 wood + 1 stone
  2. Iron axe      = 5 wood + 5 iron
  3. Leather helmet = 3 cloth + 3 threads + 3 leather
  4. Leather bib    = 5 cloth + 6 threads + 10 leather
  5. Leather leggings = 4 cloth + 5 threads + 4 leather
  6. Leather boots  = 3 cloth + 3 threads + 5 leather
  7. Threads        = 5 cloth

------------------------------------------------------------
  ARMOR (leather)
------------------------------------------------------------
  Helmet    +10 max HP
  Bib       +20 max HP
  Leggings  +15 max HP
  Boots     +5  max HP

  Armor has its own durability and breaks in combat.
  Equip / unequip via options 16 and 17.

------------------------------------------------------------
  COMBAT
------------------------------------------------------------
  When you meet an animal:
    1 - run away (lose energy, food, water)
    2 - fight    (choose your weapon)

  Weapons in combat:
    1 - stone axe    (15 dmg)
    2 - iron axe     (25 dmg)
    3 - iron pick    (35 dmg)
    4 - torch        (10 dmg)

  WARNING: A mouse cannot be killed - it is too small.
  Meeting a mouse just costs you HP and you run away.

  Rewards for victory: bones, meat, leather, cloth.

------------------------------------------------------------
  BEGINNER TIPS
------------------------------------------------------------
  1. Watch your food and water - they drop with every action.
  2. Sleep often - energy runs out fast.
  3. First chop wood (option 12 or 13) and craft a stone
     axe (option 8 -> 1).
  4. Look for berries (option 4) - they restore everything.
  5. You need stone for the axe -> search via option 9.
  6. Save iron for the iron axe and pick - they speed up
     your progress a lot.
  7. Free mode (20) is the most convenient way to find
     resources: walk around and press 'e'.
  8. The game autosaves - feel free to exit anytime.

------------------------------------------------------------
  CHEATS ARE FORBIDDEN
------------------------------------------------------------
  If HP > 250 - the config is deleted and progress resets.

------------------------------------------------------------
           Good luck surviving! 
------------------------------------------------------------

)";
  void prov_alive();
  void load_json();
  void ubdate_json();
  void resurs_mine(int &resours, int &hp_resours, long long x_resurs,
                   long long y_result, int time_to_find, int reset_hp,
                   std::string resours_name, int instr,
                   void (kop_rast::*func_update)());
  void locate_sera();
  void rybka_tree_kamen_topor_big();
  void rybka_tree_kamen_topor_normal();
  void rybka_tree_kamen_topor_small();
  void stone_process();
  void time(int time_cin);
  void hp_minys();
  void ate_berry();
  void sleep();
  template <typename T> void print(T &&print_str) {
    std::cout << print_str << std::endl;
  }
  void locate_tkan();
  void hunting();
  void craft_boots_leather();
  void craft_leggings_leather();
  void locate_iron();
  void craft_bib_leather();
  void craft_helmet_leather();
  void vstr_wolf();
  void vstr_bear();
  void prov_coord();
  void vstr_mouse();
  void mouse_coordinats();

  void craft_threads();
  void vstr_olen();
  void fight(long long y_animal, int &hp_animal, long long x_animal,
             int damage_animal, int reset_hp_animal, std::string name_animal);
  void random_ubdate_();
  void craft_axe_stone();
  void craft_axe_iron();
  void craft();
  void locate_berry();
  void hp_minus_for_fight(int ddmage_for_def_fight, int &hp_bron_for_def_fight);
  void reset();
  void regeneration();
  void prov_instryment_stone_axe_hp();
  void prov_pick_iron_hp();
  void prov_iron_axe_hp();
  void prov_instryments();
  void update_coordinats_sulfrum();
  void update_coordinats_iron();
  void update_coordinats_stone();
  void update_coordinats_big_tree();
  void update_coordinats_normal_tree();
  void update_coordinats_small_tree();
  void update_coordinats_berry();
  void update_coordinats_tkan();
  void loc_shanc();
  bool loc_shanc_auto(long long x_plus, long long y_plus, int shanc_what,
                      int big_whanc_what, long long &x_what, long long &y_what,
                      std::string name_object,
                      char char_for_auto

  );
  void update_coordinats_wolf();
  void update_coordinats_mouse();
  void update_coordinats_bear();
  void update_coordinats_olen();
  void update_coordinats();

  void menu();
  void free_mode();
  void print_menu();
  void free_mode_auto();
  void print_statisc_user();
  void print_statistic_axe();
  void print_info();
  void craft_bron();
  void leather_minus_for_def_fuction_fight_ok_avtomatisation_for_bear();
  void leather_minus_for_def_fuction_fight_ok_avtomatisation_for_wolf();
  void leather_minus_for_def_fuction_fight_ok_avtomatisation_for_mouse();
  void leather_minus_for_def_fuction_fight_ok_avtomatisation_for_olen();
  void ignore();
  void continue_enter();
  void auto_minus_leathing(int damage_helmet, int damage_bib,
                           int damage_leggings, int damage_boots);
  void proc_for_fight_all_animals(
      std::string name_animal_fight, int damage_animal, int fight_bone,
      int fight_meet, int fight_tkan, int fight_kosha, int &hp_animal_fight,
      int reset_hp_animal_for_fight, int leathing_bib_minus_sample,
      int leathing_helmet_minus_sample, int leathing_boots_minus_sample,
      int leathing_leggints_minus_sample

  );

  void donning_armor();
  void undonning_armor();
  void prov_bron();
  //! рандомные числа для добычи дерева
  int tree_rand_kamen_topor{0};
  int tree_rand_iron_topor{0};
  int tree_rand_MVK_topor{0};
  int tree_chainsaw{0};
  // рандомное время находки дерева
  int tree_time{0};
  std::string jjson;
  // шанс встретить большое дерево
  int tree__big_shans{0};
  int shans_berry{0};
  // шанс втретить среднее дерево

  int tree_normal_shans{0};
  int shans_tkan = 0;
  // время находки камня
  // шанс втретить волка
  int shans_wolf{0};
  // шанс втретить мышь
  int shans_mouse{0};
  // шанс втретить медведя
  int shans_bear{0};
  // шанс втретить оленя
  int shanc_olen{0};
  int shans_n_stoe{0};
  // шанс втретить маленькое дерево
  int tree_small_shans{0};
  //! координаты начало ======
  long long y{0}, x{0};
  // координаты большого дерева

  long long y_big_big_tree{0};
  long long y_normal_big_tree{0};
  long long y_small_big_tree{0};
  long long x_big_big_tree{0};
  long long x_normal_big_tree{0};
  long long x_small_big_tree{0};

  // координаты среднего дерева

  long long y_big_normal_tree{0};
  long long y_normal_normal_tree{0};
  long long y_small_normal_tree{0};
  long long x_big_normal_tree{0};
  long long x_normal_normal_tree{0};
  long long x_small_normal_tree{0};

  // координаты маленького дерева

  long long y_big_small_tree{0};
  long long y_normal_small_tree{0};
  long long y_small_small_tree{0};
  long long x_big_small_tree{0};
  long long x_normal_small_tree{0};
  long long x_small_small_tree{0};

  // камень

  long long y_big_stone{0};
  long long y_normal_stone{0};
  long long y_small_stone{0};
  long long x_big_stone{0};
  long long x_normal_stone{0};
  long long x_small_stone{0};

  // сера

  long long y_big_sulfur{0};
  long long y_normal_sulfur{0};
  long long y_small_sulfur{0};
  long long x_big_sulfur{0};
  long long x_normal_sulfur{0};
  long long x_small_sulfur{0};

  // железо

  long long y_big_iron{0};
  long long y_normal_iron{0};
  long long y_small_iron{0};
  long long x_big_iron{0};
  long long x_normal_iron{0};
  long long x_small_iron{0};

  // волк

  long long y_big_wolf{0};
  long long y_normal_wolf{0};
  long long y_small_wolf{0};
  long long x_big_wolf{0};
  long long x_normal_wolf{0};
  long long x_small_wolf{0};

  // медведь

  long long y_big_bear{0};
  long long y_normal_bear{0};
  long long y_small_bear{0};
  long long x_big_bear{0};
  long long x_normal_bear{0};
  long long x_small_bear{0};

  // олень

  long long y_big_olen{0};
  long long y_normal_olen{0};
  long long y_small_olen{0};
  long long x_big_olen{0};
  long long x_normal_olen{0};
  long long x_small_olen{0};

  // мышь

  long long y_big_mouse{0};
  long long y_normal_mouse{0};
  long long y_small_mouse{0};
  long long x_big_mouse{0};
  long long x_normal_mouse{0};
  long long x_small_mouse{0};

  // ткань

  long long y_big_tkan{0};
  long long y_normal_tkan{0};
  long long y_small_tkan{0};
  long long x_big_tkan{0};
  long long x_normal_tkan{0};
  long long x_small_tkan{0};

  // ягоды

  long long y_big_berries{0};
  long long y_normal_berries{0};
  long long y_small_berries{0};
  long long x_big_berries{0};
  long long x_normal_berries{0};
  long long x_small_berries{0};

  //! координаты конец =====

  // шанс размера дерево
  int tree_razmer_shans{0};
  // время находки серы
  int time_sera{0};
  // шанс встретить руды
  int stown_shans{0};
  int sera_shans{0};
  int metal_shans{0};
  int time_small_tree{0};
  // шанс встретить бочку
  int bochka_shans{0};
  int hp_iron_exa = 140;
  // время нахождения ткани
  int time_tkan = 0;
  int time_normal_tree{0};
  //! рандомные числа для камня
  int stown_stown_topor{0};
  int stown_iron_pick{0};
  int stown_MVK_pick{0};
  bool is_bool_leathing_bib = false;
  bool is_bool_leathing_boots = false;
  bool is_bool_leathing_leggings = false;
  bool is_bool_leathing_helmet = false;
  int stown_byr{0};
  int time_to_iron{0};
  //! жизнь всех существ и предметов
  short hp_bochka = 40;
  int hp_person = 100;
  int hp_tree_big = 90;
  int hp_tree_normal = 70;
  int hp_tree_small = 55;
  int hp_stown = 70;
  int hp_sera = 60;
  int hp_iron = 70;
  int hp_berry = 5;
  int hp_pick = 150;
  short eda = 100;
  int hp_bear = 120;
  int hp_mouse = 10;
  int hp_olen = 80;
  int hp_wolf = 100;
  short water = 100;
  short hp_stown_topor = 100;

  //! важные переменные
  int level_user = 0;
  int stown_topor = 1;
  int tree = 0;
  int tkan = 0;
  int verst_level = 0;
  int metal = 0;
  int hp_tkan = 30;
  int skrap = 0;
  int hp_leathing_bib = 50;
  int hp_leathing_leggings = 20;
  int hp_leating_boots = 10;
  int hp_leathing_helmet = 25;
  int MVK = 0;
  int hp_max = 100;
  std::string name_user;

  int cin_hunting{0};
  int stown = 0;
  int leather_bib = 0;
  int leather_helmet = 0;
  int leather_boots = 0;
  int leather_leggings = 0;
  int voda_butka = 0;
  int fakel = 1;
  int bone = 0;
  int berry = 0;
  int meet = 0;
  int kosha = 0;
  int nitki = 0;
  int byr = 0;
  // уроны предметов  по существам
  // топоры
  int damage_stone_axe_for_animal = 15;
  int damage_iron_axe_for_animal = 25;
  // кирка
  int damage_iron_pick_for_animal = 35;
  // факел
  int damage_fakel_for_animal = 10;
  // волк
  int damage_wolf = 10;
  // медведь
  int damage_bear = 15;
  // олень
  int damage_olen = 1;
  // мышьы
  int damage_mouse = 5;

  int sera = 0;
  int chainsaw = 0;
  int iron_pick = 0;
  int MVk_pick = 0;
  int iron_topor = 0;
  int MVK_topor = 0;
  std::string cin_menu;
  int energy = 100;
  std::string deception;
};
