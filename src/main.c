#include "rogue.h"

int main(){
    Player *user;
    int ch;
    Position * newPosition;

    Level * level;

    screenSetUp();
   
   level = createLevel();

    user = playerSetUp();

    /* main game loop */
    while ((ch=getch()) != 'q'){
       newPosition= handleInput(ch,user);
       checkPosition( newPosition, user, level);
    }
    endwin();
    return 0;
}

int screenSetUp(){
    initscr();
    printw("hello world");
    noecho();
    refresh();
    srand(time(NULL));


    return 1;
}


