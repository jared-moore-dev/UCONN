#include <stdio.h>
#include "calendar.h"

int numDaysInMonth(int month, int year){
  /*
    
   */
  switch(month){
  case JAN:
    return 31;
    break;
  case FEB:
    if ((year%4 == 0 && year%100 != 0) || year%400 == 0){
	    return 29;
    } else {return 28;}
    break;
  case MAR:
    return 31;
    break;
  case APR:
    return 30;
    break;
  case MAY:
    return 31;
    break;
  case JUN:
    return 30;
    break;
  case JUL:
    return 31;
    break;
  case AUG:
    return 31;
    break;
  case SEPT:
    return 30;
    break;
  case OCT:
    return 31;
    break;
  case NOV:
    return 30;
    break;
  case DEC:
    return 31;
    break;
     /*
      TODO: Add the cases for February through December. Don't forget about leap years. 
      For years that are not centuries (i.e. not 1900, 2000), it is a leap year if it is disible by 4.
      For years that are centuries, it is a leap year if it is divisible by 400.
      Return -1 if the month doesn't fit any of the cases. 
     */
  default:
    return -1;
  }
}

int numFirstMondays(int startYear, int endYear, int janFirstWeekday)
{
  /*
    TODO: Add a loop here to compute the number of mondays that fall on the first of the month between January 1st of startYear and dec 31st of endYear. Note that janFirstWeekday is the weekday of january 1st of startYear.
   */
  int weekDay = janFirstWeekday;
  int count = 0;
  for(int y = startYear;y <= endYear; y++){
	  for(int m=JAN; m <= DEC; m++){
		  if (weekDay==MONDAY){
			  count ++;
		  }
		  weekDay = (weekDay + numDaysInMonth(m, y)) % 7;
	  } 
  }
  return count;
}
