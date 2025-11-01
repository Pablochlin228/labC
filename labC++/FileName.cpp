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
		cout << "8)Take book to library" << endl;
		cout << "9)Exit" << endl;
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
				else
				{
					throw "Incorrect option!";
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
				if (library.searchByName(search) == -1)
				{
					cout << "There arent any book with this name!" << endl;
				}
				else
				{
					cout << "Your book number is: " << library.searchByName(search) + 1 << endl;
				}
				break;
			}
			case 3: {
				string search2;
				cout << "Enter the genre of book you want to find:" << endl;
				cin.ignore();
				getline(cin, search2);
				if (library.serchByGenre(search2) == -1)
				{
					cout << "There arent any book with this genre!" << endl;
				}
				else
				{
					cout << "Your book number is: " << library.serchByGenre(search2) + 1 << endl;
				}
				break;
			}
			case 4: {
				string search3;
				cout << "Enter the author of book you want to find:" << endl;
				cin.ignore();
				getline(cin, search3);
				if (library.serchByAuthor(search3) == -1)
				{
					cout << "There arent any book with this author!" << endl;
				}
				else
				{
					cout << "Your book number is: " << library.serchByAuthor(search3) + 1 << endl;
				}
				break;
			}
			case 5:
				library.showAllBooks();
				break;
			case 6: {
				Visitor* visitor = library.getFrequentVisitor();
				if (visitor == nullptr)
				{
					throw "There arent any visitors!";
				}
				else
				{
					cout << "Most frequent visitor: " << endl;
					cout << "Surname: " << visitor->getSurname() << endl;
					cout << "Id: " << visitor->getId() << endl;
					cout << "Books on hand: " << visitor->getBookOnHandsCount() << endl;
				}
				break;
			}
			case 7: {
				string bookname;
				cout << "Enter the name of the book you want to return: " << endl;
				cin.ignore();
				getline(cin, bookname);
				int index = library.searchByName(bookname);
				if (index == -1)
				{
					throw "There arent any book with this name!";
				}
				else
				{
					library.returnBookToLibrary(index);
					cout << "You return the book!" << endl;
				}
				break;
			}
			case 8: {
				string bookname2;
				cout << "Enter the name of the book you want to take: " << endl;
				cin.ignore();
				getline(cin, bookname2);
				int index2 = library.searchByName(bookname2);
				if (index2 == -1)
				{
					throw "There arent any book with this name!";
				}
				else
				{
					Visitor* visitor = nullptr;
					string surname2;
					int id2;
					cout << "Enter your surname: " << endl;
					cin.ignore();
					getline(cin, surname2);
					cout << "Enter your id: " << endl;
					cin >> id2;
					visitor = library.addVisitirToLibrary(surname2, id2);
					library.takeBookFromLibrary(index2,visitor);
					cout << "You take the book!" << endl;
				}
				break;
			}
			case 9:
				cout << "Programme is done!" << endl;
				return false;
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