/*
 Name: Dominic MacIsaac
 Class: CPSC 122, Section 1
 Date Submitted: 1/28/2021
 Assignment: Project 1                                              
 Description: Output amount of prime numbers indicated by user onto a new file. The numbers are written in amount of columns specified by user. 
 Notes:
*/


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

void userInputNums(int& amtNums, int& cols);
bool isPrime(int num);
void printPrimes(int num, int& ct, int cols, ofstream& fout);

int main(int argc, char* argv[])
{
 ofstream fout;
 int amtNums = 0, cols = 0, totalPrimes = 0, ct = 0, currentNum = 3;
	
	
 if(argc != 2)
 {
  cout << "Too many command line parameters entered" << endl;
  exit(EXIT_FAILURE);
 }
 fout.open(argv[1]);
 
 
 userInputNums(amtNums, cols);
 
 
 if(amtNums >= 1) //Adds 2 as a prime number so that it can later skip even numbers, saving computing space
 {
  printPrimes(2, ct, cols, fout);
  totalPrimes++;
 }
 while(totalPrimes < amtNums)
 {
  if(isPrime(currentNum))
  {
   totalPrimes++;
   printPrimes(currentNum, ct, cols, fout);
  }
  currentNum = currentNum + 2;
 }
	
	
 return 0;
}

/*
Description: Asks the user to input amount of primes generated and how many columns to display them
Input: pass by reference amount of primes and amount of columns
Returns: nothing
*/
void userInputNums(int& nums, int& cols)
{

 cout << "Please enter how many prime numbers you would like to generate" << endl;
 cin >> nums;
	
 cout << "Please enter how many columns you would like to display" << endl;
 cin >> cols;

 return;
}

/*
Description: Determines whether input integer is prime
Input: integer whose primality is to be judged
Returns: true if num is prime, false otherwise
*/

bool isPrime(int num)
{
 for(int currentDiv = 3; currentDiv < num; currentDiv = currentDiv + 2)
 {	
  if(num % currentDiv == 0)
  {
   return 0;
  }
 }
 return 1;
}

/*
Description: Prints prime number to output file in amount of columns specified by user
Input: number to be output, current column, total amount of columns, output stream
Returns: nothing
*/
void printPrimes(int num, int& ct, int cols, ofstream& fout)
{
 fout << num << '\t';
 if (ct % cols == cols - 1)
 {
  fout << endl;
 }
 ct++;
}
