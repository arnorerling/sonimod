#ifndef SALESDOMAIN_H
#define SALESDOMAIN_H

#include "SalesRep.h"
#include <iostream>
using namespace std;

class SalesDomain
{
    private:
    SalesRep salesRep;

    public:
        SalesDomain();
        void getDrink();
};

#endif // SALESDOMAIN_H
