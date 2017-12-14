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
        ManagerUI();
        //the menu for manager
        void startUI();
        //the menu for add/change
        void addChangeMenu();
        //the menu for remove
        void removeFromMenu();
        //the menu to see sale figures
        void seeSaleFigures();

        //add or change pizza into list
        void addPizza();
        //add or change crust into list
        void addCrust();
        //add or change topping into list
        void addTopping();
        //add or change drink into list
        void addDrink();
        //add or change sidedish into list
        void addSide();
        //add or change restaurant branch into list
        void addBranch();
        //add or change user into list
        void addUser();

        //prints all pizzas from list
        void printPizza();
        //prints all crusts from list
        void printCrust();
        //prints all toppings from list
        void printTopping();
        //prints all drinks from list
        void printDrink();
        //prints all sidedishes from list
        void printSide();
        //prints all restaurant branches from list
        void printBranch();
        //prints all users from list
        void printUser();
        //prints all orders based on what branch and what date range.
        void printFigures(string branch, string dateFrom, string dateTo);

        //removes a pizza from list
        void removePizza();
        //removes a crust from list
        void removeCrust();
        //removes a topping from list
        void removeTopping();
        //removes a drink from list
        void removeDrink();
        //removes a sidedish from list
        void removeSide();
        //removes a restaurant branch from list
        void removeBranch();
        //removes a user from branch
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
