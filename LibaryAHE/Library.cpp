#include "library.h"
#include "stdafx.h"


void Library::AddBook(const Book &book)
{
	books.push_back(book);
}

void Library::Display() const
{
	for (int i = 0; i < books.size(); i++)
	{
		cout << i + 1 << ". ";
		books[i].DisplayShort();
	}
}
//void Library::save() {
//	ofstream plik("library.txt");
//	for (vector<Book>::iterator i = books.begin(); i < books.end(); i++)
//		plik << i->toString();
//	plik.close();
//
//}

//void Library::load()  {
//	ifstream plik("library.txt");
//	while (plik) {
//		string author, title;
//		plik >> author >> title;
//		Book tmp (author, title, 1999, 4, "Ziutek Books", 150, "Bardzo ciekawa bajka");
//		books.push_back(tmp);
//	}
//}
void Library::load() {
	fstream plik;
	plik.open("library.txt", ios::in);

	if (plik.good() == false) {
		cout << "Plik nie istnieje!";
		exit(0);
	}
	string line;
	int number_line = 1;
	string author; string title; unsigned int year = 0; unsigned int edition = 0; string publisher; unsigned int pages = 0; string description;
	while (getline(plik, line)) {

			switch (number_line) {
				case 1: author = line; break;
				case 2: title = line; break;
				case 3: year = atoi(line.c_str()); break;
				case 4: edition = atoi(line.c_str()); break;
				case 5: publisher = line; break;
				case 6: pages = atoi(line.c_str()); break;
				case 7: description = line; break;			
			} if (number_line == 7) { 
				
				Book tmp(author, title, year, edition, publisher, pages, description);
				books.push_back(tmp);
				number_line = 0;
			}
			number_line++;


		//	for (number_line; number_line++; number_line >= 7) {
		//		
		//		if (number_line == 1) {
		//			author = line; break;
		//		if (number_line == 2)
		//			title = line; break;
		//		if (number_line == 3)
		//			year = atoi(line.c_str()); break;
		//		if (number_line == 4)
		//			edition = atoi(line.c_str()); break;
		//		if (number_line == 5)
		//			publisher = line; break;
		//		if (number_line == 6)
		//			pages = atoi(line.c_str()); break;
		//		if (number_line == 7)
		//			description = line; break;
		//		}
				//Library::AddBook(Book(author, title, year, edition, publisher, pages, description));

		}
	plik.close();
}


Book& Library::operator[](size_t index)
{
	return books[index];
}

size_t Library::GetSize() const
{
	return books.size();
}
