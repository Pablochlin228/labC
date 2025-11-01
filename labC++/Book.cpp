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

string Book::getGenre()
{
	return genre;
}

string Book::getAuthor()
{
	return author;
}

bool Book::getIsOnHands()
{
	return isOnHands;
}

Visitor* Book::getVisitor()
{
	return visitor;
}

void Book::SetIsOnHands(bool status)
{
	isOnHands = status;
}

void Book::SetVisitor(Visitor* v)
{
	visitor = v;
}
