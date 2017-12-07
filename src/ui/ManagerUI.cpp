#include "ManagerUI.h"

ManagerUI::ManagerUI()
{
    //ctor
}

void ManagerUI::startUI() {
    system("CLS");
    cout << "Welcome Manager" << endl;
    cout << "What would you like to do?" << endl;
    char select = '\0';
    while (select != '3') {
        cout << "--------------------------" << endl;
        cout << "1: Add/Change menu" << endl;
        cout << "2: Remove from menu" << endl;
        cout << "3: Quit" << endl;
        cin >> select;

        switch(select) {
            case '1': addChangeMenu();
            break;
            case '2': removeFromMenu();
            break;
            case '3': cout << endl;
            break;
            default: cout << "Invalid input" << endl;
        }
    }
}

void ManagerUI::addChangeMenu() {
    system("CLS");
    char select = '\0';
    while (select != 'q') {
        cout << "-----Add/Change-----" << endl;
        cout << "c: Pizza crust" << endl;
        cout << "t: Pizza topping" << endl;
        cout << "p: Pizza menu" << endl;
        cout << "d: Drink" << endl;
        cout << "s: Sidedish" << endl;
        cout << "b: Branch" << endl;
        cout << "q: Quit" << endl;
        cout << "--------------------------" << endl;
        cin >> select;

        switch(select){
            case 'c': {
                printCrust();
                addCrust();
                break;
            }
            case 't': {
                printTopping();
                addTopping();
                break;
            }
            case 'p': {
                printPizza();
                addPizza();
                break;
            }
            case 'd': {
                printDrink();
                addDrink();
                break;
            }
            case 's': {
                printSide();
                addSide();
                break;
            }
            case 'b': {
                printBranch();
                addBranch();
            }
        }
    }
}

void ManagerUI::removeFromMenu() {
    system("CLS");
    char select = '\0';
    while (select != 'q') {
        cout << "-----Remove-----" << endl;
        cout << "c: Pizza crust" << endl;
        cout << "t: Pizza topping" << endl;
        cout << "p: Pizza menu" << endl;
        cout << "d: Drink" << endl;
        cout << "s: Sidedish" << endl;
        cout << "b: Branch" << endl;
        cout << "q: Quit" << endl;
        cout << "--------------------------" << endl;
        cin >> select;

        switch(select){
            case 'c':
                printCrust();
                removeCrust();
                break;
            case 't':
                printTopping();
                removeTopping();
                break;
            case 'p':
                printPizza();
                removePizza();
                break;
            case 'd':
                printDrink();
                removeDrink();
                break;
            case 's':
                printSide();
                removeSide();
                break;
            case 'b':
                printBranch();
                removeBranch();
        }
    }
}

void ManagerUI::addCrust() {
    int inches[3]= {14, 16, 18};
    cout << "----Add Crust----" << endl;
    string name = checkName();

    for (int i = 0; i < 3; i++) {
        cout<< inches[i] << "\" ";
        int price = checkPrice();
        Crust crust(name, inches[i], price);
         try {
        managerDomain.addCrust(crust);
        }
        catch(CrustChangedException) {
            cout << "price of crust \"" << crust.getName();
            cout << "\" of size " << crust.getInches();
            cout << " has been changed" << endl;
        }
    }
}

void ManagerUI::addTopping() {
    cout << "----Add Topping----" << endl;
    string name = checkName();
    int price = checkPrice();
    Topping topping(name, price);

    try {
        managerDomain.addTopping(topping);
    }
    catch(ToppingChangedException) {
        cout << "price of topping \"" << topping.getName();
        cout << "\" has been changed" << endl;

    }
}

