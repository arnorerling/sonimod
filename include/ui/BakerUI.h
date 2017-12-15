#ifndef BAKERUI_H
#define BAKERUI_H

#include <iostream>
#include "BakerDomain.h"
#include "Output.h"
#include <cstdlib>

using namespace std;

class BakerUI
{
    private:

        BakerDomain bakerDomain;
        Output output;
        string branch;

        //baker chooses a restaurant branch
        void chooseRestaurant();

        //prints all restaurant branches
        void printRestaurants();
        //prints all orders that are not ready
        //phone numbers and name
        //tell baker to hurry up if order is older than 30min and 1hour
        void printOrders();
        //user chooses an order and the whole order will print out
        void printOneOrder();

        //user chooses an order to mark in process
        void markInProcess();
        //user chooses an order to mark ready
        void markReady();

        //finds a specific order
        Order findOrder();
        //checks if phone number is valid
        string checkNumber();
        //checks if input is valid
        char checkInput();
        //prints baker logo
        void printLogo();


    public:
        //Starts UI for sales, prints out menu
        BakerUI();
        //start menu for baker
        void startUI();
};

#endif // BAKERUI_H
