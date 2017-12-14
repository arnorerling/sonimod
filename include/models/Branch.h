#ifndef BRANCH_H
#define BRANCH_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Branch
{
    private:
        string name;

    public:
        //constructors
        Branch();
        Branch(string name);
        //reads and writes from a file
        void write(ofstream& fout) const;
        void read(ifstream& fin);
        //overwrite cout for branch
        friend ostream& operator << (ostream& out, const Branch& branch);
        //checks if two branch classes are the same
        friend bool operator == (const Branch &left_branch, const Branch &right_branch);
        //functions that get private variables
        string getName() const;
        //functions that set private variables
        void setName(const string name);
};

#endif // BRANCH_H
