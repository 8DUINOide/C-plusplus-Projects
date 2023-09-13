//==================================================================================================
//Filename : PAZ_Using cstdlib and ctime library in C++.cpp
//Author : Al Francis B. Paz
//Email : afpaz@gbox.adnu.edu.ph
//Assignment Number : 3
//Description : Using cstdlib and ctime library in C++, this Program will display the number of days your avatar will survive and also the transitions.
//Last modified: September 22, 2022
//==================================================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

//Variables
    int g = 0; 
    int random_Int  = 0;
    int previous_random_Int = 0;
    int H;
    int A;
    int d;
    int alive;
    char Y_or_N;

//Write a program that accepts from user, values for health and armor.  Your program will display the number of days your avatar will survive and also the transitions.

    while(g<1){
        
        cout<<"Welcome to Volatile Avatar! \n";
        cout<<"Please enter the initial health: ";
        cin>>H;
        cout<<"Please enter the initial armor: ";
        cin>>A;
        cout<<" Avatar's Initial Health("<<H<<") & Armor("<<A<<")."<<endl;
        cout<<"\nTransitions: ";
        
        srand(time(0));
        alive = 0;
        
        for (d=-1; alive<1;d++){
            if (H <= 0 || A <= 0){
                alive++;
            }
            else{
                random_Int = 1 + (rand()%4);
                if(random_Int !=previous_random_Int){
                    switch(random_Int ){
                        case 1: 
                        H-=20; A+=10;
                        cout<<"-> Firebender["<<H<<"/"<<A<<"]";
                        previous_random_Int=random_Int ;
                        break;
                         case 2: 
                        H+=10; A-=15;
                        cout<<"-> Waterbender["<<H<<"/"<<A<<"]";
                       previous_random_Int=random_Int ;
                        break;
                         case 3: 
                        H-=5; A+=5;
                        cout<<"-> Earthbender["<<H<<"/"<<A<<"]";
                       previous_random_Int=random_Int ;
                        break;
                         case 4: 
                        H+=3; A+=2;
                        cout<<"-> Airbender["<<H<<"/"<<A<<"] " ;
                       previous_random_Int=random_Int ;
                        break;
                    }
                }
                else{
                    d--;
                }
            }
            }

//Design an algorithm that will compute the maximum number of days you will survive. The successive moves can also be pseudorandomly generated as long as it does not stay on the same element the next day. 
          
            cout<<"\n\nAvatar survived for "<<d<<" days. \n";
            cout<<"\n Continue[Y/N]? ";
            cin>>Y_or_N;
            switch(Y_or_N){
                case 'Y': case 'y':
                cout<<endl;
                break;
                case 'N': case 'n':
                g++;
                break;
            }
            }
        }
    



