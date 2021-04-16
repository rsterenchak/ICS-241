/*
 * This program utilizes a class named Complex and a driver method in order to call print, set, copy, add, subtract, divide, multiply, and get functions from Complex class. The driver method is used to test each method created in the Complex class ensuring proper functionality.
 * 
 * Robert Sterenchak
 * ICS212 - Assignment 21
 * November 23, 2019
 */
#include <iostream>
#include <cmath>
using namespace std;

/*class named Complex used to represent and set Complex number variables*/
class Complex {

public:

  /*Constructor consisting of two double numbers.*/
  Complex(){
 
    real = 0;//real value initially set to 0;
    imaginary = 0;//imaginary value initially set to 0;
 
  }//ends Constructor #1

  /*Constructor allows the setting of real and imaginary values per each Complex Object created.*/
  Complex(double realParam, double imaginaryParam){
    
    set(realParam, imaginaryParam);

  }//ends Constructor #2
  
  /*Constructor allows the copying of one function's values with another.*/
  Complex(const Complex &copyComplex){

    set(copyComplex.real, copyComplex.imaginary);

  }//ends copy constructor
  
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

  /*Destructor function prints upon setting of Complex object values.*/
  ~Complex(){
    if(imaginary<0){//if imaginary is negative then prints equation with minus sign.                    
      cout << "Destructor for: (" << real << " - " << abs(imaginary) << "i)\n";
    }
    else{//else when imaginary is positive then prints equation with plus sign.                         
      cout << "Destructor for: (" << real << " + " << imaginary << "i)\n";
    }
  }

  /*Addition function allows the addition of real and imaginary values within Complex objects.*/
  Complex add(const Complex &addComplex){
    double real3 = real + addComplex.real;
    double imaginary3 =  imaginary + addComplex.imaginary;

    Complex complex3(real3, imaginary3);//sets and returns values using the above calculations
  
    return complex3;
  }
  
  /*Subraction function allows the subtraction of real and imaginary values within Complex objects.*/
  Complex subtract(const Complex &subtractComplex){
    double real3 = real - subtractComplex.real;
    double imaginary3 = imaginary - subtractComplex.imaginary;

    Complex complex3(real3, imaginary3);//sets and returns values using the above calculations

    return complex3;
  }

  /*Divide function allows the division of real and imaginary values between two Complex objects.*/
  Complex divide(const Complex &divideComplex){
    double real3 = (((real*divideComplex.real)+(imaginary*divideComplex.imaginary))/((divideComplex.real*divideComplex.real)+(divideComplex.imaginary*divideComplex.imaginary)));
    double imaginary3 = (((imaginary*divideComplex.real)-(real*divideComplex.imaginary))/((divideComplex.real*divideComplex.real)+(divideComplex.imaginary*divideComplex.imaginary)));


    Complex complex3(real3, imaginary3);//sets and returns values using the above calculations

    return complex3;
  }

  /*Multiply function allows the multiplication of real and imaginary values between two Complex objects*/
  Complex multiply(const Complex &multiplyComplex){
    double real3 = ((real*multiplyComplex.real)-(imaginary*multiplyComplex.imaginary));
    double imaginary3 = ((imaginary*multiplyComplex.real)+(real*multiplyComplex.imaginary));

    Complex complex3(real3, imaginary3);//sets and returns values using the above calculations

    return complex3;
  }


private:
  // Data Members
  double real;
  double imaginary;


};

/*Main function where functions are called and information is printed to the user.*/
int main(void){
  
  Complex c1;//creates c1 object
  Complex c2;//creates c2 object
  Complex c3;//creates c3 object

  c1.set(1.1, 2.3);//uses set function to assign real and imaginary values
  cout << "Test the Constructor with two parameters.\n";
  cout << "Complex number c1 is: ";
  c1.print();//Tests print function

  c2 = c1;//copies c1 to c2 object 
  c3 = c1;//copies c1 to c3 object

  cout << "\n\nTest the copy constructor.\n";
  cout << "Complex number c2 is: ";
  c2.print();//Tests print function  
  cout << "\nComplex number c3 is: ";
  c3.print();//Tests print function  
  
  cout << "\n\nTest the add() member function. Add c1 and c2 and store in c3.\n";
  c3 = c1.add(c2);//tests add function
  cout << "Complex number c3 is: ";
  c3.print();//Tests print function                                                                     

  cout << "\n\nTest the subtract() member function. Subtract c2 from itself and store in c3.\n";
  c3 = c2.subtract(c2);//tests subtract function
  cout << "Complex number c3 is: ";
  c3.print();//Tests print function                                                                     
  
  cout << "\n\nTest the multiply() member function. Multiply c1 by itself and store in c3.\n";
  c3 = c1.multiply(c1);//tests multiply function
  cout << "Complex number c3 is: ";
  c3.print();//Tests print function 

  cout << "\n\nTest the divide() member function. Divide c1 by itself and store in c3.\n";
  c3 = c1.divide(c1);//tests divide function
  cout << "Complex number c3 is: ";
  c3.print();//Tests print function 

  cout << "\n\n";

  return 0;
  
}//end of main

