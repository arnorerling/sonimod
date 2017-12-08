#ifndef MAINREP_H
#define MAINREP_H
#include "NotFoundException.h"
#include "MainRep.h"
#include "User.h"
#include <vector>
#include <string>
class MainRep
{
    public:
        MainRep();
        vector<User> getUsers();

    protected:

    private:
};

#endif // MAINREP_H
