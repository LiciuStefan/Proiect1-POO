#pragma once
#include <iostream>
using namespace std;


class Servicii {
public:
	Servicii(string, int, double);
	Servicii();
	Servicii(const Servicii&);
	void set_nume(string);
	void set_durata(int);
	void set_pret(double);
	string get_nume();
	int get_durata();
	double get_pret();
	friend bool operator ==(Servicii&, Servicii&);
	friend bool operator != (Servicii&, Servicii&);
	friend istream& operator>>(istream&, Servicii&);
	friend ostream& operator<<(ostream&, const Servicii&);
private:
	string nume;
	int durata;
	double pret;
};