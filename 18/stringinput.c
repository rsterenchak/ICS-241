#include <stdio.h>
#include <stdlib.h>
#include "stringinput.h"

/**
 * Safer functions for string input: getstring() and getline2().
 *
 * @author William Albritton
 */

/**
 * Reads characters from the input steam, and stores the characters in a string,
 * and adds a null character ('\0') after the last character in the string.
 * It will read up to size-1 number of characters, and will read until the end of file,
 * newline, blank space, or tab. Will leave the rest of the characters on the input stream.
 *
 * Warning: If the string array has less than size number of characters,
 * this may crash the program, or write over memory!
 *
 * @param string[] An array of characters, with size number of elements.
 * @param size The number of characters in string[] param.
 * @return index The number of characters read into the String.
 *               If there are no characters added to the string, a 0 is returned.
 */
int getstring(char string[], const int size) {
  int index = 0;
  char character = 'z';

  // Get input from the user, stops storing characters if there is
  // an EOF, newline, space, or tab character.
  for (index = 0; index < (size - 1); index++) {

    character = getchar();

    // check for end of file
    if (EOF == character) break;
    // check for end of line
    if ('\n' == character) break;
    // check for space
    if (' ' == character) break;
    // check for a tab
    if ('\t' == character) break;

    string[index] = character;
  }
  // Add the null character to terminate the String.
  string[index] = END_OF_STRING;

  return index; // Number of characters in the string.
}

/**
 * IMPORTANT: named getline2() to not interfere with stdio.h getline() function. 
 *
 * Reads characters from the input steam, and stores the characters in a string,
 * and adds a null character ('\0') after the last character in the string.
 * It will read up to size-1 number of characters until the end of file or newline.
 * Performs a clean up - removes the rest of the characters from the input steam.
 *
 * Warning: If the string has less than size number of characters,
 * this may crash the program, or write over memory!
 *
 * @param string[] An array of characters, with size number of elements.
 * @param size The number of characters in string[]
 * @return index The number of characters read into the String.
 *               If there are no characters added to the string, a 0 is returned.
 */
int getline2(char string[], const int size) {

  int index = 0;
  char character = 'z';

  // Get input from the user, stops storing characters if there is
  // an EOF or newline character.
  for (index = 0; index < (size - 1); index++) {

    character = getchar();

    // Check for end of file
    if (EOF == character) break;
    // Check for end of line
    if ('\n' == character) break;

    string[index] = character;
  }

  // Add the null character to terminate the String.
  string[index] = END_OF_STRING;

  // Clean-up.
  // Remove the rest of the characters from input stream.
  while (('\n' != character) && (EOF != character)) {
    character = getchar();
  }

  return index; // Number of characters in the string.
}
