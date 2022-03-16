#include <iostream>
#include <fstream>
#include "Salon.h"

using namespace std;

Salon::Salon(string num, string adr, int nr_angj)
{
	this->nume = num;
	this->adresa = adr;
	this->numar_angajati = nr_angj;
}
Salon::Salon()
{
	this->nume = "";
	this->adresa = "Adresa nu este inca disponibila";
	this->numar_angajati = 0;
}

Salon::Salon(const Salon& Salon1) {
	this->angajati.clear();
	this->produse.clear();
	this->programari.clear();
	this->servicii.clear();
	this->nume = Salon1.nume;
	this->adresa = Salon1.adresa;
	this->numar_angajati = Salon1.numar_angajati;
	for (auto i = Salon1.angajati.begin(); i != Salon1.angajati.end(); ++i)
		this->angajati.push_back(*i);
	for (auto i = Salon1.produse.begin(); i != Salon1.produse.end(); ++i)
		this->produse.push_back(*i);
	for (auto i = Salon1.programari.begin(); i != Salon1.programari.end(); ++i)
		this->programari.push_back(*i);
	for (auto i = Salon1.servicii.begin(); i != Salon1.servicii.end(); ++i)
		this->servicii.push_back(*i);
}
void Salon::set_nume(string num)
{
	this->nume = num;
}
string Salon::get_nume()
{
	return this->nume;
}

void Salon::set_adresa(string s)
{
	this->adresa = s;
}
string Salon::get_adresa() {
	return this->adresa;
}

void Salon::set_numar_angajati(int Nr_Angajati)
{
	this->numar_angajati = Nr_Angajati;
	this->angajati.reserve(numar_angajati);
}

int Salon::get_numar_angajati()
{
	return this->numar_angajati;
}

void Salon::set_numar_produse(int Nr_Produse)
{
	this->produse.reserve(Nr_Produse);
}
int Salon::get_numar_produse()
{
	return this->produse.size();
}

void Salon::set_numar_servicii(int Nr_Servicii)
{
	this->angajati.reserve(Nr_Servicii);
}

int Salon::get_numar_servicii()
{
	return this->servicii.size();
}
void Salon::add_angajat(Angajati angj)
{
	this->angajati.push_back(angj);
	if (this->angajati.size() > this->numar_angajati)
		this->numar_angajati += 1;
}

void Salon::elimina_angajat(string angj)
{
	for (int i = 0; i < this->angajati.size(); ++i)
	{
		if (angajati[i].get_nume() == angj)
		{
			for (int j = i + 1; j < this->angajati.size(); ++j)
				angajati[j - 1] = angajati[j];
			angajati.resize(angajati.size() - 1);
			this->numar_angajati -= 1;
			cout << "Angajatul a fost eliminat\n";
			return;
		}
	}
	cout << "Angajatul nu a fost gasit!\n";
}

void Salon::check_angajati()
{
	if (this->angajati.size() == 0)
	{
		cout << "Nu exista inca angajati!";
		return;
	}
	else
		for (auto i = this->angajati.begin(); i != this->angajati.end(); ++i)
			cout << *i << ' ';
}
void Salon::anuleaza_rezervare(Programari Prog)
{
	for (int i = 0; i < this->programari.size(); ++i)
		if (this->programari[i] == Prog)
		{
			for (int j = i + 1; j < this->programari.size(); ++j)
				this->programari[j - 1] = this->programari[j];
			this->programari.pop_back();
		}
}
void Salon::elimina_serviciu(Servicii S)
{
	for (int i = 0; i < this->servicii.size(); ++i)
		if (this->servicii[i] == S)
		{
			for (int j = i + 1; j < this->servicii.size(); ++j)
				this->servicii[j - 1] = this->servicii[j];
			//this->servicii.resize(servicii.size() - 1);
			//continue;
			this->servicii.pop_back();
		}
}

void Salon::add_produs(Produse P)
{
	bool OK = true;
	for (auto i = this->produse.begin(); i != this->produse.end(); ++i)
	{
		if (*i == P)
		{
			*i += P;
			OK = false;
			continue;
		}
	}
	if (OK)
		this->produse.push_back(P);
}

