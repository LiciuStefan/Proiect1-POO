#pragma once
#include <iostream>
#include <string>
using namespace std;

class Angajati {
public:
	Angajati(string, int, int);
	Angajati();
	Angajati(const Angajati&);
	void set_nume(string);
	void set_id_angajat(int);
	void set_salariu(int);
	string get_nume();
	int get_id();
	int get_salariu();
	friend bool operator == (Angajati&, Angajati&);
	friend bool operator != (Angajati&, Angajati&);
	friend istream& operator>>(istream&, Angajati&);
	friend ostream& operator<<(ostream&, const Angajati&);
private:
	string nume;
	int id_angajat;
	int salariu;
};