void ManagerUI::addPizza() {
    cout << "----Add Pizza----" << endl;
    int inches[3]= {14, 16, 18};
    string name = checkName();
    int price = 0;
    Pizza pizza(name);

    cout << "Would you like to add a topping? (y/n) :";
    char addTopping = checkAnswer();
    if(addTopping == 'y') {
        printTopping();
    }
    while(addTopping == 'y'){
        string toppingName = checkName();
        Topping topping(toppingName);
        try{
            managerDomain.checkToppingAvaliability(topping);
            pizza.addTopping(topping);
            cout << "Add another topping? (y/n): ";
        }
        catch(ToppingNotAvailableException){
            cout << "Topping not avaliable!" << endl;
            cout << "Try another topping? (y/n): ";
        }
        addTopping = checkAnswer();
    }
    for (int i = 0; i < 3; i++) {
        cout << inches[i] << "\" ";
        price = checkPrice();
        pizza.setFixedPrice(price);
        Crust crust(inches[i]);
        pizza.addCrust(crust);
        try {
            managerDomain.addPizza(pizza);
        }
        catch(PizzaChangedException) {
            cout << "price of pizza \"" << pizza.getName();
            cout << "\" of size " << pizza.getCrustSize();
            cout << " has been changed" << endl;
        }
    }
}

void ManagerUI::addDrink() {
    cout << "----Add Drink----" << endl;
    string name = checkName();
    int liter[2] = {1,2};
    for (int i = 0; i < 2; i++) {
        cout << liter[i] << "L ";
        int price = checkPrice();
        Drink drink(name, liter[i], price);

        try {
            managerDomain.addDrink(drink);
        }
        catch(DrinkChangedException) {
            cout << "price of drink \"" << drink.getName();
            cout << "\" of size " << drink.getLiter();
            cout << " has been changed" << endl;
        }
    }
}

void ManagerUI::addSide() {
    cout << "----Add Sidedish----" << endl;
    string name = checkName();
    int price = checkPrice();
    Sidedish sidedish(name, price);
    try {
        managerDomain.addSidedish(sidedish);
    }
    catch(SidedishChangedException) {
        cout << "price of sidedish \"" << sidedish.getName();
        cout << "\" has been changed" << endl;
    }
    cout << endl;
}

void ManagerUI::addBranch() {
    cout << "----Add Branch----" << endl;
    string name = checkName();
    Branch branch(name);
    try {
        managerDomain.addBranch(branch);
    }
    catch(BranchExistsException) {
        cout << "Branch already exists" << endl;
    }
}

void ManagerUI::printCrust() {
    cout << "----Crusts List----" << endl;
    vector<Crust> crusts = managerDomain.printCrust();
    for (int i = 0; i < crusts.size(); i++) {
        cout << crusts[i];
    }
    cout << "-------------------" << endl;
}

void ManagerUI::printTopping() {
    cout << "----Toppings List----" << endl;
    vector<Topping> toppings = managerDomain.printTopping();
    for (int i = 0; i < toppings.size(); i++) {
        cout << toppings[i];
    }
    cout << "---------------------" << endl;
}
void ManagerUI::printPizza() {
    cout << "----Pizza List----" << endl;
    vector<Pizza> pizzas = managerDomain.printPizza();
    for (int i = 0; i < pizzas.size(); i++) {
        cout << pizzas[i];
    }
    cout << "-------------------" << endl;
}

void ManagerUI::printDrink() {
    cout << "----Drinks List----" << endl;
    vector<Drink> drinks = managerDomain.printDrink();
    for (int i = 0; i < drinks.size(); i++) {
        cout << drinks[i];
    }
    cout << "-------------------" << endl;
}

void ManagerUI::printSide() {
    cout << "----Sidedish List----" << endl;
    vector<Sidedish> sidedishes = managerDomain.printSidedish();
     for (int i = 0; i < sidedishes.size(); i++) {
        cout << sidedishes[i];
    }
    cout << "---------------------" << endl;
}

void ManagerUI::printBranch() {
    cout << "----Branch List----" << endl;
    vector<Branch> branches = managerDomain.printBranch();
     for (int i = 0; i < branches.size(); i++) {
        cout << branches[i];
    }
    cout << "-------------------" << endl;
}

