#include "colon.h"

Colon::Colon(int r, int c)
{
   x = r;
   y = c;
   toggle = true;
   change = false;   
}

void Colon::display(bool onOff)
{
    if(onOff)
    {
          if(toggle)
          {
             if(!change)
                display(BLACKONWHITE);
             else
                display(BLACKONYELLOW);
          }
          else
             display(WHITEONBLACK);
          toggle = !toggle;  
    }
    else
       display(WHITEONBLACK);
}
void Colon::changeColor(bool onOff)
{
    change = onOff;
}
void Colon::display(int color)
{
    attron(COLOR_PAIR(color));
    mvprintw(x, y, " ");
    mvprintw(x + 5, y, " ");
    attroff(COLOR_PAIR(color));
}
