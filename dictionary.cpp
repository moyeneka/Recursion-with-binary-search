#include "dictionary.h"
#include <algorithm>
#include <string>
#include <cctype>
#include <array>
Dictionary::Dictionary ()
{
  count = 0;
  // Initialize word array
  for (int i = 0; i < NUM_WORDS; i++)
    {
      word[i] = "";
      rank[i] = 0;
      sampleGetter[i] = "";
    }
}

Dictionary::Dictionary (const Dictionary & dict)
{
     count = dict.count;
  // Initialize word array
  for (int i = 0; i < NUM_WORDS; i++)
    {
      word[i] = dict.word[i];
      rank[i] = dict. rank[i];
      sampleGetter[i] = dict.sampleGetter[i];
    }
}

Dictionary::~Dictionary ()
{
}

//----------------------------------------------
void Dictionary::readWord (string name)
{
  // Open input file
  ifstream din;
  din.open (name.c_str ());
  if (din.fail ())
    cout << "could not open sample.txt\n";
  // Read strings into word array
  for (count = 0; count < NUM_WORDS && !din.eof (); count++)
    {
      din >> rank[count] >> word[count];
      //  cout <<rank[count]<< word[count]<<endl;
    }
  din.close ();
}


//----------------------------------------------
int Dictionary::readSample (string sampleName)
{
  int count_sample = 0;
  string tmp = "";
  string out = "";
  // Open input file
  ifstream file;
  file.open (sampleName.c_str ());
  if (file.fail ())
    cout << "could not open sample.txt\n";
  for (count = 0; count < NUM_WORDS && !file.eof (); count++)
    {
      file >> tmp;
      sampleGetter[count] = Tolower (tmp);
      count_sample++;
    }
  file.close ();
  cout << "Total count of word in this sample file is " << count_sample << endl;

  return count_sample;
}


int Dictionary::binarySearch (string word[], string searchValue,int low, int high)
{
  int i = 0;
  int mid = (low + high) / 2;
  if (low > high)
    return 1001;

  else if (searchValue.compare (word[mid]) == 0)
    return rank[mid];

  else if (word[mid].compare (searchValue) > 0)
    {
     return binarySearch (word, searchValue, low, mid - 1);
    }
  else if (word[mid].compare (searchValue) < 0)
    {
     return binarySearch (word, searchValue, mid + 1, high);
    }

}

string Dictionary::Tolower (string search)
{
  string out = "";
  string tmp = search;
  for (int i = 0; i < tmp.length (); i++)
    {
      tmp[i] = tolower (tmp[i]);
     if (tmp[i] >= 'a' && tmp[i] <= 'z')
	    out = out + tmp[i];
    }

  return out;
}

int Dictionary::searcher (int count_it)
{

  int count_sample = count_it;
  int total_count = 0;
  for (int i = 0; i < count_sample; i++)
    {
      int result = binarySearch (word, sampleGetter[i], 0, NUM_WORDS - 1);
	  total_count += result;
    }
  cout << "Total sum of ranks found in this sample text file is " << total_count << endl;
  return total_count;

}