void ManagerUI::removeCrust() {
    cout << "-----Remove Crust-----" << endl;
    string name = checkName();
    Crust crust(name);

    try {
        managerDomain.removeCrust(crust);
        cout << "\"" << crust.getName() << "\" crust was removed" << endl;
    }
    catch(CrustNotAvailableException) {
        cout << "This crust \"" << crust.getName();
        cout << "\" is not on the list" << endl;
    }
}

void ManagerUI::removeTopping() {
    cout << "-----Remove Topping-----" << endl;
    string name = checkName();
    Topping topping(name);

    try {
        managerDomain.removeTopping(topping);
        cout << "\"" << topping.getName() << "\" topping was removed" << endl;
    }
    catch(ToppingNotAvailableException) {
        cout << "This topping \"" << topping.getName();
        cout << "\" is not on the list" << endl;
    }
}

void ManagerUI::removePizza() {
    cout << "-----Remove Pizza-----" << endl;
    string name = checkName();
    Pizza pizza(name);

    try {
        managerDomain.removePizza(pizza);
        cout << "\"" << pizza.getName();
        cout << "\" pizza was removed" << endl;
    }
    catch(PizzaNotAvailableException) {
        cout << "This pizza \"" << pizza.getName();
        cout << "\" is not on the list" << endl;
    }

}
void ManagerUI::removeDrink() {
    cout << "-----Remove Drink-----" << endl;
    string name = checkName();
    Drink drink(name);

    try {
        managerDomain.removeDrink(drink);
        cout << "\"" << drink.getName();
        cout << "\" drink was removed" << endl;
    }
    catch(DrinkNotAvaliableException) {
        cout << "This drink \"" << drink.getName();
        cout << "\" is not on the list" << endl;
    }
}
void ManagerUI::removeSide() {
    cout << "-----Remove Sidedish-----" << endl;
    string name = checkName();
    Sidedish sidedish(name);
    try {
        managerDomain.removeSidedish(sidedish);
        cout << "\"" << sidedish.getName();
        cout << "\" sidedish was removed" << endl;
    }
    catch(SideDishNotAvailableException) {
        cout << "This sidedish \"" << sidedish.getName();
        cout << "\" is not on the list" << endl;
    }
}
void ManagerUI::removeBranch() {
    cout << "-----Remove Branch-----" << endl;
    string name = checkName();
    Branch branch(name);

    try {
        managerDomain.removeBranch(branch);
        cout << "Restaurant at \"" << branch.getName();
        cout << "\" was removed" << endl;
    }
    catch(BranchNotAvailableException) {
        cout << "Restaurant at \"" << branch.getName();
        cout << "\" is not on the list" << endl;
    }
}


string ManagerUI::checkName() {
    string name = "";
    bool allowed = false;

    while(!allowed){
        cout << "Name: ";
        cin >> ws;
        getline(cin, name);
        managerDomain.toLowerCase(name);
        try{
            allowed = managerDomain.checkValidName(name);
        }
        catch(InvalidNameException){
            cout << "Name cant include numbers" << endl;
        }
    }
    return name;
}

int ManagerUI::checkPrice() {
    string price = "";
    int price1 = 0;
    bool allowed = false;

    while(!allowed){
        cout << "Price: ";
        cin >> ws;
        getline(cin, price);
        try{
            price1 = managerDomain.checkValidPrice(price);
            allowed = true;
        }
        catch(InvalidPriceException){
            cout << "Invalid price, try again" << endl;
        }
    }
    return price1;
}

char ManagerUI::checkAnswer() {
    string answer = "";
    char answer1 = '\0';
    bool allowed = false;

    while(!allowed){
        cin >> ws;
        getline(cin, answer);
        try{
            allowed = managerDomain.checkValidAnswer(answer);
            answer1 = answer[0];
        }
        catch(InvalidAnswerException){
            cout << "Invalid answer, please answer \'y\' or \'n\'" << endl;
        }
    }
    return answer1;
}
