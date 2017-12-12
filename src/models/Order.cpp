#include "Order.h"
#include "Sidedish.h"

Order::Order()
{
    this->customerAddress = "";
    this->ready = false;
    this->deliverd = false;
    this->paidFor = false;
    this->inProcess = false;
    this->pickup = false;
    this->branch = "";
    this->customerAddress = "";
    this->orderTime = time(0);
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


void Order::addCustomerName(const string &name){
    this->customerName = name;
}
void Order::addCustomerPhoneNum(const string &num){
    this->phoneNumber = num;
}
void Order::addCustomerAddress(const string &address){
    this->customerAddress = address;
}
void Order::addBranch(const string &branch){
    this->branch = branch;
}
void Order::addComment(string comment){
    this->comment = comment;
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
void Order::setTime(){
    this->orderTime = time(0);
}

void Order::addTotalPrice(int price) {
    this->totalPrice += price;
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

string Order::getTimeString() const {
    string timeString = ctime(&orderTime);
    timeString.erase(timeString.size() - 1 );
    return timeString;
}

time_t Order::getTime() const{
    return this->orderTime;
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

int Order::getTotal() const{
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

int Order::getTotalPrice() const {
    return this->totalPrice;
}

void Order::cleanOrder(){
    this->pizzas.clear();
    this->drinks.clear();
    this->sideDishes.clear();

    this->customerName = "";
    this->phoneNumber = "";
    this->customerAddress = "";
    this->branch = "";

    this->paidFor = false;
    this->inProcess = false;
    this->ready = false;
    this->deliverd = false;
    this->pickup = false;
    this->orderTime = 0;

    this->totalPrice = 0;
}

ostream& operator << (ostream& out, const Order& order){
    out << "------------------------------------------------------" << endl;
    out << "Order time: " << ctime(&order.orderTime);
    if(order.ready){
        out << "Customer Name: " << order.getCustomerName() << endl;
        out << "Customer number: " << order.getCustomerPhoneNumber() << endl;
        out << "Customer adress: " << order.getCustomerAddress() << endl;
    }
    out << endl;

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
    out << endl;
    out << "Order total: " << order.getTotal() << endl << endl;
    /*out << endl;

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
    */
    if (order.pickup) {
        out << "Order will be picked up at ";
        out << order.getBranch() << endl;
    }
    else {
        out << "Deliver to address ";
        out << order.getCustomerAddress() << endl;
    }


    return out;
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

    int strLen2 = customerAddress.length() + 1;
     fout.write((char*)(&strLen2), sizeof(int));
    fout.write(customerAddress.c_str(), strLen2);

    int strLen3 = branch.length() + 1;
    fout.write((char*)(&strLen3), sizeof(int));
    fout.write(branch.c_str(), strLen3);

    int strLen4 = comment.length() + 1;
    fout.write((char*)(&strLen4), sizeof(int));
    fout.write(comment.c_str(), strLen4);

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
    fout.write((char*)(&orderTime), sizeof(long));

}

void Order::read(ifstream& fin) {

    int strLen = 0, strLen1 = 0, strLen2 = 0, strLen3 = 0, strLen4 = 0;
    fin.read((char*)(&strLen), sizeof(int));
    char *str = new char[strLen];
    fin.read(str, strLen);
    this->customerName = str;

    fin.read((char*)(&strLen1), sizeof(int));
    char *str1 = new char[strLen1];
    fin.read(str1, strLen1);
    this->phoneNumber = str1;

    fin.read((char*)(&strLen2), sizeof(int));
    char *str2 = new char[strLen2];
    fin.read(str2, strLen2);
    this->customerAddress = str2;

    fin.read((char*)(&strLen3), sizeof(int));
    char *str3 = new char[strLen3];
    fin.read(str3, strLen3);
    this->branch = str3;

    fin.read((char*)(&strLen4), sizeof(int));
    char *str4 = new char[strLen4];
    fin.read(str4, strLen4);
    this->comment = str4;

    delete[] str;
    delete[] str1;
    delete[] str2;
    delete[] str3;
    delete[] str4;

    int tCount = 0;
    fin.read((char*)(&tCount), sizeof(int));

    for (int i = 0; i < tCount; i++) {
        Pizza pizza;
        pizza.read(fin);
        pizzas.push_back(pizza);
    }

    int tCount1 = 0;
    fin.read((char*)(&tCount1), sizeof(int));

    for (int i = 0; i < tCount1; i++) {
        Drink drink;
        drink.read(fin);
        drinks.push_back(drink);
    }

    int tCount2 = 0;
    fin.read((char*)(&tCount2), sizeof(int));

    for (int i = 0; i < tCount2; i++) {
        Sidedish sidedish;
        sidedish.read(fin);
        sideDishes.push_back(sidedish);
    }

    fin.read((char*)(&totalPrice), sizeof(int));
    fin.read((char*)(&paidFor), sizeof(char));
    fin.read((char*)(&inProcess), sizeof(char));
    fin.read((char*)(&ready), sizeof(char));
    fin.read((char*)(&deliverd), sizeof(char));
    fin.read((char*)(&pickup), sizeof(char));
    fin.read((char*)(&orderTime), sizeof(long));
}
