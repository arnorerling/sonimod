#ifndef OUTPUT_H
#define OUTPUT_H
#include <iostream>
using namespace std;

class Output{
    public:
        Output();
        //cleans the screen
        void clean();
        //waits for user to press a key to continue
        void wait();

        //waits for sales user to press a key to continue
        //dirty fix because for some reason wait function wont work sometimes for sales
        //void salesWait();
};

#endif // OUTPUT_H

