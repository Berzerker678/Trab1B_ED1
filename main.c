#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "game.h"
#include "menu.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    //GAME_SNAKE * vet[0];
    //GAME_SNAKE *Game = &vet[0];
    GAME_SNAKE *Game = malloc(sizeof(GAME_SNAKE)); //Não ensinou malloc



    set_board_size(Game, 10, 10);
    init_obstacles(Game);
    init_snake(Game, 10,1);

    set_obstacle(Game, 3, 2);
    set_obstacle(Game, 3, 3);
    set_obstacle(Game, 3, 4);
    set_obstacle(Game, 3, 5);

    draw_board(Game);

/*
    move_snake(Game,DOWN);
    draw_board(Game);
    move_snake(Game,DOWN);
    draw_board(Game);
    move_snake(Game,DOWN);
    draw_board(Game);
    move_snake(Game,DOWN);
    draw_board(Game);
    move_snake(Game,RIGHT);
    draw_board(Game);
    */


    return 0;
}
