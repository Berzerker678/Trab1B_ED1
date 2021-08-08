#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#define SNAKE_MAX_SIZE 5
#define OBS_MAX 100

//ASCII
#define CHAR_SPACE  32
#define CHAR_BODY   42
#define CHAR_TAIL   176
#define CHAR_HEAD   99
#define CHAR_OBS    88


typedef enum SnakeObject
{
    HEAD = 1,
    BODY,
    TAIL,
    OBSTACLE
} SnakeObject;

typedef enum Direction
{
    UP = 1,
    DOWN,
    LEFT,
    RIGHT
} Direction;

typedef struct SnakeGame
{
    int obstacles[OBS_MAX];
    int snake[SNAKE_MAX_SIZE];
    int gameSizeX;
    int gameSizeY;
} SnakeGame;



void initItemSnake(SnakeGame *snakeGame, const int boardX, const int boardY);
void initItemObstacle(SnakeGame *snakeGame);
void setBoardSize(SnakeGame* snakeGame, const int boardX, const int boardY);

void setBoardObstacle(SnakeGame* snakeGame, const int boardX, const int boardY);

void drawObject(const SnakeObject part);
void drawBoardGame(SnakeGame* snakeGame);

int moveSnakeToPosition(SnakeGame* snakeGame, const Direction direction);
int getRealBoardPosition(SnakeGame * snakeGame, const int boardX, const int boardY);
int checkObstaclePosition(SnakeGame * snakeGame, const int boardX, const int boardY);
int checkPieceSnake(SnakeGame * snakeGame, const int boardX, const int boardY);
int checkItemOnSpace(SnakeGame *snakeGame,const int boardX, const int boardY);




#endif // GAME_H_INCLUDED
