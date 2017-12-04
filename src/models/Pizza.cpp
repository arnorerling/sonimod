#include "Pizza.h"
using namespace std;

Pizza::Pizza() {
    price = 0;
}

Pizza::Pizza(string &name, vector<Topping> &toppings, Crust &crust, int &price) {
    this->name = name;
    this->toppings = toppings;
    this->crust = crust;
    this->price = price;
}

void Pizza::write(ofstream& fout) const {

    int strLen = name.length() + 1;
    fout.write((char*)(&strLen), sizeof(int));
    fout.write(name.c_str(), strLen);

    int tCount = toppings.size();
    fout.write((char*)(&tCount), sizeof(int));

    for (int i = 0; i < tCount; i++) {
        fout.write((char*)(&toppings[i]), sizeof(Topping));
    }

    fout.write((char*)(&crust), sizeof(Crust));

    fout.write((char*)(&price), sizeof(int));
}

void Pizza::read(ifstream& fin) {

    int strLen = name.length();

    fin.read((char*)(&strLen), sizeof(int));
    char *str = new char[strLen];
    fin.read(str, strLen);
    name = str;

    int tCount;
    fin.read((char*)(&tCount), sizeof(int));

    Topping topping;
    for (int i = 0; i < tCount; i++) {
        fin.read((char*)(&topping), sizeof(Topping));
        toppings.push_back(topping);
    }
    fin.read((char*)(&crust), sizeof(Crust));
    fin.read((char*)(&price), sizeof(int));

    delete[] str;
}

ostream& operator << (ostream& out,const Pizza& pizza) {
    out << endl << "Pizza with " << pizza.toppings.size() << " toppings:" << endl;
    out << "Crust type: " << endl;
    out << pizza.crust << endl;

    out << "Toppings:" << endl;

    for(unsigned int i = 0; i < pizza.toppings.size(); i++) {
        out << pizza.toppings[i] << endl;
    }
    return out;
}

void Pizza::addTopping(Topping topping) {
    this->toppings.push_back(topping);
}

void Pizza::addCrust(Crust crust) {
    this->crust = crust;
}

void Pizza::setPrice(){
    for(unsigned int i = 0;i < this->toppings.size(); i++){
        this->price += this->toppings[i].getPrice();
    }
    this->price += this->crust.getPrice();
}

int Pizza::getPrice(){
    return this->price;
}


