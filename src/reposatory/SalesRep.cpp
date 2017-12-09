#include "SalesRep.h"

SalesRep::SalesRep()
{
    //ctor
}

void SalesRep::getPizzas(vector<Pizza>& pizzas) {

    Pizza currPizza;
    ifstream fin;
    fin.open("Pizzas_Binary.dat", ios::binary);
    if(fin.is_open()) {
        while(!fin.eof()){
            currPizza.read(fin);
            if(!fin.eof()){
                pizzas.push_back(currPizza);
            }
        }
        fin.close();
    } else {
        cout << "File not found" << endl;
    }
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

void SalesRep::getToppings(vector<Topping>& toppings) {
    Topping currTopping;
    ifstream fin;
    fin.open("Topping_Binary.dat", ios::binary);
    if(fin.is_open()) {
        while(!fin.eof()){
            currTopping.read(fin);
            if(!fin.eof()){
                toppings.push_back(currTopping);
            }
        }
        fin.close();
    }
}

void SalesRep::getCrust(vector<Crust>& crusts) {
    Crust currCrust;
    ifstream fin;
    fin.open("Crust_Binary.dat", ios::binary);
    if(fin.is_open()) {
        while(!fin.eof()){
            currCrust.read(fin);
            if(!fin.eof()){
                crusts.push_back(currCrust);
            }
        }
        fin.close();
    }
}

void SalesRep::getBranches(vector<Branch>& Branches) {
    Branch currBranch;
    ifstream fin;
    fin.open("Branch_Binary.dat", ios::binary);
    if(fin.is_open()) {
        while(!fin.eof()){
            currBranch.read(fin);
            if(!fin.eof()){
                Branches.push_back(currBranch);
            }
        }
        fin.close();
    }
}

void SalesRep::fileOrder(Order& order){

    ofstream fout;
    fout.open("Order_Binary.dat", ios::binary|ios::app);
    if(fout.is_open()) {
        order.write(fout);
        fout.close();
    }
    else {
        cout << "File did not open" << endl;
    }
}
