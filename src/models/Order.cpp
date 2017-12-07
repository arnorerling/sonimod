#include "Order.h"
#include "Sidedish.h"

Order::Order()
{
//ctor
}

void Order::addPizza(Pizza& pizza){
    this->pizzas.push_back(pizza);
}

void Order::addSideDish(Sidedish& sidedish){
    this->sideDishes.push_back(sidedish);
}

void Order::addDrink(Drink& drink){
    this->drinks.push_back(drink);
}

void Order::addCustomerName(string name){
    this->custumerName = name;
}
void Order::addBranch(string branch){
    this->branch = branch;
}

void Order::addCustomerPhoneNum(string num){
    this->phoneNumber = num;
}
string Order::getCustomerName(){
    return this->custumerName;
}
string Order::getCustomerPhoneNumber(){
    return this->phoneNumber;
}

ostream& operator << (ostream& out, Order& order){
    out << "------------------------------------------------------" << endl;
    out << "Customer Name: " << order.getCustomerName() << endl;
    out << "Customer number: " << order.getCustomerPhoneNumber() << endl;

    if (order.pizzas.size() > 0) {
        out << "Pizzas: " << endl;
        for(unsigned int i = 0; i < order.pizzas.size(); i++){
            out << order.pizzas[i] << endl;
        }
    }

    if (order.sideDishes.size() > 0) {
        out << "Sidedishes: " << endl;
        for(unsigned int i = 0; i < order.sideDishes.size(); i++){
            out << order.sideDishes[i].getName() << endl;
        }
    }
    if (order.drinks.size() > 0) {
        out << "Drinks: " << endl;
        for(unsigned int i = 0; i < order.drinks.size(); i++){
            out << order.drinks[i].getName() << endl;
        }
    }

    out << "Order total: " << order.getTotal() << endl;
    return out;
}

int Order::getTotal(){
    int total = 0;
    for(unsigned int i = 0; i < this->pizzas.size(); i++){
        total += this->pizzas[i].getPrice();
    }
    for(unsigned int i = 0; i < this->sideDishes.size(); i++){
        total += this->sideDishes[i].getPrice();
    }
    for(unsigned int i = 0; i < this->drinks.size(); i++){
        total += this->drinks[i].getPrice();
    }
    return total;
}

void Order::write(ofstream& fout) const {

    int strLen = custumerName.length() + 1;
    fout.write((char*)(&strLen), sizeof(int));
    fout.write(custumerName.c_str(), strLen);
    int strLen1 = phoneNumber.length() + 1;
    fout.write((char*)(&strLen1), sizeof(int));
    fout.write(phoneNumber.c_str(), strLen1);
    int strLen2 = branch.length() + 1;
    fout.write((char*)(&strLen2), sizeof(int));
    fout.write(branch.c_str(), strLen2);

    int tCount = pizzas.size();
    fout.write((char*)(&tCount), sizeof(int));

    for (int i = 0; i < tCount; i++) {
        pizzas[i].write(fout);
    }

    int tCount1 = drinks.size();
    fout.write((char*)(&tCount1), sizeof(int));

    for (int i = 0; i < tCount1; i++) {
        drinks[i].write(fout);
    }

    int tCount2 = sideDishes.size();
    fout.write((char*)(&tCount2), sizeof(int));

    for (int i = 0; i < tCount2; i++) {
        sideDishes[i].write(fout);
    }

    fout.write((char*)(&totalPrice), sizeof(int));

    fout.write((char*)(&paidFor), sizeof(char));

    fout.write((char*)(&ready), sizeof(char));

    fout.write((char*)(&deliverd), sizeof(char));

}

void Order::read(ifstream& fin) {

    int strLen;
    int strLen1;
    int strLen2;
    fin.read((char*)(&strLen), sizeof(int));
    char *str = new char[strLen];
    fin.read(str, strLen);
    custumerName = str;

    fin.read((char*)(&strLen1), sizeof(int));
    char *str1 = new char[strLen1];
    fin.read(str1, strLen1);
    phoneNumber = str1;

    fin.read((char*)(&strLen2), sizeof(int));
    char *str2 = new char[strLen2];
    fin.read(str2, strLen2);
    branch = str2;

    int tCount;
    fin.read((char*)(&tCount), sizeof(int));

    Pizza pizza;
    for (int i = 0; i < tCount; i++) {
        pizza.read(fin);
        pizzas.push_back(pizza);
    }

    int tCount1;
    fin.read((char*)(&tCount1), sizeof(int));

    Drink drink;
    for (int i = 0; i < tCount1; i++) {
        drink.read(fin);
        drinks.push_back(drink);
    }

    int tCount2;
    fin.read((char*)(&tCount2), sizeof(int));

    Sidedish sidedish;
    for (int i = 0; i < tCount2; i++) {
        sidedish.read(fin);
        sideDishes.push_back(sidedish);
    }

    fin.read((char*)(&totalPrice), sizeof(int));

    fin.read((char*)(&paidFor), sizeof(char));

    fin.read((char*)(&ready), sizeof(char));

    fin.read((char*)(&deliverd), sizeof(char));


    delete[] str;
    delete[] str1;
    delete[] str2;
}
