#include <iostream>
using namespace std;
#include "Book.h"

#pragma once
class Library
{
	Book* ptr;
	int size = 4;
	int count;
public:
	Library();
	void addBookToLibrary(Book& obj);
	int searchByName(string n);
};

