#include <iostream>
#include "MainUI.h"

using namespace std;

void printLogo() {
cout << " __                  " << endl;
cout << "(_  _ __  o __  _  _|" << endl;
cout << "__)(_)| | | |||(_)(_|" << endl;
}

int main()
{
    printLogo();
    MainUI mainui;
    mainui.start();
    return 0;
}
