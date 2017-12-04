#include "MainUI.h"
#include <iostream>
using namespace std;

MainUI::MainUI()
{
    //ctor
}

void MainUI::start() {

    cout << "Welcome to Sonimod" << endl;
    cout << "Choose an action" << endl;
    cout << "------------------" << endl;
    cout << "m: Manager" << endl;
    cout << "s: Sales" << endl;
    cout << "b: Baker" << endl;
    cout << "d: Delivery" << endl;
}
