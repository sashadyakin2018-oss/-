#include "globals.h"
#include <iostream>

std::vector<Vehicle*> list;
int ID = 0;

void printTableHeader()
{
	cout << left
		<< setw(5) << "ID"
		<< setw(25) << "Тип"
		<< setw(15) << "Марка"
		<< setw(15) << "Модель"
		<< setw(10) << "Год"
		<< setw(10) << "Вес, т"
		<< endl;

	cout << string(80, '-') << endl;
}