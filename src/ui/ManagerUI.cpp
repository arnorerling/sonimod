#include "ManagerUI.h"


ManagerUI::ManagerUI()
{
    //ctor
}

void ManagerUI::startUI() {
    output.clean();
    printManLogo();
    char select = '\0';
    while (select != '4') {
        output.clean();
        printManLogo();
        cout << "1: Add/Change" << endl;
        cout << "2: Remove" << endl;
        cout << "3: Sale Figures" << endl;
        cout << "4: Quit" << endl;
        select = checkInput();

        switch(select) {
            case '1':
                addChangeMenu();
                break;
            case '2':
                removeFromMenu();
                break;
            case '3':
                seeSaleFigures();
                break;
            case '4':
                cout << "GoodBye" << endl;
                break;
            default: cout << "Invalid input" << endl;
        }
    }
}

void ManagerUI::addChangeMenu() {
    char select = '\0';
    while (select != '8') {
        output.clean();
        printManLogo();
        cout << "-----Add/Change-----" << endl;
        cout << "1: Pizza crust" << endl;
        cout << "2: Pizza topping" << endl;
        cout << "3: Pizza from menu" << endl;
        cout << "4: Drink" << endl;
        cout << "5: Sidedish" << endl;
        cout << "6: Branch" << endl;
        cout << "7: User" << endl;
        cout << "8: Quit" << endl;
        cout << "--------------------" << endl;

        select = checkInput();
        switch(select){
            case '1':
                output.clean();
                printCrust();
                addCrust();
                break;
            case '2':
                output.clean();
                printTopping();
                addTopping();
                break;
            case '3':
                output.clean();
                printPizza();
                addPizza();
                break;
            case '4':
                output.clean();
                printDrink();
                addDrink();
                break;
            case '5':
                output.clean();
                printSide();
                addSide();
                break;
            case '6':
                output.clean();
                printBranch();
                addBranch();
                break;
            case '7':
                output.clean();
                printUser();
                addUser();
                break;
            case '8':
                output.clean();
                cout << endl;
                break;
            default:
                output.clean();
                cout << "Invalid input" << endl;
        }
    }
}

void ManagerUI::removeFromMenu() {
    char select = '\0';
    while (select != '8') {
        output.clean();
        printManLogo();
        cout << "-----Remove-----" << endl;
        cout << "1: Pizza crust" << endl;
        cout << "2: Pizza topping" << endl;
        cout << "3: Pizza from menu" << endl;
        cout << "4: Drink" << endl;
        cout << "5: Sidedish" << endl;
        cout << "6: Branch" << endl;
        cout << "7: User" << endl;
        cout << "8: Quit" << endl;
        cout << "--------------------------" << endl;
        select = checkInput();
        switch(select){
            case '1':
                output.clean();
                printCrust();
                removeCrust();
                break;
            case '2':
                output.clean();
                printTopping();
                removeTopping();
                break;
            case '3':
                output.clean();
                printPizza();
                removePizza();
                break;
            case '4':
                output.clean();
                printDrink();
                removeDrink();
                break;
            case '5':
                output.clean();
                printSide();
                removeSide();
                break;
            case '6':
                output.clean();
                printBranch();
                removeBranch();
                break;
            case '7':
                output.clean();
                printUser();
                removeUser();
                break;
            case '8':
                output.clean();
                cout << endl;
                break;
            default:
                output.clean();
                cout << "Invalid input" << endl;
        }
    }
}

void ManagerUI::seeSaleFigures() {
    output.clean();
    printManLogo();
    cout << "-----Sale Figures-----" << endl;
    printBranch();
    string branch = checkBranch();
    if (branch.empty()) {
        printAllFigures();
    }
    else {
        printBranchFigures(branch);
    }
    output.wait();
}

