#include <vector>
#include "book.h"
#include "stdafx.h"

using namespace std;

class Library
{
	vector<Book> books;

public:
	void AddBook(const Book &book);

	void Display() const;

	Book& operator[](size_t index);

	size_t GetSize() const;

	void save();

	void load();
};
#pragma once


