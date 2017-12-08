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

        char checkInput();
        User checkUser();
};

#endif // MAINUI_H
