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
		Crust(string name);
		Crust(int inches);
		Crust(string name, int inches);
		Crust(string name, int price, int inches);


        void write(ofstream& fout) const;
        void read(ifstream& fin);

		friend ostream& operator << (ostream& out, const Crust& crust);
		friend bool operator == (const Crust &right_crust, const Crust &left_crust);

        string getName() const;
        int getInches() const;
		int getPrice() const;

        void setName(const string name);
        void setInches(const int inches);
		void setPrice(const int price);

};


#endif // CRUST_H
