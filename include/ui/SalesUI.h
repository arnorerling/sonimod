#ifndef SALESUI_H
#define SALESUI_H

#include "SalesDomain.h"
#include <iostream>

using namespace std;


class SalesUI {

    private:
        SalesDomain salesDomain;

    public:
        SalesUI();
        void startUI();

        void getPizza();
        void getDrink();
        void getSidedish();
};

#endif // SALESUI_H
