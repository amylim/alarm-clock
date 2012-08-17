#include "clock.h"

Clock::Clock(int r, int c)
{
      x = r;
      y = c;
      hr = 12;
      min = 0;
      sec = 0;
      isPM = false;
      is24 = false;
      isSec = true;
}
Clock::Clock(Clock &other)
{
    copy(other);
}
void Clock::initialize()
{
     bool toggle = true;
     int input = 0;
     while((input = kbinput()) != 270)
     {
       display(toggle);
       toggle = !toggle;
       if(toggle)
         addSec(1);
     }  
     display(true);
     setClock();    
}
void Clock::clearDisplay()
{
     Digit hour1(x, y), hour2(x, y+10), min1(x, y+25), min2(x, y+35), sec1(x, y+50), sec2(x, y+60);
     hour1.display(8, false); 
     hour2.display(8, false);
     min1.display(8, false);
     min2.display(8, false); 
     sec1.display(8, false);
     sec2.display(8, false);
     attron(COLOR_PAIR(WHITEONBLACK));
     mvprintw(x+6, y-5, "  ");            //erase PM indicator   
     refresh();
}
void Clock::display(bool onOff)
{
     Digit hour1(x, y), hour2(x, y+10), min1(x, y+25), min2(x, y+35), sec1(x, y+50), sec2(x, y+60);
     if(onOff)
     {
          clearDisplay();
          hour1.display(hr/10, true); 
          hour2.display(hr%10, true);
          min1.display(min/10, true);
          min2.display(min%10, true); 
          sec1.display(sec/10, isSec);
          sec2.display(sec%10, isSec);

          if(isPM)
          {
             attron(COLOR_PAIR(BLACKONWHITE));
             mvprintw(x+6, y-5, "PM");
          }
          else
          {
             attron(COLOR_PAIR(WHITEONBLACK));
             mvprintw(x+6, y-5, "  ");
          }
          refresh();
     }
     else
         clearDisplay();   
}
void Clock::displayColor(bool onOff)
{
     Digit hour1(x, y), hour2(x, y+10), min1(x, y+25), min2(x, y+35), sec1(x, y+50), sec2(x, y+60);
     hour1.changeColor(true); 
     hour2.changeColor(true); 
     min1.changeColor(true); 
     min2.changeColor(true); 
     sec1.changeColor(true); 
     sec2.changeColor(true); 
     if(onOff)
     {
          clearDisplay();
          hour1.display(hr/10, true); 
          hour2.display(hr%10, true);
          min1.display(min/10, true);
          min2.display(min%10, true); 
          sec1.display(sec/10, isSec);
          sec2.display(sec%10, isSec);

          if(isPM)
          {
             attron(COLOR_PAIR(BLACKONYELLOW));
             mvprintw(x+6, y-5, "PM");
             attroff(COLOR_PAIR(BLACKONYELLOW));
          }
          else
          {
             attron(COLOR_PAIR(WHITEONBLACK));
             mvprintw(x+6, y-5, "  ");
          }
          refresh();
     }
     else
         clearDisplay();   
}
void Clock::onOffSecDisplay()
{
     isSec = !isSec;
}
void Clock::increment(bool onOff)
{
     addSec(1);
     display(onOff);
}

void Clock::setUTC()
{
      mvprintw(21, 80, "Setting UTC...");
      clrtoeol();
      refresh();

      int input = 0;
      while((input = kbinput()) != 10)
      {                
         switch(input)
         {
            case 272:              //F8 increases the hours 
                 hr = (hr == 14) ? 14 : hr + 1;
                break;  
            case 56:               //8 decreases the hours
                 hr = (hr == -12) ? -12 : hr - 1;
                break;
            case 273:             //F9 increases the minutes
                min = (min == 59) ? 0 : min + 1;
                break;
            case 57:              //9 decreases the minutes
                min = (min == 0) ? 59 : min - 1;
                break;
            case 274:         //F10 increases the minutes
                sec = (sec == 59) ? 0 : sec + 1;
                break;
            case 48:          //0 decreases the minutes
                sec = (sec == 0) ? 59 : sec - 1;
                break;
         }
         mvprintw(17, 80, "UTC %d:%d:%d", hr, min, sec);
         clrtoeol();
         
      }
      mvprintw(21, 80, "End UTC set.");
      clrtoeol();
      refresh();     
}

void Clock::addHr(int qty)
{
    if(!is24)
    {
        for(int i = 0; i < qty; i++)
        {
            hr = (hr == 12) ? 1 : hr + 1;
            if(hr == 12)
            {
                isPM = !isPM;  
                cout<<(char)7;    
            }
            
        }
    }
    else
        for(int i = 0; i < qty; i++)
             hr = (hr == 23) ? 0 : hr + 1;
    /*bool isConvert = false;         //for future reference
    bool prePM = isPM;                //for programs that will have
    if(!is24)                         //greater change in hours
    {
        convert12or24();
        isConvert = true;
    }
    if(qty >= 24)
    {
        hr += qty%24;
        //addDay(qty/24);
    }
    else
        hr += qty;
    if(hr >= 24)
    {
        hr -= 24;
        //addDay(1);
    }
    if(isConvert)
    {              
        convert12or24();
        if(prePM != isPM)
            cout<<(char)7;
    }*/
}

