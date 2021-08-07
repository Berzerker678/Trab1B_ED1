#include <stdio.h>
#include "game.h"


void init_obstacles(GAME_SNAKE * GM)
{
    int i;
    for(i=0;i<sizeof(GM->OBSTACLES) / sizeof(int);i++)
      GM->OBSTACLES[i] = -1;
}


void set_obstacle(GAME_SNAKE * GM, int x, int y)
{
    int i;
    int get_pos =  get_real_pos(GM, x, y);
    if (get_pos > (GM->TAB_SIZEX * GM->TAB_SIZEY) || get_pos < 0) return;

    for (i=0; i< sizeof(GM->OBSTACLES) / sizeof(int); i++)
    {
        if (GM->OBSTACLES[i] < 0)
        {
            GM->OBSTACLES[i] = get_pos;
            return;
        }
    }
}


void set_board_size(GAME_SNAKE * GM, int sizeX, int sizeY)
{
    GM->TAB_SIZEX = sizeX;
    GM->TAB_SIZEY = sizeY;
}


//Determina a posição que a snake vai nascer.
void init_snake(GAME_SNAKE *GM, int x, int y)
{
    int i;
    for(i = 0; i < sizeof(GM->SNAKE) / sizeof(int); i++)
        GM->SNAKE[i] = get_real_pos(GM, x, y);;
}


//Desenha o tabuleiro na tela com verificação de posicionamento da snake no tabuleiro.
void draw_board(GAME_SNAKE * GM)
{
    printf(" ******************************** SNAKE ******************************** \n");
    printf(" Trabalho: 1A | Estrutura de dados I\n");
    printf(" \n");
    printf(" ******************************** SNAKE ******************************** \n");

    int check;
    int TabX = GM->TAB_SIZEX;    //Separei o X e o Y. Só para manter um padrão.
    int TabY = GM->TAB_SIZEY;

    printf("   |");
    for (int x=0; x < TabY; x++)
        printf("%d|",x+1);

    printf("\n");

    for(int y=0; y < TabY; y++)
    {
        printf("%2d |",y+1);
        for(int x=0; x < TabX; x++)
        {
            check = check_space(GM,x, y);
            draw_objects(check);
        }
        printf("\n");
    }

}


//Faz uma verificação do posicionamento do tabuleiro e verifica qual é a parte da snake ou o obstaculo no local
int check_space(GAME_SNAKE *GM,int x, int y)
{
    int part;
    int PosX = x+1;
    int PosY = y+1;

    part = check_pos_obstacles(GM, PosX, PosY);
    if (part >= 0) return part;

    part = check_pos_snake(GM, PosX, PosY);
    if (part >= 0) return part;


    return -1;
}


int check_pos_snake(GAME_SNAKE * GM, int x, int y)
{

    int i;
    int get_pos = get_real_pos(GM, x, y);
    int snake_s = sizeof(GM->SNAKE) / sizeof(int);

    for (i = 0; i < snake_s; i++)
    {
        if (get_pos == GM->SNAKE[i])
        {
            if(i == 0) return HEAD;
            if(i > 0 && i < snake_s-1) return BODY;
            if(i == snake_s-1) return TAIL;
        }
    }

    return -1;
}


int check_pos_obstacles(GAME_SNAKE * GM, int x, int y)
{
    int i;
    int get_pos = get_real_pos(GM, x, y);
    int obs_s = sizeof(GM->OBSTACLES) / sizeof(int);

    for (i = 0; i < obs_s; i++)
        if (get_pos == GM->OBSTACLES[i]) return OBSTACLE;

    return -1;
}

//Desenha no tabuleiro o caractere de acordo com a parte da snake (cabeça, corpo, calda)
void draw_objects(int part)
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
void simular_snake(GAME_SNAKE * GM, int Move)
{
    GAME_SNAKE * FK = GM;



}*/

//Movimenta a snake no tabuleiro (Não existe colisão de movimento)
void move_snake(GAME_SNAKE * GM,int move)
{
    int i;
    int snake_s = sizeof(GM->SNAKE) / sizeof(int);

    //Criar aqui a verificação de movimentação

    for(i = snake_s-1; i > 0; i--)        //Movimenta todo corpo após a cabeça
        GM->SNAKE[i] = GM->SNAKE[i-1];

    switch (move)                         //Movimenta a cabeça
    {
    case UP:    //cima
        GM->SNAKE[0] -= GM->TAB_SIZEX;
        break;
    case RIGHT: //direita
        GM->SNAKE[0] = GM->SNAKE[0] + 1;
        break;
    case DOWN:  //baixo
        GM->SNAKE[0] += GM->TAB_SIZEX;
        break;
    case LEFT:  //esquerda
        GM->SNAKE[0] = GM->SNAKE[0] - 1;
        break;
    }
}



int get_real_pos(GAME_SNAKE * GM, int x, int y)
{
    return (y * GM->TAB_SIZEX) - (GM->TAB_SIZEX - x);
}
