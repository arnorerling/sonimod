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

        //the menu for add/change
        void addChangeMenu();
        //the menu for remove
        void removeFromMenu();
        //the menu to see sale figures
        void seeSaleFigures();
        //the menu to see failed orders
        void seeFailedOrders();

        //add or change item in list
        void addPizza();
        void addCrust();
        void addTopping();
        void addDrink();
        void addSide();
        void addBranch();
        void addUser();

        //prints items from list
        void printPizza();
        void printCrust();
        void printTopping();
        void printDrink();
        void printSide();
        void printBranch();
        void printUser();

        //prints all orders based on branch and date range.
        void printFigures(string branch, string dateFrom, string dateTo);
        //prints all failed orders based on branch and date range
        void printFailedOrders(string branch, string dateFrom, string dateTo);

        //removes item from list
        void removePizza();
        void removeCrust();
        void removeTopping();
        void removeDrink();
        void removeSide();
        void removeBranch();
        void removeUser();

        //Functions that send parameters to domain for validation, they also try and catch
        string checkName();
        int checkPrice();
        char checkInput();
        char checkAnswer();
        string checkUsername();
        string checkPassword();
        char checkJob();
        string checkBranch();
        string checkDate();

        //prints manager logo
        void printManLogo();

    public:
        //Constructor
        ManagerUI();
         //Starts UI for manager, prints out menu
        void startUI();
};

#endif // MANAGERUI_H
