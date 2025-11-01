#include <iostream>
using namespace std;
#include "Book.h"

#pragma once
class Library
{
	Book* ptr;
	Visitor* visitors;
	int size = 4;
	int visitirsSize = 4;
	int visitorsCount;
	int count;
public:
	Library();
	Visitor* addVisitirToLibrary(string s, int id);
	void addBookToLibrary(Book& obj);
	int searchByName(string n);
	int serchByGenre(string n);
	int serchByAuthor(string n);
	void showAllBooks();
	void showFrequentVisitor();
	void returnBookToLibrary(int index);
};

