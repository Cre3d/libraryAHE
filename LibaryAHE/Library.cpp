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
void Library::save() {
	ofstream plik("library.txt");
	for (vector<Book>::iterator i = books.begin(); i < books.end(); i++)
		plik << i->toString();
	plik.close();

}

void Library::load()  {
	ifstream plik("library.txt");
	while (plik) {
		string author, title;
		plik >> author >> title;
		Book tmp (author, title, 1999, 4, "Ziutek Books", 150, "Bardzo ciekawa bajka");
		books.push_back(tmp);
	}
}

Book& Library::operator[](size_t index)
{
	return books[index];
}

size_t Library::GetSize() const
{
	return books.size();
}
