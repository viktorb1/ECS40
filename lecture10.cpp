#include <iostream>

int main()
{

}

// const
// name mangling
// references
// constructors

class Person {
  char name[80];
  int age;

public:
  void setAge(int ag);
  int getAge() const;
  void setName(const char *n);
  char* getName();
}

int Person::getAge() const
{
  return age;
}

cout << Don.getAge();

const char *Person::getName() const
{
  return name;
}

char *ptr = Don.getName(); //compiler won't let this happen, must be const char*





// NAME MANGLING

int foo(int a, float b, char c, int *d) => @foo$qifcpi




// REFERENCE VARIABLES

int n = 7;
int &ref = n;
ref = 19;
cout << n; // 19

foo2(n);

foo2(int &num) {
  *num = 33;
}

cout << n; // 33




// CONSTRUCTORS
1. default
2. copy

class Person {
  char name [80];
  int age;
public:
  Person();
  Person(const Person &P) //has to be a reference for copy
}

Person::Person():age(0) //default 
{
  name[0] = '\0';

}

