#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <unistd.h>
#include<windows.h>
#include"board.h"
#define ONE_FISH 1
#define TWO_FISH 2
#define THREE_FISH 3
#define PLAYER_ONE 10
#define PLAYER_TWO 20
#define ICE_FLOE 11
#define WATER 0
Game_phase game;
void change_colour(Game_phase game,int x,int y);
void generate_board(Game_phase *game)
{
    int num_of_1fish;
    int num_1fish_placed=0;
    num_of_1fish=2*game->number_of_penguins+2;
    int random_fish;
    int num_fish1_placed=0;
    int rand_m,rand_n;
      for(int i=0;i<num_of_1fish;i++)
        {
            rand_m=1+rand()%(game->m-2);
            rand_n=1+rand()%(game->n-2);
            while(game->board[rand_m][rand_n]==ONE_FISH)
            {
                rand_m=1+rand()%game->m;
                rand_n=1+rand()%game->n;
            }
            game->board[rand_m][rand_n]=ONE_FISH;
            
        }
    for(int i=1;i<game->m-1;i++)
    {
        for(int j=1;j<game->n-1;j++)
        {
            random_fish=rand()%2;
            if(game->board[i][j]!=ONE_FISH)
            {
                if(random_fish==0)
                game->board[i][j]=TWO_FISH;
                else if(random_fish==1)
                game->board[i][j]=THREE_FISH;
            }
        }
    }
     


}
void show_board(Game_phase game)
{
    system("cls");
    printf(" Turn of player: %d\n",game.current_player);
    printf("   ");
    for(int i=0;i<game.n;i++)   
    {
        printf("%4d",i);
    }printf("\n  ");       //printing barriers and coordinates
    for(int i=0;i<game.n;i++)
    {
        printf("_____");   //printing barriers and coordinates
    }printf("\n");
    for(int i=0;i<game.m;i++)
    {
        for(int j=0;j<game.n;j++)
        {
            if(j==0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN|0);
                printf("%2d | ",i);
            }
            change_colour(game,i,j);
            if(game.board[i][j]==WATER)
            printf("    ");
            else
            printf("%3d ",game.board[i][j]);
        }printf("\n");
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN|0);
}
void place_penguin(Game_phase *game)
{
    if (game->current_player==1)
       {
           game->num_placed_penguins_player1++;
           game->board[game->placement_coord_y][game->placement_coord_x]=10;

       }
    else
        {
            game->num_placed_penguins_player2++;
            game->board[game->placement_coord_y][game->placement_coord_x]=20;
        }
}

void remove_fish(Game_phase *game)
{
    game->board[game->movement_y][game->movement_x]=WATER;
}
void move_penguin(Game_phase *game)
{
    if(game->current_player==1)
    {
        game->board[game->movement_y][game->movement_x]=PLAYER_ONE;
    }
    else if(game->current_player==2)
    {
        game->board[game->movement_y][game->movement_x]=PLAYER_TWO;
    }
}
void remove_ice_floe(Game_phase *game)
{
    game->board[game->penguin_position_y][game->penguin_position_x]=WATER;
}
void change_colour(Game_phase game,int x,int y)
{
    if(game.board[x][y]==ONE_FISH||game.board[x][y]==TWO_FISH||game.board[x][y]==THREE_FISH)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15|BACKGROUND_INTENSITY);
    else if(game.board[x][y]==PLAYER_ONE)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0|BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    else if(game.board[x][y]==PLAYER_TWO)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED | BACKGROUND_GREEN);
    else if(game.board[x][y]==WATER)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE | BACKGROUND_INTENSITY);
}