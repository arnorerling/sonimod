#include "SalesUI.h"


SalesUI::SalesUI() {

}

void SalesUI::startUI() {

    char select = '\0';
    while (select != '0') {
        output.clean();
        printLogo();
        select = '\0';
        cout << "------------------" << endl;
        cout << "1: Add pizza" << endl;
        cout << "2: Add pizza from menu" << endl;
        cout << "3: Add sidedish" << endl;
        cout << "4: Add drink" << endl;
        cout << "5: Print order" << endl;
        cout << "6: Get order total" << endl;
        cout << "7: File order" << endl;
        cout << "0: Quit" << endl;
        cout << "------------------" << endl;
        select = checkInput();

        switch(select) {
            case '1': {
                output.clean();
                this->addPizza();
                break;
            }
            case '2': {
                output.clean();
                this->addPizzaMenu();
                break;
            }
            case '3': {
                output.clean();
                this->addSidedish();
                break;
            }
            case '4': {
                output.clean();
                this->addDrink();
                break;
            }
            case '5': {
                output.clean();
                cout << this->order;
                output.wait();
                break;
            }
            case '6': {
                output.clean();
                cout << "Order total: "<< this->order.getTotalPrice() << "kr" << endl;
                output.wait();

                break;
            }
            case '7': {
                output.clean();
                this->fileOrder();
                break;
            }
            case '0': {
                output.clean();
                cout << "Have a good day!" << endl;
                break;
            }
            default:
                cout << "Invalid input" << endl;
                output.wait();
        }
        this->order.setTotal();
    }

}

void SalesUI::addCustomer() {
    cout << "Customers's name: ";
    string name = validName();
    cout << "Customers's number: ";
    string phoneNumber = validPhoneNumber();
    this->order.addCustomerName(name);
    this->order.addCustomerPhoneNum(phoneNumber);
}

void SalesUI::addPizza() {
    try{
        Pizza pizza;
        int size = 0;
        this->addCrust(pizza, size);
        output.clean();
        this->addToppings(pizza);
        pizza.setPrice();
        this->order.addPizza(pizza);
    }
    catch(FileNotOpenException) {
        cout << "Adding a pizza not available!, topping file not found" << endl;
        output.salesWait();
    }
    catch(CrustFileNotFoundException) {
        cout << "Adding a pizza not available!, crust file not found" << endl;
        output.salesWait();
    }
    catch(LengthNotRightException) {
        cout << "Crust file empty!" << endl;
        output.wait();
    }
    catch(LengthNotRightException) {
        cout << "Topping file empty" << endl;
        output.wait();
    }
}

void SalesUI::addPizzaMenu() {
    try {
        Pizza pizza;
        int size = 0;
        this->addCrust(pizza, size);
        output.clean();
        this->choosePizza(pizza, size);
        this->order.addPizza(pizza);
    }
    catch(FileNotOpenException) {
        cout << "Adding a pizza not available!, pizza file not found" << endl;
        output.wait();
    }
    catch(CrustFileNotFoundException) {
        cout << "Adding a pizza not available!, crust file not found" << endl;
        output.salesWait();
    }
    catch(LengthNotRightException) {
        cout << "Pizza file empty!!" << endl;
        output.wait();
    }
    catch(LengthNotRightException) {
        cout << "Crust file empty!" << endl;
        output.wait();
    }

}

void SalesUI::choosePizza(Pizza &pizza, int &size) {
    bool available = false;
    while(!available) {
        try {
            printPizzas();
            cout << "Pizza name: ";
            string name = validName();
            available = salesDomain.checkPizzaAvailability(name,size , pizza);
            pizza.setName(name);
        }
        catch(NotFoundException) {
            cout << "Pizza file not available!" << endl;
            output.salesWait();
        }
    }
}

void SalesUI::addCrust(Pizza &pizza, int &size) {
    bool available = false;
    while(!available) {
        try{
            printCrusts();
            cout << "Crust name: ";
            string name = validName();
            cout << "Crust size: ";
            size = validNumber();
            Crust crust(name,size);
            available = salesDomain.checkCrustAvailability(crust);
            pizza.addCrust(crust);
        }
        catch(NotFoundException) {
            cout << "Crust not available!" << endl;
            output.wait();
        }
        output.clean();
    }
}

