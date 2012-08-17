#ifndef _DIGITS
#define _DIGITS

#include "initialize.h"
#include <string>

//7-segment display of the digits 0-9
class Digit
{
   public:
      Digit(int r = 10, int c = 40);    //r = row and c = column start location for the digit
      void display(int d, bool onOff);  //displays the whole digit; onOff = true turns on the digit
      void changeColor(bool onOff);     //makes the digit yellow if true
          
   private:
      string lookup[10];
      int x, y;
      bool blink, toggle;
      
      void display(int d, int color);
           
};

#endif
