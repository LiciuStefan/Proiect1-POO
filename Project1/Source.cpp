#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include "Salon.h"
#include "Angajati.h"
#include "Produse.h"
#include "Programari.h"
#include "Servicii.h"
using namespace std;

int main()
{
	system("CLS");
	vector<Salon>Saloane;
	Salon Salon_default("Apostroph", "Piatra Neamt", 35);
	Saloane.push_back(Salon_default);
	int choice;
	string OK;
	string nume, nume_salon, firma, operatie;
	bool cont;
label:
	cout << "Meniu" << "\n" << "##########################\n";
	cout <<"1.Vezi saloane disponibile\n"<<"2.Adauga Salon\n"<<"3.Adauga angajat\n" << "4.Elimina angajat\n" <<"5.Vezi lista angajati\n" << "6.Adauga produs\n" << "7.Comanda produs\n" << "8.Fa o rezervare\n" << "9.Anuleaza rezervarea\n" << "10.Vezi salariu mediu\n"<<"11.Operatii saloane\n"<<"12.Sorteaza Angajati";
	cout << "\nTastati 0 pentru a renunta\n"<<"##########################\n";
	cin >> choice;
	while (!cin)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Input invalid\n";
		system("PAUSE");
		system("CLS");
		goto label;
	}
	while (choice)
		{
			if (choice == 1)
			{
				if (Saloane.size() == 0)
					cout << "Nu exista inca saloane!\n";
				else
					for (auto i = Saloane.begin(); i != Saloane.end(); ++i)
						cout << *i;
			}
			else if (choice == 2)
			{
				Salon Object;
				cout << "Introduceti salonul de forma nume, adresa, numar de angajati\n";
				cin >> Object;
				Saloane.push_back(Object);
				cout << "Salonul cu numele " << Object.get_nume() << " a fost adaugat\n";
			}
			else if (choice == 3)
			{
				Angajati Angajat;
				cout << "Introduceti angajatul de forma nume, id, salariu.\n";
				cin >> Angajat;
				cout << "Introduceti numele salonului in care vreti sa introduceti angajatul:\n";
			    cont = false;
				cin >> nume_salon;
				for (auto i = Saloane.begin(); i != Saloane.end(); ++i)
				{
					if (i->get_nume() == nume_salon)
					{
						i->add_angajat(Angajat);
						cont = true;
					}
				}

				//Salon_default.add_angajat(Angajat);
				if (cont == true)
					cout << "Angajatul cu numele " << Angajat.get_nume() << " a fost adaugat\n";
				else
					cout << "Salonul nu a fost gasit\n";
			}
			else if (choice == 4)
			{
				
			    cont = false;
				cout << "Introduceti numele complet al angajatului de eliminat:\n";
				cin >> nume;
				cout << "Introduceti numele salonului din care se elimina angajatul:\n";
				cin >> nume_salon;
				for (auto i = Saloane.begin(); i != Saloane.end(); ++i)
				{
					if (i->get_nume() == nume_salon)
					{
						i->elimina_angajat(nume);
						cont = true;
					}
				}
				if (cont == true)
					cout << "Angajatul cu numele " << nume << " a fost eliminat din salonul " << nume_salon << '\n';
				else
					cout << "Angajatul nu a fost gasit\n";
				//Salon_default.elimina_angajat(nume);

			}
			else if (choice == 5)
			{
				
				cont = false;
				cout << "Introduceti numele salonului:\n";
				cin >> nume_salon;
				for (auto i = Saloane.begin(); i != Saloane.end(); ++i)
				{
					if (i->get_nume() == nume_salon)
					{
						i->check_angajati();
						cont = true;
						continue;
					}
				}
				if (!cont)
					cout << "Salonul nu a fost gasit\n";

			}
			else if (choice == 6)
			{
				Produse Product;
				cout << "Adaugati produsul dorit, de forma marca, numar produse si pret:\n";
				cin >> Product;
				cont = false;
				cout << "Introduceti numele salonului:\n";
				cin >> nume_salon;
				for (auto i = Saloane.begin(); i != Saloane.end(); ++i)
				{
					if (i->get_nume() == nume_salon)
					{
						i->add_produs(Product);
						cont = true;
						continue;
					}
				}
				if (!cont)
					cout << "Salonul nu a fost gasit\n";
				else cout << "Produsul a fost adaugat in stoc\n";
			}

			else if (choice == 7)
			{
			   
				cout << "Introduceti numele salonului:\n";
				//cout << "Produse disponibile:\n";
				//Salon_default.see_available_products();
				cin >> nume_salon;
				for (auto i = Saloane.begin(); i != Saloane.end(); ++i)
				{
					if (i->get_nume() == nume_salon)
					{
						i->see_available_products();
						cout << "\nIntroduceti marca produsului dorit:\n";
						cin >> firma;
						if (i->check_product_availability(firma))
							cout << "Produsul este in stoc\n";
						else
							cout << "Produsul nu se afla in stoc\n";
						//cont = true;
						continue;
					}
				}

			}

			else if (choice == 8)
			{
				
				cout << "Introduceti numele salonului:\n";
				cin >> nume_salon;
				cout << "Programari indisponibile:\n";
				cont = false;
				for (auto i = Saloane.begin(); i != Saloane.end(); ++i)
				{
					if (i->get_nume() == nume_salon)
					{
						cont = true;
						i->see_programari();
						Programari Programare1;
						cout << "Introduceti programarea de forma ora, serviciu dorit si tarif:\n";
						cin >> Programare1;
						if (i->check_reservation_availability(Programare1))
						{
							cout << "Programarea poate fi efectuata\n";
							i->add_programare(Programare1);
						}
						else
							cout << "Programarea nu poate fi efectuata\n";
						continue;
					}
				}
				if (cont == false)
					cout << "Salonul nu a fost gasit\n";
			}
			else if (choice == 9)
			{
				
				cout << "Introduceti numele salonului:\n";
				cin >> nume_salon;
				cont = false;
				for (auto i = Saloane.begin(); i != Saloane.end(); ++i)
				{
					if (i->get_nume() == nume_salon)
					{
						cont = true;
		
						Programari Programare1;
						cout << "Introduceti programarea de forma ora, serviciu dorit si tarif:\n";
						cin >> Programare1;
						if (i->check_reservation_availability(Programare1))
						{
							cout << "Programarea nu a fost gasita\n";
							continue;
						}
						else
						{
							cout << "Programarea a fost anulata\n";
							i->anuleaza_rezervare(Programare1);
							continue;
						}
					}
				}
				if (cont == false)
					cout << "Salonul nu a fost gasit\n";
			}

			else if (choice == 10)
			{
				
				cont = false;
				cout << "Introduceti numele salonului:\n";
				cin >> nume_salon;
				for (auto i = Saloane.begin(); i != Saloane.end(); ++i)
				{
					if (i->get_nume() == nume_salon)
					{
						cont = true;
						cout << "Salariul mediu/angajat este:\n";
						cout << i->salariu_in_medie() << " lei\n";
						continue;
					}
				}
				if(cont == false)
					cout << "Salonul nu a fost gasit\n";
			}

			else if (choice == 11)
			{
			Salon Salon1;
			Salon Salon2;
			Angajati Angajat;
			Produse Produs;
			Servicii Serviciu;
			Programari Programare;
			 cout << "Introduceti primul salon de forma nume, adresa, numar de angajati:\n";
			 cin >> Salon1;
			 cout << "Doriti sa adaugati angajati?\n";
			 cin >> OK;
			 
			 if (OK.compare("Da") == 0 || OK.compare("da") == 0)
			 {   adauga_angajat:
				 cout << "Introduceti angajat de forma nume, id, salariu:\n";
				 cin >> Angajat;
				 Salon1.add_angajat(Angajat);
				 cout << "Doriti sa adaugati si alti angajati?\n";
				 cin >> OK;
				 if (OK.compare("Da") == 0 || OK.compare("da") == 0)
					 goto adauga_angajat;
			 }
			 cout << "Doriti sa adaugati produse?\n";
			 cin >> OK;

			 if (OK.compare("Da") == 0 || OK.compare("da") == 0)
			 {
			 adauga_produs:
				 cout << "Introduceti produsul de forma marca, numar bucati, pret:\n";
				 cin >> Produs;
				 Salon1.add_produs(Produs);
				 cout << "Doriti sa adaugati si alte produse\n";
				 cin >> OK;
				 if (OK.compare("Da") == 0 || OK.compare("da") == 0)
					 goto adauga_produs;
			 }

			 cout << "Doriti sa adaugati servicii?\n";
			 cin >> OK;

			 if (OK.compare("Da") == 0 || OK.compare("da") == 0)
			 {
			 adauga_serviciu:
				 cout << "Introduceti serviciul de forma nume, durata, pret:\n";
				 cin >> Serviciu;
				 Salon1.add_serviciu(Serviciu);
				 cout << "Doriti sa adaugati si alte servicii?\n";
				 cin >> OK;
				 if (OK.compare("Da") == 0 || OK.compare("da") == 0)
					 goto adauga_serviciu;
			 }

			 cout << "Doriti sa adaugati programari?\n";
			 cin >> OK;

			 if (OK.compare("Da") == 0 || OK.compare("da") == 0)
			 {
			 adauga_programare:
				 cout << "Introduceti programarea de forma ora, nume serviciu, pret:\n";
				 cin >> Programare;
				 Salon1.add_programare(Programare);
				 cout << "Doriti sa adaugati si alte programari?\n";
				 cin >> OK;
				 if (OK.compare("Da") == 0 || OK.compare("da") == 0)
					 goto adauga_programare;
			 }
			 cout << "Introduceti al doilea salon de forma nume, adresa, numar de angajati:\n";
			 cin >> Salon2;
			 cout << "Doriti sa adaugati angajati?\n";
			 cin >> OK;
			 if (OK.compare("Da") == 0 || OK.compare("da") == 0)
			 {
			 adauga_angajat2:
				 cout << "Introduceti angajat de forma nume, id, salariu:\n";
				 cin >> Angajat;
				 Salon2.add_angajat(Angajat);
				 cout << "Doriti sa adaugati si alti angajati?\n";
				 cin >> OK;
				 if (OK.compare("Da") == 0 || OK.compare("da") == 0)
					 goto adauga_angajat2;
			 }
			 cout << "Doriti sa adaugati produse?\n";
			 cin >> OK;

			 if (OK.compare("Da") == 0 || OK.compare("da") == 0)
			 {
			 adauga_produs2:
				 cout << "Introduceti produsul de forma marca, numar bucati, pret:\n";
				 cin >> Produs;
				 Salon2.add_produs(Produs);
				 cout << "Doriti sa adaugati si alte produse\n";
				 cin >> OK;
				 if (OK.compare("Da") == 0 || OK.compare("da") == 0)
					 goto adauga_produs2;
			 }

			 cout << "Doriti sa adaugati servicii?\n";
			 cin >> OK;

			 if (OK.compare("Da") == 0 || OK.compare("da") == 0)
			 {
			 adauga_serviciu2:
				 cout << "Introduceti serviciul de forma nume, durata, pret:\n";
				 cin >> Serviciu;
				 Salon2.add_serviciu(Serviciu);
				 cout << "Doriti sa adaugati si alte servicii?\n";
				 cin >> OK;
				 if (OK.compare("Da") == 0 || OK.compare("da") == 0)
					 goto adauga_serviciu2;
			 }

			 cout << "Doriti sa adaugati programari?\n";
			 cin >> OK;

			 if (OK.compare("Da") == 0 || OK.compare("da") == 0)
			 {
			 adauga_programare2:
				 cout << "Introduceti programarea de forma ora, nume serviciu, pret:\n";
				 cin >> Programare;
				 Salon2.add_programare(Programare);
				 cout << "Doriti sa adaugati si alte programari?\n";
				 cin >> OK;
				 if (OK.compare("Da") == 0 || OK.compare("da") == 0)
					 goto adauga_programare2;
			 }

			 cout << "Inserati operatia dorita:\n";
			 cin >> operatie;
			 if (operatie == "+=")
			 {
				 Salon1 += Salon2;
				 cout << Salon1;

			 }
			 else if (operatie == "-=")
			 {
				 Salon1 -= Salon2;
				 cout << Salon1;

			 }
			 else if (operatie == "+")
			 {
	
				 cout << Salon1+Salon2;
			 }
			 else if (operatie == "-")
			 {
				 cout << Salon1-Salon2;
			 }
			 else if (operatie == "==")
			 {
				 if (Salon1 == Salon2)
					 cout << "Saloanele sunt echivalente\n";
				 else cout << "Saloanele sunt diferite\n";
			 }
			 else if (operatie == "!=")
			 {
				 if (Salon1 == Salon2)
					 cout << "Saloanele sunt echivalente\n";
				 else cout << "Saloanele sunt diferite\n";
			 }
			 cout << "\n";
            }

			else if (choice == 12)
			{
			   int ch;
			   cont = false;
			   cout << "Introduceti numele salonului:\n";
			   cin >> nume_salon;
			   cout << "Sortare dupa:\n 1.Nume\n2.Salariu\n";
			   cin >> ch;
			   if (ch == 1)
		 	    {
				   for (auto i = Saloane.begin(); i != Saloane.end(); ++i)
				   {
					   if (i->get_nume() == nume_salon)
					   {
						   cont = true;
						   cout << "Angajatii sortati dupa nume:\n";
						   i->sorteaza_angajati_dupa_nume();
						   i->check_angajati();
						   continue;
					   }
				   }
				   if (cont == false)
					   cout << "Salonul nu a fost gasit\n";

			    }
			   else if (ch == 2)
			    {

				   for (auto i = Saloane.begin(); i != Saloane.end(); ++i)
				   {
					   if (i->get_nume() == nume_salon)
					   {
						   cont = true;
						   cout << "Angajatii sortati dupa salariu:\n";
						   i->sorteaza_angajati_dupa_salariu();
						   i->check_angajati();
						   continue;
					   }
				   }
				   if (cont == false)
					   cout << "Salonul nu a fost gasit\n";
			    }
			    else cout << "Input invalid\n";
			}

			else
			{
			  cout << "Input invalid\n";
			  system("PAUSE");
			  system("CLS");
			  goto label;
			}
			cout << "Doriti o alta optiune? (Da/Nu)\n";
			cin >> OK;
			if (OK.compare("Da") == 0 || OK.compare("da") == 0)
			{
				cout << "\nIntroduceti optiunea aleasa:\n";
				cin >> choice;
			}
			else
				choice = 0;
		}
	return 0;
}