void ManagerUI::addPizza() {
    cout << "----Add Pizza----" << endl;
    int inches[3]= {14, 16, 18};
    string name = checkName();
    int price = 0;
    Pizza pizza(name);

    cout << "Would you like to add a topping? (y/n) :";
    char addTopping = checkAnswer();
    output.clean();
    if(addTopping == 'y') {

        printTopping();
    }
    while(addTopping == 'y'){
        string toppingName = checkName();
        Topping topping(toppingName);
        try{
            managerDomain.checkTopping(topping);
            pizza.addTopping(topping);
            cout << "Add another topping? (y/n): ";
        }
        catch(NotFoundException){
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
        catch(ItemChangedException) {
            cout << "price of pizza \"" << pizza.getName();
            cout << "\" of size " << pizza.getCrustSize();
            cout << " has been changed" << endl;
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
        catch(ItemChangedException) {
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
    catch(ItemChangedException) {
        cout << "price of topping \"" << topping.getName();
        cout << "\" has been changed" << endl;

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
        catch(ItemChangedException) {
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
    catch(ItemChangedException) {
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
    catch(ItemChangedException) {
        cout << "Branch already exists" << endl;
    }
}

void ManagerUI::addUser() {
    cout << "----Add Employee----" << endl;
    string username = checkUsername();
    string password = checkPassword();
    output.clean();
    char jobNumber = checkJob();


    User user(username, password, jobNumber);
    try {
        managerDomain.addUser(user);
    }
    catch(ItemChangedException) {
        cout << "User's password/job has been changed" << endl;
    }
}

void ManagerUI::printPizza() {
    vector<Pizza> pizzas = managerDomain.getPizzas();
    cout << "-------------------Pizza List--------------------" << endl;
    cout << setw(15) << "Name" << setw(10) << "14\"";
    cout << setw(10) << "16\"" << setw(10) << "18\"" << endl;
    cout << "--------------------------------------------------" << endl;
    for(unsigned int i = 0; i < pizzas.size(); i++){
        if (i % 3 == 0){
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

void ManagerUI::printCrust() {
    vector<Crust> crusts = managerDomain.getCrusts();
    cout << "--------------------Crust List--------------------" << endl;
    cout << setw(15) << "Name" << setw(10) << "14\"";
    cout << setw(10) << "16\"" << setw(10) << "18\"" << endl;
    cout << "--------------------------------------------------" << endl;
    for(unsigned int i = 0; i < crusts.size(); i++){
        if (i % 3 == 0){
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

void ManagerUI::printTopping() {
    vector<Topping> toppings = managerDomain.getToppings();
    cout << "-----------Toppings List-----------" << endl;
    cout << setw(15) << "Name" << setw(10) << "Price" << endl;
    cout << "-----------------------------------" << endl;
    for(unsigned int i = 0; i < toppings.size(); i++){
        cout << setw(15) << toppings[i].getName();
        cout << setw(10) << toppings[i].getPrice() << endl;
    }
    cout << "-----------------------------------" << endl;
}

void ManagerUI::printDrink() {
    vector<Drink> drinks = managerDomain.getDrinks();
    cout << "------------Drinks List------------" << endl;
    cout << setw(15) << "Name" << setw(8) << "1L" << setw(8) << "2L" << endl;
    cout << "-----------------------------------" << endl;
    for(unsigned int i = 0; i < drinks.size(); i++){
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

void ManagerUI::printSide() {
    vector<Sidedish> sidedishes = managerDomain.getSidedishes();
    cout << "-----------Sidedish List-----------" << endl;
    cout << setw(15) << "Name" << setw(10) << "Price" << endl;
    cout << "-----------------------------------" << endl;
    for(unsigned int i = 0; i < sidedishes.size(); i++){
        cout << setw(15) << sidedishes[i].getName();
        cout << setw(10) << sidedishes[i].getPrice() << endl;
    }
    cout << "-----------------------------------" << endl;
}

void ManagerUI::printBranch() {
    cout << "----Branch List----" << endl;
    vector<Branch> branches = managerDomain.getBranches();
     for (unsigned int i = 0; i < branches.size(); i++) {
        cout << branches[i];
    }
    cout << "-------------------" << endl;
}

void ManagerUI::printUser() {
    cout << "--------Employee List--------" << endl;
    cout << setw(12) << "Name" << setw(15) << "Job" << endl;
    cout << "------------------------------" << endl;
    vector<User> users = managerDomain.getUsers();
     for (unsigned int i = 0; i < users.size(); i++) {
        cout << setw(12) << users[i].getName();
        cout << setw(15) << users[i].getJob() << endl;
    }
    cout << "-----------------------------" << endl;
}

void ManagerUI::printAllFigures() {
    cout << "-----All sale figures-----" << endl;
    vector<Order> orders = managerDomain.getOrders();
    int total = 0;
    for (unsigned int i = 0; i < orders.size(); i++) {
        cout << "Order time: " << orders[i].getTimeString();
        cout << "\tPrice: " << orders[i].getTotal() << endl;
        total += orders[i].getTotal();
    }
    cout << endl;
    cout << "\t\t\t\t\tTotal: " << total << endl;
    cout << "-------------------" << endl;
}

void ManagerUI::printBranchFigures(const string branch) {
    cout << endl;
    cout << "-----Sale figures for " << branch << "-----"  << endl;
    vector<Order> orders = managerDomain.getBranchOrders(branch);
    int total = 0;
    for (unsigned int i = 0; i < orders.size(); i++) {
        cout << "Order time: " << orders[i].getTimeString();
        cout << "\tPrice: " << orders[i].getTotal() << endl;
        total += orders[i].getTotal();
    }
    cout << endl;
    cout << "\t\t\t\t\tTotal: " << total << endl;
    cout << "-------------------" << endl;
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
    catch(NotFoundException) {
        cout << "This pizza \"" << pizza.getName();
        cout << "\" is not on the list" << endl;
    }

}

void ManagerUI::removeCrust() {
    cout << "-----Remove Crust-----" << endl;
    string name = checkName();
    Crust crust(name);

    try {
        managerDomain.removeCrust(crust);
        cout << "\"" << crust.getName() << "\" crust was removed" << endl;
    }
    catch(NotFoundException) {
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
    catch(NotFoundException) {
        cout << "This topping \"" << topping.getName();
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
    catch(NotFoundException) {
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
    catch(NotFoundException) {
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
    catch(NotFoundException) {
        cout << "Restaurant at \"" << branch.getName();
        cout << "\" is not on the list" << endl;
    }
}

void ManagerUI::removeUser() {
    cout << "-----Remove User-----" << endl;
    string name = checkName();
    User user(name);

    try {
        managerDomain.removeUser(user);
        cout << "User \"" << user.getName();
        cout << "\" was removed" << endl;
    }
    catch(NotFoundException) {
        cout << "User \"" << user.getName();
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
        catch(InvalidInputException){
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
        catch(InvalidInputException){
            cout << "Invalid price, try again" << endl;
        }
    }
    return price1;
}

char ManagerUI::checkInput() {
    string input = "";
    char input1 = '\0';
    bool allowed = false;

    while(!allowed){
        cin >> ws;
        getline(cin, input);
        try{
            allowed = managerDomain.checkValidInput(input);
            input1 = input[0];
        }
        catch(InvalidInputException){
            cout << "Invalid input" << endl;
        }
    }
    return input1;
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
        catch(InvalidInputException){
            cout << "Invalid answer, please answer \'y\' or \'n\'" << endl;
        }
    }
    return answer1;
}

string ManagerUI::checkUsername() {
    string username = "";
    bool allowed = false;

    while(!allowed){
        cout << "Username: ";
        cin >> ws;
        getline(cin, username);
        try{
            allowed = managerDomain.checkValidUsername(username);
        }
        catch(InvalidInputException){
            cout << "Username must be one word" << endl;
        }
    }
    return username;
}

string ManagerUI::checkPassword() {
    string pw = "";
    bool allowed = false;

    while(!allowed){
        cout << "Password: ";
        cin >> ws;
        getline(cin, pw);
        try{
            allowed = managerDomain.checkValidPassword(pw);
        }
        catch(InvalidInputException){
            cout << "Password must be one word and include at least 2 numbers" << endl;
        }
    }
    return pw;
}

char ManagerUI::checkJob() {
    string job = "";
    char job1 = '\0';
    bool allowed = false;
    cout << "---Choose Job----" << endl;
    cout << "1: Manager" << endl;
    cout << "2: Sales" << endl;
    cout << "3: Baker" << endl;
    cout << "4: Delivery" << endl;
    while(!allowed){
        cin >> ws;
        getline(cin, job);
        try{
            allowed = managerDomain.checkValidJob(job);
            job1 = job[0];
        }
        catch(InvalidInputException){
            cout << "Invalid input, try again" << endl;
        }
    }
    return job1;
}

string ManagerUI::checkBranch() {
    string branch = "";
    bool allowed = false;

    while(!allowed){
        cout << "Restaurant (press enter for all): ";
        getline(cin, branch);
        if (branch.empty()) {
            return branch;
        }
        try{
            allowed = managerDomain.checkValidBranch(branch);
        }
        catch(NotFoundException){
            cout << "This restaurant doesn't exist" << endl;
        }
    }
    return branch;
}

void ManagerUI::printManLogo(){
cout << "_  _ ____ _  _ ____ ____ ____ ____" << endl;
cout << "|\\/| |__| |\\ | |__| | __ |___ |__/" << endl;
cout << "|  | |  | | \\| |  | |__] |___ |  \\" << endl;
cout << "-----------------------------------" << endl;
}
