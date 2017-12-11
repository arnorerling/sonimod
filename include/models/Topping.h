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
		Topping(string name, int price);

        void write(ofstream& fout) const;
        void read(ifstream& fin);

		friend ostream& operator << (ostream& out, const Topping& topping);
		friend bool operator ==(const Topping &right_top, const Topping &left_top);

        string getName() const;
		int getPrice() const;

        void setName(const string &name);
		void setPrice(const int &price);
};


#endif
