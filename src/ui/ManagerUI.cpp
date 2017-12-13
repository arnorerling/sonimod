#include "ManagerUI.h"


ManagerUI::ManagerUI() {

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
        switch(select) {
            case '1':
                output.clean();
                printCrust();
                addCrust();
                output.wait();
                break;
            case '2':
                output.clean();
                printTopping();
                addTopping();
                output.wait();
                break;
            case '3':
                output.clean();
                printPizza();
                addPizza();
                output.wait();
                break;
            case '4':
                output.clean();
                printDrink();
                addDrink();
                output.wait();
                break;
            case '5':
                output.clean();
                printSide();
                addSide();
                output.wait();
                break;
            case '6':
                output.clean();
                printBranch();
                addBranch();
                output.wait();
                break;
            case '7':
                output.clean();
                printUser();
                addUser();
                output.wait();
                break;
            case '8':
                output.clean();
                cout << endl;
                break;
            default:
                output.clean();
                cout << "Invalid input" << endl;
                output.wait();
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
        switch(select) {
            case '1':
                output.clean();
                printCrust();
                removeCrust();
                output.wait();
                break;
            case '2':
                output.clean();
                printTopping();
                removeTopping();
                output.wait();
                break;
            case '3':
                output.clean();
                printPizza();
                removePizza();
                output.wait();
                break;
            case '4':
                output.clean();
                printDrink();
                removeDrink();
                output.wait();
                break;
            case '5':
                output.clean();
                printSide();
                removeSide();
                output.wait();
                break;
            case '6':
                output.clean();
                printBranch();
                removeBranch();
                output.wait();
                break;
            case '7':
                output.clean();
                printUser();
                removeUser();
                output.wait();
                break;
            case '8':
                output.clean();
                cout << endl;
                break;
            default:
                output.clean();
                cout << "Invalid input" << endl;
                output.wait();
        }
    }
}

