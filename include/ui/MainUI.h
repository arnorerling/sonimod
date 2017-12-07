#ifndef MAINUI_H
#define MAINUI_H
#include "MainDomain.h"

class MainUI
{
    private:
        MainDomain mainDomain;
    public:
        MainUI();
        void start();

        char checkInput();
};

#endif // MAINUI_H
