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

        //users chooses a restaurant branch
        void chooseRestaurant();

        //prints out all the restaurant branches
        void printRestaurants();
        //prints out a list of all orders's
        //phone numbers and name
        void printReadyOrders();
        //user chooses an order and the whole order will print out
        void printOrders();
        //prints out a list with all ready order's phone numbers and name
        //lets you know if order is older than 30min and 1 hour
        //after 2 hours, order will be marked failed and put into waterloo file
        void printOneOrder();

        //user chooses an order to be marked paid for
        void markPaidFor();
        //user chooses an order to be marked delivered
        //the order will be stored in legacy file after that.
        void markDelivered();

        //finds a specific order
        Order findOrder();
        //checks if phone number is valid
        string checkNumber();
        //checks if input is valid
        char checkInput();
        //prints delivery logo
        void printLogo();

    public:
        //Starts UI for sales, prints out menu
        DeliveryUI();
        //starts the menu for delivery
        void startUI();
};

#endif // DELIVERYUI_H
