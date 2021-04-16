/*
 * This program utilizes several variables and five pre-defined functions in order to generate a random  mortage value along with interest rates and information relevant to the life of the thirty year loan. Specific calculations are also stored into their own integer and double variables to be displayed to the user. This program ultimately displays an estimated monthly payment to the user.  
 * 
 * Robert Sterenchak
 * ICS212 - Assignment 08
 * September 21, 2019
 */
#include <stdio.h>
#include "getdouble.h"
#include <stdlib.h>
#include <math.h>

#define TITLE "Upon execution the following program generates a random mortage amount and ultimately calculates it's necessary monthly payment.\n\n"

int main (void){
  
  /*Pre-defined constant is printed to the user more information on the purpose of this program.*/
  srand(time(NULL));//initialized to ensure random  mortage input

  /*Generates random mortage value between the values of 419,000 - 719,000*/
  double randMortage =(((rand() %(719-419 + 1)) + 419) * 1000);//properly sets an upper and lower limit random mortage 

  /*Various values relevant to calculating monthly payment amount*/
  double principle = randMortage;//Principle
  double annInterest = .035;//Interest
  int totalYears = 30;//Years length of Loan
  int totalMonths = totalYears * 12;//Total amount of months
  /*Monthly Interest calculated by divinding my months in a year*/
  double monthlyInt = (annInterest/(12));//decimal form

  /*Monthly payment calculated using a formula*/
  int monthlyPay = principle * ((monthlyInt*(pow(1 + monthlyInt,(totalMonths))))/(pow(1 + monthlyInt,(totalMonths)) - 1)); 

  /*This statement prints to user general information about the program use and function.*/
  printf(TITLE);
  /*Prints to user randomly generated mortage amount.*/
  printf("The randomly generated mortage is: $%0.2f\n\n", floor(randMortage));
  printf("Current interest rate is set at: %0.1f%\n\n", (annInterest * 100));
  /*Monthly interest calculated for use in monthly payment formula.*/
  printf("Approximate monthly interest is: %0.4f%\n\n", monthlyInt);  
  printf("Total months left on this loan are: %d\n\n", totalMonths);
  /*Prints to user monthly mortage payment using the ceil() function*/
  printf("Your estimated monthly mortage payment is: $%0.2f\n\n", ceil(monthlyPay));
  
  return 0;
  


}
