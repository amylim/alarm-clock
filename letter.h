#ifndef _LETTER
#define _LETTER

#include "initialize.h"
#include <string>

//14-segment display of the alphabet 0-25; 26 has all the segments drawn in 
class Letter
{
   public:
     Letter(int r = 50, int c = 10);    //r = row and c = column start location for the letter
     void display(int d, bool onOff);   //displays one letter; d = letter (ex. A=0, B=1, C=2...); onOff = true displays letter
     void changeColor(bool onOff);      //if onOff true, then the display with be yellow instead of white
     
   private:
     string lookup[27];
     int x, y;
     bool blink, toggle;
     void display(int d, int color);
};

#endif
