#include "SalesUI.h"


SalesUI::SalesUI(){

}
void SalesUI::startUI() {
    Order order;
    salesDomain.getDrinks(this->avaliableDrinks);
    salesDomain.getSidedishes(this->avaliableSidedishes);
    salesDomain.getPizzas(this->avaliablePizzas);
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

void SalesUI::addPizza(){
    cout << "Here we are adding pizzas to your order!" << endl;
}

void SalesUI::addDrink(){
    bool avaliable = false;
    string name;
    int size = 0;
    while(!avaliable){
        cout << "Enter name of drink: ";
        cin >> name;
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
