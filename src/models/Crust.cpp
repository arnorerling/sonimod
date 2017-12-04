#include "Crust.h"


Crust::Crust() {
	this->name = "";
	this->price = 0;
	this->inches = 0;
}

Crust::Crust(string name, int inches, int price) {

	this->name = name;
	this->inches = inches;
	this->price = price;
}

ostream& operator << (ostream& out, const Crust& crust) {

    out << "Name: " << crust.name << " ";
    out << "Inches: " << crust.inches << " ";
    out << "Price: " << crust.price;
	return out;
}

string Crust::getName() {
    return this->name;
}

int Crust::getInches() {
    return this->inches;
}

int Crust::getPrice() {
    return this->price;
}
