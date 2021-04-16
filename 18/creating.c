#include <stdio.h>
#include <stdlib.h>
#include "student.h"

/**
 * Writes a binary file of 20 fixed-length records of students.
 * The same blank Student record will be written 20 times.
 * The file students.data that is created is a binary file, NOT a plain-text file.
 * The program reading.c is needed to read students.data after it's created.
 *
 * The following files are needed to compile:
 *   student.h
 *   makefile-creating
 *
 * To compile this file:
 *   % make -f makefile-creating
 * To run:
 *   % ./program
 *
 * @author Ed Meyer
 * @original_author William Albritton
 */
int main() {

  // Loop increment variable.
  int i = 0;
  
  // The "data" that will be writted 20 times.
  // -1 means no student data.
  Student blank = {-1, "", "", 0, 0.0};      
  FILE *filePointer = NULL;
  
  // Output filename.
  // IMPORTANT! This will be a binary file, NOT a text file.
  char *fileName = "students.data";
  
  // Error checking variables.
  int fileClosed = 0; 
  int writeError = 0;
  
  // Show the size of the student structure.
  // Each write will use that many bytes.
  printf("sizeof(Student)=%d\n", sizeof(Student));
  
  // Open a connection to a file for writing a binary file.
  filePointer = fopen(fileName, "wb");
  // If cannot open the filehandle, terminate the program.
  if (filePointer == NULL) {
    printf("File \"%s\" could not be opened.\n", fileName); 
    exit(1);
  } else {
  
    // Write out 20 records to the file.
    for (i = 0; i < MAX_RECORDS; i++) {

      // Make room to add records to a file.
      // Student blank is written to the file.
      // sizeof(): calculates the number of bytes in the struct.
      // 1: means we are writing just one record to the file.
      // filePointer: is the file we are writing to.
      writeError = fwrite(&blank, sizeof(Student), 1, filePointer);
      // Error checking.
      if (1 == writeError) {
        printf("Record #%d was correctly written to file \"%s\".\n", i, fileName);
      } else {
        printf("Record #%d was NOT correctly written to file \"%s\".\n", i, fileName);
      }
    }
    
    // Close the file connection.
    fileClosed = fclose(filePointer);
    // Error checking.
    if (0 == fileClosed) {
      printf("File connection to \"%s\" closed successfully.\n", fileName);
    } else {
      printf("File connection to \"%s\" did NOT close successfully.\n", fileName);
    }
  }
  
  return 0;
}

/*

sizeof(Student)=40
Record #0 was correctly written to file "students.data". 
Record #1 was correctly written to file "students.data". 
Record #2 was correctly written to file "students.data". 
Record #3 was correctly written to file "students.data". 
Record #4 was correctly written to file "students.data". 
Record #5 was correctly written to file "students.data". 
Record #6 was correctly written to file "students.data". 
Record #7 was correctly written to file "students.data". 
Record #8 was correctly written to file "students.data". 
Record #9 was correctly written to file "students.data". 
Record #10 was correctly written to file "students.data". 
Record #11 was correctly written to file "students.data". 
Record #12 was correctly written to file "students.data". 
Record #13 was correctly written to file "students.data". 
Record #14 was correctly written to file "students.data". 
Record #15 was correctly written to file "students.data". 
Record #16 was correctly written to file "students.data". 
Record #17 was correctly written to file "students.data". 
Record #18 was correctly written to file "students.data". 
Record #19 was correctly written to file "students.data". 
File connection to "students.data" closed successfully.

 */

