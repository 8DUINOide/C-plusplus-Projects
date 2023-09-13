//==================================================================================================
//Filename : PAZ_Object Oriented Programming in C++(vectors and class functions).cpp
//Author : Al Francis B. Paz
//Email : afpaz@gbox.adnu.edu.ph
//Assignment Number : 2
/*Description : Object Oriented Programming in C++(vectors and class functions), A C++ program that the print class functions was modified. A program that keeps track of a meal. In this case, a meal can be thought of as all of the drinks, appetizers, courses, and desserts served.  Each items in the meal category will be printed on the screen based on the input statements inside the main function.
*/
//Last modified: February 22, 2022
//==================================================================================================

#include <iostream>
#include <vector>
using namespace std;


class Meal {
  public:
    void AddDrink(string drink) {
      drinks.push_back(drink);
    }
    void PrintDrinks() {
      if (drinks.size() == 0) {
        cout << "Drinks: None" << endl;
      } else {
        cout << "Drinks: ";
        for (int i = 0; i < drinks.size(); i++) {
          cout << drinks[i];
          if (i == drinks.size() - 1) {
            cout << endl;
          } else if (i == drinks.size() - 2) {
            cout << " and ";
          } else {
            cout << ", ";
          }
        }
      }
    }
    void AddAppetizer(string app) {
      appetizers.push_back(app);
    }
    void PrintAppetizers() {
      if (appetizers.size() == 0) {
        cout << "Appetizers: None" << endl;
      } else {
        cout << "Appetizers: ";
        for (int i = 0; i < appetizers.size(); i++) {
          cout << appetizers[i];
          if (i == appetizers.size() - 1) {
            cout << endl;
          } else if (i == appetizers.size() - 2) {
            cout << ", and ";
          } else {
            cout << ", ";
          }
        }
      }
    }
    void AddMainCourse(string mc) {
      main_courses.push_back(mc);
    }
    void PrintMainCourses() {
      if (main_courses.size() == 0) {
        cout << "Main Course: None" << endl;
      } else if (main_courses.size() == 1) {
        cout << "Main Course: " << main_courses[0] << endl;
      } else {
        cout << "Main Courses: ";
        for (int i = 0; i < main_courses.size(); i++) {
          cout << main_courses[i];
          if (i == main_courses.size() - 1) {
            cout << endl;
          } else if (i == main_courses.size() - 2) {
            cout << " and ";
          } else {
            cout << ", ";
          }
        }
      }
    }
    void AddDessert(string dessert) {
      desserts.push_back(dessert);
    }
    void PrintDesserts() {
      if (desserts.size() == 0) {
        cout << "Dessert(s): None" << endl;
      } else if (desserts.size() == 1) {
        cout << "Dessert: " << desserts[0] << endl;
      } else {
        cout << "Desserts: ";
        for (int i = 0; i < desserts.size(); i++) {
          cout << desserts[i];
          if (i == desserts.size() - 1) {
            cout << endl;
          } else if (i == desserts.size() - 2) {
            cout << ", and ";
          } else {
            cout << ", ";
          }
        }
      }
    }

  private:
    vector<string> drinks;
    vector<string> appetizers;
    vector<string> main_courses;
    vector<string> desserts;
};



int main() {

  Meal dinner;
  dinner.AddDrink("pomelo juice");
  dinner.AddDrink("cabernet sauvignon");
  dinner.PrintDrinks();
  dinner.AddAppetizer("egg rolls");
  dinner.AddAppetizer("croccantino di foie gras");
  dinner.AddAppetizer("cheese sticks");
  dinner.AddAppetizer("buffalo wings");
  dinner.PrintAppetizers();
  dinner.AddMainCourse("medium-rare wagyu beef steak");
  dinner.PrintMainCourses();
  dinner.PrintDesserts();

  return 0;
}

