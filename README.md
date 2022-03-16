# Proiect1-POO
Primul proiect realizat in cadrul cursului de Programare orientata pe obiecte, anul I, Facultatea de Matematica si Informatica, Universitatea din Bucuresti
Proiectul poate fi utilizat in gestionarea unor saloane.
Clasele utilizate:
Angajati
Servicii
Produse
Programari
Salon

Clasele sunt definite prin agregare, fiecare obiect de tip salon continand un vector de angajati, servicii, produse si programari.
Pentru fiecare clasa au fost supraincarcati operatori compusi de atribuire, operatori aritmetici binari, operatori relationali si de citire si scriere.
Da asemenea, au fost implementate functii de set si get, plus alte utilitati in clasa Salon precum sorteaza_angaajti_dupa_salariu, add_angajat, elimina_angajat, check_product_availability, check_reservation_availability, anuleaza_rezervare, salariu_in_medie etc.

Fluxuri de testare:
Programul prezinta un meniu cu 12 optiuni.
Pentru a selecta optiunea dorita, se introduce numarul corespunzator. Pentru iesire din meniu se introduce 0.
Daca inputul nu este corespunzator, se va afisa mesajul "Input invalid" si se va reseta meniul.
La fiecare pas sunt disponibile informatii despre tipul datelor ce trebuie introduse de catre utilizator.
Pentru evidentierea actiunilor folosim un vector de obiecte de tip Salon. La inceput acesta contine un singur element, by default, salonul Apostroph.
Utilizatorul are optiunea de viziona saloanele, de a adauga saloane, de a adauga si/sau elimina angajati, adauga sau comanda produs, de a face rezervari si de a le anula, alegand totodata salonul in care vrem sa facem aceste aranjamente. In plus, putem viziona salariul mediu de persoana intr-un salon, sau putem face operatii cu doua saloane introduse si gestionate de la tastatura. (+, -, +=, -=, ==, !=) Se pot sorta si viziona angajatii dupa nume/salariu.

Exemplu input:
1 //Vezi saloane disponibile
Da
2 //Adauga salon
Elegance
Bucuresti
50
Da
2 //Adauga salon
Noreen
Ilfov
20
Da
2 //Adauga salon
Salomeea
Bacau
15
Da
3 //Adauga angajat
Liciu
1
5000
Apostroph //Salonul in care se adauga angajatul
Da
3 //Adauga angajat
Popovici
12
4500
Salomeea
Da
5 //Vezi lista angajati
Apostroph
Da
4 //Elimina angajati
Liciu
Apostroph
Da
5 //Vezi lista angajati
Apostroph
Da
6 //Adauga produs
Babor
50
60
Apostroph
Da
6 //Adauga produs
Chanel
30
100
Apostroph
Da
7 //Comanda produs
Apostroph
Chanel
Da
8 // Adauga programare
Salomeea
10:30
Masaj
45
Da
8 //Adauga programare
Salomeea
12:00
Make-up
80
Da
10 //Vezi salariu mediu
Salomeea
Da
3 //Adauga angajat
Liciu
1
5000
Apostroph
Da
3 //Adauga angajat
Chitu
2
5500
Apostroph
Da
3 //Adauga angajat
Popovici
3
2500
Da
12 //Sorteaza angajati
Apostroph
1 //Dupa nume
Da
12 //Sorteaza angajati
Apostroph
2 //Dupa salariu
Nu

Input+Output:
Meniu
##########################
1.Vezi saloane disponibile
2.Adauga Salon
3.Adauga angajat
4.Elimina angajat
5.Vezi lista angajati
6.Adauga produs
7.Comanda produs
8.Fa o rezervare
9.Anuleaza rezervarea
10.Vezi salariu mediu
11.Operatii saloane
12.Sorteaza Angajati
Tastati 0 pentru a renunta
##########################
1
Apostroph Piatra Neamt 35

Doriti o alta optiune? (Da/Nu)
Da

Introduceti optiunea aleasa:
2
Introduceti salonul de forma nume, adresa, numar de angajati
Elegance
Bucuresti
50
Salonul cu numele Elegance a fost adaugat
Doriti o alta optiune? (Da/Nu)
Da

Introduceti optiunea aleasa:
2
Introduceti salonul de forma nume, adresa, numar de angajati
Noreen
Ilfov
20
Salonul cu numele Noreen a fost adaugat
Doriti o alta optiune? (Da/Nu)
Da

