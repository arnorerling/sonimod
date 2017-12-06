#include "SalesUI.h"


SalesUI::SalesUI(){

}
void SalesUI::startUI() {
    Order order;
    addCustomer();

    char select = '\0';
    while (select != 'q') {
        select = '\0';

        cout << "Sales Menu" << endl;
        cout << "Choose an action" << endl;
        cout << "------------------" << endl;
        cout << "p: Add Pizza" << endl;
        cout << "s: Add Sidedish" << endl;
        cout << "d: Add drink" << endl;
        cout << "o: Print order" << endl;
        cout << "t: Get order total" << endl;
        cout << "f: File order" << endl;
        cout << "------------------" << endl;

        cin >> select;

        switch(select){
            case 'p': {
                addPizza();
                break;
            }
            case 's': {
                printSidedishes();
                addSidedish();
                break;
            }
            case 'd': {
                printDrinks();
                addDrink();
                break;
            }
            case 'o': {
                cout << this->order;
                break;
            }
            case 't': {
                cout << "Order total: "<< order.getTotal();
                break;
            }
            case 'f': {
                fileOrder();
                select = 'q';
                break;
            }
        }
    }

}
void SalesUI::addCustomer(){
    bool allowed = false;
    string name;
    string phoneNumber;


    do{
        cout << "Enter customer name: ";
        cin >> ws;
        getline(cin, name);
        try{
            allowed = salesDomain.isValidName(name);
            order.addCustomerName(name);

        }
        catch(InvalidNameException){
            cout << "Invalid name!" << endl;
        }
    }while(!allowed);
    do{
        cout << "Enter customer phone number: ";
        cin >> ws;
        getline(cin, phoneNumber);
        try{
            allowed = salesDomain.isValidPhoneNumber(phoneNumber);
            order.addCustomerPhoneNum(phoneNumber);

        }
        catch(InvalidPhoneNumberException){
            cout << "Invalid number!" << endl;
            allowed = false;
        }
    }while(!allowed);
}
void SalesUI::printPizzas(){
    cout << endl;
}

void SalesUI::printDrinks() {
    vector<Drink> drinks;
    salesDomain.getDrinks(drinks);
    cout << "Drinkslist" << endl;
    for(unsigned int i = 0; i < drinks.size(); i++){
        cout << drinks[i];
    }

}

void SalesUI::printSidedishes() {
    vector<Sidedish> sidedishes;
    salesDomain.getSidedishes(sidedishes);
    cout << "Sidedishlist" << endl;
    for(unsigned int i = 0; i < sidedishes.size(); i++){
        cout << sidedishes[i];
    }
}

void SalesUI::printToppings(){
    vector<Topping> toppings;
    salesDomain.getToppings(toppings);
    cout << "Toppingslist" << endl;
    for(unsigned int i = 0; i < toppings.size(); i++){
        cout << toppings[i];
    }
}

void SalesUI::printCrusts(){
    vector<Crust> crusts;
    salesDomain.getCrusts(crusts);
    cout << "Crustslist" << endl;
    for(unsigned int i = 0; i < crusts.size(); i++){
        cout << crusts[i];
    }
}

void SalesUI::addDrink(){
    bool available = false;
    string name;
    int size = 0;
    while(!available){
        cout << "Enter name of drink: ";
        cin >> ws;
        getline(cin, name);
        cout << "Enter size of drink: ";
        cin >> size;
        Drink drink(name,size);
        try{
            available = salesDomain.checkDrinkAvailability(drink);
            this->order.addDrink(drink);
        }
        catch(DrinkNotAvailableException){
            cout << "Drink not available!" << endl;
        }
        catch(SizeNotAvailableException){
            cout << "Size not available!" << endl;
        }
    }


}

void SalesUI::addSidedish(){
    bool available = false;
    string name;
    while(!available){
        cout << "Enter name of sidedish: ";
        cin >> name;
        Sidedish sidedish(name);
        try{
            available = salesDomain.checkSidedishAvailability(sidedish);
            this->order.addSideDish(sidedish);
        }
        catch(SideDishNotAvailableException){
            cout << "Sidesish not available!" << endl;
        }
    }
}

void SalesUI::addPizza(){
    Pizza pizza;
    bool available = false;
    string name;
    int size;
    char anotherTopping = 'y';

    printCrusts();
    while(!available) {
        cout << "Enter crust name: ";
        cin >> name;
        cout << "Enter Size: ";
        cin >> size;
        Crust crust(name,size);
        try{
            available = salesDomain.checkCrustAvailability(crust);
            pizza.addCrust(crust);
        }
        catch(CrustNotAvailableException){
            cout << "Crust not available!" << endl;
        }
    }
    printToppings();
    while(anotherTopping == 'y'){
        cout << "Enter topping name: ";
        cin >> ws;
        getline(cin, name);
        Topping topping(name);
        try{
            available = salesDomain.checkToppingAvailability(topping);
            pizza.addTopping(topping);
        }
        catch(ToppingNotAvailableException){
            cout << "Topping not avaliable!" << endl;
        }
        cout << "another topping? (y/n): ";
        cin >> anotherTopping;
    }
    pizza.setPrice();
    order.addPizza(pizza);
}
void SalesUI::fileOrder(){
    cout << "Enter branch name: ";
    string branch;
    cin >> ws;
    getline(cin,branch);
    order.addBranch(branch);
    salesDomain.fileOrder(order);
    cout << "Order filed!" << endl;

}

