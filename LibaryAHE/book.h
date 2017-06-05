#pragma once
#include <string>
#include <iostream>
#include "stdafx.h"

using namespace std;

class Book
{
	string author;
	string title;
	unsigned int year;
	unsigned int edition;
	string publisher;
	unsigned int pages;
	string description;

public:
	Book(string _author, string _title, unsigned int _year, unsigned int _edition, string _publisher, unsigned int _pages, string _description);
	Book(const Book &book);
	string toString();

	void SetAuthor(string _author);
	string GetAuthor() const;

	void SetTitle(string _title);
	string GetTitle() const;

	void SetYear(unsigned int _year);
	unsigned int GetYear() const;

	void SetEdition(unsigned int _edition);
	unsigned int GetEdition() const;

	void SetPublisher(string _publisher);
	string GetPublisher() const;

	void SetPages(unsigned int _pages);
	unsigned int GetPages() const;

	void SetDescription(string _description);
	string GetDescription() const;

	void Display() const;
	void DisplayShort() const;
};
