//==================================================================================================
//Filename : PAZ_Object Oriented Programming in C++(Inheritance).cpp
//Author : Al Francis B. Paz
//Email : afpaz@gbox.adnu.edu.ph
//Exercise Number : 2
//Description : Object Oriented Programming in C++(Inheritance), A program that makes use of derived classes and base classes and displays 
//respective statements varying on the functions called in the main function.
//Last modified: March 23, 2023
//==================================================================================================


#include <iostream>
using namespace std;

class Ataman {     
protected:
    string name; 
    
  public:           
    Ataman (string Name) {   
    name=Name;
    }
    
    void dalagan () {
        cout << name << " --> Habulin mo ko!" << endl;
    }
};

class Ikus: public Ataman {
    public:

    Ikus (string name) : Ataman (name) {}
    
    void taram () {
        cout << name << " --> Ngiyaw!" << endl;
    }
};

class Ido: public Ataman {
    public:
    Ido (string name) : Ataman (name) {}
    
    void taram () {
        cout << name << " --> Rawr!" << endl;
    }
};

class Pusakal: public Ikus {
    public:
    Pusakal (string name) : Ikus (name) {}
};


int main() {
  Ataman *ataman;
  Pusakal *pusakal;
  Ido ido(“Togbo”);
 
  ataman = pusakal = new Pusakal("Hi-Ro");
  pusakal -> taram();
  static_cast<Pusakal *>(ataman) -> taram();
  ataman -> dalagan();
  ido.taram();
    
  return 0;
}

