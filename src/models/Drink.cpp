#include "Drink.h"

Drink::Drink() {
	this->name = "";
	this->liter = 0;
	this->price = 0;
}

Drink::Drink(string name) {
    this->name = name;
	this->liter = 0;
	this->price = 0;
}

Drink::Drink(string name, int liter){
	this->name = name;
	this->liter = liter;
	this->price = 0;
}

Drink::Drink(string name, int size, int price) {
	this->name = name;
	this->liter = size;
    this->price = price;
}

void Drink::write(ofstream& fout) const {

    int strLen = name.length() + 1;
    fout.write((char*)(&strLen), sizeof(int));
    fout.write(name.c_str(), strLen);

    fout.write((char*)(&price), sizeof(int));
    fout.write((char*)(&liter), sizeof(int));
}

void Drink::read(ifstream& fin) {

    int strLen = name.length();
    fin.read((char*)(&strLen), sizeof(int));
    char *str = new char[strLen];
    fin.read(str, strLen);
    name = str;

    fin.read((char*)(&price), sizeof(int));
    fin.read((char*)(&liter), sizeof(int));

    delete[] str;
}

ostream& operator << (ostream& out, const Drink& drink) {

    out << "Name: " << drink.name << " ";
    out << "Size: " << drink.liter << " ";
    out << "Price: " << drink.price << endl;
    return out;
}

bool operator == (const Drink &left_drink, const Drink &right_drink) {
    if (left_drink.name == right_drink.name) {
        if (left_drink.liter == right_drink.liter) {
            return true;
        }
    }
    return false;
}

string Drink::getName() const {
    return this->name;
}

int Drink::getLiter() const {
    return this->liter;
}

int Drink::getPrice() const {
    return this->price;
}

void Drink::setName(const string name) {
    this->name = name;
}
void Drink::setLiter(const int liter) {
    this->liter = liter;
}

void Drink::setPrice(const int price) {
    this->price = price;
}
