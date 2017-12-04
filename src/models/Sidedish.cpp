#include "Sidedish.h"

Sidedish::Sidedish()
{
    name = "";
    price = 0;
}

Sidedish::Sidedish(string name, int price) {
    this->name = name;
    this->price = price;
}

ostream& operator << (ostream& out, const Sidedish& sidedish) {

    out << "Name: " << sidedish.name << " ";
    out << "Price: " << sidedish.price << endl;
    return out;
}

int Sidedish::getPrice(){
    return this->price;
}

string Sidedish::getName(){
    return this->name;
}
