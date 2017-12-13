#ifndef MAINUI_H
#define MAINUI_H
#include "MainDomain.h"
#include "Output.h"

#ifdef WIN32
#include <windows.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

class MainUI
{
    private:
        MainDomain mainDomain;
        Output output;
    public:
        MainUI();
        void start();
        void login();
        void mainMenu();
        void SetStdinEcho(bool enable);

        char checkInput();
        User checkUser();
        void printLogo();
};

#endif // MAINUI_H
