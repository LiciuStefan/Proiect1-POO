#pragma once
#include <iostream>
#include <vector>
#include "Produse.h"
#include "Programari.h"
#include "Angajati.h"
#include "Servicii.h"

using namespace std;
class Salon {
public:
	Salon(string, string, int);
	Salon();
	Salon(const Salon&);
	void set_nume(string);
	string get_nume();
	void set_adresa(string);
	string get_adresa();
	void set_numar_angajati(int);
	int get_numar_angajati();
	void set_numar_produse(int);
	int get_numar_produse();
	void set_numar_servicii(int);
	int get_numar_servicii();
	void add_angajat(Angajati);
	void elimina_angajat(string);
	void check_angajati();
	void add_produs(Produse );
	void add_programare(Programari);
	void add_serviciu(Servicii);
	bool check_product_availability(string);
	bool check_reservation_availability(Programari);
	void see_programari();
	void see_available_products();
	void see_servicii();
	void anuleaza_rezervare(Programari);
	void elimina_serviciu(Servicii);
	void sorteaza_angajati_dupa_nume();
	void sorteaza_angajati_dupa_salariu();
	double salariu_in_medie();
	Salon& operator += (Salon&);
	Salon& operator += (int);
	Salon& operator -= (Salon&);
	Salon& operator -=(int);
	Salon& operator *=(int);
	Salon& operator /=(int);
	Salon operator + ();
	friend Salon operator + (Salon&, Salon&);
	friend Salon operator +(Salon&, int);
	friend Salon operator +(int, Salon&);
	friend Salon operator - (Salon&, Salon&);
	friend Salon operator -(Salon&, int);
	friend Salon operator -(int, Salon&);
	friend Salon operator *(Salon&, int);
	friend Salon operator *(int, Salon&);
	friend Salon operator /(Salon&, const int);
	friend Salon operator /(const int, Salon&);
	friend bool operator == (Salon&, Salon&);
	friend bool operator != (Salon&, Salon&);

	friend ostream& operator<<(ostream&, const Salon&);
	friend istream& operator>>(istream&, Salon&);
private:
	string nume;
	string adresa;
	int numar_angajati;
	vector<Angajati> angajati;
	vector<Produse>produse;
	vector<Programari>programari;
	vector<Servicii>servicii;
};