
//==================================================================================================
//Filename : PAZ_Making a Memory game using the Object Oriented Programming in C++.cpp
//Author : Al Francis B. Paz
//Email : afpaz@gbox.adnu.edu.ph
//Assignment Number : 1
/*Description : Making a Memory game using the Object Oriented Programming in C++, A C++ program for the game of memory using object-oriented programming.
This program design a class named Card which you will use to create card objects. The
attributes and actions/methods appropriate to the game is that it asks the user to input whether he/she wants to reveal all cards or not in playing the game.
*/
//Last modified: February 14, 2022
//==================================================================================================

#include <iostream>
#include<chrono>
#include<thread>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

const int TOTALCARDS = 100;

class Card {

public:

    string object;
    bool revealed;
    Card(string object) : object(object), revealed(false) {}

void reveal() {
    revealed = true;
    }

};

class MemoryGame {
private:
    vector<Card> cards;
    int paired;

public:
    int User= 0, Pixel= 0, points = User+ Pixel;
    int card1, card2;
    string name;
    string player;
    char response;
    MemoryGame() : paired(0) {
        //naming cards
        vector<string> objects = {"dog","cat","bird","fish","tree","flower","book","phone","computer","car","plane","train",
        "music","sport","art","food","sun","moon","star","sky","ocean","mountain","river","lake","forest","desert","island",
        "beach","house","apartment","school","hospital","bank","park","museum","library","restaurant","cafe","store","market",
        "gas station","theater","concert","opera","dance","painting","sculpture","photography","fashion","jewelry"};

        //duplicating and shuffling the string objects
        srand(time(0));
        for (int i = 0; i < TOTALCARDS/ 2; ++i) {
                string object = objects[i];
                cards.push_back(Card(object));
                cards.push_back(Card(object));
                }
        for (int i = TOTALCARDS- 1; i > 0; --i) {
                int j = rand() % (i + 1);
                swap(cards[i], cards[j]);
                }
 }
 void display () { //displaying the board/grid

     int TOTALCARDS= 100;

     cout << "....................................\n";
     for (int i = 1; i <= 10; i++) {
            for (int j = 1; j <= 10; j++) {
                int sheet = (i - 1) * 10 + j;
                int sheet2 = (i - 1) * 10 + j;
                if (cards[sheet-1].object=="x") {
                    cout << "x" << "\t";
                } else if (cards[sheet2-1].object=="x") {
                    cout << "x" << "\t";
                } else cout << sheet << "\t";
                }



     cout << endl;
     }
     cout << "....................................\n";
 }

void display2 (int card1,int card2) { //displaying the board/grid

     int TOTALCARDS= 100;

     cout << "....................................\n";
     for (int i = 1; i <= 10; i++) {
            for (int j = 1; j <= 10; j++) {
                int sheet = (i - 1) * 10 + j;
                int sheet2 = (i - 1) * 10 + j;
                if (sheet==card1){
                    cout << cards[sheet-1].object<<"\t";
                } else if (sheet==card2){
                    cout << cards[sheet2-1].object<<"\t";
                } else if (sheet!=card1){
                   cout << sheet << "\t";
                }  else if (sheet2!=card2){
                   cout << sheet2 << "\t";
                }
     }

     cout << endl;
     }
     cout << "....................................\n";
 }

  void revelation() { //displaying the cheat sheet

     int TOTALCARDS= 100;

     cout << "....................................\n ";
     int i,j;
     for ( i = 1; i <= 20; i++) {
            for ( j = 1; j <= 5; j++) {
                int sheet= (i - 1) * 5 + j;
                cout <<sheet <<setfill('-')<<setw(12)<<cards[sheet-1].object<<"\t";

     }

     cout << endl;
     }
     cout << "....................................\n";

     cout << "Press any key to continue. ";
     cin>>response;

 }