Introduceti optiunea aleasa:
2
Introduceti salonul de forma nume, adresa, numar de angajati
Salomeea
Bacau
15
Salonul cu numele Salomeea a fost adaugat
Doriti o alta optiune? (Da/Nu)
Da

Introduceti optiunea aleasa:
3
Introduceti angajatul de forma nume, id, salariu.
Liciu
1
5000
Introduceti numele salonului in care vreti sa introduceti angajatul:
Apostroph
Angajatul cu numele Liciu a fost adaugat
Doriti o alta optiune? (Da/Nu)
Da

Introduceti optiunea aleasa:
3
Introduceti angajatul de forma nume, id, salariu.
Popovici
12
4500
Introduceti numele salonului in care vreti sa introduceti angajatul:
Salomeea
Angajatul cu numele Popovici a fost adaugat
Doriti o alta optiune? (Da/Nu)
Da

Introduceti optiunea aleasa:
5
Introduceti numele salonului:
Apostroph
Liciu 1 5000 Doriti o alta optiune? (Da/Nu)
Da

Introduceti optiunea aleasa:
4
Introduceti numele complet al angajatului de eliminat:
Liciu
Introduceti numele salonului din care se elimina angajatul:
Apostroph
Angajatul a fost eliminat
Angajatul cu numele Liciu a fost eliminat din salonul Apostroph
Doriti o alta optiune? (Da/Nu)
Da

Introduceti optiunea aleasa:
5
Introduceti numele salonului:
Apostroph
Nu exista inca angajati!Doriti o alta optiune? (Da/Nu)
Da

Introduceti optiunea aleasa:
6
Adaugati produsul dorit, de forma marca, numar produse si pret:
Babor
50
60
Introduceti numele salonului:
Apostroph
Produsul a fost adaugat in stoc
Doriti o alta optiune? (Da/Nu)
Da

Introduceti optiunea aleasa:
6
Adaugati produsul dorit, de forma marca, numar produse si pret:
Chanel
30
100
Introduceti numele salonului:
Apostroph
Produsul a fost adaugat in stoc
Doriti o alta optiune? (Da/Nu)
Da

Introduceti optiunea aleasa:
7
Introduceti numele salonului:
Apostroph
Babor 50 60 Chanel 30 100
Introduceti marca produsului dorit:
Chanel
Produsul este in stoc
Doriti o alta optiune? (Da/Nu)
Da

Introduceti optiunea aleasa:
8
Introduceti numele salonului:
Salomeea
Programari indisponibile:
Nu exista inca programari!Introduceti programarea de forma ora, serviciu dorit si tarif:
10:30
Masaj
45
Programarea poate fi efectuata
Doriti o alta optiune? (Da/Nu)
Da

Introduceti optiunea aleasa:
8
Introduceti numele salonului:
Salomeea
Programari indisponibile:
Serviciu: Masaj Ora:10:30 Pret:45
Introduceti programarea de forma ora, serviciu dorit si tarif:
12:00
Make-up
80
Programarea poate fi efectuata
Doriti o alta optiune? (Da/Nu)
Da

Introduceti optiunea aleasa:
9
Introduceti numele salonului:
Salomeea
Introduceti programarea de forma ora, serviciu dorit si tarif:
12:00
Make-up
80
Programarea a fost anulata
Doriti o alta optiune? (Da/Nu)
Da

Introduceti optiunea aleasa:
10
Introduceti numele salonului:
Salomeea
Salariul mediu/angajat este:
300 lei
Doriti o alta optiune? (Da/Nu)
Da

Introduceti optiunea aleasa:
3
Introduceti angajatul de forma nume, id, salariu.
Liciu
1
5000
Introduceti numele salonului in care vreti sa introduceti angajatul:
Apostroph
Angajatul cu numele Liciu a fost adaugat
Doriti o alta optiune? (Da/Nu)
Da

Introduceti optiunea aleasa:
3
Introduceti angajatul de forma nume, id, salariu.
Chitu
2
5500
Introduceti numele salonului in care vreti sa introduceti angajatul:
Apostroph
Angajatul cu numele Chitu a fost adaugat
Doriti o alta optiune? (Da/Nu)
Da

Introduceti optiunea aleasa:
3
Introduceti angajatul de forma nume, id, salariu.
Popovici
3
2500
Introduceti numele salonului in care vreti sa introduceti angajatul:
Apostroph
Angajatul cu numele Popovici a fost adaugat
Doriti o alta optiune? (Da/Nu)
Da

