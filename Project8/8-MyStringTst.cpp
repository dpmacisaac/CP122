/*
Name: Dominic MacIsaac
Class: CPSC 122, Section 1
Date Submitted: March 5, 2021
Assignment: Project 8 
Description: Program illustrates using class MyString and class functions
Notes: 
*/

#include "8-MyString.h"
#include <iostream> 
using namespace std;


int main(int argc, char* argv[])
{

  MyString str1(argv[1]);
  MyString* str2 = new MyString(argv[1]);

  /*
  //Test of myDisplay
  cout << "***************************************" << endl;
  cout << "*****Test 1 myDisplay*****" << endl;
  cout << "static test" << endl;
  cout << "output should be the command line input" << endl;
  str1.myDisplay();
  cout << endl;
  cout << "*****Test 2  myDisplay*****" << endl;
  cout << "dynamic test" << endl;
  cout << "output should be the command line input" << endl;
  str2->myDisplay();
  cout << endl;
  cout << "***************************************" << endl;
  //End Test of myDisplay
  */

  /*
  //Test of myStrcpy
  char newInput[] = {'A','B','C','D'};
  cout << "***************************************" << endl;
  cout << "*****Test 1 myStrcpy*****" << endl;
  cout << "static test" << endl;
  cout << "output should be ABCD" << endl;
  str1.myStrcpy(newInput);
  str1.myDisplay();
  cout << endl;
  cout << "*****Test 2  myStrcpy*****" << endl;
  cout << "dynamic test" << endl;
  cout << "output should be the ABCD" << endl;
  str2->myStrcpy(newInput);
  str2->myDisplay();
  cout << endl;
  cout << "***************************************" << endl;
  str1.myStrcpy(argv[1]); //reverts the string back to the originals
  str2->myStrcpy(argv[1]);
  //End Test of myStrcpy
  */
 
  /*
  //Test of myStrlen
  cout << "***************************************" << endl;
  cout << "*****Test 1 myStrlen*****" << endl;
  cout << "static test" << endl;
  cout << "output should be the number of chars in command line input" << endl;
  cout << str1.myStrlen() << endl;
  cout << "*****Test 2  myStrlen*****" << endl;
  cout << "dynamic test" << endl;
  cout << "output should be the number of chars in command line input" << endl;
  cout << str2->myStrlen() << endl;
  cout << "***************************************" << endl;
  //End Test of myStrlen
  */
  
  /*
  //Test of isEqual
  cout << "***************************************" << endl;
  cout << "*****Test 1 isEqual*****" << endl;
  cout << "static test" << endl;
  cout << "output should be false" << endl;
  cout << str1.isEqual(".") << endl;
  cout << "output should be true" << endl;
  cout << str1.isEqual(argv[1]) << endl; //will always equal the input
  cout << "*****Test 2  myStrlen*****" << endl;
  cout << "dynamic test" << endl;
  cout << "output should be false" << endl;
  cout << str2->isEqual(".") << endl; 
  cout << "output should be true" << endl;
  cout << str2->isEqual(argv[1]) << endl;
  cout << "***************************************" << endl;
  //End Test of isEqual
  */
  
  /*
  //Test of find
  cout << "***************************************" << endl;
  cout << "*****Test 1 find*****" << endl;
  cout << "static test" << endl;
  cout << "output should be 2" << endl;
  str1.myStrcpy("Hello"); //uses a constant value to test find feature
  cout << str1.find("llo") << endl;;
  cout << "output should be -1" << endl;
  cout << str1.find("lll") << endl;
  cout << "*****Test 2  find*****" << endl;
  cout << "dynamic test" << endl;
  cout << "output should be 2" << endl;
  str2->myStrcpy("Hello");
  cout << str2->find("ll") <<endl;
  cout << "output should be -1" << endl;
  cout << str2->find("lll") << endl;
  cout << "***************************************" << endl;
  str1.myStrcpy(argv[1]); //reverts back to original strings
  str2->myStrcpy(argv[1]);
  //End Test of find
  */
  
  /*
  //Test of concat
  cout << "***************************************" << endl;
  cout << "*****Test 1 concat*****" << endl;
  cout << "static test" << endl;
  cout << "output should be the command line input + ABCD" << endl;
  str1.concat("ABCD");
  str1.myDisplay();
  cout << endl;
  cout << "*****Test 2  concat*****" << endl;
  cout << "dynamic test" << endl;
  cout << "output should be the command line input + ABCD" << endl;
  str2->concat("ABCD");
  str2->myDisplay();
  cout << endl;
  cout << "***************************************" << endl;
  str1.myStrcpy(argv[1]); //reverts back to original strings
  str2->myStrcpy(argv[1]);
  //End Test of concat
  */
 
  delete str2;
  return 0;  
}
   
  
