#pragma once
#include <iostream>
#include <string>

using namespace std;

class Produse {
public:
	Produse(string brand, int nr_prod, double price);
	Produse();
	Produse(const Produse& Produs);
	void set_marca(string brand);
	string get_marca();
	void set_numar_produse_disponibile(int nr_prod);
	int get_numar_produse_disponibile();
	void set_pret(double price);
	double get_pret();

	Produse& operator += (Produse&);
	Produse& operator +=(int);
	Produse& operator -= (Produse&);
	Produse& operator -=(int);
	Produse& operator *= (Produse&);
	Produse& operator *= (int);
	Produse& operator /= (Produse&);
	Produse& operator /= (int);
	

	friend Produse operator + (Produse&, Produse&);
	friend Produse operator + (Produse&, int);
	friend Produse operator + (int, Produse&);
	friend Produse operator - (Produse&, Produse&);
	friend Produse operator - (Produse&, int);
	friend Produse operator - (int, Produse&);
	friend Produse operator * (Produse&, Produse&);
	friend Produse operator * (Produse&, int);
	friend Produse operator * (int, Produse&);
	friend Produse operator / (Produse&, Produse&);
	friend Produse operator / (Produse&, int);
	friend Produse operator / (int, Produse&);
	friend bool operator == (Produse&, Produse&);
	friend bool operator != (Produse&, Produse&);
	friend ostream& operator<<(ostream&, const Produse&);
	friend istream& operator>>(istream&, Produse&);
	friend ifstream& operator>>(ifstream&, Produse&);
	friend ofstream& operator<<(ofstream&, Produse&);
private:
	string marca;
	int numar_produse_disponibile;
	double pret;
};