void SalesUI::addToppings(Pizza &pizza) {
    string name;
    char addTopping = 'y';
    while(addTopping == 'y') {
    try {
        printToppings();
        cout << "Topping name: ";
        string name = validName();
        Topping topping(name);
        salesDomain.checkToppingAvailability(topping);
        pizza.addTopping(topping);
        cout << "Add another topping (y/n)?";
        }
        catch(NotFoundException) {
            cout << "Topping not avaliable!" << endl;
            cout << "Try another topping (y/n)? ";
        }
        addTopping = validAnswer();
        output.clean();
    }
}

void SalesUI::addDrink() {
    bool available = false;
    string name;
    while(!available) {
        try {
            this->printDrinks();
            cout << "Drink name: ";
            string name = validName();
            cout << "Size: ";
            int size = validNumber();
            Drink drink(name, size);
            available = salesDomain.checkDrinkAvailability(drink);
            this->order.addDrink(drink);
        }
        catch(NotFoundException) {
            cout << "Drink not available!" << endl;
            output.wait();
        }
        catch(FileNotOpenException) {
            cout << "Drink file not found" << endl;
            output.wait();
            break;
        }
        catch(LengthNotRightException) {
            cout << "Drink file empty" << endl;
            output.wait();
            break;
        }
    }
}

void SalesUI::addSidedish() {

    bool available = false;
    while(!available) {
        try {
            this->printSidedishes();
            cout << "Sidedish name: ";
            string name = validName();
            Sidedish sidedish(name);
            available = salesDomain.checkSidedishAvailability(sidedish);
            this->order.addSideDish(sidedish);
        }
        catch(NotFoundException) {
            output.clean();
            cout << "Sidedish not available!" << endl;
            output.wait();
        }
        catch(FileNotOpenException) {
            cout << "Sidedish file not found" << endl;
            output.wait();
            break;
        }
        catch(LengthNotRightException) {
            cout << "Sidedish file empty" << endl;
            output.wait();
            break;
        }
    }
}

void SalesUI::addBranch() {
    bool found = false;
    while(!found) {
        try {
        printBranches();
        cout << "Restaurant name: ";
        string branch = validName();

        found = salesDomain.checkBranchAvailability(branch);
        this->order.addBranch(branch);
        }
        catch(NotFoundException) {
            cout << "Branch not found" << endl;
        }
    }
}

void SalesUI::addAddress() {
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
        cout << this->order.getCustomerAddress() << endl;
    }

}

void SalesUI::printPizzas() {
    vector<Pizza> pizzas = salesDomain.getPizzas();
     cout << "-------------------Pizza menu--------------------" << endl;
    cout << setw(15) << "Name" << setw(10) << "14\"";
    cout << setw(10) << "16\"" << setw(10) << "18\"" << endl;
    cout << "--------------------------------------------------" << endl;
    for(unsigned int i = 0; i < pizzas.size(); i++) {
        if (i % 3 == 0) {
            if (i != 0) {
                cout << endl;
            }
            cout << setw(15) << pizzas[i].getName();
        }
        cout << setw(8) << pizzas[i].getPrice() << "kr ";
    }
    cout << endl;
    cout << "---------------------------------------------------" << endl;
}

void SalesUI::printCrusts() {
    vector<Crust> crusts = salesDomain.getCrusts();
    cout << "--------------------Crust menu--------------------" << endl;
    cout << setw(15) << "Name" << setw(10) << "14\"";
    cout << setw(10) << "16\"" << setw(10) << "18\"" << endl;
    cout << "--------------------------------------------------" << endl;
    for(unsigned int i = 0; i < crusts.size(); i++){
        if (i % 3 == 0) {
            if (i != 0) {
                cout << endl;
            }
            cout << setw(15) << crusts[i].getName();
        }
        cout << setw(8) << crusts[i].getPrice() << "kr ";
    }
    cout << endl;
    cout << "---------------------------------------------------" << endl;
}

void SalesUI::printToppings() {
    vector<Topping> toppings = salesDomain.getToppings();
    cout << "-----------Toppings menu-----------" << endl;
    cout << setw(15) << "Name" << setw(10) << "Price" << endl;
    cout << "-----------------------------------" << endl;
    for(unsigned int i = 0; i < toppings.size(); i++) {
        cout << setw(15) << toppings[i].getName();
        cout << setw(10) << toppings[i].getPrice() << endl;
    }
    cout << "-----------------------------------" << endl;
}

