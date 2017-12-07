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
		Crust();
		///Basic constructor that sets all variables to 0
		Crust(string name, int inches);
		Crust(int inches);
		Crust(string name);

		Crust(string name, int price, int inches);
		///constructor that sets the name and the price to be equal to the parameters

        void write(ofstream& fout) const;
        ///Writes a Crust class in a binary file

        void read(ifstream& fin);
        ///Reads a Crust class in a binary file

		friend ostream& operator << (ostream& out, const Crust& crust);
		///Overloads the '<<' operator to print the name and the price of a topping

		friend bool operator == (const Crust &right_crust, const Crust &left_crust);

        string getName() const;
        ///get name of crust

        int getInches() const;
        ///get size of crust

		int getPrice() const;
		///get price of crust
		void setPrice(int price);

};


#endif // CRUST_H
