#include "Topping.h"

Topping::Topping(){
	this->name[0] = '\0';
	this->price = 0;
}

Topping::Topping(string name, int price){

	this->name = name;
	this->price = price;
}


ostream& operator << (ostream& out, const Topping& topping){

    out << "Name: " << topping.name << " ";
    out << "Price: " << topping.price << endl;
	return out;

}

string Topping::getName() {
    return this->name;
}

int Topping::getPrice(){
	return this->price;
}
