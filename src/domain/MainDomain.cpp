#include "MainDomain.h"

MainDomain::MainDomain()
{
    //ctor
}

bool MainDomain::checkValidInput(string &select) {
    if (select.length() == 1) {
        return true;
    }
    throw InvalidInputException();
    return false;
}

Username MainDomain::checkUser(string &name, string &password) {
    vector<Username> userList = mainRep.getUsers();

    for (int i = 0; i < userList.size(); i++){
        if (userList[i].getName() == name && userList[i].getPassword() == password) {
            return userList[i];
        }
    }
    throw SideDishNotAvailableException();
}