void ManagerUI::seeSaleFigures() {
    output.clean();
    printManLogo();
    printBranch();
    string branch = checkBranch();
    cout << "------------Choose a date limit----------" << endl;
    cout << "\"DD.MM.YYYY\" or press Enter for default" << endl;
    cout << "Date limit from: ";
    string dateFrom = checkDate();
    cout << "Date limit to: ";
    string dateTo = checkDate();

    printFigures(branch, dateFrom, dateTo);
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
    while(addTopping == 'y') {
        string toppingName = checkName();
        Topping topping(toppingName);
        try {
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
    if (!pizzas.empty()) {
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
    else {
        cout << "Pizza list is empty" << endl;
    }
}

void ManagerUI::printCrust() {
    vector<Crust> crusts = managerDomain.getCrusts();
    if (!crusts.empty()) {
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
    else {
        cout << "Crust list is empty" << endl;
    }
}

void ManagerUI::printTopping() {
    vector<Topping> toppings = managerDomain.getToppings();
    if (!toppings.empty()) {
        cout << "-----------Toppings List-----------" << endl;
        cout << setw(15) << "Name" << setw(10) << "Price" << endl;
        cout << "-----------------------------------" << endl;
        for(unsigned int i = 0; i < toppings.size(); i++){
            cout << setw(15) << toppings[i].getName();
            cout << setw(10) << toppings[i].getPrice() << endl;
        }
        cout << "-----------------------------------" << endl;
    }
    else {
        cout << "Topping list is empty" << endl;
    }
}

void ManagerUI::printDrink() {
    vector<Drink> drinks = managerDomain.getDrinks();
    if (!drinks.empty()) {
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
    else {
        cout << "Drinks list is empty" << endl;
    }
}

void ManagerUI::printSide() {
    vector<Sidedish> sidedishes = managerDomain.getSidedishes();
    if (!sidedishes.empty()) {
        cout << "-----------Sidedish List-----------" << endl;
        cout << setw(18) << "Name" << setw(10) << "Price" << endl;
        cout << "-----------------------------------" << endl;
        for(unsigned int i = 0; i < sidedishes.size(); i++){
            cout << setw(18) << sidedishes[i].getName();
            cout << setw(10) << sidedishes[i].getPrice() << endl;
        }
        cout << "-----------------------------------" << endl;
    }
    else {
        cout << "Sidedish list is empty" << endl;
    }
}

void ManagerUI::printBranch() {
    vector<Branch> branches = managerDomain.getBranches();
    if (!branches.empty()) {
        cout << "----Branch List----" << endl;
         for (unsigned int i = 0; i < branches.size(); i++) {
            cout << branches[i];
        }
        cout << "-------------------" << endl;
    }
    else {
        cout << "Branch list is empty" << endl;
    }
}

void ManagerUI::printUser() {
    vector<User> users = managerDomain.getUsers();
    if (!users.empty()) {
        cout << "--------Employee List--------" << endl;
        cout << setw(12) << "Name" << setw(15) << "Job" << endl;
        cout << "------------------------------" << endl;
         for (unsigned int i = 0; i < users.size(); i++) {
            cout << setw(12) << users[i].getName();
            cout << setw(15) << users[i].getJob() << endl;
        }
        cout << "-----------------------------" << endl;
    }
    else {
        cout << "User list is empty" << endl;
    }
}

void ManagerUI::printFigures(string branch, string dateFrom, string dateTo) {
    cout << endl;
    cout << "-----Sale figures";
    if (!dateFrom.empty()) {
        cout << " from " << dateFrom;
    }
    if (!dateTo.empty()) {
        cout << " to " << dateTo;
    }
    if (!branch.empty()) {
        cout << " at " << branch;
    }
    cout << "-----"<< endl;

    vector<Order> branchOrders = managerDomain.getBranchOrders(branch);
    vector<Order> dateFromOrders = managerDomain.getDateFromOrders(dateFrom, branchOrders);
    vector<Order> dateToOrders = managerDomain.getDateToOrders(dateTo, dateFromOrders);

    int total = 0;
    for (unsigned int i = 0; i < dateToOrders.size(); i++) {
        cout << "Order time: " <<  dateToOrders[i].getTimeString();
        cout << "\tPrice: " << dateToOrders[i].getTotal() << endl;
        total += dateToOrders[i].getTotal();
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
    catch (CantDeleteException) {
        cout << "Can't delete user admin" << endl;
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
        try {
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

    while(!allowed) {
        cout << "Price: ";
        cin >> ws;
        getline(cin, price);
        try {
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

    while(!allowed) {
        cin >> ws;
        getline(cin, input);
        try {
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

    while(!allowed) {
        cout << "Username: ";
        cin >> ws;
        getline(cin, username);
        try {
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

    while(!allowed) {
        cout << "Password: ";
        cin >> ws;
        getline(cin, pw);
        try {
            allowed = managerDomain.checkValidPassword(pw);
        }
        catch(InvalidInputException) {
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
    while(!allowed) {
        cin >> ws;
        getline(cin, job);
        try {
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

    while(!allowed) {
        cout << "Restaurant (press enter for all): ";
        getline(cin, branch);
        if (branch.empty()) {
            return branch;
        }
        try{
            allowed = managerDomain.checkValidBranch(branch);
        }
        catch(NotFoundException) {
            cout << "This restaurant doesn't exist" << endl;
        }
    }
    return branch;
}

string ManagerUI::checkDate() {
    string date = "";
    bool allowed = false;
    while(!allowed){
        getline(cin, date);
        if (date.empty()) {
            return date;
        }
        try {
            allowed = managerDomain.checkValidDate(date);
        }
        catch(InvalidDateException) {
            cout << "Invalid date, year cant be less than 1970." << endl;
            cout << "Please enter\"DD.MM.YYYY\" or press Enter: " << endl;
        }
        catch(InvalidInputException) {
            cout << "Invalid date, please enter \"DD.MM.YYYY\" or press Enter" << endl;
        }
        catch(LengthNotRightException) {
            cout << "Length is wrong, please enter \"DD.MM.YYYY\" or press Enter" << endl;
        }
    }
    return date;
}

void ManagerUI::printManLogo() {
cout << "_  _ ____ _  _ ____ ____ ____ ____" << endl;
cout << "|\\/| |__| |\\ | |__| | __ |___ |__/" << endl;
cout << "|  | |  | | \\| |  | |__] |___ |  \\" << endl;
cout << "-----------------------------------" << endl;
}
