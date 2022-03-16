#include <iostream>
#include <string>
#include "Programari.h"
using namespace std;

Programari::Programari(string hour, string serviciu, double trf)
{
	this->ora = hour;
	this->serviciu_dorit = serviciu;
	this->tarif = trf;
}
Programari::Programari()
{
	this->ora = "";
	this->serviciu_dorit = "";
	this->tarif = 0.0;
}
Programari::Programari(const Programari& Prog)
{
	this->ora = Prog.ora;
	this->serviciu_dorit = Prog.serviciu_dorit;
	this->tarif = Prog.tarif;

}
void Programari::set_ora(string hour)
{
	this->ora = hour;
}
void Programari::set_serviciu(string serviciu)
{
	this->serviciu_dorit = serviciu;
}
void Programari::set_tarif(double trf)
{
	this->tarif = trf;
}
string Programari::get_ora()
{
	return this->ora;
}
string Programari::get_serviciu_dorit()
{
	return this->serviciu_dorit;
}
double Programari::get_tarif()
{
	return this->tarif;
}

bool operator ==(Programari& Prog1, Programari& Prog2)
{
	return (Prog1.ora == Prog2.ora && Prog1.serviciu_dorit == Prog2.serviciu_dorit);
}

bool operator != (Programari& Prog1, Programari& Prog2)
{
	return (Prog1.ora != Prog2.ora || Prog1.serviciu_dorit != Prog2.serviciu_dorit);
}

istream& operator>>(istream& in, Programari& Prog)
{
	in >> ws;
	getline(in, Prog.ora);
	getline(in, Prog.serviciu_dorit);
	in>> Prog.tarif;
	return in;
}

ostream& operator<<(ostream& o, const Programari& Prog)
{
	o << "Serviciu: " << Prog.serviciu_dorit << " " << "Ora:" << Prog.ora << ' ' << "Pret:" << Prog.tarif << '\n';
	return o;
}