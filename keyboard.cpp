#include "keyboard.h"

int kbinput()
{
    static unsigned int previous = 11;
    unsigned int input = getch();
//    mvprintw(0,0,"input = %d",input);
//    clrtoeol();
//    refresh();
    if(input == ERR)
      return previous;
    else
    {
       previous = 11;
       return input;
    }
}
