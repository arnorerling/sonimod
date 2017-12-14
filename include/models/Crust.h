#ifndef CRUST_H
#define CRUST_H

#include <string.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Crust {

	private:
		string name;
		int inches;
		int price;

	public:
	    //constructors
		Crust();
		Crust(string name);
		Crust(int inches);
		Crust(string name, int inches);
		Crust(string name, int price, int inches);

        //read and write into files
        void write(ofstream& fout) const;
        void read(ifstream& fin);

        //overwrites cout for crust
		friend ostream& operator << (ostream& out, const Crust& crust);
		//checks if two crusts have the same name and size
		friend bool operator == (const Crust &right_crust, const Crust &left_crust);

        //gets private variables
        string getName() const;
        int getInches() const;
		int getPrice() const;

        //sets private variables
        void setName(const string name);
        void setInches(const int inches);
		void setPrice(const int price);

};


#endif // CRUST_H
