#include <string>
#include "copy_rust.h"
// Текст справки вынесен из класса, чтобы copy_rust.h не раздувался.
// Функция вместо inline-переменной, чтобы работало и без C++17.
const std::string kop_rast::help_text = R"HELP(

+==========================================================+
|                   HELP - SURVIVAL GAME                   |
|                       version 4.5                        |
+==========================================================+

------------------------------------------------------------
  MAIN MENU (type the number and press Enter)
------------------------------------------------------------
  1  - Show all information about resources and status
  2  - Exit the game (progress is saved automatically)
  3  - Sleep for 10 sec            (+75 energy)
  4  - Show this help message
  5  - Open craft menu
  6  - Put on armor
  7  - Take off armor
  8  - Player statistics
  9  - Axe statistics
  10 - FREE MODE (walk around the world)
  11 - Eat 5 berries               (+food, +water, +energy, +HP)

  Extra commands:
  "help"  - show this help
  "clear" - clear the screen

------------------------------------------------------------
  FREE MODE (option 10)
------------------------------------------------------------
  w - move x+        s - move x-
  d - move y+        a - move y-
  e - inspect the area (trees, stone, iron, sulfur, berries,
      cloth and animals are found ONLY this way)
  q - return to main menu (progress is saved)

  When the game asks "y or n":
    y - accept (gather the resource / meet the animal)
    n - decline (keep looking)

------------------------------------------------------------
  CHARACTER STATUS
------------------------------------------------------------
  HP     - health. Reaching 0 = death.
  Food   - drops with every action. Reaching 0 = death.
  Water  - drops with every action. Reaching 0 = death.
  Energy - spent on actions, restored by sleeping.
           Reaching -100 = death.
  Tool durability - drops with use. At 0 the tool breaks.

  HP regeneration works when food >= 70 AND water >= 70.

------------------------------------------------------------
  RESOURCES
------------------------------------------------------------
  tree  - wood      (base crafting material)
  stown - stone     (for stone axe)
  metal - iron      (for iron axe)
  sera  - sulfur    (rare resource)
  berry - berries   (restore stats)
  tkan  - cloth     (for leather armor and threads)
  nitki - threads   (crafted from cloth)
  bone  - bones     (from hunting)
  meet  - meat      (from hunting)
  kosha - leather   (from hunting)

------------------------------------------------------------
  TOOLS
------------------------------------------------------------
  Stone axe - basic, chops trees, mines stone
  Iron axe  - faster and more durable
  Iron pick - for stone, sulfur, iron
  Torch     - weak weapon, but always with you

------------------------------------------------------------
  CRAFTING (option 5)
------------------------------------------------------------
  1. Stone axe         = 5 wood + 1 stone
  2. Iron axe          = 5 wood + 5 iron
  3. Leather helmet    = 3 cloth + 3 threads + 3 leather
  4. Leather bib       = 5 cloth + 6 threads + 10 leather
  5. Leather leggings  = 4 cloth + 5 threads + 4 leather
  6. Leather boots     = 3 cloth + 3 threads + 5 leather
  7. Threads           = 5 cloth

------------------------------------------------------------
  ARMOR (leather)
------------------------------------------------------------
  Helmet +10 max HP     Bib   +20 max HP
  Leggings +15 max HP   Boots +5 max HP

  Armor has its own durability and wears out in combat.
  Equip / unequip via options 6 and 7.

------------------------------------------------------------
  COMBAT
------------------------------------------------------------
  When you meet an animal:
    1 - run away (lose energy, food, water)
    2 - fight    (choose your weapon)

  Weapons in combat:
    1 - stone axe (15 dmg)    2 - iron axe (25 dmg)
    3 - iron pick (35 dmg)    4 - torch    (10 dmg)

  A mouse cannot be killed - it only costs you HP.
  Rewards for victory: bones, meat, leather, cloth.

------------------------------------------------------------
  BEGINNER TIPS
------------------------------------------------------------
  1. Watch your food and water - they drop with every action.
  2. Sleep often - energy runs out fast.
  3. Enter free mode (10), walk around and press 'e'.
  4. First chop wood and craft a stone axe (option 5 -> 1).
  5. Berries restore everything - eat them with option 11.
  6. Save iron for the iron axe - it speeds up progress.
  7. The game autosaves - feel free to exit anytime.

------------------------------------------------------------
  CHEATS ARE FORBIDDEN
------------------------------------------------------------
  If HP > 250 - the config is deleted and progress resets.

------------------------------------------------------------
           Good luck surviving!
------------------------------------------------------------

)HELP";
const std::string kop_rast::help_text_for_set = R"HELP(
  +==========================================================+
|                      SETTINGS HELP                       |
+==========================================================+

  Type a letter and press Enter.

  h - show this help
  n - change your player name
  r - remove the save file (config) and start from scratch
  q - leave settings and go back to the main menu

------------------------------------------------------------
  WARNING
------------------------------------------------------------
  r and d cannot be undone: all resources, tools, armor
  and coordinates are lost. The game will ask you to
  confirm with "y" before deleting anything.
  Any answer other than "y" cancels the action.
)HELP";