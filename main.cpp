/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include "dictionary.h"
#include <iomanip>
using namespace std;


int main ()
{
  Dictionary dict;
  dict.readWord ("words.txt");
  cout << "Welcome to the Dictionary Program\n";
  cout << "This program compares words of a dictionary and calculates how Hard it is to read a book\n";
  cout << setprecision(2);  
  cout << fixed;

  int input = 0;
  float average = 0.0;
  int result = 0;
  int countSample = 0;
  cout <<"----------------------------------------------------------------------------"<< endl << " Menu" << endl;
  cout <<"----------------------------------------------------------------------------"<< endl;
  cout << "Input 0 to quite" << "\n" <<
    "Input 1 to read and Calculate sample 1" << "\n" <<
    "Input 2 to read and Calculate sample 2" << "\n" <<
    "Input 3 to read and Calculate sample 3" << "\n" <<
    "Input 4 to read and Calculate sample 4" << "\n" <<
    "Input 5 to read and Calculate sample 5" << endl;
  cin >> input;
  cout << "----------------------------------------------------------------------------" << endl;

  // while loop to do what is inputed in the menu
  while (input != 0)
    {
      switch (input)
	{
	case 1:
	  // asking for input from the user
	  cout <<"----------------------------------------------------------------------------"<< endl << "Sample 1" << endl;
	  cout <<"----------------------------------------------------------------------------"<< endl;
	  countSample = dict.readSample ("sample1.txt");
	  result = dict.searcher (countSample);
	  average = result * 1.0 / countSample;
	  cout << "The estimated reading level of text file found is:  " << average << endl;
	  break;
	case 2:
	  // asking for input from the user
	  cout <<"----------------------------------------------------------------------------"<< endl << " Sample 2" << endl;
	  cout <<"----------------------------------------------------------------------------"<< endl;
	  countSample = dict.readSample ("sample2.txt");
	  result = dict.searcher (countSample);
	  average = result / countSample;
	  cout << "The estimated reading level of text file found is:  " << average << endl;
	  cout <<"----------------------------------------------------------------------------"<< endl;
	  break;
	case 3:
	  // asking for input from the user
	  cout << "----------------------------------------------------------------------------"<< endl << " Sample 3" << endl;
	  cout <<"----------------------------------------------------------------------------"<< endl;
	  countSample = dict.readSample ("sample3.txt");
	  result = dict.searcher (countSample);
	  average = result / countSample;
	  cout << "The estimated reading level of text file found is:  " << average << endl;
	  cout <<"----------------------------------------------------------------------------"<< endl;
	  break;

	case 4:
	  // asking for input from the user
	  cout <<"----------------------------------------------------------------------------"<< endl << " Sample 4" << endl;
	  cout <<"----------------------------------------------------------------------------"<< endl;
	  countSample = dict.readSample ("sample4.txt");
	  result = dict.searcher (countSample);
	  average = result / countSample;
	  cout << "The estimated reading level of text file found is:  " << average << endl;
	  cout <<"----------------------------------------------------------------------------"<< endl;
	  break;

	case 5:
	  // asking for input from the user
	  cout << "----------------------------------------------------------------------------"<< endl << " Sample 5" << endl;
	  cout <<"----------------------------------------------------------------------------"<< endl;
	  countSample = dict.readSample ("sample5.txt");
	  result = dict.searcher (countSample);
	  average = result / countSample;
	  cout << "The estimated reading level of text file found is:  " << average << endl;
	  cout <<"----------------------------------------------------------------------------"<< endl;
	  break;


	default:
	  // if not any of the asked input print out default
	  cout << "Your input is not right, Pick a choice BETWEEN 0-4" << endl
	    << endl;
	}
      cout << "----------------------------------------------------------------------------"<< endl << " Menu" << endl;
      cout <<"----------------------------------------------------------------------------"<< endl;
      cout << "Input 0 to quite" << "\n" <<
	    "Input 1 to read and Calculate sample 1" << "\n" <<
	    "Input 2 to read and Calculate sample 2" << "\n" <<
	    "Input 3 to read and Calculate sample 3" << "\n" <<
	    "Input 4 to read and Calculate sample 4" << "\n" <<
	    "Input 5 to read and Calculate sample 5" << endl;
      cin >> input;
      cout <<"----------------------------------------------------------------------------"<< endl;
    }
// if input is zero do this
  cout << "You just quited" << "\n" << "Thank You" << endl;

  return 0;
}
