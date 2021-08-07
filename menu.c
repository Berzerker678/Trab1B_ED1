#include "menu.h"
#include <stdio.h>


enum MENU_ITEMS{
    EXIT= 0,
    POS_NUMB,
    POS_START,
    SIMULATION
};


//Menu principal - Seleção de itens de configuração
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

//Função de simulação
/*
int menu_simulation{
    return 0;
}
*/

//Função de seleção de posição inicial do jogo
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
