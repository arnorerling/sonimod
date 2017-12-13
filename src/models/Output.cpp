#include "Output.h"

Output::Output(){ }

void Output::clean() {
    for(int i = 0; i < 40; i++) {
            cout << endl;
    }
}

void Output::wait() {
    cout << "Press enter to continue.." << endl;
    cin.ignore();
    cout << "Screen is clean" << endl;
}

void Output::salesWait() {
    cout << "Press enter to continue.." << endl;
    cin.ignore();
    cin.get();
    cout << "Screen is clean" << endl;
}
