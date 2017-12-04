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

        void addCrust();
        void addTopping();
        void addPizza();
        void addDrink();
        void addSide();
        void addBranch();

        void printDrinks();
};

#endif // MANAGERUI_H
