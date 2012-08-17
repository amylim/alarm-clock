#include "letter.h"

Letter::Letter(int r, int c)
{
   x = r;
   y = c;
   lookup[0] = "ABCEFGH";   //A
   lookup[1] = "ABCDHMN";   //B
   lookup[2] = "ADEF";      //C
   lookup[3] = "ABCDMN";    //D
   lookup[4] = "ADEFGH";    //E
   lookup[5] = "AEFGH";     //F
   lookup[6] = "ACDEFH";    //G
   lookup[7] = "BCEFGH";    //H
   lookup[8] = "ADMN";      //I
   lookup[9] = "BCDE";      //J
   lookup[10] = "EFGJL";    //K
   lookup[11] = "DEF";      //L
   lookup[12] = "BCEFIJ";   //M
   lookup[13] = "BCEFIL";   //N
   lookup[14] = "ABCDEF";   //O
   lookup[15] = "ABEFGH";   //P
   lookup[16] = "ABCDEFL";  //Q
   lookup[17] = "ABEFGHL";  //R
   lookup[18] = "AFGHCD";   //S
   lookup[19] = "AMN";      //T
   lookup[20] = "BCDEF";    //U
   lookup[21] = "EFJK";     //V
   lookup[22] = "BCEFKL";   //W
   lookup[23] = "IJKL";     //X
   lookup[24] = "IJN";      //Y
   lookup[25] = "ADJK";     //Z
   lookup[26] = "ABCDEFGHIJKLMN"; //all segments turned on
   blink = false;
   toggle = false;                   
}

void Letter::display(int d, bool onOff)
{
     if(onOff)
       if(!blink && !toggle)
          display(d, BLACKONWHITE);
       else
          display(d, BLACKONYELLOW);         
     else
        display(d,WHITEONBLACK);
}

void Letter::display(int d, int color)
{
     attron(COLOR_PAIR(color));
     //mvprintw(1,1,"For %d segments %s need to be turned on", d, lookup[d].c_str());
     //clrtoeol();
     for(int j=0; j<lookup[d].size(); j++)
     {
        switch(lookup[d].at(j))
        {
           case 'A' : for(int i = 0; i < 11; i++)
                         mvprintw(x, y + i, " ");   
                      break;
                      
           case 'B' : for(int i = 0; i < 6; i++)
                         mvprintw(x + i, y + 10, " ");
                      break;
                      
           case 'C' : for(int i = 5; i<11; i++)
                         mvprintw(x + i, y + 10, " ");
                      break;
                      
           case 'D' : for(int i = 0; i<11; i++)
                         mvprintw(x + 10, y + i, " ");
                      break;
                      
           case 'E' : for(int i = 5; i<11; i++)
                         mvprintw(x + i, y, " ");
                      break;
                      
           case 'F' : for(int i = 0; i<6; i++)
                         mvprintw(x + i, y, " ");
                      break;
                      
           case 'G' : for(int i = 0; i<6; i++)
                         mvprintw(x + 5, y + i, " ");
                      break;
                      
           case 'H' : for(int i = 6; i<11; i++)
                         mvprintw(x + 5, y + i, " ");
                      break;
                      
           case 'I' : for(int i = 0; i<6; i++)
                         mvprintw(x + i, y + i, " ");
                      break;
                      
           case 'J' : for(int i = 0; i<6; i++)
                         mvprintw(x + 5 - i, y + 5 + i, " ");
                      break;
                      
           case 'K' : for(int i = 0; i<6; i++)
                         mvprintw(x + 10 - i, y + i, " ");
                      break;
                      
           case 'L' : for(int i = 0; i<6; i++)
                         mvprintw(x + 5 + i, y + 5 + i, " ");
                      break;
                      
           case 'M' : for(int i = 0; i<6; i++)
                         mvprintw(x + i, y + 5, " ");
                      break;
                      
           case 'N' : for(int i = 5; i<11; i++)
                         mvprintw(x + i, y + 5, " ");
                      break;
           
        }
        refresh();
     }
     attroff(COLOR_PAIR(color));
}