void Clock::lessHr(int qty)
{
    if(!is24)
    {
        for(int i = 0; i < qty; i++)
        {
            hr = (hr == 1) ? 12 : hr - 1;
            if(hr == 11)
            {
                isPM = !isPM;
                cout<<(char)7;
            }
        }  
    }   
    else 
        for(int i = 0; i < qty; i++)
             hr = (hr == 0) ? 23 : hr - 1;
    /*bool isConvert = false;         //for future reference 
    bool prePM = isPM;                //for programs that will have 
    if(!is24)                         //greater change in hours
    {                                 
        convert12or24();
        isConvert = true;
    }
    if(qty >= 24)
    {
        hr -= qty%24;
        //lessDay(qty/24);
    }
    else
        hr -= qty;
    if(hr < 0)
    {
        hr += 24;
        //lessDay(1);
    }
    if(isConvert)
    {              
        convert12or24();
        if(prePM != isPM)
            cout<<(char)7;
    }  */
}
void Clock::addMin(int qty)
{
     if(qty >= 60)
     {
         min += qty%60;
         addHr(qty/60);
     }
     else
         min += qty;
     if(min >= 60)
     {
         min -= 60;
         addHr(1);
     }
}
void Clock::lessMin(int qty)
{
     if(qty >= 60)
     {
         min -= qty%60;
         lessHr(qty/60);
     }
     else
         min -= qty;
     if(min < 0)
     {
         min += 60;
         lessHr(1);
     }  
}
void Clock::addSec(int qty)
{
     if(qty >= 60)
     {
         sec += qty%60;
         addMin(qty/60);
     }
     else
         sec += qty;
     if(sec >= 60)
     {
         sec -= 60;
         addMin(1);
     }   
}
void Clock::lessSec(int qty)
{
     if(qty >= 60)
     {
         sec -= qty%60;
         lessMin(qty/60);
     }
     else
         sec -= qty;
     if(sec < 0)
     {
         sec += 60;
         lessMin(1);
     }   
}
void Clock::convert12or24()
 {
      if(!is24)
      {
          if(isPM && hr != 12)
               hr += 12;
          else if(!isPM && hr == 12)
               hr = 0;
          isPM = false;
          mvprintw(2, 80, "Converting to 24h");
      }
      else
      {
          if(hr >= 12)
          {
             if(hr != 12)
                hr -= 12;
             isPM = true;
          }
          else if(hr == 0)
               hr = 12;
          mvprintw(2, 80, "Converting to 12h");
      }
      refresh();
      is24 = !is24;
 }
void Clock::setClock()
{
      mvprintw(1, 80, "Setting clock...");
      clrtoeol();
      refresh();
      int input = 0;
      while((input = kbinput()) != 10)
      {                
         switch(input)
         {
            case 272: addHr(1);    //F8 increases the hours 
                break;  
            case 56: lessHr(1);    //8 decreases the hours
                break;
            case 273: addMin(1);   //F9 increases the minutes
                break;
            case 57: lessMin(1);   //9 decreases the minutes
                break;
            case 274: addSec(1);   //F10 increases the minutes
                break;
            case 48: lessSec(1);   //0 decreases the minutes
                break;
         }
         display(true);
         
      }
      mvprintw(1, 80, "End setting");
      clrtoeol();
      refresh();
}

void Clock::copy(const Clock &other)
{
    hr = other.hr;
    min = other.min;
    sec = other.sec;
    isPM = other.isPM;
    is24 = other.is24;     
}

Clock& Clock::operator=(Clock &other)
{
    if(this != &other)
     copy(other);
    return *this;
}
Clock& Clock::operator=(const Clock &other)
{
    if(this != &other)
     copy(other);
    return *this;
}

void Clock::showTime(int x, int y)
{
     mvprintw(x, y, "%d:%d:%d", hr, min, sec);
     clrtoeol();    
}
void Clock::stopwatch()
{
        mvprintw(4, 80, "Setting stopwatch...");
        is24 = true;
        setClock();
        int input = 0;
        Colon colon1(5, 30), colon2(5, 55);
        bool oneSec = true;
        while((input = kbinput()) != 268 && !(hr == 0 && min == 0 && sec == 0))
        { 
            if(oneSec)
               lessSec(1); 
            oneSec = !oneSec;
            colon1.display(true);
            colon2.display(true);
            display(true);       
        }
        if(hr == 0 && min == 0 && sec == 0)
        {
            mvprintw(4, 80, "Time's up!!");
            for(int i = 0; i<7; i++)
                std::cout<<(char)7;
        }
        else
            mvprintw(4, 80, "Exiting timer");    
        clrtoeol();          
}
bool operator==(const Clock &a, const Clock &b)
{
   return (a.hr == b.hr && a.min == b.min && a.sec == b.sec && a.isPM == b.isPM); 
}
void Clock::snooze()
{
    addMin(10);  
    mvprintw(3, 80, "Snoozing. Will go off again at %d:%d:%d", hr, min, sec);
    clrtoeol();
}
void Clock::stopAlarm()
{
    mvprintw(3, 80, "Alarm deactivating. Good morning."); 
    clrtoeol();  
}
void Clock::addUTC(Clock &other, Clock &UTC)
{
     Clock temp = other;
     if(UTC.hr < 0)
     {
        temp.lessHr(-UTC.hr);
        temp.lessMin(UTC.min);
        temp.lessSec(UTC.sec);
     }
     else
     {
        temp.addHr(UTC.hr);
        temp.addMin(UTC.min);
        temp.addSec(UTC.sec);
     }
     hr = temp.hr;
     min = temp.min;
     sec = temp.sec;
     isPM = temp.isPM;
     is24 = temp.is24;
}

