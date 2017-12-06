#ifndef MANAGERUI_H
#define MANAGERUI_H
#include "ManagerDomain.h"

class ManagerUI
{
    private:
        ManagerDomain managerDomain;

    public:
        ManagerUI();

        void startUI();
        void addChangeMenu();
        void removeFromMenu();

        void addCrust();
        void addTopping();
        void addPizza();
        void addDrink();
        void addSide();
        void addBranch();

        void printCrust();
        void printTopping();
        void printPizza();
        void printDrink();
        void printSide();
        void printBranch();

        void removeCrust();
        void removeTopping();
        void removePizza();
        void removeDrink();
        void removeSide();
        void removeBranch();
};

#endif // MANAGERUI_H
