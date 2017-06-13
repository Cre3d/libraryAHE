// LibaryAHE.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include <cstdlib>

#include "library.h"

using namespace std;

void Menu(const Library &lib)
{
	system("cls");

	cout << "Liczba ksizek w bibliotece: " << lib.GetSize() << endl << endl;

	cout << "1. Wyswietl biblioteke" << endl;
	cout << "2. Wyswietl szczegilowe informacje o ksiazce" << endl;
	cout << "3. Dodaj ksiazke" << endl;
	cout << "4. Usun ksiazke" << endl;
	cout << "5. Wypozycz ksiazke" << endl;
	cout << "6. Zwroc ksiazke" << endl;
	cout << "8. Zapis biblioteki" << endl;
	cout << "9. Wczytaj biblioteke" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "0. Koniec" << endl << endl;
	cout << "Twoj wybor: ";
}


int main()
{
	Library lib;
	
	lib.AddBook(Book("KowalskiJan", "CzerwonyKapturek", 1999, 4, "Ziutek Books", 150, ""));
	lib.AddBook(Book("NowakJan", "JasMalgosia", 1999, 11, "Ziutek Books", 234, "Bardzo ciekawa bajka"));


	//	lib.Display();
	//	
	//	lib[1].DisplayShort();
	//	
	//	system("pause");
	//	
	char ch;
	bool end = 0;

	while (!end)
	{
		cout << "Liczba ksizek w bibliotece: " << lib.GetSize() << endl;
		Menu(lib);

		cin >> ch;
		cin.clear();
		cin.ignore(10000, '\n');

		switch (ch)
		{
		case '1': // Wyswietl ksiazki
			lib.Display();
			system("pause");
			break;
		case '2': // Wyswietl szczeglowe informacje
			cout << "Ktora ksiazka: ";
			int book_number;
			cin >> book_number;
			lib[book_number - 1].Display();
			system("pause");
			break;
		case '3': // Dodaj ksiazke
		{
			//Author
			char author[100];
			cout << "Autor: ";
			cin.getline(author, 100);

			//Title
			char title[300];
			cout << "Tytul: ";
			cin.getline(title, 300);
		

			//Year
			unsigned int year;
			cout << "Rok: ";
			cin >> year;
			cin.ignore();

			//Edition
			unsigned int edition;
			cout << "Wydanie: ";
			cin >> edition;
			cin.ignore();

			//Publisher
			char publisher[100];
			cout << "Wydawnictwo: ";
			cin.getline(publisher, 100);
			

			//Pages
			unsigned int pages;
			cout << "Ilosc stron: ";
			cin >> pages;
			cin.ignore();

			//Description
			char description[1000];
			cout << "Opis: ";
			cin.getline(description, 1000);
			

			// Save to file
			fstream plik;
			plik.open("library.txt", ios::out | ios::app);
			plik << author << endl;
			plik << title << endl;
			plik << year << endl;
			plik << edition << endl;
			plik << publisher << endl;
			plik << pages << endl;
			plik << description << endl;

			plik.close();

			// Add to vector
			 lib.AddBook(Book(author,title,year,edition,publisher,pages,description));
			//lib.AddBook(Book(author, title, year, 1, "PWN", 100, "Opis"));
		}
		break;
		case '4': // Usun ksiazke
		{
			
		}
		break;
		case '5': // Wypozycz ksiazke
		{

		}
		break;
		case '6': // Zwroc ksiazke
		{

		}
		break;
		case '8': // Zapis bazy
		{
			lib.save();
		}
		break;
		case '9': // Wczytanie bazy
		{
			lib.load();
		}
		break;
		case '0':
			end = 1;
			break;
		}
	}

	return 0;
}



