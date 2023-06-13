#include "text_processing.h"


void separator() { // Cosmetic element used for separating sections
    cout << string(100,'=') << endl;
}

int get_choice(){ // Getting a correct integer from the user
    int choice = 0;
    while(true) {
        cin >> choice;
        if (choice > 0 && choice < 10) {
            return choice;
        }
        cin.clear();
        cin.ignore(256,'\n');
        cout
                << "\x1b[1A" // Move cursor up
                << "\x1b[2K"; // Delete the entire line
    }
}

void display(string text_to_display){
    cout.setf(ios::right, ios:: adjustfield);
    cout.width(100);
    cout << right << setfill(' ') << setw(50) << text_to_display << endl;
}