#include <iostream>
#include "Angajati.h"
using namespace std;

Angajati::Angajati(string name, int id, int salary)
{
	this->nume = name;
	this->id_angajat = id;
	this->salariu = salary;
}
Angajati::Angajati()
{
	this->nume = "";
	this->id_angajat = 0;
	this->salariu = 0;
}
Angajati::Angajati(const Angajati& Angajat)
{
	this->nume = Angajat.nume;
	this->id_angajat = Angajat.id_angajat;
	this->salariu = Angajat.salariu;
}
void Angajati::set_nume(string Nume_Angajat)
{
	this->nume = Nume_Angajat;
}

string Angajati::get_nume()
{
	return this->nume;
}

void Angajati::set_id_angajat(int id)
{
	this->id_angajat = id;
}
int Angajati::get_id()
{
	return this->id_angajat;
}
void Angajati::set_salariu(int salary)
{
	this->salariu = salary;
}
int Angajati::get_salariu()
{
	return this->salariu;
}
bool operator == (Angajati& Angajat1, Angajati& Angajat2)
{
	return (Angajat1.nume == Angajat2.nume);
}
bool operator != (Angajati& Angajat1, Angajati& Angajat2)
{
	return(Angajat1.nume != Angajat2.nume);
}
istream& operator>>(istream& in, Angajati& Angajat)
{
	in >> ws;
	getline(in, Angajat.nume);
	in >> Angajat.id_angajat >> Angajat.salariu;
	return in;
}

ostream& operator<<(ostream& o, const Angajati& Angajat)
{
	o << Angajat.nume << ' ' << Angajat.id_angajat << ' ' << Angajat.salariu;
	return o;
}