void Salon::add_serviciu(Servicii S)
{
	this->servicii.push_back(S);
}
void Salon::add_programare(Programari Prog)
{
	if (this->check_reservation_availability(Prog) != 0)
		this->programari.push_back(Prog);
}
bool Salon::check_reservation_availability(Programari Prog)
{
	for (int i = 0; i < this->programari.size(); ++i)
		if ((this->programari[i].get_ora() == Prog.get_ora()) && (this->programari[i].get_serviciu_dorit() == Prog.get_serviciu_dorit()))
			return false;
	return true;
}
void Salon::see_programari()
{
	if (this->programari.size() == 0)
	{
		cout << "Nu exista inca programari!";
		return;
	}
	else
		for (auto i = this->programari.begin(); i != this->programari.end(); ++i)
			cout << *i;
}
void Salon::see_servicii()
{
	if (this->servicii.size() == 0)
	{
		cout << "Nu exista inca servicii disponibile!";
		return;
	}
	else
		for (auto i = this->servicii.begin(); i != this->servicii.end(); ++i)
			cout << *i;
}

bool Salon::check_product_availability(string firma)
{
	for (int i = 0; i < this->produse.size(); ++i)
	{
		if (this->produse[i].get_marca() == firma && this->produse[i].get_numar_produse_disponibile() != 0)
			return true;
	}
	return false;
}

void Salon::see_available_products()
{
	if (this->produse.size() == 0)
	{
		cout << "Nu exista produse disponibile!";
		return;
	}
	else
		for (auto i = this->produse.begin(); i != this->produse.end(); ++i)
			cout << *i << ' ';
}

void Salon::sorteaza_angajati_dupa_nume()
{
	for(auto i = this->angajati.begin(); i!= this->angajati.end(); ++i)
		for (auto j = i + 1; j != this->angajati.end(); ++j)
		{
			if (i->get_nume() > j->get_nume())
				swap(*i, *j);
		}
}
void Salon::sorteaza_angajati_dupa_salariu()
{
	for (auto i = this->angajati.begin(); i != this->angajati.end(); ++i)
		for (auto j = i + 1; j != this->angajati.end(); ++j)
		{
			if (i->get_salariu() > j->get_salariu())
				swap(*i, *j);
		}
}

Salon& Salon::operator +=(Salon& S)
{
	this->numar_angajati += S.numar_angajati;
	for (auto i = S.angajati.begin(); i != S.angajati.end(); ++i)
		this->add_angajat(*i);
	
	for (auto i = S.produse.begin(); i != S.produse.end(); ++i)
	{
		for (auto j = this->produse.begin(); j != this->produse.end(); ++j)
			if (*j == *i)
			{
				*j += *j;
				continue;
			}
		this->produse.push_back(*i);
	}
	for (auto i = S.programari.begin(); i != S.programari.end(); ++i)
		if (this->check_reservation_availability(*i))
			this->programari.push_back(*i);
	for (auto i = S.servicii.begin(); i != S.servicii.end(); ++i)
	{
		for (auto j = this->servicii.begin(); j != this->servicii.end(); ++j)
			if (*j == *i)
				continue;
		this->servicii.push_back(*i);
	}

	return *this;
}
double Salon::salariu_in_medie()
{
	double medie = 0;
	for (auto i = this->angajati.begin(); i != this->angajati.end(); ++i)
		medie += i->get_salariu();
	medie /= float(this->numar_angajati);
	return medie;
 }
Salon& Salon::operator +=(int number)
{
	this->numar_angajati += number;
	return *this;
}

