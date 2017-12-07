#ifndef BAKERUI_H
#define BAKERUI_H

#include "BakerDomain.h"
#include "Branch.h"
#include <vector>

class BakerUI
{
    private:
    BakerDomain bakerDomain;
    Branch branch;

    public:
        BakerUI();
        void startUI();
        void printRestaurants();
        void chooseRestaurant();
        void printOrders();

};

#endif // BAKERUI_H
