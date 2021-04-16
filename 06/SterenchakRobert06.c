/*                                                                                                       * This program takes a character between the numbers one and nine inclusive and tranlates them to the spanish language. This program utilizes two variables to include one pre-defined constant and a character variable inputted by the user in order to attain character selection for translation. Several conditional statements are also utilized in order to ensure correct output and to account for errors.             *                                                                                        
 * Robert Sterenchak                                                                                    
 * ICS212 - Assignment 06                                                                               
 * September 15, 2019                                                                                   
*/
#include <stdio.h>

#define TITLE "The following program will translate in spanish any number between 0 and 9 .\n"

/*Main Method*/
int main (void){
  
  /*Character variable*/
  char userInput = 'a';
  printf(TITLE);

  /*Asks user to input character betwee zero and nine.*/
  puts("Please enter a number between 0 and 9 inclusive.");
  /*Recieves character input and is assigned to userInput variable*/
  userInput = getchar();
  
  /*"Overall" if statement ensuring user input is indeed between zero and nine inclusive*/ 
  if((userInput==('0')) ||(userInput==('1')) ||(userInput==('2')) ||(userInput==('3')) ||(userInput==('4')) ||(userInput==('5')) ||(userInput==('6')) ||(userInput==('7')) ||(userInput==('8')) ||(userInput==('9'))){
    /*Translates zero to "cero"*/
    if(userInput == '0'){
    printf("Translation: cero\n");
    }
    /*Translates one to "uno"*/
    if(userInput == '1'){
    printf("Translation: uno\n");
    }
    /*Translates two to "dos"*/
    if(userInput == '2'){
    printf("Translation: dos\n");
    }
    /*Translates three to "tres"*/
    if(userInput == '3'){
    printf("Translation: tres\n");
    }
    /*Translates four to "cuatro"*/
    if(userInput == '4'){
    printf("Translation: cuatro\n");
    }
    /*Translates five to "cinco"*/
    if(userInput == '5'){
    printf("Translation: cinco\n");
    }
    /*Translates six to "seis"*/
    if(userInput == '6'){
    printf("Translation: seis\n");
    }
    /*Translates seven to "siete"*/
    if(userInput == '7'){
    printf("Translation: siete\n");
    }
    /*Translates eight to "ocho"*/
    if(userInput == '8'){
    printf("Translation: ocho\n");
    }
    /*Translates nine to "nueve"*/
    if(userInput == '9'){
    printf("Translation: nueve\n");
    }
     }
  /*Statement prints error message in the case the user inputs an incorrect character*/
  else{
    printf("ERROR: '%c' is not a character in the range of 0 - 9.\n", userInput);
    
  }
  return 0;
}
