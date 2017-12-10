#ifndef MAINUI_H
#define MAINUI_H
#include "MainDomain.h"
#include "Username.h"

class MainUI
{
    private:
        MainDomain mainDomain;
    public:
        MainUI();
        void start();
        void login();
        void mainMenu();

        char checkInput();
        User checkUser();
        void printLogo();
};

#endif // MAINUI_H
