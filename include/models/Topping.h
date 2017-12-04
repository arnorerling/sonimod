#ifndef TOPPING_H
#define TOPPING_H

#include <string.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Topping {

	private:
		string name;
		int price;

	public:
		Topping();
		Topping(string name);
		///Basic constructor that sets all variables to 0 and 'verbose' to false

		Topping(string name, int price);
		///constructor that sets the name and the price to be equal to the parameters
		///and 'verbose' to be false

        void write(ofstream& fout) const;
        void read(ifstream& fin);

		friend ostream& operator << (ostream& out, const Topping& topping);
		///Overloads the '<<' operator to print the name and the price of a topping

		friend istream& operator >> (istream& in, Topping& topping);
		///Overloads the '>>' operator to request input of the name and price of a topping

        string getName() const;
		int getPrice() const;

		void setPrice(int price);
		///Returns the price of a topping

};


#endif
