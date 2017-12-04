#ifndef BAKERUI_H
#define BAKERUI_H

#include "BakerDomain.h"
#include "Branch.h"
#include <vector>

class BakerUI
{
    private:
    BakerDomain bakerDomain;
    vector<Branch> branchList;

    public:
        BakerUI();
        void startUI();
        void printRestaurants();
        void chooseRestaurant();

};

#endif // BAKERUI_H
