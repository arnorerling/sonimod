#ifndef MAINDOMAIN_H
#define MAINDOMAIN_H
#include "InvalidInputException.h"
#include <string>
using namespace std;

class MainDomain
{
    private:

    public:
        MainDomain();
        bool checkValidInput(string &select);
};

#endif // MAINDOMAIN_H
