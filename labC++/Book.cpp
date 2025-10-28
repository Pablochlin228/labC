#include "Book.h"

Book::Book()
{
	isOnHands = false;
}

Book::Book(string name, string a, string g, bool check, Visitor* v)
{
	bookName = name;
	author = a;
	genre = g;
	isOnHands = check;
	visitor = v;
}

string Book::getBookName()
{
	return bookName;
}
