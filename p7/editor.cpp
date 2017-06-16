#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


void readFile(vector<string> &source, ifstream &sourcefp);
void editFile(vector<string> &source, ifstream &commandsfp);
void insert(vector<string> &source, ifstream &sourcefp);
void replace(vector<string> &source, ifstream &sourcefp);
void find(vector<string> &source, ifstream &sourcefp);
void deleteLines(vector<string> &source, ifstream &sourcefp);
void eraseWords(vector<string> &source, ifstream &sourcefp);
void copyAndPaste(vector<string> &source, ifstream &sourcefp);
void move(vector<string> &source, ifstream &sourcefp);
void writeToFile(vector<string> &source, ofstream &output);


int main(int argc, char **argv)
{
  if (argc == 4)
  {
    vector<string> source;
    
    ifstream sourcefp(argv[1]);
    readFile(source, sourcefp);

    ifstream commandsfp(argv[2]);
    editFile(source, commandsfp);

    ofstream outputfp(argv[3]);
    writeToFile(source, outputfp);
  } // if 3 file names were given

  return 0;
} // main()


void readFile(vector<string> &source, ifstream &sourcefp)
{
  string line;

  while (getline(sourcefp, line))
    source.push_back(line);
} // readSource()


void editFile(vector<string> &source, ifstream &sourcefp)
{
  char opt;

  while (sourcefp >> opt)
  {
    if(opt == 'I')
      insert(source, sourcefp);
    else // replace
      if(opt == 'R')
        replace(source, sourcefp);
    else // find
      if(opt == 'F')
        find(source, sourcefp);
    else // delete line
      if(opt == 'D')
        deleteLines(source, sourcefp);
    else // erase word
      if(opt == 'E')
        eraseWords(source, sourcefp);
    else // copy lines
      if(opt == 'C')
        copyAndPaste(source, sourcefp);
    else // move lines
      if(opt == 'M')
        move(source, sourcefp);
  } // while another line of commands exist
} //applyCommands()


void insert(vector<string> &source, ifstream &sourcefp)
{
  int lineNumber, position;
  string insert;
  sourcefp >> lineNumber >> position;
  getline(sourcefp, insert);
  insert = insert.substr(1);
  vector<string>::iterator itr = source.begin() + lineNumber;
  itr->insert(position, insert);
} // insert()


void replace(vector<string> &source, ifstream &sourcefp)
{
  int lineNumber, start, end;
  string replacement;
  sourcefp >> lineNumber >> start >> end;
  getline(sourcefp, replacement);
  replacement = replacement.substr(1);
  vector<string>::iterator itr = source.begin() + lineNumber;
  itr->replace(start, end - start, replacement);
} // replace()


void find(vector<string> &source, ifstream &sourcefp)
{
  string strToFind;
  getline(sourcefp, strToFind);
  strToFind = strToFind.substr(1);
  vector<string>::iterator itr;
  cout << strToFind << ' ';

  for(itr = source.begin(); itr != source.end(); ++itr)
    if(itr->find(strToFind) != string::npos)
      cout << itr - source.begin() << ' ';

  cout << endl;
} // find()


void deleteLines(vector<string> &source, ifstream &sourcefp)
{
  int startLine, endLine;
  sourcefp >> startLine >> endLine;
  vector<string>::iterator itr = source.begin();
  source.erase(itr + startLine, itr + endLine + 1);
} // deleteLine()


void eraseWords(vector<string> &source, ifstream &sourcefp)
{
  string wordToErase;
  getline(sourcefp, wordToErase);
  wordToErase = wordToErase.substr(1);
  vector<string>::iterator itr;
  unsigned int pos;

  for(itr = source.begin(); itr != source.end(); ++itr)
  {
    if (*itr == wordToErase)
        source.erase(itr);
    else // the wordToErase did not match the entire line
      if(itr->find(wordToErase) != string::npos)
      {
        pos = itr->find(wordToErase);
        itr->erase(pos, wordToErase.length());
      } // if the word is found in the line
  } // iterates through the lines from the file
} // eraseWord()


void copyAndPaste(vector<string> &source, ifstream &sourcefp)
{
  int startLine, endLine, destination;
  sourcefp >> startLine >> endLine >> destination;
  vector<string>::iterator start = source.begin() + startLine;
  vector<string>::iterator end = source.begin() + endLine + 1;
  vector<string>::iterator placeToInsert = source.begin() + destination;
  source.insert(placeToInsert, start, end);
} // copy()


void move(vector<string> &source, ifstream &sourcefp)
{
  int startLine, endLine, destination;
  sourcefp >> startLine >> endLine >> destination;
  vector<string>::iterator start = source.begin() + startLine;
  vector<string>::iterator end = source.begin() + endLine + 1;
  vector<string>::iterator placeToInsert = source.begin() + destination;

  if (placeToInsert < start || placeToInsert > end)
  {
    source.insert(placeToInsert, start, end);
    start = source.begin() + startLine;
    end = source.begin() + endLine + 1;
    placeToInsert = source.begin() + destination;    
    
    if (placeToInsert > start)
      source.erase(start, end);
    else // line was inserted before start (so start moves up)
      source.erase(start + (end-start) , end + (end-start));
  } // if they are not trying to move it into the same place
} // move()


void writeToFile(vector<string> &source, ofstream &output)
{
  vector<string>::iterator it;

  for (it = source.begin(); it != source.end(); ++it)
    output << *it << endl;
} // writeFile

