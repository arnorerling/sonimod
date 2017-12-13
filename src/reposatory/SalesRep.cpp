#include "SalesRep.h"

SalesRep::SalesRep()
{
    //ctor
}

void SalesRep::getPizzas(vector<Pizza>& pizzas) {


    ifstream fin;
    fin.open("Pizzas_Binary.dat", ios::binary);
    if(fin.is_open()) {
        while(!fin.eof()){
            Pizza currPizza;
            currPizza.read(fin);
            if(!fin.eof()){
                pizzas.push_back(currPizza);
            }
        }
        fin.close();
    }
    else {
        throw FileNotOpenException();
    }
}

void SalesRep::getDrinks(vector<Drink>& drinks) {
    ifstream fin;
    fin.open("Drink_Binary.dat", ios::binary);
    if(fin.is_open()) {
        while(!fin.eof()){
            Drink currDrink;
            currDrink.read(fin);
            if(!fin.eof()){
                drinks.push_back(currDrink);
            }
        }
        fin.close();
    }
    else {
        throw FileNotOpenException();
    }
}

void SalesRep::getSidedishes(vector<Sidedish>& sidedishes) {

    ifstream fin;
    fin.open("Sidedish_Binary.dat", ios::binary);
    if(fin.is_open()) {
        while(!fin.eof()){
            Sidedish currSidedish;
            currSidedish.read(fin);
            if(!fin.eof()){
                sidedishes.push_back(currSidedish);
            }
        }
        fin.close();
    }
    else {
        throw FileNotOpenException();
    }
}

void SalesRep::getToppings(vector<Topping>& toppings) {
    ifstream fin;
    fin.open("Topping_Binary.dat", ios::binary);
    if(fin.is_open()) {
        while(!fin.eof()){
            Topping currTopping;
            currTopping.read(fin);
            if(!fin.eof()){
                toppings.push_back(currTopping);
            }
        }
        fin.close();
    }
    else {
        throw FileNotOpenException();
    }
}

void SalesRep::getCrust(vector<Crust>& crusts) {
    Crust currCrust;
    ifstream fin;
    fin.open("Crust_Binary.dat", ios::binary);
    if(fin.is_open()) {
        while(!fin.eof()){
            Crust currCrust;
            currCrust.read(fin);
            if(!fin.eof()){
                crusts.push_back(currCrust);
            }
        }
        fin.close();
    }
    else {
        throw CrustFileNotFoundException();
    }
}

void SalesRep::getBranches(vector<Branch>& Branches) {
    ifstream fin;
    fin.open("Branch_Binary.dat", ios::binary);
    if(fin.is_open()) {
        while(!fin.eof()){
            Branch currBranch;
            currBranch.read(fin);
            if(!fin.eof()){
                Branches.push_back(currBranch);
            }
        }
        fin.close();
    }
    else {
        throw FileNotOpenException();
    }
}

void SalesRep::fileOrder(Order& order){

    ofstream fout;
    fout.open("Order_Binary.dat", ios::binary|ios::app);
    order.write(fout);
    fout.close();

}
