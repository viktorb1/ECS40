#include "indexpager.h"
using namespace std;


void IndexPager::read(istream &is)
{
  string line;
  int lineNumber = 0, wordKey = 0;

  while(getline(is, line))
  {
    string::iterator stritr = line.begin();

    while(stritr != line.end())
    {
      string word;

      while(stritr != line.end() && isalpha(*stritr))
      {
        word += *stritr;
        ++stritr;
      } // while the value is part of the alphabet

      while(stritr != line.end() && !isalpha(*stritr))
        ++stritr;

      if(word.length() != 0)
        addToMaps(word, lineNumber, wordKey);
    } // while the line did not end

    lineNumber++;
  } // while there are still lines left in the file

  readMapsToVector();
} // read()


void IndexPager::addToMaps(const string &word, int lineNumber, int &wordKey)
{
  if(words.count(word) == 0)
  {
    words.insert(map<string, int>::value_type(word, wordKey));
    lines.insert(multimap<int, int>::value_type(wordKey, lineNumber));
    wordKey++;
  } // if the word doesn't exist in the map yet
  else // word exists in map already
  {
    map<string, int>::iterator itr = words.find(word);
    lines.insert(multimap<int, int>::value_type(itr->second, lineNumber));
  } // word exists in map already
} // addToMaps()


void IndexPager::readMapsToVector()
{
  map<string, int>::iterator mapitr = words.begin();

  for(mapitr = words.begin(); mapitr != words.end(); ++mapitr)
  {
    string line;
    line += mapitr->first + " ";
    addNumbers(line, mapitr->second);
    text.push_back(line);
  } // loop through each key/value pair in the map
} // readMapsToVector()


void IndexPager::addNumbers(string &line, int key)
{
  multimap<int, int>::iterator mmapitr = lines.find(key);
  vector<int> lineNumbers;
  vector<int>::iterator itr;

  while(mmapitr->first == key)
  {
    if (lineNumbers.empty() || lineNumbers.back() != mmapitr->second)
      lineNumbers.push_back(mmapitr->second);

    ++mmapitr;
  } // while the wordKeys match

  for(itr = lineNumbers.begin(); itr != lineNumbers.end(); ++itr)
  {
    vector<int>::iterator next = itr + 1;

    if (next != lineNumbers.end() && *itr + 1 == *next)
    {
      line += intToString(*itr);
      line += "-";

      while(next != lineNumbers.end() && *itr + 1 == *next)
        ++itr, ++next;
    } // if the next number is consecutive
    
    line += intToString(*itr);
    line += ", ";
  } // iterates through the newly created vector of line numbers

  line.erase(line.end() - 2, line.end());
  line += ".";
} // addNumbers()