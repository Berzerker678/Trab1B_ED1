#include "menu.h"
#include <stdio.h>


enum MENU_ITEMS{
    EXIT= 0,
    POS_NUMB,
    POS_START,
    SIMULATION
};


//Menu principal - Sele��o de itens de configura��o
int menu_main(){
  int input;

  do{
    scanf("%d",&input);

    switch (input)
    {
    case POS_NUMB:
        return 0;
    case POS_START:
        return 0;
    case SIMULATION:
        return 0;
    }
  }while (input == EXIT);

    return 0;
}

//Fun��o de simula��o
/*
int menu_simulation{
    return 0;
}
*/

//Fun��o de sele��o de posi��o inicial do jogo
int menu_set_init_pos(){
    return 0;
}

void display_items(){



}

int message_get_value(){
    int input;
    scanf("%d",&input);
    return input;
}


void message_show(char *input){
    printf("%s",input);
}
