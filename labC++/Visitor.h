#include <iostream>
using namespace std;

#pragma once
class Visitor
{
	string surname;
	int id;
	int bookOnHandsCount;
public:
	Visitor();
	Visitor(string s, int i);
	string getSurname();
	int getId();
	int getBookOnHandsCount();
	bool canTakeBook();
	void addBook();
	void returnBook();
};

