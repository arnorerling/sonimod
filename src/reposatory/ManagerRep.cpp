#include "ManagerRep.h"

ManagerRep::ManagerRep() {
    //ctor
}

void ManagerRep::addPizza(const Pizza &pizza) {

    ofstream fout;
    fout.open("Pizzas_Binary.dat", ios::binary|ios::app);
    pizza.write(fout);
    fout.close();
}

void ManagerRep::addCrust(const Crust &crust) {
    ofstream fout;
    fout.open("Crust_Binary.dat", ios::binary|ios::app);
    crust.write(fout);
    fout.close();
}

void ManagerRep::addTopping(const Topping &topping) {
    ofstream fout;
    fout.open("Topping_Binary.dat", ios::binary|ios::app);
    topping.write(fout);
    fout.close();
}

void ManagerRep::addDrink(const Drink &drink) {
    ofstream fout;
    fout.open("Drink_Binary.dat", ios::binary|ios::app);
    drink.write(fout);
    fout.close();
}

void ManagerRep::addSidedish(const Sidedish &sidedish) {
    ofstream fout;
    fout.open("Sidedish_Binary.dat", ios::binary|ios::app);
    sidedish.write(fout);
    fout.close();
}

void ManagerRep::addBranch(const Branch &branch) {
    ofstream fout;
    fout.open("Branch_Binary.dat", ios::binary|ios::app);
    branch.write(fout);
    fout.close();
}

void ManagerRep::addUser(const User &user) {
    ofstream fout;
    fout.open("Users_Binary.dat", ios::binary|ios::app);
    user.write(fout);
    fout.close();
}

vector<Pizza> ManagerRep::getPizza() {
    vector <Pizza> pizzas;
    ifstream fin;
    fin.open("Pizzas_Binary.dat", ios::binary);
    if (fin.is_open()) {
        while(!fin.eof()){
            Pizza pizza;
            pizza.read(fin);
            if(!fin.eof()){
                pizzas.push_back(pizza);
            }
        }
        fin.close();
    }
    return pizzas;
}

vector<Crust> ManagerRep::getCrust() {
    vector <Crust> crusts;
    ifstream fin;
    fin.open("Crust_Binary.dat", ios::binary);
    Crust crust;
    if (fin.is_open()) {
        while(!fin.eof()){
            crust.read(fin);
            if(!fin.eof()){
                crusts.push_back(crust);
            }
        }
        fin.close();
    }
    return crusts;
}

vector<Topping> ManagerRep::getTopping() {
    vector <Topping> toppings;
    ifstream fin;
    fin.open("Topping_Binary.dat", ios::binary);
    Topping topping;
    if (fin.is_open()) {
        while(!fin.eof()){
            topping.read(fin);
            if(!fin.eof()){
                toppings.push_back(topping);
            }
        }
        fin.close();
    }
    return toppings;
}

vector<Drink> ManagerRep::getDrink() {
    vector <Drink> drinks;
    ifstream fin;
    fin.open("Drink_Binary.dat", ios::binary);
    Drink drink;
    if (fin.is_open()) {
        while(!fin.eof()){
            drink.read(fin);
            if(!fin.eof()){
                drinks.push_back(drink);
            }
        }
    }
    fin.close();
    return drinks;
}

vector<Sidedish> ManagerRep::getSidedish() {
    vector <Sidedish> sidedishes;
    ifstream fin;
    fin.open("Sidedish_Binary.dat", ios::binary);
    Sidedish sidedish;
    if (fin.is_open()) {
        while(!fin.eof()){
            sidedish.read(fin);
            if(!fin.eof()){
                sidedishes.push_back(sidedish);
            }
        }
        fin.close();
    }
    return sidedishes;
}

vector<Branch> ManagerRep::getBranch() {
    vector <Branch> branches;
    ifstream fin;
    fin.open("Branch_Binary.dat", ios::binary);
    Branch branch;
    if (fin.is_open()) {
        while(!fin.eof()){
            branch.read(fin);
            if(!fin.eof()){
                branches.push_back(branch);
            }
        }
    }
    fin.close();
    return branches;
}

vector<User> ManagerRep::getUser() {
    vector <User> users;
    ifstream fin;
    fin.open("Users_Binary.dat", ios::binary);
    User user;
    if (fin.is_open()) {
        while(!fin.eof()){
            user.read(fin);
            if(!fin.eof()){
                users.push_back(user);
            }
        }
    }
    fin.close();
    return users;
}

vector<Order> ManagerRep::getLegacyOrder() {
    vector <Order> orders;
    ifstream fin;
    fin.open("LegacyOrder_Binary.dat", ios::binary);
    if (fin.is_open()) {
        while(!fin.eof()){
            Order order;
            order.read(fin);
            if(!fin.eof()){
                orders.push_back(order);
            }
        }
        fin.close();
    }
    return orders;
}

vector<Order> ManagerRep::getWaterlooOrder() {
    vector <Order> orders;
    ifstream fin;
    fin.open("WaterlooOrder_Binary.dat", ios::binary);
    if (fin.is_open()) {
        while(!fin.eof()){
            Order order;
            order.read(fin);
            if(!fin.eof()){
                orders.push_back(order);
            }
        }
        fin.close();
    }
    return orders;
}

void ManagerRep::changePizzaList(vector<Pizza> &pizzas) {

    ofstream fout;
    fout.open("Pizzas_Binary.dat", ios::binary);
    for (unsigned int i = 0; i < pizzas.size(); i++) {
        pizzas[i].write(fout);
    }
    fout.close();
}

void ManagerRep::changeCrustList(vector<Crust> &crusts) {

    ofstream fout;
    fout.open("Crust_Binary.dat", ios::binary);
    for (unsigned int i = 0; i < crusts.size(); i++) {
        crusts[i].write(fout);
    }
    fout.close();
}

void ManagerRep::changeToppingList(vector<Topping> &toppings) {

    ofstream fout;
    fout.open("Topping_Binary.dat", ios::binary);
    for (unsigned int i = 0; i < toppings.size(); i++) {
        toppings[i].write(fout);
    }
    fout.close();
 }

void ManagerRep::changeDrinkList(vector<Drink> &drinks) {

    ofstream fout;
    fout.open("Drink_Binary.dat", ios::binary);
    for (unsigned int i = 0; i < drinks.size(); i++) {
        drinks[i].write(fout);
    }
    fout.close();
}

void ManagerRep::changeSidedishList(vector<Sidedish> &sidedishes) {

    ofstream fout;
    fout.open("Sidedish_Binary.dat", ios::binary);
    for (unsigned int i = 0; i < sidedishes.size(); i++) {
        sidedishes[i].write(fout);
    }
    fout.close();
}

 void ManagerRep::changeBranchList(vector<Branch> &branches) {

    ofstream fout;
    fout.open("Branch_Binary.dat", ios::binary);
    for (unsigned int i = 0; i < branches.size(); i++) {
        branches[i].write(fout);
    }
    fout.close();
 }

void ManagerRep::changeUsersList(vector<User> &users) {

    ofstream fout;
    fout.open("Users_Binary.dat", ios::binary);
    for (unsigned int i = 0; i < users.size(); i++) {
        users[i].write(fout);
    }
    fout.close();
}
