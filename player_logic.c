#include<stdio.h>
#include"player_logic.h"
Game_phase game;
int can_penguin_move(int x,int y,Game_phase game);
void set_player_to_1(Game_phase *game)
{
    game->current_player=1;
}
int penguins_left_of_any_player(Game_phase game)
{
    if(game.num_placed_penguins_player1<game.number_of_penguins||game.num_placed_penguins_player2<game.number_of_penguins)
        return 1;
    else
        return 0;
}
int penguins_left_of_current_player(Game_phase game)
{
    if(game.current_player==1)
    {
        if(game.num_placed_penguins_player1<game.number_of_penguins)
            return 1;
        else
            return 0;
    }
    else if(game.current_player==2)
    {
        if(game.num_placed_penguins_player2<game.number_of_penguins)
            return 1;
        else
            return 0;
    }
}
void change_player(Game_phase *game)
{
    printf("Change of player...\n");

    if(game->current_player == 1)
    {
        game->current_player++;
    }
    else if(game->current_player == 2)
    {
        game->current_player--;
    }

}

int are_there_any_possible_movements_for_any_player(Game_phase game)
{
    for(int i=0;i<game.m;i++)
    {
        for(int j=0;j<game.n;j++)
        {
            if(game.board[i][j]==10||game.board[i][j]==20)
            {
                if(can_penguin_move(i,j,game))
                return 1;
            }
        }
    }
    printf("no more movement for any player\n");
    return 0;
    
       
}
int are_there_any_posible_movement_for_current_player(Game_phase game)
{
    for(int i=0;i<game.m;i++)
    {
        for(int j=0;j<game.n;j++)
        {
            if(game.current_player==1)
            {
                if(game.board[i][j]==10)
                 {
                    if(can_penguin_move(i,j,game))
                    return 1;
                }
            }
            if(game.current_player==2)
            {
                if(game.board[i][j]==20)
                 {
                    if(can_penguin_move(i,j,game))
                    return 1;
                }
            }
            
        }
    }
    printf("no more movement for current player\n");
    return 0;
    
       
}
int can_penguin_move(int y,int x,Game_phase game)
{
    //checking if penguin can move with respect to matrix size
    if(game.board[y][x+1] == 1 || game.board[y][x+1] == 2|| game.board[y][x+1] == 3)
        return 1;
    else if(game.board[y][x-1] == 1 || game.board[y][x-1] == 2 || game.board[y][x-1] == 3)
        return 1;
    else if(game.board[y+1][x] == 1 || game.board[y+1][x] == 2 || game.board[y+1][x] == 3)
        return 1;
    else if(game.board[y-1][x] == 1 || game.board[y-1][x] == 2 || game.board[y-1][x] == 3)
        return 1;
    else
        return 0;

    

}