#include "Library.h"

Library::Library()
{
	ptr = nullptr;
	count = 0;
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
