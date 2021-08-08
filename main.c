#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "game.h"
#include "menu.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    //SnakeGame *SnakeGame = malloc(sizeof(SnakeGame)); //Não ensinou malloc
    SnakeGame GS;
    SnakeGame* SnakeGame = NULL;
    SnakeGame = &GS;

    setBoardSize(SnakeGame, 10, 10);
    initItemObstacle(SnakeGame);
    initItemSnake(SnakeGame, 5, 5);

    setBoardObstacle(SnakeGame, 3, 3);

    drawBoardGame(SnakeGame);
    moveSnakeToPosition(SnakeGame, DOWN);
    drawBoardGame(SnakeGame);
    moveSnakeToPosition(SnakeGame, DOWN);
    drawBoardGame(SnakeGame);
    moveSnakeToPosition(SnakeGame, DOWN);
    drawBoardGame(SnakeGame);
    moveSnakeToPosition(SnakeGame, DOWN);
    drawBoardGame(SnakeGame);
    moveSnakeToPosition(SnakeGame, RIGHT);
    drawBoardGame(SnakeGame);
    moveSnakeToPosition(SnakeGame, RIGHT);
    drawBoardGame(SnakeGame);
    moveSnakeToPosition(SnakeGame, RIGHT);
    drawBoardGame(SnakeGame);
    moveSnakeToPosition(SnakeGame, UP);
    drawBoardGame(SnakeGame);
    moveSnakeToPosition(SnakeGame, UP);
    drawBoardGame(SnakeGame);
    moveSnakeToPosition(SnakeGame, UP);
    drawBoardGame(SnakeGame);
    moveSnakeToPosition(SnakeGame, RIGHT);
    drawBoardGame(SnakeGame);


    return 0;
}
