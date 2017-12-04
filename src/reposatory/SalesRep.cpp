#include "SalesRep.h"

SalesRep::SalesRep()
{
    //ctor
}

void SalesRep::getPizzas(vector<Pizza>& pizzas) {
    /*
    Pizza currPizza;
    ifstream fin;
    fin.open("Pizza_Binary.dat", ios::binary);
    if(fin.is_open()) {
        while(!fin.eof()){
            currPizza.read(fin);
            if(!fin.eof()){
                pizzas.push_back(currPizza);
            }
        }
        fin.close();
    }*/
}

void SalesRep::getDrinks(vector<Drink>& drinks) {
    Drink currDrink;
    ifstream fin;
    fin.open("Drink_Binary.dat", ios::binary);
    if(fin.is_open()) {
        while(!fin.eof()){
            currDrink.read(fin);
            if(!fin.eof()){
                drinks.push_back(currDrink);
            }
        }
        fin.close();
    }
}

void SalesRep::getSidedishes(vector<Sidedish>& sidedishes) {
    Sidedish currSidedish;
    ifstream fin;
    fin.open("Sidedish_Binary.dat", ios::binary);
    if(fin.is_open()) {
        while(!fin.eof()){
            currSidedish.read(fin);
            if(!fin.eof()){
                sidedishes.push_back(currSidedish);
            }
        }
        fin.close();
    }
}
