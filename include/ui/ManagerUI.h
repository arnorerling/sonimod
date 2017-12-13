#ifndef MANAGERUI_H
#define MANAGERUI_H
#include "ManagerDomain.h"
#include "Output.h"
#include "Crust.h"
#include "Topping.h"
#include "Drink.h"
#include "Sidedish.h"
#include "Branch.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <iomanip>
using namespace std;

class ManagerUI
{
    private:
        ManagerDomain managerDomain;
        Output output;

    public:
        ManagerUI();

        void startUI();
        void addChangeMenu();
        void removeFromMenu();
        void seeSaleFigures();

        void addPizza();
        void addCrust();
        void addTopping();
        void addDrink();
        void addSide();
        void addBranch();
        void addUser();

        void printPizza();
        void printCrust();
        void printTopping();
        void printDrink();
        void printSide();
        void printBranch();
        void printUser();

        void printAllFigures();
        void printFigures(string branch, string dateFrom, string dateTo);

        void removePizza();
        void removeCrust();
        void removeTopping();
        void removeDrink();
        void removeSide();
        void removeBranch();
        void removeUser();

        string checkName();
        int checkPrice();
        char checkInput();
        char checkAnswer();
        string checkUsername();
        string checkPassword();
        char checkJob();
        string checkBranch();
        string checkDate();

        void printManLogo();
};

#endif // MANAGERUI_H
