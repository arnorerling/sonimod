#ifndef MANAGERUI_H
#define MANAGERUI_H

#include "ManagerDomain.h"

#include "Output.h"
#include <iostream>
#include <iomanip>
using namespace std;

class ManagerUI
{
    private:
        ManagerDomain managerDomain;
        Output output;

        void printManLogo();

    public:
        //Starts UI for sales, prints out menu
        ManagerUI();
        //the menu for manager
        void startUI();

        //the menu for add/change
        void addChangeMenu();
        //the menu for remove
        void removeFromMenu();
        //the menu to see sale figures
        void seeSaleFigures();

        //add or change item in list
        void addPizza();
        void addCrust();
        void addTopping();
        void addDrink();
        void addSide();
        void addBranch();
        void addUser();

        //prints all items from a list
        void printPizza();
        void printCrust();
        void printTopping();
        void printDrink();
        void printSide();
        void printBranch();
        void printUser();

        //prints all orders based on what branch and what date range.
        void printFigures(string branch, string dateFrom, string dateTo);

        //removes item from list
        void removePizza();
        void removeCrust();
        void removeTopping();
        void removeDrink();
        void removeSide();
        void removeBranch();
        void removeUser();

        //checks if a name is valid
        string checkName();
        //checks if a price is valid
        int checkPrice();
        //check if input is valid
        char checkInput();
        //check if answer is valid
        char checkAnswer();
        //check if username is valid
        string checkUsername();
        //check if password is valid
        string checkPassword();
        //check if job is valid
        char checkJob();
        //check if branch is valid
        string checkBranch();
        //check if date is valid
        string checkDate();
};

#endif // MANAGERUI_H
