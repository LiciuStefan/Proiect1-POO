#include <iostream>
#include <fstream>
#include <string>
#include "Produse.h";


Produse::Produse(string brand, int nr_prod, double price)
{
	marca = brand;
	numar_produse_disponibile = nr_prod;
	pret = price;
}

Produse::Produse()
{
	marca = "";
	numar_produse_disponibile = 0;
	pret = 0;
}

Produse::Produse(const Produse& Produs)
{
	marca = Produs.marca;
	numar_produse_disponibile = Produs.numar_produse_disponibile;
	pret = Produs.pret;
}

void Produse::set_marca(string brand)
{
	marca = brand;
}

string Produse::get_marca()
{
	return marca;
}

void Produse::set_numar_produse_disponibile(int nr_prod)
{
	numar_produse_disponibile = nr_prod;
}

int Produse::get_numar_produse_disponibile()
{
	return numar_produse_disponibile;
}

void Produse::set_pret(double price)
{
	pret = price;
}

double Produse::get_pret()
{
	return pret;
}

Produse& Produse::operator += (Produse& Produs)
{
	if (marca != Produs.marca) marca = marca + " " + "si" + " " + Produs.marca;
	numar_produse_disponibile += Produs.numar_produse_disponibile;
	pret = double((numar_produse_disponibile * pret + Produs.numar_produse_disponibile * Produs.pret)) / double(numar_produse_disponibile);
	return *this;
}

Produse& Produse::operator += (int number)
{
	numar_produse_disponibile += number;
	return *this;
}

Produse& Produse::operator -= (Produse& Produs)
{
	try {
		numar_produse_disponibile -= Produs.numar_produse_disponibile;
		if (numar_produse_disponibile >= 0)
		{
			pret = double((numar_produse_disponibile * pret - Produs.numar_produse_disponibile * Produs.pret)) / double(numar_produse_disponibile);
			return *this;
		}
		else {
			numar_produse_disponibile += Produs.numar_produse_disponibile;
			throw(numar_produse_disponibile);
		}
	}
	catch (int Nr_prod) {
		cout << "Stocul este insuficient!" << '\n';
		cout << "Numar produse in stoc: " << Nr_prod << '\n';
		cout << "Numar produse dorite: " << Produs.numar_produse_disponibile << '\n';
	}
	return *this;
}

Produse& Produse::operator -= (int number)
{
	try {
		if (numar_produse_disponibile - number >= 0)
		{
			numar_produse_disponibile -= number;
			return *this;
		}
		else {
			throw runtime_error("Numar produse insuficient");
		}
	}
	catch (runtime_error)
	{
		cout << "Stocul este insuficient";
	}
	return *this;
}

Produse& Produse::operator *= (Produse& Produs)
{
	marca = marca + " " + "si" + " " + Produs.marca;
	numar_produse_disponibile *= Produs.numar_produse_disponibile;
	pret = double((numar_produse_disponibile * pret + Produs.numar_produse_disponibile * Produs.pret)) / double(numar_produse_disponibile);
	return *this;
}
Produse& Produse::operator *= (int number)
{
	numar_produse_disponibile *= number;
	return *this;
}

Produse& Produse::operator /= (Produse& Produs)
{
	numar_produse_disponibile /= Produs.numar_produse_disponibile;
	return *this;
}

Produse& Produse::operator /= (int number)
{
	numar_produse_disponibile /= number;
	return *this;
}


Produse operator +(Produse& Produs1, Produse& Produs2)
{
	Produse Prod_Final(Produs1);
	Prod_Final += Produs2;
	return Prod_Final;
}

Produse operator +(Produse& Produs, int number)
{
	Produse Prod_Final(Produs);
	Prod_Final += number;
	return Prod_Final;
}

Produse operator +(int number, Produse& Produs)
{
	Produse Prod_Final(Produs);
	Prod_Final += number;
	return Prod_Final;
}

Produse operator -(Produse& Produs1, Produse& Produs2)
{
	Produse P(Produs1);
	try {
		P -= Produs2;
	}
	catch (string)
	{
		throw runtime_error("Stocul este insuficient");
	}
	return P;
}

Produse operator -(Produse& Produs, int number)
{
	Produse P(Produs);
	try {
		P -= number;
	}
	catch (runtime_error&)
	{
		throw runtime_error("Stocul este insuficient");
	}
	return P;
}

Produse operator -(int number, Produse& Produs)
{
	Produse P(Produs);
	try {
		P -= number;
	}
	catch (runtime_error&)
	{
		throw runtime_error("Stocul este insuficient");
	}
	return P;
}

Produse operator *(Produse& Produs1, Produse& Produs2)
{
	Produse P(Produs1);
	P *= Produs2;
	return P;
}

Produse operator *(Produse& Produs, int number)
{
	Produse P(Produs);
	P *= number;
	return P;
}

Produse operator *(int number, Produse& Produs)
{
	Produse P(Produs);
	P *= number;
	return P;
}

Produse operator / (Produse& Produs1, Produse& Produs2)
{
	Produse P(Produs1);
	P /= Produs2;
	return P;
}

Produse operator / (Produse& Produs, int number)
{
	Produse P(Produs);
	P /= number;
	return P;
}

Produse operator / (int number, Produse& Produs)
{
	Produse P(Produs);
	P /= number;
	return P;
}

bool operator == (Produse& Produs1, Produse& Produs2)
{
	if (Produs1.marca != Produs2.marca)
		return false;
	return true;

}
bool operator != (Produse& Produs1, Produse& Produs2)
{
	if (Produs1.marca == Produs2.marca)
		return false;
	return true;

}

ostream& operator<<(ostream& o, const Produse& Produs)
{
	o << Produs.marca << ' ' << Produs.numar_produse_disponibile << ' ' << Produs.pret;
	return o;
}

ofstream& operator<<(ofstream& o, Produse& Produs)
{
	o << Produs.marca << ' ' << Produs.numar_produse_disponibile << ' ' << Produs.pret;
	return o;
}

istream& operator>>(istream& in, Produse& Produs)
{
	in >> Produs.marca >> Produs.numar_produse_disponibile >> Produs.pret;
	return in;
}

ifstream& operator>>(ifstream& in, Produse& Produs)
{
	in >> Produs.marca >> Produs.numar_produse_disponibile >> Produs.pret;
	return in;
}
