#include <iostream>
#include <fstream>
#include "Matrix/matrix.hpp"

using namespace std;

int main()
{
    cout << "\nTworzymy macierz A o wymiarach 4x4\n\n";
    Matrix A(4, 4);
    cout << " Przed zainicjowaniem wartosci: \n";
    A.print();
    A.CreateMatrix();
    cout << " Po zainicjowaniu wartosci wedlug przypadkowego wzoru: \n";
    A.print();
    cout << "\n\nTworzymy macierz B o wymiarach 4x4\n\n";
    Matrix B(4);
    cout << " Przed zainicjowaniem wartosci: \n";
    B.print();
    B.CreateMatrix();
    cout << " Po zainicjowaniu wartosci wedlug przypadkowego wzoru: \n";
    B.print();

    cout << "\n\nW macierzy A znajduja sie " << A.cols() << " kolumny i " << A.rows() << " wiersze" << endl
         << endl;

    cout << "Teraz sprawdzimy jaka wartosc znajduje sie w komurce o wspolrzednych (1, 3) w macierzy A\n";
    cout << "Wartosc w tej komurce jest rowna: " << A.get(1, 3) << endl
         << endl;
    double x = B.get(2, 3);
    cout << "Nastepnie  zmienimy warosc komurki (2, 3) w macierzy B na 10\n";
    B.set(2, 3, 10);
    cout << "Przed zamiana: " << x << "\nPo zamianie: " << B.get(2, 3) << endl
         << endl;

    cout << "Teraz dodajmy do siebie te macierze.\n\nPrzed dodaniem A wyglada nastepujaco:\n";
    A.print();
    cout << "\n\nNatomiast B wyglada tak:\n";
    B.print();
    cout << "\n\nPo dodaniu:\n";
    Matrix C = A.add(B);
    C.print();

    cout << "\n\nTeraz odejmiemy  macierz B od macierzy powstalej w wyniku dodania A i B\n\n";
    Matrix D = C.substract(B);
    D.print();

    cout << "\n\nNa koncu pomnozmy macierz uzyskana po odejmowaniu z macierza uzyskana po dodawaniu  \n\n";
    Matrix E = D.multiply(C);
    E.print();

    string filename = "plik.txt", path;
    cout << "\n\nTeraz zapiszymy macierz A do pliku\n\n";
    cout << "Podaj sciezke do zapisu\n";
    cin >> path;
    A.store(filename, path);

    cout << "Nastepnie wczytamy macierz A z pliku do innego obiektu\n\n";
    Matrix f(filename, path);
    cout << "Powstala macierz wyglada nastepujaco:\n\n";
    f.print();

    return 0;
}

