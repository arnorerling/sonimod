#include "SalesUI.h"


SalesUI::SalesUI(){

}
void SalesUI::startUI() {
    system("CLS");
    printLogo();
    Order order;
    addCustomer();

    char select = '\0';
    while (select != '7') {
        select = '\0';
        cout << "------------------" << endl;
        cout << "1: Add Pizza" << endl;
        cout << "2: Add pizza from menu" << endl;
        cout << "3: Add Sidedish" << endl;
        cout << "4: Add drink" << endl;
        cout << "5: Print order" << endl;
        cout << "6: Get order total" << endl;
        cout << "7: File order" << endl;
        cout << "8: Quit" << endl;
        cout << "------------------" << endl;
        cin >> select;

        switch(select){
            case '1': {
                addPizza();
                break;
            }
            case '2': {
                printPizzas();
                addPizzaMenu();
                break;
            }
            case '3': {
                printSidedishes();
                addSidedish();
                break;
            }
            case '4': {
                printDrinks();
                addDrink();
                break;
            }
            case '5': {
                cout << this->order;
                break;
            }
            case '6': {
                cout << "Order total: "<< this->order.getTotal() << endl;
                break;
            }
            case '7': {
                fileOrder();
                select = '7';
                break;
            }
            case '8': {
                cout << endl;
                break;
            }
        }
    }
}

void SalesUI::addCustomer(){
    bool allowed = false;
    cout << "Customers's name: ";
    string name = validName();
    cout << "Customers's number: ";
    string phoneNumber = validPhoneNumber();
    order.addCustomerName(name);
    order.addCustomerPhoneNum(phoneNumber);
}

void SalesUI::addPizza(){
    Pizza pizza;
    this->addCrust(pizza);
    this->addToppings(pizza);
    pizza.setPrice();
    order.addPizza(pizza);
}

void SalesUI::addPizzaMenu(){

    Pizza pizza;
    this->choosePizza(pizza);
    this->addCrust(pizza);
    order.addPizza(pizza);
}

void SalesUI::choosePizza(Pizza &pizza){
    bool available = false;
    while(!available) {
        cout << "Pizza name: ";
        string name = validName();
        try{
            available = salesDomain.checkPizzaAvailability(name, pizza);
            pizza.setName(name);
        }
        catch(NotFoundException){
            cout << "Pizza not available!" << endl;
        }
    }
}

void SalesUI::addCrust(Pizza &pizza){
    printCrusts();
    bool available = false;
    while(!available) {
        cout << "Crust name: ";
        string name = validName();
        cout << "Crust size: ";
        int size = validNumber();
        Crust crust(name,size);
        try{
            available = salesDomain.checkCrustAvailability(crust);
            pizza.addCrust(crust);
        }
        catch(NotFoundException){
            cout << "Crust not available!" << endl;
        }
    }
}

void SalesUI::addToppings(Pizza &pizza){
    printToppings();
    string name;
    char addTopping = 'y';
    while(addTopping == 'y'){
        cout << "Topping name: ";
        string name = validName();
        Topping topping(name);
        try{
            salesDomain.checkToppingAvailability(topping);
            pizza.addTopping(topping);
            cout << "Add another topping?" << endl;
        }
        catch(NotFoundException){
            cout << "Topping not avaliable!" << endl;
            cout << "Try another topping? " << endl;
        }
    addTopping = validAnswer();
    }
}

void SalesUI::addDrink(){
    bool available = false;
    string name;
    int size = 0;
    while(!available){
        cout << "Drink name: ";
        string name = validName();
        cout << "Size: ";
        int size = validNumber();
        Drink drink(name, size);
        try{
            available = salesDomain.checkDrinkAvailability(drink);
            this->order.addDrink(drink);
        }
        catch(NotFoundException){
            cout << "Drink not available!" << endl;
        }
        catch(NotFoundException){
            cout << "Size not available!" << endl;
        }
    }
}

void SalesUI::addSidedish(){
    bool available = false;
    while(!available){
        cout << "Sidedish name: ";
        string name = validName();
        Sidedish sidedish(name);
        try{
            available = salesDomain.checkSidedishAvailability(sidedish);
            this->order.addSideDish(sidedish);
        }
        catch(NotFoundException){
            cout << "Sidesish not available!" << endl;
        }
    }
}

