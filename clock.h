#ifndef _CLOCK
#define _CLOCK
#include <iostream>
#include <curses.h>
#include "initialize.h"
#include "digit.h"
#include "colon.h"
#include "keyboard.h"

class Clock
{
   public:          
      Clock(int r = 3, int c = 10);             //r = row and c = column start location for the clock
      Clock(Clock &other);                      //copy constructor
      void initialize();                        //initializes the clock by having it blink and increment 
                                                  //seconds until the user presses F6 to set the clock; see setClock();
      void clearDisplay();                      //clears the display of the clock
      void display(bool onOff);                 //displays the whole clock; onOff = true turns on the display
      void displayColor(bool onOff);            //same as display() but displays the whole clock in yellow
      void increment(bool onOff);               //adds one second to the clock and displays it after each increment
      void addHr(int qty);                      //adds hours by the argument's amount
      void lessHr(int qty);                     //subtracts hours by the argument's amount
      void addMin(int qty);                     //adds minutes by the argument's amount
      void lessMin(int qty);                    //subtracts minutes by the argument's amount
      void addSec(int qty);                     //adds seconds by the argument's amount
      void lessSec(int qty);                    //subtracts seconds by the argument's amount
      void setClock();                          //allows user to set the clock; F8 = add hour; 8 = subtract hour
                                                                              //F9 = add minute; 9 = subtract minute
                                                                              //F10 = add second; 0 = subtract second
      void convert12or24();                     //switches the display of the clock from 12hr/24hr
      void showTime(int x, int y);              //prints the time with text(to verify 7-segment display)
      void stopwatch();                         //changes Clock to a stopwatch; press F4 to exit; counts down until 0:00:00, beeps and automatically exits, 
      void onOffSecDisplay();                   //switches the seconds display on/off
      void setUTC();                            //allows user to set the clock; F8 = add hour; 8 = subtract hour
                                                //hours range from -12 to 14  //F9 = add minute; 9 = subtract minute
                                                                              //F10 = add second; 0 = subtract second
      void addUTC(Clock &other, Clock &UTC);    //offsets from the original clock to get the new timezone
      void snooze();                            //adds 10 minutes to the alarm
      void stopAlarm();                         //stops the alarm from going off until the next 24 hrs or reset
      Clock& operator=(Clock &other);           
      Clock& operator=(const Clock &other);
      friend bool operator==(const Clock &a, const Clock &b);     //overloads the == operator
   private:
      int hr, min, sec, x, y;
      bool isPM, is24, isSec;   
      void copy(const Clock &other);
};

#endif
