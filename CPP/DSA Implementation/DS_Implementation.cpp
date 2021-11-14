#include <iostream>
#include "DS.cpp"
#include "Queue_menu.cpp"
#include "Stack_menu.cpp"
using namespace std;

int main(){        
    char cmd = 'A';
    while(cmd != 'E'){
        cout << "The following options are available: " << endl
             << "1. Queue (Q)" << endl
             << "2. Stack (S)" << endl
             << "3. Exit (E)" << endl
             << "What do you want to do? ";
        cin >> cmd;


        // Queue option is chosen
        if(cmd == 'Q'){
            q_menu();
        }

        // Stack option is selected
        if(cmd == 'S'){
            stck_menu();
        }

        // Exit command is chosen
        else if(cmd == 'E'){
            break;
        }

        // invalid option is chosen.
        else {
            cout << "Invalid command, try again" << endl;
        }        
    }
    return 0;
}