#include <iostream>
using namespace std;

void q_menu(){
    char cmd = 'A';
    int size;

    cout << endl << "What should be the size of Queue? ";
    cin >> size;
    
    Queue Q(size);

    while(cmd != 'M'){
        cout << "The following options are available: " << endl
             << "1. Insert (I)" << endl
             << "2. Delete (D)" << endl
             << "3. Display (V)" << endl
             << "4. Main Menu (M)" << endl
             << "What do you want to do? ";
        cin >> cmd;

        // Command insert is chosen, ask the element to insert to queue, and perform the insertion.
        if (cmd == 'I'){
            int m;
            cout << "Type integer to insert: ";
            cin >> m;
            Q.insert(m);
            cout << "Inserted " << m << " into the Queue" << endl;
        }

        // Command delete is chosen, simply delete the front of Queue
        else if(cmd == 'D'){            
            Q.del();
            cout << "Deleted from Queue" << endl;
        }

        else if(cmd == 'V'){
            cout << "Element in front of Queue is: ";
            Q.display();            
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