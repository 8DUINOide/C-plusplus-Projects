//======================================================================================
//Filename : PAZ_Using the string and cstring library in C++.cpp
//Author : Al Francis B. Paz
//Email : afpaz@gbox.adnu.edu.ph
//Exercise Number : 5
//Description : Using the string and cstring library in C++, A program that decrypts the intercepted message thru keyboard input. The ASCII codes for the unencrypted message are limited to the visible ASCII characters only.
//Last modified: September 22, 2022
//======================================================================================

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(){
    //variables
    string str, str2;
    int t, i, key;
    
    //Giving of instruction to the user. Put the main instruction of the program.
    cout<<"Code Decryptor \n"
        <<"Enter the intercepted message: ";
        cin>>str;
        cout<<endl
    //Constructing 2 dimentional arrays.
        <<"Key        Decrypted Message \n";
        str2 = str;
    
    // Write a program that decrypts the intercepted message thru keyboard input. The ASCII codes for the unencrypted message are limited to the visible ASCII characters only. You only know that the key used is a number between 1 and 100. Your program should try to decode the message using all possible keys between 1 and 100. When you try the valid key, the message will make sense. For all other keys, the message will appear as gibberish.

        char* Encrypted_Char = const_cast<char*>(str.c_str());;
        char* Original_Char = const_cast<char*>(str2.c_str());;
        t = strlen(Encrypted_Char);
        
        for(key = 1;key<= 100;key++){
            for(i =0;i<t;i++){
                if((Encrypted_Char[i] - key)<32){
                   Original_Char[i] = Encrypted_Char[i] - 32 - key + 127;
                }
                else{
                    Original_Char[i] = Encrypted_Char[i] - key;
                }
            }
    // Your program will display on the screen 100 decrypted message (using keys 1 to 100) from the original encrypted message.

            cout<<key<<"           "<<Original_Char<<endl;
        }
        return 0;
                }
                
            