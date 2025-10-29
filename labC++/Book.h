#include <iostream>
using namespace std;
#include "Visitor.h"

#pragma once
class Book
{
	string bookName;
	string author;
	string genre;
	bool isOnHands;
	Visitor* visitor;
public:
	Book();
	Book(string name, string a, string g, bool check, Visitor* v);
	string getBookName();
	string getGenre();
	string getAuthor();
	bool getIsOnHands();
	Visitor* getVisitor();
};
