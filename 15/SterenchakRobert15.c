/*
 * This program utilizes a pointer array of functions, integer variables, and pointer array to store morse code characters with the translations. 
 * 
 * Robert Sterenchak
 * ICS212 - Assignment 15
 * October 28, 2019
 * @bugs Program compiles, unable to properly run due to segmentation fault. Attempted to debug but solution was not found.
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 36

const char *morse[SIZE] = {
  "0 -----",
  "1 .----",
  "2 ..---",
  "3 ...--",
  "4 ....-",
  "5 .....",
  "6 -....",
  "7 --...",
  "8 ---..",
  "9 ----.",
  "a .-",
  "b -...",
  "c -.-.",
  "d -..",
  "e .",
  "f ..-.",
  "g --.",
  "h ....",
  "i ..",
  "j .---",
  "k -.-",
  "l .-..",
  "m --",
  "n -.",
  "o ---",
  "p .--.",
  "q --.-",
  "r .-.",
  "s ...",
  "t -",
  "u ..-",
  "v ...-",
  "w .--",
  "x -..-",
  "y -.--",
  "z --..",


};

/*Main function where variables and pointers are initialized, commandline input is also utilized*/
int main(int argc, char *argv[]){
  int i = 0;
  int start = 2;//variable used to continue morse code print
  //variable used to correctly print out morse code bits
  
  if(argc < 2){
    printf("Error: At least 2 command line arguments are expected, only %i present.\n", argc);
    printf("Enter Morse Code on the command line.\n");
    return -1;
  }//error checking in the case arguments in command line input is less than required

  for(i=0;i<36; i++){//for loop iterates through entire morse code pointer array until match is found  
    int h = 0;
        
    for(h=1;(argv[h])!=('\0');h++){//for loop prints morse code bits until argument finishes
	int result = strcmp(morse[i], argv[h]);
	
	if(result = 0){
	  int length = strlen(morse[i]) - 1;//assigns updated value for matching morse code length
	while(start<=length){
	 printf("%c", morse[i][start]);
	 start++;
	}//while end
        
	}//if end
	
     }//ends for#2
      //i = 0;//resets after argument finishes to start new check 
      }//ends for#1


  return 0;
  
}//end of main
