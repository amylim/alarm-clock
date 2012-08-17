#ifndef _COLON
#define _COLON

#include <curses.h>
#include "initialize.h"

//displays a flashing colon
class Colon
{
   public:
     Colon(int r = 5, int c = 30);  //r = row and c = column start location for the colon
     void display(bool onOff);      //displays a flashing colon
     void changeColor(bool onOff);  //if onOff true, then the display with be yellow instead of white
     
   private:
     int x, y;
     bool toggle, change;
     void display(int color);
           
      
};
#endif
