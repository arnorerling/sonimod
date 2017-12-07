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
