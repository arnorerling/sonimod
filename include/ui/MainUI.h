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

        //hides the input when bool parameter is false
        void SetStdinEcho(bool enable);
        //check input
        char checkInput();
        //checks if user is in list
        User checkUser();
        //prints Sonimod logo
        void printLogo();
        //user can login
        void login();
        //if user is a manager he will go to mainMenu for all
        void mainMenu();

    public:
        //Starts UI for sales, prints out menu
        MainUI();
        //starts main menu
        void start();
};

#endif // MAINUI_H
