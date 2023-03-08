#ifndef GAME_LOGIC_H_
#define GAME_LOGIC_H_
#include"structure.h"
extern int board[250][250];
int position_valid(Game_phase game,int board[250][250]);
int are_there_any_fish_left(Game_phase game);
void increase_score(Game_phase *game);
int movement_forbidden(Game_phase game,int board[250][250]);

#endif