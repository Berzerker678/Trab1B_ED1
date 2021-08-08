#include <stdio.h>
#include "game.h"


void initItemObstacle(SnakeGame *snakeGame)
{
    const int obstaclesLength = sizeof(snakeGame->obstacles) / sizeof(int);
    int count;
    for(count = 0; count < obstaclesLength; count++)
    {
        snakeGame->obstacles[count] = -1;
    }
}


void initItemSnake(SnakeGame *snakeGame, const int boardX, const int boardY)
{
    const int snakeSize = sizeof(snakeGame->snake) / sizeof(int);
    int count;
    for(count = 0; count < snakeSize; count++)
        snakeGame->snake[count] = getRealBoardPosition(snakeGame, boardX, boardY);
}


void setBoardSize(SnakeGame* snakeGame, const int boardX, const int boardY)
{
    snakeGame->gameSizeX = boardX;
    snakeGame->gameSizeY = boardY;
}


void setBoardObstacle(SnakeGame* snakeGame, const int boardX, const int boardY)
{
    const int obstaclePosition = getRealBoardPosition(snakeGame, boardX, boardY);
    const int obstacleSize = sizeof(snakeGame->obstacles) / sizeof(int);

    if (obstaclePosition > (snakeGame->gameSizeX * snakeGame->gameSizeY) || obstaclePosition < 0) return;


    int count;
    for (count=0; count< obstacleSize; count++)
    {
        if (snakeGame->obstacles[count] < 0)
        {
            snakeGame->obstacles[count] = obstaclePosition;
            return;
        }
    }
}


void drawBoardGame(SnakeGame* snakeGame)
{
    printf(" ******************************** snake ******************************** \n");
    printf(" Trabalho: 1A | Estrutura de dados I\n");
    printf(" \n");
    printf(" ******************************** snake ******************************** \n");

    int getBoardItemSpace;
    const int gameSizeX = snakeGame->gameSizeX;
    const int gameSizeY = snakeGame->gameSizeY;

    printf("   |");

    int count;
    for (count=0; count < gameSizeY; count++)
    {
        printf("%d|",count + 1);
    }

    printf("\n");

    int countX, countY;
    for (countY = 0; countY < gameSizeY; countY++)
    {
        printf("%2d |",countY+1);
        for (countX = 0; countX < gameSizeX; countX++)
        {
            getBoardItemSpace = checkItemOnSpace(snakeGame, countX, countY); //Verifica qual item está ocupando aquele espaço e em seguida desenha ele na drawObject
            drawObject(getBoardItemSpace);
        }
        printf("\n");
    }
}


int checkItemOnSpace(SnakeGame *snakeGame,const int boardX, const int boardY)
{
    int charItem;
    const int positionX = boardX+1;
    const int positionY = boardY+1;

    charItem = checkObstaclePosition(snakeGame, positionX, positionY);
    if (charItem >= 0) return charItem;

    charItem = checkPieceSnake(snakeGame, positionX, positionY);
    if (charItem >= 0) return charItem;

    return -1;
}


int checkPieceSnake(SnakeGame * snakeGame, const int boardX, const int boardY)
{
    const int realPosition = getRealBoardPosition(snakeGame, boardX, boardY);
    const int snakeSize    = sizeof(snakeGame->snake) / sizeof(int);

    int count;
    for (count = 0; count < snakeSize; count++)
    {
        if (realPosition == snakeGame->snake[count])
        {
            if(count == 0) return HEAD;
            if(count  > 0 && count < snakeSize - 1) return BODY;
            if(count == snakeSize - 1) return TAIL;
        }
    }

    return -1;
}


int checkObstaclePosition(SnakeGame * snakeGame, const int boardX, const int boardY)
{
    int count;
    const int realPosition = getRealBoardPosition(snakeGame, boardX, boardY);
    const int obstacleSize = sizeof(snakeGame->obstacles) / sizeof(int);

    for (count = 0; count < obstacleSize; count++)
        if (realPosition == snakeGame->obstacles[count]) return OBSTACLE;

    return -1;
}


void drawObject(const SnakeObject part)
{
    switch (part)
    {
    case HEAD:
        printf("%c|", CHAR_HEAD);
        break;
    case BODY:
        printf("%c|", CHAR_BODY);
        break;
    case TAIL:
        printf("%c|", CHAR_TAIL);
        break;
    case OBSTACLE:
        printf("%c|", CHAR_OBS);
        break;
    default:
        printf("%c|", CHAR_SPACE);
    }
}
/*
void simular_snake(SnakeGame * snakeGame, int Move)
{
    SnakeGame * FK = snakeGame;



}*/


void moveSnakeToPosition(SnakeGame* snakeGame, const Direction snakeDirection)
{
    int snakeSize = sizeof(snakeGame->snake) / sizeof(int);

    int count;
    for(count = snakeSize-1; count > 0; count--)
    {
        snakeGame->snake[count] = snakeGame->snake[count-1];
    }

    switch (snakeDirection)
    {
    case UP:
        snakeGame->snake[0] -= snakeGame->gameSizeX;
        break;
    case RIGHT:
        snakeGame->snake[0] = snakeGame->snake[0] + 1;
        break;
    case DOWN:
        snakeGame->snake[0] += snakeGame->gameSizeX;
        break;
    case LEFT:
        snakeGame->snake[0] = snakeGame->snake[0] - 1;
        break;
    }
}


int getRealBoardPosition(SnakeGame * snakeGame, const int boardX, const int boardY)
{
    return (boardY * snakeGame->gameSizeX) - (snakeGame->gameSizeX - boardX);
}