Introduceti optiunea aleasa:
12
Introduceti numele salonului:
Apostroph
Sortare dupa:
 1.Nume
2.Salariu
1
Angajatii sortati dupa nume:
Chitu 2 5500 Liciu 1 5000 Popovici 3 2500 Doriti o alta optiune? (Da/Nu)
Da

Introduceti optiunea aleasa:
12
Introduceti numele salonului:
Apostroph
Sortare dupa:
 1.Nume
2.Salariu
2
Angajatii sortati dupa salariu:
Popovici 3 2500 Liciu 1 5000 Chitu 2 5500 Doriti o alta optiune? (Da/Nu)
Nu


Exemplul2:
input:
11 //Operatii saloane
Noreen
Bucuresti
45
Da //Adauga angajat
Liciu
1
5500
Da //Adauga angajat
Popovici
2
4500
Nu //Trecem la produse
Da //Adauga produs
Babor
200
50
Nu //Trecem la servicii
Da //Adauga serviciu
Make-up
60
100
Da //Adauga serviciu
Hairstyle
40
40
Nu //Trecem la programari
Da //Adauga programare
10:30
Hairstyle
40
Nu //Trecem la cel de-al doilea salon
Salomeea
Bacau
35
Da //Adauga angajati
Chitu
23
4000
Nu //Trecem la produse
Da //Adauga produse
Chanel
100
110
Nu //Trecem la servicii
Da //Adauga servicii
Pedichiura
35
50
Nu //Trecem la programari
Da //Adauga programari
11:20
Pedichiura
50
Nu //Executam operatia
+= //Supraincarcare operator (se aduna numarul de agajati, se adauga angajatii, produsele, serviciile si rezervarile celui de-al doilea salon la primul);

Output:
Meniu
##########################
1.Vezi saloane disponibile
2.Adauga Salon
3.Adauga angajat
4.Elimina angajat
5.Vezi lista angajati
6.Adauga produs
7.Comanda produs
8.Fa o rezervare
9.Anuleaza rezervarea
10.Vezi salariu mediu
11.Operatii saloane
12.Sorteaza Angajati
Tastati 0 pentru a renunta
##########################
11
Introduceti primul salon de forma nume, adresa, numar de angajati:
Noreen
Bucuresti
45
Doriti sa adaugati angajati?
Da
Introduceti angajat de forma nume, id, salariu:
Liciu
1
5500
Doriti sa adaugati si alti angajati?
Da
Introduceti angajat de forma nume, id, salariu:
Popovici
2
4500
Doriti sa adaugati si alti angajati?
Nu
Doriti sa adaugati produse?
Da
Introduceti produsul de forma marca, numar bucati, pret:
Babor
200
50
Doriti sa adaugati si alte produse
Nu
Doriti sa adaugati servicii?
Da
Introduceti serviciul de forma nume, durata, pret:
Make-up
60
100
Doriti sa adaugati si alte servicii?
Da
Introduceti serviciul de forma nume, durata, pret:
Hairstyle
40
40
Doriti sa adaugati si alte servicii?
Nu
Doriti sa adaugati programari?
Da
Introduceti programarea de forma ora, nume serviciu, pret:
10:30
Hairstyle
40
Doriti sa adaugati si alte programari?
Nu
Introduceti al doilea salon de forma nume, adresa, numar de angajati:
Salomeea
Bacau
35
Doriti sa adaugati angajati?
Da
Introduceti angajat de forma nume, id, salariu:
Chitu
23
4000
Doriti sa adaugati si alti angajati?
Nu
Doriti sa adaugati produse?
Da
Introduceti produsul de forma marca, numar bucati, pret:
Chanel
100
110
Doriti sa adaugati si alte produse
Nu
Doriti sa adaugati servicii?
Da
Introduceti serviciul de forma nume, durata, pret:
Pedichiura
35
50
Doriti sa adaugati si alte servicii?
Nu
Doriti sa adaugati programari?
Da
Introduceti programarea de forma ora, nume serviciu, pret:
11:20
Pedichiura
50
Doriti sa adaugati si alte programari?
Nu
Inserati operatia dorita:
+=
Noreen Bucuresti 80
Liciu 1 5500 Popovici 2 4500 Chitu 23 4000
Babor 200 50 Chanel 100 110
 Serviciu: Hairstyle Ora:10:30 Pret:40
 Serviciu: Pedichiura Ora:11:20 Pret:50
 Make-up 60 100 Hairstyle 40 40 Pedichiura 35 50
Doriti o alta optiune? (Da/Nu)
Nu
