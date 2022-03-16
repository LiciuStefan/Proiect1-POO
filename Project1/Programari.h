#pragma once
#include <iostream>
using namespace std;

class Programari {
public:
	Programari(string, string, double);
	Programari();
	Programari(const Programari&);
	void set_ora(string);
	void set_serviciu(string serviciu);
	void set_tarif(double);
	string get_ora();
	string get_serviciu_dorit();
	double get_tarif();
	friend bool operator == (Programari&, Programari&);
	friend bool operator != (Programari&, Programari&);
	friend istream& operator>>(istream&, Programari&);
	friend ostream& operator<<(ostream&, const Programari&);
private:
	string ora;
	string serviciu_dorit;
	double tarif;
};