 void start() { //game function
     system("cls");
     cout << "\nWelcome to the memory game!\n\nYou will be matched with a computer in order to play this game.\n";
     cout << "\nPlease enter your name: ";
     cin >> name;
     cout << "\n\n" << name << ", you are extremely lucky! The computer wants you to play first. o_o\n\n\nComputer: Hi, I am Pixel.";
     cout << " Let us have a nice memory game!  ^_^ Good luck! >_<\n\n\n";

     player="human";


    while (true) {

        cout << "\nIf you want to reveal all the pairs, type 'X'. \n";
        cout << "However, if you do want to enjoy the game, press any letter to continue: ";
        cin>>response;

        while (response=='X'|| response=='x') {
            revelation();
        }





        while (true) { // user interface
            system("cls");
            cout << "\n\nTry to find pairs of matching objects.\n";
            cout << "\n" << name << "'s  Turn:\n";
            display ();
            cout << "\nChoose your first card (1-100): ";
            cin >> card1;
            cout << "Choose your second card (1-100): ";
            cin >> card2;

            while (true){
                if (card1 <= 0 || card1> TOTALCARDS){
                    cout << "Try again.\nChoose your first card: ";
                    cin>>card1;
                } else if (cards[card1 - 1].object == "x" ){ //checks if the card has already been paired to avoid duplicates
                    cout << "This card has already been picked. Try again.\nChoose your first card: ";
                    cin>>card1;
                } else break;
            }

            cards[card1 - 1].reveal();
            cout << "\nYour first card " << card1<< " is a: " << cards[card1 - 1].object<<endl;

            while (card2 == card1|| card2> TOTALCARDS|| card2<=0 || cards[card2 - 1].object=="x") {
                cout << "\nTry again, do not choose the same card\nChoose your second card: ";
                cin >> card2;
            }

            cards[card2 - 1].reveal();
            cout << "Your second card " << card2<< " is a: " << cards[card2 - 1].object << endl;

            if (cards[card1 - 1].object == cards[card2 - 1].object) {
                cout << "\nYou found a pair!\n";
                display2 (card1,card2);
                cards[card1 - 1].object = "x"; //replaces the matched cards with "x" to remove them from
                cards[card2 - 1].object = "x"; //the 10x10 grid
                paired+= 2;
                User+=1;
                cout << endl << name << "'s  Points: " << User<< endl;
                sleep_for(seconds(2));
                system("cls");

            } else {
                cout << "\nThese items don't match.\n";
                display2 (card1,card2);
                cards[card1 - 1].revealed = false;
                cards[card2 - 1].revealed = false;
                player="computer";
                cout << endl << name << "'s  Points: " << User<< endl;
                sleep_for(seconds(5));
                system("cls");

                break;
                }





        }

        while (true){ //computer interface
            system("cls");

            cout << "\n\nIt's Pixel's turn now!!!\n\n";

            display();

            card1=1+rand()%100;

            while (card1 <= 0 || card1> TOTALCARDS|| cards[card1 - 1].object == "x"){
                card1=1+rand()%100;
            }

            cards[card1 - 1].reveal();

            cout << "\nPixel's first card " << card1<< " is a: " << cards[card1 - 1].object << endl;

            card2=(rand()%100)+1;

            while (card2 == card1|| card2> TOTALCARDS|| cards[card2 - 1].object == "x") {
                card2=(rand()%100)+1;
            }

            cards[card2 - 1].reveal();
            cout << "Pixel's second card " << card2<< " is a: " << cards[card2 - 1].object << endl;


            if (cards[card1 - 1].object == cards[card2 - 1].object) {
                cout << "Pixel found a pair!\n";
                display2 (card1,card2);
                cards[card1 - 1].object = "x";
                cards[card2 - 1].object = "x";
                paired+= 2;
                Pixel+=1;
                cout << "\nPixel's Points: " << Pixel<< endl;
                sleep_for(seconds(2));
                system("cls");
            } else {
                cout << "\nThe cards do not match. :( \n";
                display2 (card1,card2);
                cards[card1 - 1].revealed = false;
                cards[card2 - 1].revealed = false;
                player=="human";
                cout << "\nPixel's Points: " << Pixel<< endl;
                sleep_for(seconds(5));
                system("cls");

                break;
                }

            }

        if (pointcounter()) { //displays who matched the most card pairs during the memory game
            if (Pixel>User)
            cout << "\n\nCongratulations, Pixel won the game!\nPixel: ^^ Yay! I won! Nice game, " << name << "! :)" <<endl;
        else if (User>Pixel)
            cout << "\n\nCongratulations, "<<name<<" won the game!" << endl;
        else cout << "\n\nIt's a draw!";
            break;
        }
    }

 }

bool pointcounter() { //checks if all 100 cards (50 pairs) has already been matched
    return points==50;
}

};

int main() { //main function

    MemoryGame game;
    game.start();

    return 0;
}


