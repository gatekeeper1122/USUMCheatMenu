// Filename: pokemon_modifiers.c

#include "cheats.h"
#include "hid.h"

/********************************
 *                              *
 *       Pokémon Modifiers      *
 *                              *
 ********************************/

// Pokémon menu entry
void    pokemonMenu(void) {
    new_spoiler("Pokemon");
        new_entry("Rename any Pokemon", renamePokemon);
        (gameVer == 10) ? new_entry_managed_note("Instant Egg from Nursery", "Hold L & talk to Nursery NPC", instantEgg, INSTANTEGG, 0) : NULL;
        (gameVer == 10) ? new_entry("Instant Egg Hatching", instantHatch) : 0;
        new_line();
    exit_spoiler();
}


// Rename any Pokemon at the Name Rater
void	renamePokemon(void) {
	WRITEU32(o_renamepokemon, 0xE3A00001);
}


// Egg instantly ready when talking to Nursery NPC while holding L
void	instantEgg(void) {
    WRITEU32(0x00444A6C, (is_pressed(BUTTON_L)) ? 0xE3A01001 : 0xE2800E1E);
    WRITEU32(0x00444A70, (is_pressed(BUTTON_L)) ? 0xE5C011E0 : 0xE1D000D0);
    WRITEU32(0x00444A74, (is_pressed(BUTTON_L)) ? 0xEA00684B : 0xE12FFF1E);
}


// Instant egg hatching in one step
void	instantHatch(void) {
	WRITEU32(0x005958C0, 0xE59D000C);
	WRITEU32(0x005958C4, 0xE59F500C);
	WRITEU32(0x005958C8, 0xE1500005);
	WRITEU32(0x005958CC, 0x03A00000);
	WRITEU32(0x005958D0, 0x11A00004);
	WRITEU32(0x005958D4, 0xE12FFF1E);
	WRITEU32(0x005958D8, 0x006CE724);
	WRITEU32(0x004919E0, 0xEB040FB6);
}
