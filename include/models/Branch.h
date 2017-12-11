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
        Branch();
        Branch(string name);

        void write(ofstream& fout) const;
        void read(ifstream& fin);

        friend ostream& operator << (ostream& out, const Branch& branch);
        friend bool operator == (const Branch &left_branch, const Branch &right_branch);

        string getName() const;
        void setName(const string name);
};

#endif // BRANCH_H
