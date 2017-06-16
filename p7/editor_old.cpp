#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void readSource(vector<string> &source, ifstream &sourcefp);
void writeFile(vector<string> &source, ofstream &output);
void applyCommands(vector<string> &source, ifstream &commandsfp);
void insert(vector<string> &source, istringstream &ss);
void replace(vector<string> &source, istringstream &ss);
void find(vector<string> &source, istringstream &ss);
void deleteLine(vector<string> &source, istringstream &ss);
void eraseWord(vector<string> &source, istringstream &ss);
void copy(vector<string> &source, istringstream &ss);
void move(vector<string> &source, istringstream &ss);


int main(int argc, char **argv)
{
  if (argc == 4)
  {
    vector<string> source;

    ifstream sourcefp(argv[1]);
    ifstream commandsfp(argv[2]);
    ofstream outputfp(argv[3]);

    readSource(source, sourcefp);
    applyCommands(source, commandsfp);
    writeFile(source, outputfp);
  } // if 3 file names were given

  return 0;
} // main()


void readSource(vector<string> &source, ifstream &sourcefp)
{
  string line;

  while (getline(sourcefp, line))
    source.push_back(line);
} // readSource()


void writeFile(vector<string> &source, ofstream &output)
{
  vector<string>::iterator it;

  for (it = source.begin(); it < source.end(); ++it)
    output << *it << endl;
} // writeFile


void applyCommands(vector<string> &source, ifstream &commandsfp)
{
  string command;
  char opt;

  while (getline(commandsfp, command))
  {
    istringstream ss(command);
    ss >> opt;
    
    if(opt == 'I')
      insert(source, ss);
    else
      if(opt == 'R')
        replace(source, ss);
    else
      if(opt == 'F')
        find(source, ss);
    else
      if(opt == 'D')
        deleteLine(source, ss);
    else
      if(opt == 'E')
        eraseWord(source, ss);
    else
      if(opt == 'C')
        copy(source, ss);
    else 
      if(opt == 'M')
        move(source, ss);
  } // while another line of commands exist
} //applyCommands()


void insert(vector<string> &source, istringstream &ss)
{
  int lineNumber, position;
  string insert;
  ss >> lineNumber >> position;
  getline(ss, insert);
  insert = insert.substr(1);
  vector<string>::iterator itr = source.begin() + lineNumber;
  itr->insert(position, insert);
} // insert()


void replace(vector<string> &source, istringstream &ss)
{
  int lineNumber, start, end;
  string replacement;
  ss >> lineNumber >> start >> end;
  getline(ss, replacement);
  replacement = replacement.substr(1);
  vector<string>::iterator itr = source.begin() + lineNumber;
  itr->replace(start, end - start, replacement);
} // replace()


void find(vector<string> &source, istringstream &ss)
{
  string strToFind;
  getline(ss, strToFind);
  strToFind = strToFind.substr(1);
  vector<string>::iterator itr;
  cout << strToFind << ' ';

  for(itr = source.begin(); itr != source.end(); ++itr)
    if(itr->find(strToFind) != string::npos)
      cout << itr - source.begin() << ' ';

  cout << endl;
} // find()


void deleteLine(vector<string> &source, istringstream &ss)
{
  int startLine, endLine;
  ss >> startLine >> endLine;
  vector<string>::iterator itr = source.begin();
  source.erase(itr + startLine, itr + endLine + 1);
} // deleteLine()


void eraseWord(vector<string> &source, istringstream &ss)
{
  string wordToErase;
  getline(ss, wordToErase);
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


void copy(vector<string> &source, istringstream &ss)
{
  int startLine, endLine, destination;
  ss >> startLine >> endLine >> destination;
  vector<string>::iterator start = source.begin() + startLine;
  vector<string>::iterator end = source.begin() + endLine + 1;
  vector<string>::iterator placeToInsert = source.begin() + destination;
  source.insert(placeToInsert, start, end);
} // copy()


void move(vector<string> &source, istringstream &ss)
{
  int startLine, endLine, destination;
  ss >> startLine >> endLine >> destination;
  vector<string>::iterator start = source.begin() + startLine;
  vector<string>::iterator end = source.begin() + endLine + 1;
  vector<string>::iterator placeToInsert = source.begin() + destination;

  if (placeToInsert < start || placeToInsert > end)
  {
    source.insert(placeToInsert, start, end);
    if (placeToInsert > start)
      source.erase(start, end);
    else // line was inserted before start (so start moves up)
      source.erase(start + (end-start) , end + (end-start));
  } // if they are not trying to move it into the same place
} // move()