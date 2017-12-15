#ifndef DELIVERYUI_H
#define DELIVERYUI_H

#include "DeliveryDomain.h"
#include "Output.h"
#include <iostream>

using namespace std;

class DeliveryUI
{
    private:
        DeliveryDomain deliveryDomain;
        Output output;
        string branch;

        Order findOrder();
        void printLogo();

    public:
        //Starts UI for sales, prints out menu
        DeliveryUI();
        //starts the menu for delivery
        void startUI();
        //delivery chooses a restaurant branch
        void chooseRestaurant();
        //prints out all the restaurant branches

        void printRestaurants();
        //prints out a list of all orders's
        //phone numbers and name
        void printOrders();
        //prints out a list with all ready order's phone numbers and name
        //lets you know if order is older than 20min, 30min
        //after 2 hours, order will be thrown out.
        void printReadyOrders();
        //user chooses an order and the whole order will print out
        void printOneOrder();

        //user chooses an order to be marked paid for
        void markPaidFor();
        //user chooses an order to be marked delivered
        //the order will be stored in legacy file after that.
        void markDelivered();

        //checks if input is valid
        char checkInput();
        //checks if phone number is valid
        string checkNumber();
};

#endif // DELIVERYUI_H
