//=============================================================================================================
//Filename : PAZ_Basic cin and cout in C++.cpp
//Author : Al Francis B. Paz
//Email : afpaz@gbox.adnu.edu.ph
//Exercise Number : 1
//Assignment Number : 2
//Description : Basic cin and cout in C++, to display the Cigarettes Sold, Profit, and Nicotine Consumed 
//Last modified: August 23, 2022
//================================================================================================================

#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int nicotine = 12;
    int cigarettes_in_a_pack = 20;
    double profit= 13.5;
    int year= 365;
    float cigarettes_sold_per_day ;
    float cigarette_packs_sold_per_year;
    float profit_per_day;
    float profit_per_year;
    int nicotine_consumed;

    cout<<"On average, how many cigarettes does your store sell in a day? \n";
    cin>>cigarettes_sold_per_day;
    cigarette_packs_sold_per_year= cigarettes_sold_per_day/ cigarettes_in_a_pack*year;
    cout<<"Number of packs sold per year: " <<round(cigarette_packs_sold_per_year) << endl;
    profit_per_day= cigarettes_sold_per_day/cigarettes_in_a_pack*profit;
     cout<<"Profit per day (Php): "<<profit_per_day<<endl;
     profit_per_year= profit_per_day*year;
     cout<<"Profit per year (Php): "<<profit_per_year<<endl;
     nicotine_consumed=cigarettes_sold_per_day*nicotine*year;
     cout<<"Nicotine consumed by customers in a year(mg): "<<nicotine_consumed << endl;
    return 0;
}

