#include <fstream>
#include <iostream>
#include <array>
using namespace std;

const int NUM_WORDS = 1000;
class Dictionary
{

private:
  int count;
  string word[NUM_WORDS];
  int rank[NUM_WORDS];
  string sampleGetter[NUM_WORDS];



public:
    Dictionary ();
    Dictionary (const Dictionary & dict);
   ~Dictionary ();
  void readWord (string file);
  int readSample (string sampleName);
  int binarySearch (string word[], string searchValue, int low, int high);
  string Tolower (string search);
  int searcher (int count_it); 

};
