#include "Visitor.h"

Visitor::Visitor()
{
	id = 0;
	bookOnHandsCount = 0;
}

Visitor::Visitor(string s, int i)
{
	surname = s;
	id = i;
	bookOnHandsCount = 0;
}

string Visitor::getSurname()
{
	return surname;
}

int Visitor::getId()
{
	return id;
}

int Visitor::getBookOnHandsCount()
{
	return bookOnHandsCount;
}

bool Visitor::canTakeBook()
{
	return bookOnHandsCount < 3;
}

void Visitor::addBook()
{
	if (canTakeBook())
	{
		bookOnHandsCount++;
	}
}

void Visitor::returnBook()
{
	if (bookOnHandsCount > 0)
	{
		bookOnHandsCount--;
	}
}

