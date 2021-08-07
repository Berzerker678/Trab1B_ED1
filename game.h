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


enum SNAKE
{
    HEAD = 1,
    BODY,
    TAIL,
    OBSTACLE
};

enum MOVE
{
    UP = 1,
    DOWN,
    LEFT,
    RIGHT
};

typedef struct Game
{
    int OBSTACLES[OBS_MAX];
    int SNAKE[SNAKE_MAX_SIZE];
    int TAB_SIZEX;
    int TAB_SIZEY;
} GAME_SNAKE;

void init_snake(GAME_SNAKE *GM, int x, int y);
void init_obstacles(GAME_SNAKE * GM);
void draw_objects(int part);
void draw_board(GAME_SNAKE *GM);
void move_snake(GAME_SNAKE * GM,int move);
void set_board_size(GAME_SNAKE * GM, int sizeX, int sizeY);
void set_obstacle(GAME_SNAKE * GM, int x, int y);
int check_space(GAME_SNAKE *GM,int x, int y);
int get_real_pos(GAME_SNAKE * GM, int x, int y);
int check_pos_snake(GAME_SNAKE * GM, int x, int y);
int check_pos_obstacles(GAME_SNAKE * GM, int x, int y);



#endif // GAME_H_INCLUDED
