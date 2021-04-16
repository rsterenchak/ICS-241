/*
 * This program utilizes a class named Complex and a driver method in order to call print, set, and get functions from Complex class. The driver method is used to test each method created in the Complex class ensuring proper functionality.
 * 
 * Robert Sterenchak
 * ICS212 - Assignment 20
 * November 20, 2019
 */
#include <iostream>
#include <cmath>
using namespace std;

/*class named Complex used to represent and set Complex number variables*/
class Complex {

public:

  /*Constructor consisting of two double numbers.*/
  Complex(){
 
    real = 0;
    imaginary = 0;
 
  }//ends Constructor

  /*Set function when called changes original values to newly designated values.*/
  void set(double a, double b){

    real = a;
    imaginary = b;

  }//ends Set Function

  /*Get function returns individiual value set for real variable.*/
  double getReal() const{
    return real;
  }//ends Get Function
  
  /*Get function returns individual value set for imaginary variable.*/
  double getImaginary() const{
    return imaginary;
  }//ends Get Function                                                                                        
 /*Print function when called prints out complex number equation.*/
 void print() const {
   
   if(imaginary<0){//if imaginary is negative then prints equation with minus sign.
     cout << "(" << real << " - " << abs(imaginary) << "i)";
   }
   else{//else when imaginary is positive then prints equation with plus sign.
     cout << "(" << real << " + " << imaginary << "i)";
   }
 }//ends Print Function


private:
  // Data Members
  double real;
  double imaginary;


};

/*Main function where functions are called and information is printed to the user.*/
int main(void){

  Complex c1;//creates c1 object
  cout << "Test the Constructor.\n";
  cout << "Complex number c1 is: ";
  c1.print();//Tests print function

  Complex c2;//creates c2 object
  c2.set(3.3, -4.4);//sets new values for c2 object variables
  cout << "\n\nTest the one set() function.\n";
  cout << "Complex number c2 is: ";
  c2.print();//Tests print function with new values


  Complex c3;//creates c3 object
  c3.set(5.5, 6.6);//sets new values for c3 object variables
  cout << "\n\nTest the two get() functions.\n";
  cout << "Complex number c3's real part  is: " << c3.getReal();//Prints and utilizes get() for real variable.
  cout << "\nComplex number c3's imaginary part is: " << c3.getImaginary();//Prints and utilizes get() for imaginary variable.
  cout << "\n";

  return 0;
  
}//end of main