void SalesUI::addBranch(){
    bool found = false;
    while(!found){
        cout << "Restaurant name: ";
        string branch = validName();
        try{
        found = salesDomain.checkBranchAvailability(branch);
        this->order.addBranch(branch);
        }
        catch(NotFoundException){
            cout << "Branch not found" << endl;
        }
    }
}

void SalesUI::addAddress(){
    cout << "Customers address: ";
    string address;
    cin >> ws;
    getline(cin, address);
    salesDomain.toLowerCase(address);
    if(address == ""){
        this->order.setPickup(true);
    }
    else {
        this->order.addCustomerAddress(address);
        cout << order.getCustomerAddress() << endl;
    }

}

void SalesUI::printPizzas(){
    vector<Pizza> pizzas;
    salesDomain.getPizzas(pizzas);
    cout << "Pizza menu" << endl;
    for(unsigned int i = 0; i < pizzas.size(); i++){
        cout << pizzas[i] << endl;
    }
}

void SalesUI::printCrusts(){
    vector<Crust> crusts;
    salesDomain.getCrusts(crusts);
    cout << "Crust menu" << endl;
    for(unsigned int i = 0; i < crusts.size(); i++){
        cout << crusts[i];
    }
}

void SalesUI::printToppings(){
    vector<Topping> toppings;
    salesDomain.getToppings(toppings);
    cout << "Toppings menu" << endl;
    for(unsigned int i = 0; i < toppings.size(); i++){
        cout << toppings[i];
    }
}

void SalesUI::printDrinks() {
    vector<Drink> drinks;
    salesDomain.getDrinks(drinks);
    cout << "Drink menu" << endl;
    for(unsigned int i = 0; i < drinks.size(); i++){
        cout << drinks[i];
    }

}

void SalesUI::printSidedishes() {
    vector<Sidedish> sidedishes;
    salesDomain.getSidedishes(sidedishes);
    cout << "Sidedish menu" << endl;
    for(unsigned int i = 0; i < sidedishes.size(); i++){
        cout << sidedishes[i];
    }
}

void SalesUI::fileOrder(){
    addBranch();
    addAddress();
    salesDomain.fileOrder(this->order);
    cout << "Order filed!" << endl;

}

string SalesUI::validName() {
    string name = "";
    bool allowed = false;

    while(!allowed) {
        cin >> ws;
        getline(cin, name);
        salesDomain.toLowerCase(name);
        try{
            allowed = salesDomain.isValidName(name);
        }
        catch(InvalidInputException){
            cout << "Invalid name, try again!" << endl;
        }
    }
    return name;
}

string SalesUI::validPhoneNumber() {
    string phoneNumber = "";
    bool allowed = false;

    while(!allowed) {
        cin >> ws;
        getline(cin, phoneNumber);
        try{
            allowed = salesDomain.isValidPhoneNumber(phoneNumber);
        }
        catch(InvalidInputException){
            cout << "Invalid phonenumber, try again!" << endl;
        }
    }
    return phoneNumber;
}

int SalesUI::validNumber() {
    string number = "";
    int number1 = 0;
    bool allowed = false;

    while(!allowed) {
        cin >> ws;
        getline(cin, number);
        try{
            number1 = salesDomain.isValidNumber(number);
            allowed = true;
        }
        catch(InvalidInputException){
            cout << "Invalid number, try again!" << endl;
        }
    }
    return number1;
}

char SalesUI::validAnswer() {
    string answer = "";
    char answer1 = '\0';
    bool allowed = false;

    while(!allowed){
        cin >> ws;
        getline(cin, answer);
        try{
            allowed = salesDomain.checkValidAnswer(answer);
            answer1 = answer[0];
        }
        catch(InvalidInputException){
            cout << "Invalid answer, please answer \'y\' or \'n\'" << endl;
        }
    }
    return answer1;
}

void SalesUI::printLogo() {
cout << "____ ____ _    ____ ____ " << endl;
cout << "[__  |__| |    |___ [__  " << endl;
cout << "___] |  | |___ |___ ___] " << endl;
}
