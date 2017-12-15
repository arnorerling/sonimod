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
	    //constructors
		Topping();
		Topping(string name);
		Topping(string name, int price);

        //reads and writes into files
        void write(ofstream& fout) const;
        void read(ifstream& fin);

        //overwrites cout operator for topping class
		friend ostream& operator << (ostream& out, const Topping& topping);
		//checks if two toppings have the same name
		friend bool operator ==(const Topping &right_top, const Topping &left_top);

        //gets private variables
        string getName() const;
		int getPrice() const;

        //sets private variables
        void setName(const string &name);
		void setPrice(int price);
};


#endif
