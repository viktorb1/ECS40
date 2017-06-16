#ifndef _INDEX_PAGER_H
#define _INDEX_PAGER_H

#include "pager.h"
#include <map>

class IndexPager : public Pager
{
  map<string, int> words;
  multimap<int, int> lines;
  void readWordsToMaps(istream &is);
  void addToMaps(const string &word, int line, int &wordKey);
  void readMapsToVector();
  void addNumbers(string &line, int key);

public:
  virtual void read(istream &is);


}; // class IndexPager


#endif