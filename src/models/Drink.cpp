#include "Drink.h"

Drink::Drink(){

	this->name = "";
	this->price = 0;
	this->liter = 0;
}

Drink::Drink(string name, int size, int price){

	this->name = name;
	this->liter = size;
    this->price = price;
}

ostream& operator << (ostream& out, const Drink& drink){

    out << "Name: " << drink.name << " ";
    out << "Size: " << drink.liter << " ";
    out << "Price: " << drink.price << endl;
    return out;
}

string Drink::getName() {
    return this->name;
}

int Drink::getPrice(){
    return this->price;
}

int Drink::getLiter() {
    return this->liter;
}
