#include "Order.h"
#include "Sidedish.h"
/*
Order::Order()
{
//ctor
}
void Order::addPizza(Pizza& pizza){
    this->pizzas.push_back(pizza);
}

void Order::addSideDish(SideDish& sidedish){
    this->sideDishes.push_back(sidedish);
}

void Order::addDrink(Drink& drink){
    this->drinks.push_back(drink);
}
ostream& operator << (ostream& out, Order& order){
    out << endl << "Pizzas in order: " << endl;
    for(unsigned int i = 0; i < order.pizzas.size(); i++){
        out << order.pizzas[i] << endl;
    }
    out << endl << "Sidedishes in order: " << endl;
    for(unsigned int i = 0; i < order.sideDishes.size(); i++){
        out << order.sideDishes[i] << endl;
    }
    out << endl << "Drinks in order: " << endl;
    for(unsigned int i = 0; i < order.drinks.size(); i++){
        out << order.drinks[i] << endl;
    }
    order.printTotal();
    return out;
}
int Order::getTotal(){
    cout << endl << "Order total: ";
    int total = 0;
    for(unsigned int i = 0; i < this->pizzas.size(); i++){
        total += this->pizzas[i].getPrice();
    }
    for(unsigned int i = 0; i < this->sideDishes.size(); i++){
        total += this->sideDishes[i].getPrice();
    }
    for(unsigned int i = 0; i < this->drinks.size(); i++){
        total += this->drinks[i].getPrice();
    }
    return total;
}
*/
