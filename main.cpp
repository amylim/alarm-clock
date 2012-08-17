/**********************************************************
Author: Amy Lim
Program: Clock
Purpose: Simulation of an alarm clock.
Notes: None.
**********************************************************/
#include <cstdlib>
#include <iostream>
#include <curses.h>
#include "initialize.h"
#include "keyboard.h"
#include "digit.h"
#include "clock.h"
#include "colon.h"
#include "letter.h" 
//#include "english.h" 
#include "date.h"

int main(int argc, char *argv[])
{
    initialize();
    attron(COLOR_PAIR(BLACKONWHITE));
    
    Clock myClock, timeZone(15, 10), alarm, alarmTemp, timer, UTC;  
    Date today; 
    Colon colon1(5, 30), colon2(5, 55);
    Colon colon3(17, 30), colon4(17, 55);
    int input = 0;
    
    today.display(true);
    myClock.initialize();
    bool display2 = false;
    bool alarmOn = false;
    bool onOffColon2 = true; 
    bool oneSec = true;
    colon3.changeColor(true);
    colon4.changeColor(true);
    while((input = kbinput()) != 27)
    {
        colon1.display(true);
        colon2.display(onOffColon2);
        colon3.display(display2);
        colon4.display(onOffColon2 && display2);
        if(oneSec)
        {
           myClock.increment(true);
           timeZone.addSec(display2);
           timeZone.displayColor(display2);          
        }
        oneSec = !oneSec;
        if(myClock == alarmTemp)
        {
           mvprintw(3, 80, "Alarm has been activated.");
           clrtoeol();
           alarmOn = true;
           for(int i = 0; i < 5; i++)
               std::cout<<(char)7;
        }
        if(input == 32 && alarmOn)               //spacebar is the snooze button for the alarm
        {
            alarmOn = false;
            alarmTemp.snooze();       
        }
        else if(input == 10 && alarmOn)         //Enter turns off the alarm
        {
            alarmOn = false;
            alarm.stopAlarm();           
        }
        myClock.showTime(0, 80);
        switch(input)
        {
           case 265: 
                myClock.convert12or24();         //F1 toggles military time on/off
                alarm.convert12or24();
                alarmTemp.convert12or24();
                timeZone.convert12or24();
                break;
           case 270: 
                myClock.setClock();              //F6 allows user to set clock
                timeZone.addUTC(myClock, UTC);
                break; 
           case 268:     
                timer.stopwatch();               //F4 stopwatch mode
                break;
           case 266:                             //F2 displays two time zones
                display2 = !display2;
                timeZone.addUTC(myClock, UTC);
                if(!display2)
                   mvprintw(17, 80, "            ");
                else
                {
                   mvprintw(17, 80, "UTC");
                   UTC.showTime(17, 84);
                }   
                break;
           case 267: 
                myClock.onOffSecDisplay();       //F3 turns the display of seconds on/off
                alarm.onOffSecDisplay();         //seconds display for timer is always on
                timeZone.onOffSecDisplay();
                onOffColon2 = !onOffColon2;        
                break;         
           case 269:                             //F5 allows user to set UTC
                UTC.setUTC();
                timeZone.addUTC(myClock, UTC);
                display2 = true;
                break;        
           case 271: 
                mvprintw(3, 80, "Setting alarm...");
                alarm.setClock();                //F7 allows user to set the alarm
                alarmTemp = alarm;
                
                break;   
           case 276: 
                today.setDate();                 //F12 allows user to set date  
                break;   
        }
    }
    myExit();
    system("PAUSE");
    return EXIT_SUCCESS;
}
