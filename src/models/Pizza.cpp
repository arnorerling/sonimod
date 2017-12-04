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

/*Topping Pizza::addTopping() {
    Topping topping;
    string choose = " ";

    cout << "------Topping List------" << endl;
    ifstream fin;
    fin.open("Toppings_Binary.dat", ios::binary);
    while(!fin.eof()) {
        topping.read(fin);
        if(!fin.eof()) {
        cout << topping;
        }
    }
    cout << "-----------------------" << endl;
    fin.close();

    while (choose != topping.getName()) {
        cout << "Choose a topping" << endl;
        cin >> ws;
        getline(cin, choose);

        fin.open("Toppings_Binary.dat", ios::binary);
        while(!fin.eof()) {
            topping.read(fin);
            if(choose == topping.getName()){
                fin.close();
                return topping;
            }
        }
        cout << "This topping is not avalible" << endl;
        fin.close();
    }
}

Crust Pizza::addCrust() {
    Crust crust;
    string choose = " ";
    int inches = 0;

    cout << "------Crust List------" << endl;
    ifstream fin;
    fin.open("Crusts_Binary.dat", ios::binary);
    while(!fin.eof()) {
        crust.read(fin);
        if(!fin.eof()) {
        cout << crust << endl;
        }
    }
    cout << "-----------------------" << endl;
    fin.close();

    while (choose != crust.getName() && inches != crust.getInches()) {
        cout << "Choose a crust" << endl;
        cin >> ws;
        getline(cin, choose);
        cout << "Choose size" << endl;
        cin >> inches;

        fin.open("Crusts_Binary.dat", ios::binary);
        while(!fin.eof()) {
            crust.read(fin);
            if(choose == crust.getName() && inches == crust.getInches()){
                fin.close();
                return crust;
            }
        }
        cout << "This crust is not avalible" << endl;
        fin.close();
    }

}

void Pizza::displayPizza(Pizza& pizza) {
    cout << pizza;
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

/*istream& operator >> (istream& in, Pizza& pizza) {



    return in;
}

int Pizza::getPrice(){
    return this->price;
}

void Pizza::addPizza(){

    this->crust = addCrust();
    this->price += crust.getPrice();


    char anotherTopping = 'y';
    while(anotherTopping != 'n'){
        Topping topping = addTopping();
        this->price += topping.getPrice();
        this->toppings.push_back(topping);
        cout << "Do you want another topping? (y/n): ";
        cin >> anotherTopping;
    }
}

*/
