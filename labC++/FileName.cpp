#include <iostream>
#include <string>
#include "Book.h"
#include "Library.h"
#include "Visitor.h"
using namespace std;

int main()
{
	Library library;
	int choice;

	while (true)
	{
		cout << "Enter the operation: " << endl;
		cout << "1)Add book to library" << endl;
		cout << "2)Find book by book name" << endl;
		cout << "3)Find book by book genre" << endl;
		cout << "4)Find book by book author" << endl;
		cout << "5)Show all books" << endl;
		cout << "6)Show a frequent library visitor" << endl;
		cout << "7)Return book to library" << endl;
		cin >> choice;

		try
		{
			switch (choice)
			{
			case 1: {
				string name, genre, author, surname;
				bool isOnHands;
				int id;
				char option;
				cout << "Enter the name of the book: " << endl;
				cin.ignore();
				getline(cin, name);
				cout << "Enter the genre of the book: " << endl;
				getline(cin, genre);
				cout << "Enter the author of the book: " << endl;
				getline(cin, author);

				cout << "Is on hand?(y/n)?" << endl;
				cin >> option;
				if (option == 'y' || option == 'Y')
				{
					isOnHands = true;
				}
				else if (option == 'n' || option == 'N')
				{
					isOnHands = false;
				}

				Visitor* visitor = nullptr;
				if (isOnHands)
				{
					cout << "Enter your surname: " << endl;
					cin.ignore();
					getline(cin, surname);
					cout << "Enter your id: " << endl;
					cin >> id;

					visitor = library.addVisitirToLibrary(surname, id);
						if (!visitor->canTakeBook())
						{
							throw "You can only have 3 books on hands!";
						}
						else
						{
							visitor->addBook();
						}
				}
				Book book(name, author, genre, isOnHands, visitor);
				library.addBookToLibrary(book);
				break;
			}
			case 2: {
				string search;
				cout << "Enter the name of book you want to find:" << endl;
				cin.ignore();
				getline(cin, search);
			}
			case 3:
				throw "Incorrect operation!";
			case 4:
				throw "Incorrect operation!";
			case 5:
				library.showAllBooks();
				break;
			case 6:
				throw "Incorrect operation!";
			case 7:
				throw "Incorrect operation!";
			default:
				throw "Incorrect operation!";
			}
		}
		catch (const char* str)
		{
			cout << "Catch exception " << str << endl;
		}

	}
}