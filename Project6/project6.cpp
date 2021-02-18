/*
Name: Dominic MacIsaac
Class: CPSC 122, Section 1
Date Submitted: 2/13/2021
Assignment: Project 6                                             
Description: Generates a key, encrypts a plain text, and decrypts a cipher text using the Affine Cipher
Notes: 
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>


using namespace std;

void fileControl (string keyFile, string fileIn, string fileOut, int mode);
void fileOpen(fstream& file, string name, char mode);
void keyGen(string);
char encrypt(char ch, int alpha, int beta);
char decrypt(char ch, int alpha, int beta, int[]);

int main(int argc, char* argv[])
{
  int mode = atoi(argv[1]);
  
  if(mode == 0)
  {
    keyGen(argv[2]);
  }
  if(mode == 1)
  {
    fileControl(argv[2], argv[3], argv[4], 1);
  }
  if(mode == 2)
  {
    fileControl(argv[2], argv[3], argv[4], 2);
  }

  return 0;
}

/*
Description: invokes fileOpen on all files.  closes all files.  Reads key file. Reads the input file and either invokes encrypt or decrypt,  depending on the value of mode.  Writes to the output file. 
Input: names of key file, input file and output file. mode value of 1 or 2
Output: writes to the output file
*/
void fileControl (string keyFile, string fileIn, string fileOut, int mode)
{
  fstream finKey, fin, fout;
  int alpha = 0, beta = 0;
  int MI[] = {0,1,0,9,0,21,0,15,0,0,0,19,0,0,0,0,0,23,0,11,0,0,0,0,0,0};
  char temp = ' ';
  
  fileOpen(finKey, keyFile, 'r');
  finKey >> alpha;
  finKey >> beta;
  finKey.close();
  
  fileOpen(fin, fileIn, 'r');
  fileOpen(fout, fileOut, 'w');
  
  while(fin.peek() != EOF)
  {
    temp = fin.get();
    temp = toupper(temp);
    if(temp > 64 && temp < 91) // only decrypt if it is a letter
    {
    	if(mode == 1)
    	{
        fout.put(encrypt(temp, alpha, beta));
      }
      if(mode == 2)
    	{
        fout.put(decrypt(temp, alpha, beta, MI));
      }
    }
    else
    {
      fout.put(temp);
    }
  }
  
  fin.close();
  fout.close();
  
  return;
}
    
/*
Description: function opens a file
Input: file stream object reference, name of the file, mode of open
Output: input file name is opened. 
*/
void fileOpen(fstream& file, string name, char mode)
{
  string fileType;

  if (mode == 'r')
    fileType = "input";
  if (mode == 'w')
    fileType = "output";

  if (mode == 'r')
    file.open(name, ios::in);  //available thorugh fstream
  if (mode == 'w')
    file.open(name, ios::out);  //available through fstream;
 
  if (file.fail()) //error condition 
  {
    cout << "Error opening " << fileType << " file" << endl; 
    exit(EXIT_FAILURE);
  }
}

/*
Description: Randomly generates and stores alpha and beta values.
The alpha value is randomly drawn from the the set:  {1,3,5,7,11, 17,19,25}
The beta value is randomly drawn from the range: [1..25]  
Output: alpha and beta values on subsequent lines of keyFile
*/

void keyGen(string keyFile)
{
  int alpha = 0, beta = 0;
  int alphaVals[] = {1,3,4,7,11,17,19,25};
  fstream keyF;
  
  fileOpen(keyF, keyFile, 'w');
  
  srand(time(NULL)); //seed the random number
  alpha = alphaVals[rand() % 8];
  srand(time(NULL)); 
  beta = rand() % 25 + 1;

  keyF << alpha << endl << beta;
  
  return;
}

/*
Description: Encrypts an upper case alphabetic character using the affine cipher
Input: upper case alphabetic character, valid alpha and beta values
Returns: encrypted version of ch
*/
char encrypt(char ch, int alpha, int beta)
{
  return static_cast<char> (((alpha*(ch-65) + beta) % 26)+65); 
}

/*
Description: Decrypts an upper case alphabetic character using the affine cipher
Input: upper case alphabetic character, valid alpha and beta values. Dictionary of multiplicative inverse values mod 26
Returns: decrypted version of input
*/
char decrypt(char ch, int alpha, int beta, int MI[])
{
  return static_cast<char>(((MI[alpha]*(ch-65) - MI[alpha] * beta + 650) % 26) + 65);
}
