/*
Robert Sterenchak
ICS212 - Assignment 04
September 10, 2019
*/
#include <stdio.h>
#include "getdouble.h"
int main (void){
  char letter1 = 'z';
  char letter2 = 'z';
  double number1 = 1;
  double number2 = 2;
  /*Programs prompts user to input a character then immediately displays their input.*/
  printf("Please input a letter to proceed.\n");
  letter1 = getchar();
  printf("The first letter you have chosen is '%c'. \n", letter1);
  letter1 = getchar();
  printf("Please input another letter to proceed.\n");
  letter2 = getchar();
  printf("The letter you have chosen is '%c'. \n", letter2);
  letter2 = getchar();
  /*Program prompts user to input a double number then immediately displays their input.*/
  printf("Please input a number to proceed.\n");
  number1 = getdouble();
  printf("The number you have chosen is '%f' \n", number1);	 
  printf("Please input another number to proceed.\n");
  number2 = getdouble();
  printf("The number you have chosen is '%f' \n", number2);
}
