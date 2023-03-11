#ifndef BOARD_H_
#define BOARD_H_ 
#include"structure.h"
void allocate(Game_phase *game);
void generate_board(Game_phase *game);
void show_board(Game_phase game);
void place_penguin(Game_phase *game);
void remove_fish(Game_phase *game);
void move_penguin(Game_phase *game);
void remove_ice_floe(Game_phase *game);


#endif //BOARD_H_