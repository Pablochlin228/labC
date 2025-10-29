#include "Library.h"

Library::Library()
{
	ptr = nullptr;
	visitors = nullptr;
	count = 0;
	visitorsCount = 0;
}

Visitor* Library::addVisitirToLibrary(string s, int id)
{
	for (int i = 0; i < visitorsCount; i++)
	{
		if (visitors[i].getSurname() == s && visitors[i].getId() == id) 
		{
			return &visitors[i];
		}
	}

	if (visitors == nullptr)
	{
		visitors = new Visitor[visitirsSize];
		visitors[0] = Visitor(s, id);
		visitorsCount++;
	}
	else if (visitorsCount >= visitirsSize)
	{
		int newSize = visitirsSize * 2;
		Visitor* visitorsUpdate = new Visitor[newSize];
		for (int i = 0; i < visitorsCount; i++)
		{
			visitorsUpdate[i] = visitors[i];
		}
		delete[] visitors;
		visitors = visitorsUpdate;
		visitirsSize = newSize;
		visitors[visitorsCount] = Visitor(s, id);
		visitorsCount++;
	}
	else
	{
		visitors[visitorsCount] = Visitor(s, id);
		visitorsCount++;
	}
	return &visitors[visitorsCount - 1];
}

void Library::addBookToLibrary(Book& obj)
{
	if (ptr == nullptr)
	{
		ptr = new Book[size];
		ptr[0] = obj;
		count++;
	}
	else if (count >= size )
	{
		int newSize = size * 2;
		Book * prtUpdate = new Book[newSize];
		for (int i = 0; i < count; i++)
		{
			prtUpdate[i] = ptr[i];
		}
		delete[] ptr;
		ptr = prtUpdate;
		size = newSize;
		ptr[count] = obj;
		count++;
	}
	else
	{
		ptr[count] = obj;
		count++;
	}
}

int Library::searchByName(string n)
{
	for (int i = 0; i < count; i++)
	{
		if (ptr[i].getBookName() == n)
		{
			return i;
		}
	}
	return -1;
}

int Library::serchByGenre(string n)
{
	for (int i = 0; i < count; i++)
	{
		if (ptr[i].getGenre() == n)
		{
			return i;
		}
	}
	return -1;
}

int Library::serchByAuthor(string n)
{
	for (int i = 0; i < count; i++)
	{
		if (ptr[i].getAuthor() == n)
		{
			return i;
		}
	}
	return -1;
}

void Library::showAllBooks()
{
	cout << "-----Books-----" << endl;
	for (int i = 0; i < count; i++)
	{
		cout << "Book name: " << ptr[i].getBookName() << endl;
		cout << "Book author: " << ptr[i].getAuthor() << endl;
		cout << "Book genre: " << ptr[i].getGenre() << endl;
		if (ptr[i].getIsOnHands())
		{
			cout << "Status: On hands" << endl;

			if (ptr[i].getVisitor() != nullptr)
			{
				cout << "Visitor surname: " << ptr[i].getVisitor()->getSurname() << endl;
				cout << "Visitor id: " << ptr[i].getVisitor()->getId() << endl;
			}
			else
			{
				cout << "Visitor: unknown" << endl;
			}
		}
		else
		{
			cout << "Status: Available" << endl;
		}
		cout << endl;
	}
	cout << "---------------" << endl;
}

