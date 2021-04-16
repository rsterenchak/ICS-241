/*
 * This program utilizes integer several variables and one pre-defined constant to calculate the approximate age of the user. Specific calculations are also stored into their own integer variables to be displayed to the user.
 * 
 * Robert Sterenchak
 * ICS212 - Assignment 05
 * September 15, 2019
 */
#include <stdio.h>
#include "getdouble.h"

#define TITLE "The following program will prompt you to input the month, day, and year you were born and will approximate your current age in days.\n"

int main (void){
  
  int month = 0;
  int day = 0;
  int year = 0;
  int currentMonth = 9;
  int currentDay = 17;
  int currentYear = 2019;
  int currDaysSince1 = ((currentYear * 365.25)+((currentMonth - 1) * (365.25/12.0))+ currentDay);
  int birtDaysSince1 = ((year * 365.25) + ((month - 1) * (365.25/12.0)) + day);
  int ageInDays = (currDaysSince1 - birtDaysSince1);

  /*Pre-defined constant is printed to the user more information on the purpose of this program.*/
  printf(TITLE);
  
  /*puts() function is utilized to give the user spacing and to see input on a newline*/
  /*Prompt for month of birth stored into the month integer variable*/
  puts("Please input the month you were born.(1-12)");//Month
  month = getdouble();
  /*Prompt for day of birth stored into the day integer variable*/
  puts("Please input the day you were born.");//Day
  day = getdouble();
  /*Prompt for year of birth stored into the year integer variable*/
  puts("Please input the year you were born.");//Year
  year = getdouble();

  /*Calculations defined once more to recalculate for newly inputted birth date values*/
  birtDaysSince1 = ((year* 365.25)+((month - 1) * (365.25/12.0)) + day);
  ageInDays = (currDaysSince1 - birtDaysSince1);
  
  /*Utilize printf() function to inform user of current date*/
  printf("The current date is %d / %d / %d.\n", currentMonth, currentDay, currentYear);
  printf("Your birthdate is %d / %d / %d.\n", month, day, year);
  /*Utilize printf() function to inform user of their calculated age in days*/
  printf("Your current age in days is %d.\n", ageInDays);
  
  
  return 0;
  




}
