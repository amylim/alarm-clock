#ifndef _DATE
#define _DATE

#include <curses.h>
#include <string>
#include "initialize.h"
#include "keyboard.h"
#include "letter.h"
#include "digit.h"
//#include "english.h" 

//using namespace english;

//uses Letter and Digit to display the date with 14 and 7 segment displays
//month is written with the a 3 letter abbreviation
//the language of the month can be changed with the namespace
class Date
{
   public:
     Date(int r = 27, int c = 5);   //r = row and c = column start location for the date
     void display(bool onOff);      //displays the whole date; onOff = true turns on the display
     void clearDisplay();           //turns off the whole date display
     void addYear();                //adds one year to the date
     void lessYear();               //subtracts one year from the date
     void addMonth();               //adds one month to the date
     void lessMonth();              //subtracts one month from the date
     void addDay();                 //adds one day to the date
     void lessDay();                //subtracts one day from the date
     void setDate();                //allows user to set the date; F8 = add month; 8 = subtract month
                                                                 //F9 = add day; 9 = subtract day
                                                                 //F10 = add year; 0 = subtract year
   private:
     int x, y, month, day, year;
};
#endif
