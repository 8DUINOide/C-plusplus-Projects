//======================================================================================
//Filename : PAZ_Using for loops in C++.cpp
//Author : Al Francis B. Paz
//Email : afpaz@gbox.adnu.edu.ph
//Laboratory Exercise Number : 3
//Description : Using for loops in C++, to print all of the prime numbers between 1 and 1000
//Last modified: August 30, 2022
//======================================================================================

#include <iostream>
using namespace std;
int main() {



   for(int j=2;j<2050;j++){
       int i;
       bool is_prime=true;
       for(i=2;i<=j/2;i++){
           if(j%i==0)
           {
               is_prime = false;
               break;
           }

       }
       if(is_prime){
           cout<<j<<", ";
       }
       }
       return 0;
   }

