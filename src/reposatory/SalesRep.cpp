#include "SalesRep.h"

SalesRep::SalesRep() {
    //ctor
}

vector<Pizza> SalesRep::getPizzas() {

    vector<Pizza> pizzas;
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
    return pizzas;
}

vector<Drink> SalesRep::getDrinks() {
    vector<Drink> drinks;
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
    return drinks;
}

vector<Sidedish> SalesRep::getSidedishes() {
    vector<Sidedish> sidedishes;
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
    return sidedishes;
}

vector<Topping> SalesRep::getToppings() {
    vector<Topping> toppings;
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
    return toppings;
}

vector<Crust> SalesRep::getCrusts() {
    vector<Crust> crusts;
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
    return crusts;
}

vector<Branch> SalesRep::getBranches() {
    vector<Branch> branches;
    ifstream fin;
    fin.open("Branch_Binary.dat", ios::binary);
    if(fin.is_open()) {
        while(!fin.eof()){
            Branch currBranch;
            currBranch.read(fin);
            if(!fin.eof()){
                branches.push_back(currBranch);
            }
        }
        fin.close();
    }
    else {
        throw FileNotOpenException();
    }
    return branches;
}

vector<Order> SalesRep::getOrders() {
    vector<Order> orders;
    ifstream fin;
    fin.open("Order_Binary.dat", ios::binary);
    if(fin.is_open()) {
        while(!fin.eof()){
            Order currOrder;
            currOrder.read(fin);
            if(!fin.eof()){
                orders.push_back(currOrder);
            }
        }
        fin.close();
    }
    else {
        throw FileNotOpenException();
    }
    return orders;
}

void SalesRep::fileOrder(Order& order) {
    ofstream fout;
    fout.open("Order_Binary.dat", ios::binary|ios::app);
    order.write(fout);
    fout.close();

}
