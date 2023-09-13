//==========================================================================================================
//Filename : PAZ_Using the cmath library in C++.cpp
//Author : Al Francis B. Paz
//Email : afpaz@gbox.adnu.edu.ph
//Assignment Number : 2
//Description : Using the cmath library in C++, to Calculate the release angles and speeds for shooting a basketball into the rim.
//Last modified: August 30, 2022
//==========================================================================================================
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
int main()
{
    //Variables

    float distance;
    float initial_ball_speed;
    float height;
    float g=9.8;
    float optimal_angle;
    float smallest_angle;
    float largest_angle;
    float maximum_height;
    float optimal_angle_deg;

//Prompt the user for the following inputs:

    cout<<"Enter the distance of the shooting hand of the robot from the center of the basketball rim (in meters): \n";
    cin>>distance; //user input
    cout<<"Enter the initial ball speed (in meters/second): \n";
    cin>>initial_ball_speed; //user input
    cout<<"Enter the height of the ceiling (in meters): \n";
    cin>>height; //user input

//compute and display the optimal angle (in degrees) for releasing the ball, such that it shoots at the center of the rim
     optimal_angle= (asin(g* distance/(initial_ball_speed*initial_ball_speed))/2)*180.0/3.14159265359;
    cout<<"The optimal angle to launch the ball is "<<fixed<<setprecision(3)<< optimal_angle <<" degrees."<<endl;

//compute and display the smallest angle (in degrees) that will still make the ball go into the rim
     smallest_angle=(asin(g*(distance-(0.45/2))/(initial_ball_speed*initial_ball_speed))/2)*180/3.14159265359;
    cout<<"Smallest angle to make the shot is "<<fixed<<setprecision(3)<<smallest_angle<<" degrees."<<endl;

//compute and display the largest angle (in degrees) that will still make the ball go into the rim
    largest_angle=(asin(g*(distance+(0.45/2))/(initial_ball_speed*initial_ball_speed))/2)*180/3.14159265359;
    cout<<"Largest angle to make the shot is "<<fixed<<setprecision(3)<<largest_angle<<" degrees."<<endl;

//compute and display the maximum height (in meters)
    optimal_angle_deg=optimal_angle*3.14159265359/180.0;
     maximum_height=(pow(initial_ball_speed,2.0)*pow(sin(optimal_angle_deg),2.0))/(2*g);
    cout<<"The basketball will reach a maximum height of "<<fixed<<setprecision(3)<<maximum_height<<" meters"<<endl;

//determine whether or not the basketball will hit the ceiling when thrown at the optimal angle
    if(maximum_height<height)
    {
        cout<<"The basketball will not hit the ceiling.\n";
    }
    else
    {
        cout<<"The basketball will hit the ceiling.\n";
    }
}
