#include <iostream>
#include <string>
#include "../system_rust/copy_rust.h"
bool kop_rast::loc_shanc_auto(
    long long x_plus,
   
    long long y_plus, 
  
    int shanc_what,
    int big_whanc_what,
    long long& x_what,
    long long& y_what
 
    ) {
        if (x < x_plus and x > -x_plus and y < y_plus and y > -y_plus) {

        if (shanc_what < big_whanc_what) {
            x_what = x;
            y_what = y;
            return true;
           

        }
    }
    return false;
}

void kop_rast::loc_shanc() {
 

    //*berry
    if (loc_shanc_auto(10000, 10000, shans_berry, 3, x_small_berries, y_small_berries)) return;
    if (loc_shanc_auto(100000, 100000, shans_berry, 3, x_normal_berries, y_normal_berries)) return;
    if (loc_shanc_auto(10000000, 10000000, shans_berry, 3, x_big_berries, y_big_berries)) return;

    //*tkan
    if (loc_shanc_auto(10000, 10000, shans_tkan, 3, x_small_tkan, y_small_tkan)) return;
    if (loc_shanc_auto(100000, 100000, shans_tkan, 3, x_normal_tkan, y_normal_tkan)) return;
    if (loc_shanc_auto(10000000, 10000000, shans_tkan, 3, x_big_tkan, y_big_tkan)) return;

    //*wolf
    if (loc_shanc_auto(10000, 10000, shans_wolf, 10, x_small_wolf, y_small_wolf)) return;
    if (loc_shanc_auto(100000, 100000, shans_wolf, 10, x_normal_wolf, y_normal_wolf)) return;
    if (loc_shanc_auto(10000000, 10000000, shans_wolf, 10, x_big_wolf, y_big_wolf)) return;

    //*mouse
    if (loc_shanc_auto(10000, 10000, shans_mouse, 5, x_small_mouse, y_small_mouse)) return;
    if (loc_shanc_auto(100000, 100000, shans_mouse, 5, x_normal_mouse, y_normal_mouse)) return;
    if (loc_shanc_auto(10000000, 10000000, shans_mouse, 5, x_big_mouse, y_big_mouse)) return;

    //*bear
    if (loc_shanc_auto(10000, 10000, shans_bear, 10, x_small_bear, y_small_bear)) return;
    if (loc_shanc_auto(100000, 100000, shans_bear, 10, x_normal_bear, y_normal_bear)) return;
    if (loc_shanc_auto(10000000, 10000000, shans_bear, 10, x_big_bear, y_big_bear)) return;

    //*olen
    if (loc_shanc_auto(10000, 10000, shanc_olen, 3, x_small_olen, y_small_olen)) return;
    if (loc_shanc_auto(100000, 100000, shanc_olen, 3, x_normal_olen, y_normal_olen)) return;
    if (loc_shanc_auto(10000000, 10000000, shanc_olen, 3, x_big_olen, y_big_olen)) return;

    //*big tree
    if (loc_shanc_auto(10000, 10000, tree__big_shans, 4, x_small_big_tree, y_small_big_tree)) return;
    if (loc_shanc_auto(1000000, 1000000, tree__big_shans, 4, x_normal_big_tree, y_normal_big_tree)) return;
    if (loc_shanc_auto(10000000, 10000000, tree__big_shans, 4, x_big_big_tree, y_big_big_tree)) return;

    //*normal tree
    if (loc_shanc_auto(10000, 10000, tree_normal_shans, 3, x_small_normal_tree, y_small_normal_tree)) return;
    if (loc_shanc_auto(1000000, 1000000, tree_normal_shans, 3, x_normal_normal_tree, y_normal_normal_tree)) return;
    if (loc_shanc_auto(10000000, 10000000, tree_normal_shans, 3, x_big_normal_tree, y_big_normal_tree)) return;

    //*small tree
    if (loc_shanc_auto(10000, 10000, tree_small_shans, 3, x_small_small_tree, y_small_small_tree)) return;
    if (loc_shanc_auto(1000000, 1000000, tree_small_shans, 3, x_normal_small_tree, y_normal_small_tree)) return;
    if (loc_shanc_auto(10000000, 10000000, tree_small_shans, 3, x_big_small_tree, y_big_small_tree)) return;

    //*stone
    if (loc_shanc_auto(10000, 10000, stown_shans, 4, x_small_stone, y_small_stone)) return;
    if (loc_shanc_auto(1000000, 1000000, stown_shans, 4, x_normal_stone, y_normal_stone)) return;
    if (loc_shanc_auto(10000000, 10000000, stown_shans, 4, x_big_stone, y_big_stone)) return;

    //*sulfur
    if (loc_shanc_auto(10000, 10000, sera_shans, 5, x_small_sulfur, y_small_sulfur)) return;
    if (loc_shanc_auto(1000000, 1000000, sera_shans, 5, x_normal_sulfur, y_normal_sulfur)) return;
    if (loc_shanc_auto(10000000, 10000000, sera_shans, 5, x_big_sulfur, y_big_sulfur)) return;

    //*iron
    if (loc_shanc_auto(10000, 10000, metal_shans, 2, x_small_iron, y_small_iron)) return;
    if (loc_shanc_auto(1000000, 1000000, metal_shans, 2, x_normal_iron, y_normal_iron)) return;
    if (loc_shanc_auto(10000000, 10000000, metal_shans, 2, x_big_iron, y_big_iron)) return;

}