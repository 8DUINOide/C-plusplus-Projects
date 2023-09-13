//======================================================================================
//Filename : PAZ_Using while loop in C++.cpp
//Author : Al Francis B. Paz
//Email : afpaz@gbox.adnu.edu.ph
//Exercise Number : 2
//Description : Using while loop in C++, to find the temperature of the air affects the speed of the molecules, which in turn affects the speed of sound.
//Last modified: August 25, 2022
//======================================================================================

#include <iostream>
using namespace std;
int main() {

     int degrees_input_begin;
    int degrees_input_end;
    float velocity;

    cout<<"Welcome to Doppler Shift Happens! \n";
     cout<<"Please enter the starting temperature (degrees):  \n";
                 cin>>degrees_input_begin;
            cout<<"Please enter the ending temperature (degrees): \n";
                cin>>degrees_input_end;

        while(degrees_input_begin <=degrees_input_end)
        {
            velocity= 331.3+0.61 * degrees_input_begin;
             cout<<"At " <<degrees_input_begin<< " degrees celcius the velocity of sound is " << velocity<< " m/s "<< endl;
             degrees_input_begin++;
        }
        return 0;
}




