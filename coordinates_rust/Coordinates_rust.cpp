#include "../system_rust/copy_rust.h"
#include <iostream>
#include <string>

void kop_rast::update_coordinats() {
    // координаты большого дерева
    update_coordinats_big_tree();
    // координаты среднего дерева
    update_coordinats_normal_tree();


    // координаты маленького дерева
    update_coordinats_small_tree();
    // камень
    update_coordinats_stone();

    // сера
    update_coordinats_sulfrum();

    // железо
    update_coordinats_iron();


    // волк
    update_coordinats_wolf();


    // медведь
    update_coordinats_bear();
 

     // олень
     update_coordinats_olen();


    // мышь
    update_coordinats_mouse();    
    // ткань
    update_coordinats_tkan();    
    
    // ягоды
    update_coordinats_berry();

    
}

void kop_rast::update_coordinats_big_tree() {
    y_small_big_tree = rand() % 20001  - 10000;
    y_normal_big_tree = rand() % 200001  - 100000;
    y_big_big_tree = rand() % 20000001  - 10000000;
    x_small_big_tree = rand() % 20001  - 10000;
    x_normal_big_tree = rand() % 200001  - 100000;
    x_big_big_tree = rand() % 20000001  - 10000000;
}
void kop_rast::update_coordinats_normal_tree() {
    y_small_normal_tree = rand() % 20001 - 10000;
    y_normal_normal_tree = rand() % 200001 - 100000;
    y_big_normal_tree = rand() % 20000001  - 10000000;
    x_small_normal_tree = rand() % 20001  - 10000;
    x_normal_normal_tree = rand() % 200001  - 100000;
    x_big_normal_tree = rand() % 20000001  - 10000000;
}

void kop_rast::update_coordinats_small_tree() {
    y_small_small_tree = rand() % 20001 - 10000;
    y_normal_small_tree = rand() % 200001 - 100000;
    y_big_small_tree = rand() % 20000001  - 10000000;
    x_small_small_tree = rand() % 20001  - 10000;
    x_normal_small_tree = rand() % 200001 -100000;
    x_big_small_tree = rand() % 20000001  - 10000000;
}

void kop_rast::update_coordinats_stone() {
    y_small_stone = rand() % 20001  - 10000;
    y_normal_stone = rand() % 200001  - 100000;
    y_big_stone = rand() % 20000001  - 10000000;
    x_small_stone = rand() % 20001  - 10000;
    x_normal_stone = rand() % 200001  - 100000;
    x_big_stone = rand() % 20000001  - 10000000;
}

void kop_rast::update_coordinats_sulfrum() {
    y_small_sulfur = rand() % 20001  - 10000;
    y_normal_sulfur = rand() % 200001  - 100000;
    y_big_sulfur = rand() % 20000001  - 10000000;
    x_small_sulfur = rand() % 20001  - 10000;
    x_normal_sulfur = rand() % 200001  - 100000;
    x_big_sulfur = rand() % 20000001  - 10000000;

}

void kop_rast::update_coordinats_iron() {
    
    y_small_iron = rand() % 20001  - 10000;
    y_normal_iron = rand() % 200001  - 100000;
    y_big_iron = rand() % 20000001  - 10000000;
    x_small_iron = rand() % 20001  - 10000;
    x_normal_iron = rand() % 200001  - 100000;
    x_big_iron = rand() % 20000001  - 10000000;
}

void kop_rast::update_coordinats_wolf() {
    
    y_small_wolf = rand() % 20001  - 10000;
    y_normal_wolf = rand() % 200001  - 100000;
    y_big_wolf = rand() % 20000001  - 10000000;
    x_small_wolf = rand() % 20001  - 10000;
    x_normal_wolf = rand() % 200001  - 100000;
    x_big_wolf = rand() % 20000001  - 10000000;
}

void kop_rast::update_coordinats_bear() {
    y_small_bear = rand() % 20001  - 10000;
    y_normal_bear = rand() % 200001  - 100000;
    y_big_bear = rand() % 20000001  - 10000000;
    x_small_bear = rand() % 20001  - 10000;
    x_normal_bear = rand() % 200001  - 100000;
    x_big_bear = rand() % 20000001  - 10000000;
}

void kop_rast::update_coordinats_olen() {
    
    y_small_olen = rand() % 20001  - 10000;
    y_normal_olen = rand() % 200001  - 100000;
    y_big_olen = rand() % 20000001  - 10000000;
    x_small_olen = rand() % 20001  - 10000;
    x_normal_olen = rand() % 200001  - 100000;
    x_big_olen = rand() % 20000001  - 10000000;
}
void kop_rast::update_coordinats_mouse() {
    
    y_small_mouse = rand() % 20001  - 10000;
    y_normal_mouse = rand() % 200001  - 100000;
    y_big_mouse = rand() % 20000001  - 10000000;
    x_small_mouse = rand() % 20001  - 10000;
    x_normal_mouse = rand() % 200001  - 100000;
    x_big_mouse = rand() % 20000001  - 10000000;
}


void kop_rast::update_coordinats_tkan() {
    y_small_tkan = rand() % 20001  - 10000;
    y_normal_tkan = rand() % 200001  - 100000;
    y_big_tkan = rand() % 20000001  - 10000000;
    x_small_tkan = rand() % 20001  - 10000;
    x_normal_tkan = rand() % 200001  - 100000;
    x_big_tkan = rand() % 20000001  - 10000000;    
}

void kop_rast::update_coordinats_berry() {
    y_small_berries = rand() % 20001  - 10000;
    y_normal_berries = rand() % 200001  - 100000;
    y_big_berries = rand() % 20000001  - 10000000;
    x_small_berries = rand() % 20001  - 10000;
    x_normal_berries = rand() % 200001  - 100000;
    x_big_berries = rand() % 20000001  - 10000000;

}



