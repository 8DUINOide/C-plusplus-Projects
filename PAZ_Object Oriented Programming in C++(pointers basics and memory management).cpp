//======================================================================================
//Filename : PAZ_Object Oriented Programming in C++(pointers basics and memory management).cpp
//Author : Al Francis B. Paz
//Email : afpaz@gbox.adnu.edu.ph
//Laboratory Exercise Number:1
/*Description : Object Oriented Programming in C++(pointers basics and memory management) , A C++ program to prompt a user to enter information regarding a Character in the show
and print out the data.*/
//Last modified: January 26, 2023
//======================================================================================

#include <iostream>
#include <cstring>
using namespace std;

/*1. Create a data type for Character using a struct. Character information should
minimally include firstName, lastName, houseName, and the actorName who
played that role. Use the char * to represent the string fields.*/

struct Character {
  char *firstName;
  char *lastName;
  char *houseName;
  char *actorName;
};

/*2. Create a function, ReadCharacter(), which accepts a pointer to a Character as an
argument to allow for firstName, lastName, houseName, and actorName to be
entered from the keyboard within the function and stored as the input parameterâ€™s data.*/

void ReadCharacter(Character *c) {
  string fname, lname, hname, aname;
  cout<<"Enter first name: ";
  cin>>fname;
  c->firstName = new char[fname.length() + 1];
  strcpy(c->firstName, fname.c_str());

  cout << "Enter last name: ";
 cin>>lname;
  c->lastName = new char[lname.length() + 1];
  strcpy(c->lastName, lname.c_str());

  cout<<"Enter house name: "; 
 cin>>hname;
  c->houseName = new char[hname.length() + 1];
  strcpy(c->houseName, hname.c_str());

  cout << "Enter actor name: ";
  cin>>aname;
    cout << "----------------------------------------\n";
  c->actorName = new char[aname.length() + 1];
  strcpy(c->actorName, aname.c_str());
}

/*3. Create a function Print() to print out all the data and take Character struct as a
parameter.*/

void Print(Character c) {
  cout << "First name: " << c.firstName << endl;
  cout << "Last name: " << c.lastName << endl;
  cout << "House name: " << c.houseName << endl;
  cout << "Actor name: " << c.actorName << endl;
}

/*4. In main(), create an array of pointers to Character to store arbitrary number of
characters as desired by the user. You may want to prompt the user at the beginning of
the program on how many characters does he/she wants to encode. Allocate each
Character, call ReadCharacter() for each Character and then Print() each
Character. When finished, do not forget to delete() the memory of each
Character allocated.*/

int main() {
  int numCharacters;
  cout<< "How many characters do you want to encode? ";
  cin >> numCharacters;

  Character **characters = new Character*[numCharacters];
  for (int i = 0; i < numCharacters; i++) {
    characters[i] = new Character;
    ReadCharacter(characters[i]);
  }

  for (int i = 0; i < numCharacters; i++) {
    Print(*characters[i]);
    cout << endl;
  }

  for (int i = 0; i < numCharacters; i++) {
    delete[] characters[i]->firstName;
    delete[] characters[i]->lastName;
    delete[] characters[i]->houseName;
delete[] characters[i]->actorName;
delete characters[i];
}
delete[] characters;

return 0;
}