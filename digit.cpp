#include "digit.h"

Digit::Digit(int r, int c)
{
   x = r;
   y = c;
   lookup[0] = "ABCDEF";
   lookup[1] = "BC";
   lookup[2] = "ABDEG";
   lookup[3] = "ABCDG";
   lookup[4] = "BCFG";
   lookup[5] = "ACDFG";
   lookup[6] = "ACDEFG";
   lookup[7] = "ABC";
   lookup[8] = "ABCDEFG";
   lookup[9] = "ABCDFG";
   blink = false;
   toggle = false;   
}

void Digit::display(int d, bool onOff)
{
     if(onOff)
       if(!blink && !toggle)
          display(d, BLACKONWHITE);
       else
          display(d, BLACKONYELLOW);         
     else
        display(d,WHITEONBLACK);
} 

void Digit::display(int d, int color)
{
     attron(COLOR_PAIR(color));
     //mvprintw(1,1,"For %d segments %s need to be turned on", d, lookup[d].c_str());
     //clrtoeol();
     for(int j=0; j<lookup[d].size(); j++)
     {
        switch(lookup[d].at(j))
        {
           case 'A' : for(int i = 1; i < 7; i++)
                         mvprintw(x, y + i, " ");   
                      break;
                      
           case 'B' : for(int i = 0; i < 5; i++)
                         mvprintw(x + i, y + 7, " ");
                      break;
                      
           case 'C' : for(int i = 6; i<11; i++)
                         mvprintw(x + i, y + 7, " ");
                      break;
                      
           case 'D' : for(int i = 1; i<7; i++)
                         mvprintw(x + 10, y + i, " ");
                      break;
                      
           case 'E' : for(int i = 6; i<11; i++)
                         mvprintw(x + i, y, " ");
                      break;
                      
           case 'F' : for(int i = 0; i<5; i++)
                         mvprintw(x + i, y, " ");
                      break;
                      
           case 'G' : for(int i = 1; i<7; i++)
                         mvprintw(x + 5, y + i, " ");
                      break;
        }
        refresh();
     }
     attroff(COLOR_PAIR(color));
}
void Digit::changeColor(bool onOff)
{
   toggle = onOff;     
}
