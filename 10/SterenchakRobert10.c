/*
 * This program utilizes several self made functions in order to generate certain calculations while also using recursion in place of loops. The mathematical calculations determined in this program are counting, adding, multiplying, powers, and finding two number greatest common divisor. All this is done while also ensuring incorrect input is taken care of in the form of an error message.    
 * 
 * Robert Sterenchak
 * ICS212 - Assignment 10
 * October 08, 2019
 */
#include <stdio.h>
#include "getdouble.h"
#include <stdlib.h>

/*Introduces program purpose and intentions to user*/
#define TITLE "This program generates several math calculations using recursion.\n"

void recursiveCount(int start, int end);//Function prints all integer starting from first to second.
int recursiveAdd(int start, int end);//Function prints summation of all integers from first to second.
int recursiveMultiply(int start, int end);//Function prints the multiplied result of both integers.
int recursivePower(int start, int end);//Function prints result of first number to the power of second.
int recursiveGcd(int start, int end);//Function finds and prints the greatest common divisor of both integers.

/*Main is where I declared all variables and necessary function calls to attain desired results.*/
int main (){
  
  int first = 0;//First number received by user.
  int second = 0;//Second number received by user.

  int summation = 0;//Variable used to print recursiveAdd();
  int multiply = 0;//Variable used to print recursiveMultiply();
  int power = 0;//Variable used to print recursivePower();
  int gcd = 0;//Varialbe used to print recursiveGcd();

  /*This statement prints to user general information about the program use and function.*/
  printf(TITLE);
  /*Initial instructions given to user.*/
  printf("Enter two positive integers, separated by a space, the first smaller than the second.\n");
  
  first = getdouble();//Receives input
  second = getdouble();//Receives input

  /*Error message prints if first number is 0 or negative.*/
  if(first <= 0){
    printf("Your input is incorrect. %d is not positive.\n", first);
    exit(0);//Program exits after error message is printed.
  }

  /*Error message prints if second number is 0 or negative.*/
  if(second <= 0){
    printf("Your input is incorrect. %d is not positive.\n", second);
    exit(0);//Program exits after error message is printed.
  }

  /*Error message prints if first number is larger than the second number*/
  if(first > second){
     printf("Your input is incorrect. %d is not smaller than %d.\n", first, second);
     exit(0);//Program exits after error message is printed.
  }

  printf("\nCounting from %d to %d = ", first, second);
  
  recursiveCount(first, second);//First function call

  summation = recursiveAdd(first, second);//Second function call

  printf("\n\nThe sum of %d to %d = %d", first, second, summation);

  multiply = recursiveMultiply(first, second);//Third function call

  printf("\n\nThe product of %d to %d = %d", first, second, multiply);

  power = recursivePower(first, second);//Fourth function call

  printf("\n\n%d to the power of %d = %d", first, second, power);

  gcd = recursiveGcd(first, second);//Final function call

  printf("\n\nThe GCD of %d and %d = %d\n\n", first, second, gcd);

  return 0;
  
}

/*Function uses printf() to correctly print all integers from first to second integers.*/
void recursiveCount(int start, int end){  

  if(start == end){//Once base case is reached the final integer is printed and functions completes.
    printf("%d", end);
     }

     else{
       printf("%d ", start);//Prints start integer
       start++;//Necessary to continually iterate through integers
       recursiveCount(start, end);//Recursively calls function so integers can continually be printed
     }

   }

/*Function returns the summation result of integers starting from first to second integers.*/
int recursiveAdd(int start, int end){
  int result = 0;

  if(start == end){//Once base case is reached result of numbers added is returned to user.
    result = end;
  }
  else{
    result = start + recursiveAdd(start + 1, end);//Result changes by recursively adding 1 to start each time. 
  }

  return result;//Result return

}

/*Function returns the multiplication of first all the way until the second integer is reached.*/
int recursiveMultiply(int start, int end){
  int result = 0;

  if(start == end){//Once base case is reached result is returned to the user.
    result = end;
  }
  else{
    result = start *  recursiveMultiply(start + 1, end);//Recursively multiplies and iterates through all integers from start to end.
  }

  return result;//Result return

}

/*Function returns the result of the first integer to the power of the second integer.*/
int recursivePower(int start, int end){
  int result = 0;
  if(end != 0){
    return result = (start * recursivePower(start, end-1));//Start integer is continually multiplied until end integer reaches 0.
  }
  else{//Base case used if second number happens to be zero.
    return 1;
  }

}

/*Function returns the greatest common divisor of both first and second integers.*/
int recursiveGcd(int start, int end){
  int x = start;//x variables used to represent start
  int y = end;//y variable used to represent end 
  int result = 0;

  if(y == 0){//Base case represents when both x and y find an int divisible for both
    return x;
  }
  else{
    return result = recursiveGcd(y, x % y);//result is recursively declared until a divisible number is found
  }

}
