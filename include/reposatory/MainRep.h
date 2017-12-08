#ifndef MAINREP_H
#define MAINREP_H
#include "SideDishNotAvailableException.h"
#include "MainRep.h"
#include "Username.h"
#include <vector>
#include <string>
class MainRep
{
    public:
        MainRep();
        vector<Username> getUsers();

    protected:

    private:
};

#endif // MAINREP_H
