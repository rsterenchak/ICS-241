#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "printbits.h"

/**
 * Program utilizes several custom functions in order to calculate specific unsigned int and char bit manipulations. Bits are combined by using shifting, inclusive OR, bit masks, and the & operator in order to define the function definitions.
 *
 * @author     Sterenchak, Robert
 * @assignment ICS 212 Assignment 16
 * @date       October 31, 2019
 */

int twosComplement(unsigned int);//Calculates two's complement of integer

unsigned int packCharacters(unsigned char, unsigned char, unsigned char, unsigned char);//Shifts character bits and stores/returns them into one unsigned integer

void unpackCharacters(unsigned int, unsigned char*, unsigned char*, unsigned char*, unsigned char*);//Translates unsigned integer into four character pointers

unsigned int circularLeftShift(unsigned int, unsigned int);//Shifts integer2 bits to the left integer1 times, and integer1 bits to the right integer2 number of times and returns a singular unsigned integer 

int main(int argc, char *argv[]) {

  int i = 0;

  // ::::: Begin error checking for the command line arguments. :::::
  // ::::::::::::::::::::     DO NOT MODIFY     :::::::::::::::::::::
  // Ensures there is the correct amount of arguments.
  if (argc != 7) {
    printf("Error: 7 commandline arguments are expected, only %d present.\n", argc);
    printf("Enter four characters followed by two integers.\n");
    exit(1);
  }
  // Ensures 4 character arguments.
  for (i = 1; i <= 4; i++) {
    if (strlen(argv[i]) != 1) {
      printf("Error: Please enter a single character for character #%i on the commandline.\n", i);
      printf("You entered %i characters: %s\n", strlen(argv[i]), argv[i]);
      exit(1);
    }
  }
  // Ensures an integer argument.
  unsigned int integer1 = atoi(argv[5]);
  if (0 == integer1 && '0' != argv[5][0]) {
    printf("Error: Expected an integer argument.\n");
    printf("You entered \"%s\" instead.\n", argv[5]);
    exit(1);
  }
  // Ensures an integer argument.
  unsigned int integer2 = atoi(argv[6]);
  if (0 == integer2 && '0' != argv[6][0]) {
    printf("Error: Expected an integer argument.\n");
    printf("You entered \"%s\" instead.\n", argv[6]);
    exit(1);
  }
  // ::::: End error checking for command line arguments. :::::

  //START OF INPUT
  puts("function #1:");
  puts("Input is unsigned integer:");
  printbits(integer1);
  unsigned int result = twosComplement(integer1);
  puts("Output is the two's complement of the integer:");
  printbits(result);

  puts("");

  puts("function #2:");
  puts("Input is 4 characters:");
  for (i = 1; i <= 4; i++) {
    print8bits(*argv[i]);
  }
  puts("Output is packed unsigned integer variable in bit format:");
  result = packCharacters(*argv[1], *argv[2], *argv[3], *argv[4]);
  printbits(result);
 
  puts("");

  puts("function #3:");
  puts("Input is unsigned integer:");
  printbits(integer1);
  char unpack1, unpack2, unpack3, unpack4;
  unpackCharacters(integer1, &unpack1, &unpack2, &unpack3, &unpack4);
  puts("Output is four unpacked characters: ");
  print8bits(unpack1);
  print8bits(unpack2);
  print8bits(unpack3);
  print8bits(unpack4);
 
  puts("");

  puts("function #4");
  puts("Input is unsigned integer:");
  printbits(integer2);
  printf("Shifted %i bit(s) to the left.\n", integer1);
  integer2 = circularLeftShift(integer1, integer2);
  printbits(integer2);

  return 0;

}

/*Function returns two's complement by initially calculatirg one's complement then adding one*/
int twosComplement(unsigned int number){
  int result = 0;
  result = (~number) + 1;//Calculation for two's complement of original unsigned integer
  return result;
}

/*Function takes 4 unsigned character bits shifting and combining them into one unsigned integer.*/
unsigned int packCharacters(unsigned char letter1, unsigned char letter2, unsigned char letter3, unsigned char letter4){
  unsigned int result = 0;//blank unsigned integer
  int shifter =8;//Amount used to shift unsigned char bits
  result = ((letter1 << (3*shifter)) | (letter2 << (2*shifter)) | (letter3 << (shifter)) | (letter4));//Calculation for packing character bits together
  return result;
}

/*Function takes one unsigned integer and manipulates it in such a way that bits are shift and mask is applied assigning the result to it's corresponding pointer character.*/
void unpackCharacters(unsigned int result, unsigned char *letter1, unsigned char* letter2, unsigned char* letter3, unsigned char* letter4){
  unsigned int mask = 0x000000ff;//mask reserves last 8 bits and makes all others zero
  int shifter = 8;//amount used to shift bits
  
  *letter1 =  (result >> (3*shifter))& mask;//Calculation for assigning letter1 pointer
  *letter2 =  (result >> (2*shifter))& mask;//Calculation for assigning letter2 pointer   
  *letter3 =  (result >> (shifter))& mask;//Calculation for assigning letter3 pointer   
  *letter4 =  (result) & mask;//Calculation for assigning letter4 pointer   
}

/*Function shifts unsigned integer2 to the left integer1 number of times, then combines that result with integer2 shifted to the right integer1 number of times bits returning the combined result*/
unsigned int circularLeftShift(unsigned int number1, unsigned int number2){
  unsigned int result = 0;//blank unsigned integer
  
  result = (number2 << number1)| (number2 >> (32 - number1));//Calculation for result
  return result;
}
