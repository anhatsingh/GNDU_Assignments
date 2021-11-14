#include <iostream>
using namespace std;

void stck_menu(){
    char cmd = 'A';
    int size;

    cout << endl << "What should be the size of Stack? ";
    cin >> size;
    
    Stack stck(size);

    while(cmd != 'M'){
        cout << "The following options are available: " << endl
             << "1. Push (P)" << endl
             << "2. Pop (O)" << endl
             << "3. Display (D)" << endl
             << "4. Main Menu (M)" << endl
             << "What do you want to do? ";
        cin >> cmd;

        // Command insert is chosen, ask the element to insert to stack, and perform the insertion.
        if (cmd == 'P'){
            int m;
            cout << "Type integer to insert: ";
            cin >> m;
            stck.push(m);
            cout << "Inserted " << m << " into the Stack" << endl;
        }

        // Command delete is chosen, simply delete the front of Queue
        else if(cmd == 'O'){
            stck.pop();
            cout << "Element popped from stack" << endl;
        }

        else if(cmd == 'D'){
            cout << "Element on top of Stack is: ";
            stck.display();
        }

        // Command Main Menu is chosen, break from loop to go back to main menu
        else if (cmd == 'M'){
            break;
        }
        
        // Invalid command is chosen, try again
        else{
            cout << endl << "Invalid command, try again!";
        }
    }
}