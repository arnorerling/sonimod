#include "Pizza.h"
using namespace std;

Pizza::Pizza() {
    this->name = "custom";
    this->price = 0;
}

Pizza::Pizza(string &name){
    this->name = name;
    this->price = 0;
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
        Topping topping;
        toppings[i].write(fout);
    }

    crust.write(fout);
    fout.write((char*)(&price), sizeof(int));
}

void Pizza::read(ifstream& fin) {
    int strLen = 0;
    fin.read((char*)(&strLen), sizeof(int));
    char *str = new char[strLen];
    fin.read(str, strLen);
    name = str;
    delete[] str;

    int tCount = 0;
    fin.read((char*)(&tCount), sizeof(int));

    for (int i = 0; i < tCount; i++) {
        Topping topping;
        topping.read(fin);
        toppings.push_back(topping);
    }

    crust.read(fin);
    fin.read((char*)(&price), sizeof(int));
}

ostream& operator << (ostream& out,const Pizza& pizza) {

    out << pizza.getCrustSize() << "\" ";
    out << pizza.name << ": cheese, ";
    for(unsigned int i = 0; i < pizza.toppings.size(); i++) {
        out << pizza.toppings[i].getName() << ", ";
    }
    out << "Crust: " << pizza.crust.getName() << " ";
    out << pizza.price << "kr" << endl;

    return out;
}

bool operator == (const Pizza &left_pizza, const Pizza &right_pizza) {
    if (left_pizza.name == right_pizza.name) {
        if (left_pizza.toppings == right_pizza.toppings) {
            return true;
        }
    }
    return false;
}

void Pizza::addTopping(const Topping &topping) {
    this->toppings.push_back(topping);
}

void Pizza::addCrust(const Crust &crust) {
    this->crust = crust;
}

void Pizza::setName(const string &name){
    this->name = name;
}

void Pizza::setFixedPrice(const int &price){
    this->price = price;
}

void Pizza::setPrice(){
    for(unsigned int i = 0;i < this->toppings.size(); i++){
        this->price += this->toppings[i].getPrice();
    }
    this->price += this->crust.getPrice();
}

string Pizza::getName() const {
    return this->name;
}

int Pizza::getPrice() const {
    return this->price;
}

int Pizza::getCrustSize() const {
    return crust.getInches();
}

