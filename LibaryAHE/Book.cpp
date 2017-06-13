#include "book.h"
#include "stdafx.h"

Book::Book(string _author, string _title, unsigned int _year, unsigned int _edition, string _publisher, unsigned int _pages, string _description)
{
	author = _author;
	title = _title;
	year = _year;
	edition = _edition;
	publisher = _publisher;
	pages = _pages;
	description = _description;
}

Book::Book(const Book &book)
{
	author = book.author;
	title = book.title;
	year = book.year;
	edition = book.edition;
	publisher = book.publisher;
	pages = book.pages;
	description = book.description;
}

//string Book::toString()
//{
//	return string(author+" "+title+"\n");
//}

void Book::SetAuthor(string _author)
{
	author = _author;
}

string Book::GetAuthor() const
{
	return author;
}

void Book::SetTitle(string _title)
{
	title = _title;
}

string Book::GetTitle() const
{
	return title;
}

void Book::SetYear(unsigned int _year)
{
	year = _year;
}

unsigned int Book::GetYear() const
{
	return year;
}

void Book::SetEdition(unsigned int _edition)
{
	edition = _edition;
}

unsigned int Book::GetEdition() const
{
	return edition;
}

void Book::SetPublisher(string _publisher)
{
	publisher = _publisher;
}

string Book::GetPublisher() const
{
	return publisher;
}

void Book::SetPages(unsigned int _pages)
{
	pages = _pages;
}

unsigned int Book::GetPages() const
{
	return pages;
}

void Book::SetDescription(string _description)
{
	description = _description;
}

string Book::GetDescription() const
{
	return description;
}

void Book::Display() const
{
	cout << "Author:      " << author << endl;
	cout << "Title:       " << title << endl;
	cout << "Year:        " << year << endl;
	cout << "Edition:     " << edition << endl;
	cout << "Publisher:   " << publisher << endl;
	cout << "Pages:       " << pages << endl;
	cout << "Description: " << description << endl;
}

void Book::DisplayShort() const
{
	cout << author << ", " << "\"" << title << "\", " << year << endl;
}
