#include<stdio.h>
#include<windows.h>
#include <unistd.h>
#include"game_logic.h"
Game_phase game;
int is_route_clear(Game_phase game);
int position_valid(Game_phase game)
{
        if(game.board[game.placement_coord_y][game.placement_coord_x]==1)
            return 1;
        else if(game.placement_coord_x>game.m||game.placement_coord_y>game.n||game.placement_coord_x<0||game.placement_coord_y<0)
            return 0;
        else
            return 0;

}
int are_there_any_fish_left(Game_phase game)
{
     game.fishes = 0;
    for(int i = 0; i < game.m; i++){
        for(int k = 0; k < game.n; k++){
            if(game.board[i][k] == 1){
                game.fishes += 1;
            }
            if(game.board[i][k] == 2){
                game.fishes += 1;
            }
            if(game.board[i][k] == 3){
                game.fishes += 1;
            }
        }
    }

    if(game.fishes == 0){
        return 0;
    }
    else{
        return 1;
    }
}
void increase_score(Game_phase *game)
{
 if (game->current_player == 1)
 {
    if(game->board[game->movement_y][game->movement_x] == 1)
    {
        game->score_counter_1 += 1;
    }
    else if(game->board[game->movement_y][game->movement_x] == 2) 
    {
        game->score_counter_1 += 2;
    }
    else if(game->board[game->movement_y][game->movement_x] == 3)
    {
        game->score_counter_1 += 3;
    }
 }
 if (game->current_player == 2)
 {
     if(game->board[game->movement_y][game->movement_x] == 1)
     {
         game->score_counter_2 += 1;
     }
     else if(game->board[game->movement_y][game->movement_x] == 2)
     {
         game->score_counter_2 += 2;
     }
     else if(game->board[game->movement_y][game->movement_x] == 3)
     {
         game->score_counter_2 +=3;
     }
 }
}
int movement_forbidden(Game_phase game)
{
    if(game.current_player==1)
    {
        if(game.board[game.penguin_position_y][game.penguin_position_x]!=10)
        {
            system("cls");
            printf("\t\t\tWRONG PENGUIN POSITION\n");
            sleep(2);
            return 0;
        }
        else if(!(game.board[game.movement_y][game.movement_x]==1||game.board[game.movement_y][game.movement_x]==2||game.board[game.movement_y][game.movement_x]==3))
        {
            system("cls");
            printf("\t\t\tWRONG PENGUIN POSITION\n");
            sleep(2);
            return 0;
        }
        else if(!(game.movement_x==game.penguin_position_x||game.movement_y==game.penguin_position_y))
        {
            system("cls");
            printf("\t\t\tYOU CAN'T MOVE DIAGONALLY\n");
            sleep(2);
            return 0;
        }
         else if(!is_route_clear(game))
        {
            system("cls");
            printf("\t\t\tWRONG MOVE\n");
            sleep(2);
            return 0;
        }
        
    }
    else if(game.current_player==2)
    {
        if(game.board[game.penguin_position_y][game.penguin_position_x]!=20)
        {
            system("cls");
            printf("\t\t\tWRONG TEAM\n");
            sleep(2);
            return 0;
        }
        else if(!(game.board[game.movement_y][game.movement_x]==1||game.board[game.movement_y][game.movement_x]==2||game.board[game.movement_y][game.movement_x]==3))
        {
            system("cls");
            printf("\t\t\tWRONG PENGUIN POSITION\n");
            sleep(2);
            return 0;
        }
        else if(!(game.movement_x==game.penguin_position_x||game.movement_y==game.penguin_position_y))
        {
            system("cls");
            printf("\t\t\tYOU CAN'T MOVE DIAGONALLY\n");
            sleep(2);
            return 0;
        }
        else if(!is_route_clear(game))
        {
            system("cls");
            printf("\t\t\tWRONG MOVE\n");
            sleep(2);
            return 0;
        }
    }
    return 1;
}
int is_route_clear(Game_phase game)
{
    int distance_x=game.movement_x-game.penguin_position_x;
    int distance_y=game.movement_y-game.penguin_position_y;
    int start_pos_x=game.penguin_position_x;
    int start_pos_y=game.penguin_position_y;
    if(distance_x>0)
    {
        for(int i=0;i<distance_x;i++)
        {
            start_pos_x+=1;
            if(game.board[game.penguin_position_y][start_pos_x]>=10||game.board[game.penguin_position_y][start_pos_x]==0)
            return 0;
        }
    }
    else if(distance_x<0)
    {
        for(int i=0;i>distance_x;i--)
        {
            start_pos_x-=1;
            if(game.board[game.penguin_position_y][start_pos_x]>=10||game.board[game.penguin_position_y][start_pos_x]==0)
            return 0;
        }
    }
    if(distance_y>0)
    {
        for(int i=0;i<distance_y;i++)
        {
            start_pos_y+=1;
            if(game.board[start_pos_y][game.penguin_position_x]>=10||game.board[start_pos_y][game.penguin_position_x]==0)
            return 0;
        }
    }
    else if(distance_y<0)
    {
        for(int i=0;i>distance_y;i--)
        {
            start_pos_y-=1;
            if(game.board[start_pos_y][game.penguin_position_x]>=10||game.board[start_pos_y][game.penguin_position_x]==0)
            return 0;
        }
    }
    return 1;
}