void SalesUI::printDrinks() {
    vector<Drink> drinks = salesDomain.getDrinks();
    cout << "------------Drinks menu------------" << endl;
    cout << setw(15) << "Name" << setw(8) << "1L" << setw(8) << "2L" << endl;
    cout << "-----------------------------------" << endl;
    for(unsigned int i = 0; i < drinks.size(); i++) {
        if (i%2 == 0) {
            if(i != 0) {
                cout << endl;
            }
            cout << setw(15) << drinks[i].getName();
        }
        cout << setw(8) << drinks[i].getPrice();
    }
    cout << endl;
    cout << "-----------------------------------" << endl;

}

void SalesUI::printSidedishes() {
    vector<Sidedish> sidedishes = salesDomain.getSidedishes();
    cout << "-----------Sidedish menu-----------" << endl;
    cout << setw(18) << "Name" << setw(10) << "Price" << endl;
    cout << "-----------------------------------" << endl;
    for(unsigned int i = 0; i < sidedishes.size(); i++){
        cout << setw(18) << sidedishes[i].getName();
        cout << setw(10) << sidedishes[i].getPrice() << endl;
    }
    cout << "-----------------------------------" << endl;
}

void SalesUI::printBranches() {
    vector<Branch> branches = salesDomain.getBranches();
    cout << "--------------branches--------------" << endl;
    for(unsigned int i = 0; i < branches.size(); i++){
        cout << branches[i].getName() << endl;
    }
    cout << "------------------------------------" << endl;
}

void SalesUI::fileOrder(){
    try{
        salesDomain.checkOrder(this->order);
        this->addBranch();
        this->addCustomer();
        this->order.setTime();
        order.addComment(this->addComment());
        cout << "Mark as paid(y/n): ";
        char paidFor = validAnswer();
        if(paidFor == 'y'){
            salesDomain.markOrderPaidFor(this->order);
            cout << "Order marked as paid." << endl;
        }
        cout << "Pickup? (y/n): ";
        char pickup = validAnswer();
        if(pickup == 'y'){
            order.setPickup(true);
            cout << "Order marked as pickup order." << endl;
        } else {
            addAddress();
        }
        salesDomain.fileOrder(this->order);
        cout << "Order filed!" << endl;
        output.clean();
        this->order.cleanOrder();
    }
    catch(FileNotOpenException) {
        cout << "Branch file not found" << endl;
        cout << "Please call IT, order can not be filed!" << endl;
        output.wait();
    }
    catch(CantFileOrderException) {
        cout << "There is nothing in the Order, Order wont be filed!" << endl;
        output.wait();
    }
    catch(LengthNotRightException) {
        cout << "Branch file empty call IT" << endl;
        output.wait();
    }
}

string SalesUI::addComment(){
    cout << "Add comment: ";
    string comment;
    cin >> ws;
    getline(cin, comment);
    return comment;
}

string SalesUI::validName() {
    string name = "";
    bool allowed = false;

    while(!allowed) {
        cin >> ws;
        getline(cin, name);
        salesDomain.toLowerCase(name);
        try {
            allowed = salesDomain.isValidName(name);
        }
        catch(InvalidInputException) {
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
        try {
            allowed = salesDomain.isValidPhoneNumber(phoneNumber);
        }
        catch(InvalidInputException) {
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
        try {
            number1 = salesDomain.isValidNumber(number);
            allowed = true;
        }
        catch(InvalidInputException) {
            cout << "Invalid number, try again!" << endl;
        }
    }
    return number1;
}

char SalesUI::validAnswer() {
    string answer = "";
    char answer1 = '\0';
    bool allowed = false;

    while(!allowed) {
        cin >> ws;
        getline(cin, answer);
        try {
            allowed = salesDomain.checkValidAnswer(answer);
            answer1 = answer[0];
        }
        catch(InvalidInputException) {
            cout << "Invalid answer, please answer \'y\' or \'n\'" << endl;
        }
    }
    return answer1;
}

char SalesUI::checkInput() {
    string input = "";
    char input1 = '\0';
    bool allowed = false;

    while(!allowed) {
        cin >> ws;
        getline(cin, input);
        try{
            allowed = salesDomain.checkValidInput(input);
            input1 = input[0];
        }
        catch(InvalidInputException) {
            cout << "Invalid input" << endl;
        }
    }
    return input1;
}
void SalesUI::printLogo() {
    cout << "____ ____ _    ____ ____ " << endl;
    cout << "[__  |__| |    |___ [__  " << endl;
    cout << "___] |  | |___ |___ ___] " << endl;
}
