#include <iostream>
#include <string>
#include "Servicii.h"
using namespace std;

Servicii::Servicii(string name, int duration, double price)
{
	this->nume = name;
	this->durata = duration;
	this->pret = price;
}
Servicii::Servicii()
{
	this->nume = "";
	this->durata = 0;
	this->pret = 0.0;
}
Servicii::Servicii(const Servicii& Serviciu)
{
	this->nume = Serviciu.nume;
	this->durata = Serviciu.durata;
	this->pret = Serviciu.pret;
}
void Servicii::set_nume(string name)
{
	this->nume = name;
}
void Servicii::set_durata(int duration)
{
	this->durata = duration;
}
void Servicii::set_pret(double price)
{
	this->pret = price;
}
string Servicii::get_nume()
{
	return this->nume;
}
int Servicii::get_durata()
{
	return this->durata;
}
double Servicii::get_pret()
{
	return this->pret;
}
bool operator == (Servicii& S1, Servicii& S2)
{
	return (S1.nume == S2.nume);
}

bool operator != (Servicii& Serviciu1, Servicii& Serviciu2)
{
	return (Serviciu1.nume != Serviciu2.nume);
}


istream& operator>>(istream& in, Servicii& Serviciu)
{
	in >> ws;
	getline(in, Serviciu.nume);
	in>> Serviciu.durata >> Serviciu.pret;
	return in;
}
ostream& operator<<(ostream& o, const Servicii& Serviciu)
{
	o << Serviciu.nume << ' ' << Serviciu.durata << ' ' << Serviciu.pret;
	return o;
}