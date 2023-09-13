//======================================================================================
//Filename : PAZ_Using Switch Case in C++.cpp
//Author : Al Francis B. Paz
//Email : afpaz@gbox.adnu.edu.ph
//Exercise Number : 4
//Description : Using Switch Case in C++, to calculate and output how many servings your favorite food should be eaten per day to maintain the persons current weight at the specified activity level. 
//Last modified: September 19, 2022
//======================================================================================
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
//Write a function that computes the calories required for the basal metabolic rate, taking as input a parameter for the persons weight, height, age and gender. 

float age;
char gender;
float weight;
float height;
float BMR;

cout<<"Enter your age: ";
cin>>age;
cout<<"Enter [M] for male and [F] for female: ";
cin>>gender;
cout<<"Enter weight (in kg): ";
cin>>weight;
cout<<"Enter height (in cm): ";
cin>>height;
cout<<"................................................"<<endl;
 
  switch (toupper(gender)) {
  case 'M':
     BMR=(10*weight)+(6.25*height)-(5.0*age)+5;
    cout<<"\n BMR is "<<BMR<<" cal per day"<<endl;
    break;
  case 'F':
    BMR=(10*weight)+(6.25*height)-(5.0*age)-161;
    cout<<"\n BMR is "<<BMR<<" cal per day"<<endl;
    break;
 
  }
//Write another function that computes the calories required for physical activity, taking as input parameters for the intensity, weight, and minutes spent exercising.

int number_of_activity;
int minutes;
float CRPA;

cout<<"................................................"<<endl;
cout<<"Choose a daily physical activity \n";
cout<<"[1] Running 10 mph \n";
cout<<"[2] Running 6 mph \n";
cout<<"[3] Basketball \n";
cout<<"[4] Walking 1 mph \n";
cout<<"Enter the number of the chosen activity: ";
cin>>number_of_activity;

 //CRPA= 0.0385*Intensity*weight*minutes;
switch (number_of_activity) {
  case 1:
    cout<<"Enter minutes spent on Running 10 mph: ";
    cin>>minutes;
    CRPA= 0.0385*17*weight*minutes;
    break;
  case 2:
   cout<<"Enter minutes spent on Running 6 mph: ";
    cin>>minutes;
    CRPA= 0.0385*10*weight*minutes;
    break;
    case 3:
    cout<<"Enter minutes spent on Basketball: ";
    cin>>minutes;
    CRPA= 0.0385*8*weight*minutes;
    break;
  case 4:
   cout<<"Enter minutes spent on Walking 1 mph: ";
    cin>>minutes;
    CRPA= 0.0385*1*weight*minutes;
    break;
 
  }
   
//Write a program, using these functions to calculate and output how many servings your favorite food should be eaten per day to maintain the person's current weight at the specified activity level. The computation should include the energy that is required to digest food.

  int number_of_food;
  float servings;
  float consume_calories;
  float CRDF;
 int kCal;
cout<<"................................................"<<endl;
cout<<"Choose a food to be consumed \n";
cout<<"[1] Doughnuts \n";
cout<<"[2] Rice \n";
cout<<"[3] Spaghetti \n";
cout<<"[4] Chicken \n";
cout<<"Enter the number of the chosen food: ";
cin>>number_of_food;
cout<<"................................................"<<endl;


 //servings=CRPA/TotalCaloriesConsumed
switch (number_of_food) {

  case 1:
  kCal=210;
  CRDF=kCal*0.1;
  consume_calories=round((BMR*CRDF*0.01)+(CRPA*CRDF*0.01))+kCal-(3*CRDF)+BMR+CRPA;
    servings=consume_calories/kCal;
     cout<<"To be just the weigh you are, you would have to consume "<<consume_calories<<" calories or "<< servings <<" servings of your favorite Doughnuts per day. \n";
    break;
  case 2:
   kCal=225;
   CRDF=kCal*0.1;
   consume_calories=round((BMR*CRDF*0.01)+(CRPA*CRDF*0.01))+kCal-(3*CRDF)+BMR+CRPA;
  servings=consume_calories/kCal;
   cout<<"To be just the weigh you are, you would have to consume "<<consume_calories<<" calories or "<< servings <<" servings of your favorite Rice per day. \n";
   break;
    case 3:
     kCal=190;
     CRDF=kCal*0.1;
    consume_calories=round((BMR*CRDF*0.01)+(CRPA*CRDF*0.01))+kCal-(3*CRDF)+BMR+CRPA;
   servings=consume_calories/kCal;
    cout<<"To be just the weigh you are, you would have to consume "<<consume_calories<<" calories or "<<servings<<" servings of your favorite Spaghetti per day. \n";
    break;
  case 4:
   kCal=75;
   CRDF=kCal*0.1;
  consume_calories=round((BMR*CRDF*0.01)+(CRPA*CRDF*0.01))+kCal-(3*CRDF)+BMR+CRPA;
   servings=consume_calories/kCal;
    cout<<"To be just the weigh you are, you would have to consume "<<consume_calories<<" calories or "<< servings <<" servings of your favorite Chicken per day. \n";
    break;
 
  }
}