#include "Order.h"
#include "Sidedish.h"

Order::Order()
{
    this->ready = false;
    this->deliverd = false;
    this->paidFor = false;
    this->inProcess = false;
    this->pickup = false;
    this->branch = "";
    this->customerAddress = "";

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
    this->customerName = name;
}
void Order::addCustomerPhoneNum(string num){
    this->phoneNumber = num;
}
void Order::addCustomerAddress(string address){
    this->customerAddress = address;
}
void Order::addBranch(string branch){
    this->branch = branch;
}

void Order::setPaidFor(bool paidFor) {
    this->paidFor = paidFor;
}
void Order::setInProcess(bool inProcess) {
    this->inProcess = inProcess;
}
void Order::setReady(bool ready) {
    this->ready = ready;
}
void Order::setDeliverd(bool deliverd) {
    this->deliverd = deliverd;
}
void Order::setPickup(bool pickup) {
    this->pickup = pickup;
}


string Order::getCustomerName() const{
    return this->customerName;
}
string Order::getCustomerPhoneNumber() const{
    return this->phoneNumber;
}
string Order::getCustomerAddress() const{
    return this->customerAddress;
}
string Order::getBranch() const{
    return this->branch;
}

bool Order::getPaidFor() const {
    return paidFor;
}
bool Order::getInProcess() const{
    return inProcess;
}
bool Order::getReady() const{
    return ready;
}
bool Order::getDeliverd() const{
    return deliverd;
}
bool Order::getPickup() const{
    return pickup;
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

    out << "Been paid for: ";
    if(order.paidFor) {
        out << "Yes!" << endl;
    }
    else {
        out << "No!" << endl;
    }
    out << "In process: ";
    if (order.inProcess) {
        out << "Yes!" << endl;
    }
    else {
        out << "No!" << endl;
    }
    out << "Is ready: ";
    if (order.ready) {
        out << "Yes!" << endl;
    }
    else {
        out << "No!" << endl;
    }
    out << "Been ";
    if (order.pickup) {
        out << "picked up at ";
        out << order.branch << ": ";
        if (order.deliverd) {
            out << "Yes!" << endl;
        }
        else {
            out << "No!" << endl;
        }
    }
    else {
        out << "delivered to address ";
        out << order.customerAddress << ": ";
        if (order.deliverd) {
            out << "Yes!" << endl;
        }
        else {
            out << "No!" << endl;
        }
    }
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

bool operator == (const Order &left_order, const Order &right_order) {
    if (left_order.phoneNumber == right_order.phoneNumber) {
        if (left_order.branch == right_order.branch) {
            return true;
        }
    }
    return false;
}

bool operator != (const Order &left_order, const Order &right_order) {
    if (left_order.phoneNumber == right_order.phoneNumber) {
        if (left_order.branch == right_order.branch) {
            return false;
        }
    }
    return true;
}

void Order::write(ofstream& fout) const {

    int strLen = customerName.length() + 1;
    fout.write((char*)(&strLen), sizeof(int));
    fout.write(customerName.c_str(), strLen);

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
    fout.write((char*)(&inProcess), sizeof(char));
    fout.write((char*)(&ready), sizeof(char));
    fout.write((char*)(&deliverd), sizeof(char));
    fout.write((char*)(&pickup), sizeof(char));

}

void Order::read(ifstream& fin) {

    int strLen = 0;
    int strLen1 = 0;
    int strLen2 = 0;
    fin.read((char*)(&strLen), sizeof(int));
    char *str = new char[strLen];
    fin.read(str, strLen);
    customerName = str;

    fin.read((char*)(&strLen1), sizeof(int));
    char *str1 = new char[strLen1];
    fin.read(str1, strLen1);
    phoneNumber = str1;

    fin.read((char*)(&strLen2), sizeof(int));
    char *str2 = new char[strLen2];
    fin.read(str2, strLen2);
    branch = str2;

    int tCount = 0;
    fin.read((char*)(&tCount), sizeof(int));

    Pizza pizza;
    for (int i = 0; i < tCount; i++) {
        pizza.read(fin);
        pizzas.push_back(pizza);
    }

    int tCount1 = 0;
    fin.read((char*)(&tCount1), sizeof(int));

    Drink drink;
    for (int i = 0; i < tCount1; i++) {
        drink.read(fin);
        drinks.push_back(drink);
    }

    int tCount2 = 0;
    fin.read((char*)(&tCount2), sizeof(int));

    Sidedish sidedish;
    for (int i = 0; i < tCount2; i++) {
        sidedish.read(fin);
        sideDishes.push_back(sidedish);
    }

    fin.read((char*)(&totalPrice), sizeof(int));
    fin.read((char*)(&paidFor), sizeof(char));
    fin.read((char*)(&inProcess), sizeof(char));
    fin.read((char*)(&ready), sizeof(char));
    fin.read((char*)(&deliverd), sizeof(char));
    fin.read((char*)(&pickup), sizeof(char));

    delete[] str;
    delete[] str1;
    delete[] str2;
}
