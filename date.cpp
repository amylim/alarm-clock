#include "date.h"

Date::Date(int r, int c)
{
   x = r;
   y = c;
   month = 1;
   day = 1;
   year = 1970;
}
void Date::display(bool onOff)
{
   if(onOff)
   {
      Letter m1(x,y-2), m2(x,y+11), m3(x, y+24);
      Digit day1(x, y + 44), day2(x, y+54), year1(x, y+69), year2(x, y+79), year3(x, y+89), year4(x, y+99);
      clearDisplay();
      attron(COLOR_PAIR(BLACKONWHITE));
      mvprintw(37, 70, " ");
      m1.display(english::monthStr[month - 1].at(0)-'A', true);
      m2.display(english::monthStr[month - 1].at(1)-'A', true);
      m3.display(english::monthStr[month - 1].at(2)-'A', true);
      day1.display(day/10, true); 
      day2.display(day%10, true);
      year1.display(year/1000, true);
      year2.display((year%1000)/100, true); 
      year3.display((year%100)/10, true);
      year4.display((year%10), true);
      refresh();
   }
   else
      clearDisplay();   
}
void Date::clearDisplay()
{
     Letter m1(x,y-2), m2(x,y+11), m3(x, y+24);
     Digit day1(x, y + 44), day2(x, y+54), year1(x, y+69), year2(x, y+79), year3(x, y+89), year4(x, y+99);
     m1.display(26, false); 
     m2.display(26, false);
     m3.display(26, false);
     day1.display(8, false); 
     day2.display(8, false);
     year1.display(8, false);
     year2.display(8, false); 
     year3.display(8, false);
     year4.display(8, false);
     refresh();
}
void Date::addYear()
{
   year = (year == 2100) ? 2100 : year + 1; 
}
void Date::lessYear()
{
   year = (year == 1900) ? 1900 : year - 1; 
}
void Date::addMonth()
{
   month = (month == 12) ? 1 : month + 1; 
}
void Date::lessMonth()
{
   month = (month == 1) ? 12 : month - 1; 
}
void Date::addDay()
{
   if(month == 2) 
   {
      if(!(year%4))//leap year
         day = (day == 29) ? 1 : day + 1; 
      else 
         day = (day == 28) ? 1 : day + 1;
   }
   else if(month == 4 || month == 6 || month == 9 || month == 11)
      day = (day == 30) ? 1 : day + 1;
   else 
      day = (day == 31) ? 1 : day + 1;
}
void Date::lessDay()
{
   if(month == 2) 
   {
      if(!(year%4))//leap year
         day = (day == 1) ? 29 : day - 1; 
      else 
         day = (day == 1) ? 28 : day - 1;
   }
   else if(month == 4 || month == 6 || month == 9 || month == 11)
      day = (day == 1) ? 30 : day - 1;
   else 
      day = (day == 1) ? 31 : day - 1;
}
void Date::setDate()
{
      mvprintw(26, 80, "Setting date...");
      clrtoeol();
      refresh();

      int input = 0;
      while((input = kbinput()) != 10)
      {                
         switch(input)
         {
            case 272: addMonth();    //F8 increases the months 
                break;
            case 56: lessMonth();    //8 decreases the months
                break;
            case 273: addDay();   //F9 increases the days
                break;
            case 57: lessDay();   //9 decreases the days
                break;
            case 274: addYear();   //F10 increases the year
                break;
            case 48: lessYear();   //0 decreases the year
                break;
         }
         display(true);
         
      }
      mvprintw(26, 80, "Date set");
      clrtoeol();
      refresh();
}
