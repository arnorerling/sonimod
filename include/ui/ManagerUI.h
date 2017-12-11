#ifndef MANAGERUI_H
#define MANAGERUI_H
#include "ManagerDomain.h"
#include "ManagerUI.h"
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
using namespace std;

class ManagerUI
{
    private:
        ManagerDomain managerDomain;

    public:
        ManagerUI();

        void startUI();
        void addChangeMenu();
        void removeFromMenu();
        void seeSaleFigures();

        void addCrust();
        void addTopping();
        void addPizza();
        void addDrink();
        void addSide();
        void addBranch();
        void addUser();

        void printCrust();
        void printTopping();
        void printPizza();
        void printDrink();
        void printSide();
        void printBranch();
        void printUser();

        void printAllFigures();

        void removeCrust();
        void removeTopping();
        void removePizza();
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

        void printManLogo();
};

#endif // MANAGERUI_H