Salon& Salon::operator -=(Salon& S)
{
	try {
		if (numar_angajati - S.numar_angajati >= 0)
		{
			numar_angajati -= S.numar_angajati;
			for (int i = 0; i < this->angajati.size(); ++i)
			{
				for (auto j = S.angajati.begin(); j != S.angajati.end(); ++j)
					if (this->angajati[i] == *j)
						this->elimina_angajat(j->get_nume());

			}
			for (int i = 0; i < this->produse.size(); ++i)
			{
				for (auto j = S.produse.begin(); j != S.produse.end(); ++j)
					if (this->produse[i] == *j)
						this->produse[i] -= *j;
			}
			for (int i = 0; i < this->programari.size(); ++i)
			{
				for (auto j = S.programari.begin(); j != S.programari.end(); ++j)
					if (this->check_reservation_availability(*j) == 0)
					{
						this->anuleaza_rezervare(*j);
						continue;
					}
			}
			for (int i = 0; i < this->servicii.size(); ++i)
			{
				for (auto j = S.servicii.begin(); j != S.servicii.end(); ++j)
					if (this->servicii[i] == *j)
					{
						this->elimina_serviciu(*j);
						continue;
					}

			}
			return *this;

		}
		else {
			throw(numar_angajati);
		}
	}
	catch (int Nr_Angajati)
	{
		cout << "Numarul de angajati este prea mic";
	}

	return *this;
}
Salon& Salon::operator -=(int number)
{
	try {
		if (numar_angajati - number >= 0)
		{
			numar_angajati -= number;

			return *this;
		}
		else {
			throw(numar_angajati);
		}
	}
	catch (int Nr_Angajati)
	{
		cout << "Numarul de angajati este prea mic" << '\n';
	}

	return *this;
}
Salon& Salon::operator *=(int number)
{
	this->numar_angajati *= number;
	this->angajati.resize(this->numar_angajati);
	return *this;
}
Salon& Salon::operator /=(int number)
{
	if (number == 0)
		throw runtime_error("Operatia nu este posibila!");
	else
	{
		this->numar_angajati /= number;
		this->angajati.resize(this->numar_angajati);
	}

	return *this;
}

Salon Salon::operator + ()
{
	return *this;
}

Salon operator + (Salon& object1, Salon& object2)
{
	Salon result(object1);
	result += object2;
	return result;
}
Salon operator +(Salon& object1, int number)
{
	Salon result(object1);
	result += number;
	return result;
}

Salon operator +(int number, Salon& object2)
{
	Salon result(object2);
	result += number;
	return result;
}

Salon operator -(Salon& object1, Salon& object2)
{
	Salon result(object1);
	try {
		result -= object2;
	}
	catch (runtime_error&)
	{
		throw runtime_error("");
	}
	return result;
}
Salon operator -(Salon& object1, int number)
{
	Salon result(object1);
	try {
		result -= number;
	}
	catch (runtime_error&)
	{
		throw runtime_error("");
	}
	return result;
}
Salon operator -(int number, Salon& object2)
{
	Salon result(object2);
	try {
		result -= number;
	}
	catch (runtime_error&)
	{
		throw runtime_error("");
	}
	return result;
}

Salon operator * (Salon& S1, int number)
{
	Salon result(S1);
	result *= number;
	return result;
}

Salon operator * (int number, Salon& S1)
{
	Salon result(S1);
	result *= number;
	return result;
}

Salon operator / (Salon& S1, const int number)
{
	if (number == 0)
		throw runtime_error("Operatie imposibila!");
	Salon result(S1);
	result /= number;
	return result;
}

Salon operator / (const int number, Salon& S1)
{
	if (number == 0)
		throw runtime_error("Operatie imposibila!");
	Salon result(S1);
	result /= number;
	return result;
}


bool operator == (Salon& object1, Salon& object2)
{
	if (object1.numar_angajati == object2.numar_angajati && object1.adresa == object2.adresa && object1.nume == object2.nume)
	{
		return true;
	}
	return false;
}
bool operator != (Salon& object1, Salon& object2)
{
	if (object1.numar_angajati != object2.numar_angajati || object1.adresa != object2.adresa || object1.nume != object2.nume)
		return true;
	return false;
}

ostream& operator<<(ostream& o, const Salon& S)
{
	o << S.nume << ' ' << S.adresa << ' ' << S.numar_angajati << '\n';
	for (auto i = S.angajati.begin(); i != S.angajati.end(); ++i)
		o << *i << ' ';
	o << '\n';
	for (auto i = S.produse.begin(); i != S.produse.end(); ++i)
		o << *i << ' ';
	for (auto i = S.programari.begin(); i != S.programari.end(); ++i)
		o << *i << ' ';
	//o << '\n';
	for (auto i = S.servicii.begin(); i != S.servicii.end(); ++i)
		o << *i << ' ';

	return o;
}

istream& operator>>(istream& in, Salon& S)
{
	in >> ws;
	getline(in, S.nume);
	getline(in, S.adresa);
	in >> S.numar_angajati;
	return in;
}