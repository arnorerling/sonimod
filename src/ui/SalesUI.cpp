#include "SalesUI.h"


SalesUI::SalesUI(){

}
void SalesUI::startUI() {
    Order order;
    salesDomain.getDrinks(this->avaliableDrinks);
    salesDomain.getSidedishes(this->avaliableSidedishes);
    salesDomain.getPizzas(this->avaliablePizzas);
    salesDomain.getCrusts(this->avaliableCrusts);
    salesDomain.getToppings(this->avaliableToppings);
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

                break;
            }
        }
    }

}

void SalesUI::printPizzas(){
    cout << endl;
}

void SalesUI::printDrinks() {

    cout << "Drinkslist" << endl;
    for(unsigned int i = 0; i < this->avaliableDrinks.size(); i++){
        cout << avaliableDrinks[i];
    }

}

void SalesUI::printSidedishes() {
    cout << "Sidedishlist" << endl;
    for(unsigned int i = 0; i < this->avaliableSidedishes.size(); i++){
        cout << avaliableSidedishes[i];
    }
}

void SalesUI::printToppings(){
    cout << "Toppingslist" << endl;
    for(unsigned int i = 0; i < this->avaliableToppings.size(); i++){
        cout << avaliableToppings[i];
    }
}

void SalesUI::printCrusts(){
    cout << "Crustslist" << endl;
    for(unsigned int i = 0; i < this->avaliableCrusts.size(); i++){
        cout << avaliableCrusts[i];
    }
}

void SalesUI::addDrink(){
    bool avaliable = false;
    string name;
    int size = 0;
    while(!avaliable){
        cout << "Enter name of drink: ";
        cin >> ws;
        getline(cin, name);
        cout << "Enter size of drink: ";
        cin >> size;
        Drink drink(name,size);
        avaliable = salesDomain.checkDrinkAvaliability(this->avaliableDrinks, drink);
        if(avaliable){
            this->order.addDrink(drink);
        }
    }


}

void SalesUI::addSidedish(){
    bool avaliable = false;
    string name;
    while(!avaliable){
        cout << "Enter name of sidedish: ";
        cin >> name;
        Sidedish sidedish(name);
        avaliable = salesDomain.checkSidedishAvaliability(this->avaliableSidedishes, sidedish);
        if(avaliable){
            this->order.addSideDish(sidedish);
        }
    }
}

void SalesUI::addPizza(){
    Pizza pizza;
    bool avaliable = false;
    string name;
    int size;
    char anotherTopping = 'y';

    printCrusts();
    while(!avaliable) {
        cout << "Enter crust name: ";
        cin >> name;
        cout << "Enter Size: ";
        cin >> size;
        Crust crust(name,size);
        avaliable = salesDomain.checkCrustAvaliability(this->avaliableCrusts, crust);
        if(avaliable){
            pizza.addCrust(crust);
        }
        else{
            cout << "Crust not avaliable!" << endl;
        }
    }
    printToppings();
    while(anotherTopping == 'y'){
        cout << "Enter topping name: ";
        cin >> name;
        Topping topping(name);
        avaliable = salesDomain.checkToppingAvaliability(this->avaliableToppings, topping);
        if(avaliable) {
            pizza.addTopping(topping);
            cout << "Do you want another topping?(y/n): ";
            cin >> anotherTopping;
        }
        else {
            cout << "Topping not avaliable!" << endl;
        }
    }
    pizza.setPrice();
    order.addPizza(pizza);
}
