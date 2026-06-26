#include "actions.h"
#include "globals.h"
#include "Vehicle.h"

#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

void regist()
{
	int yearOfManufacture;
	string brand, model;
	double weight;

	cin.ignore();

	cout << "Тип техники:\n";
	cout << "1) Автомобиль\n";
	cout << "2) Корабль\n";
	cout << "3) Самолёт\n";
	cout << "4) Космический корабль\n";

	int choice;
	cin >> choice;

	system("cls");
	cin.ignore();

	SetConsoleCP(1251);

	cout << "Введите марку транспортного средства: ";
	getline(cin, brand);

	cout << "Введите модель транспортного средства: ";
	getline(cin, model);

	cout << "Введите год выпуска транспортного средства: ";
	cin >> yearOfManufacture;

	cout << "Введите вес транспортного средства (в тоннах): ";
	cin >> weight;
	SetConsoleCP(866);

	if (choice == 1)
	{
		list.push_back(
			new Car(
				++ID,
				"Автомобиль",
				brand,
				model,
				yearOfManufacture,
				weight));
	}
	else if (choice == 2)
	{
		list.push_back(
			new Ship(
				++ID,
				"Корабль",
				brand,
				model,
				yearOfManufacture,
				weight));
	}
	else if (choice == 3)
	{
		list.push_back(
			new Plane(
				++ID,
				"Самолёт",
				brand,
				model,
				yearOfManufacture,
				weight));
	}
	else if (choice == 4)
	{
		list.push_back(
			new SpaceShip(
				++ID,
				"Космический корабль",
				brand,
				model,
				yearOfManufacture,
				weight));
	}

}

void changeEntry()
{
	if (list.empty())
	{
		cout << "Список пуст!\n";
		system("pause");

		return;
	}

	int option, entryNum, i = 0;

	cout << "Введите ID записи которую хотите изменить: ";
	cin >> entryNum;

	for (; i < list.size(); i++)
	{
		if (list[i]->getId() == entryNum)
			break;
	}

	if (i == list.size())
	{
		cout << "Такого ID не существует!\n";
		system("pause");

		return;
	}

	cout << "Что вы хотите изменить?\n";

	cout << "1)Тип транспортного средства\n";
	cout << "2)Марку транспортного средства\n";
	cout << "3)Модель транспортного средства\n";
	cout << "4)Год выпуска транспортного средства\n";
	cout << "5)Вес транспортного средства\n";

	cout << "Ввод: ";
	cin >> option;

	if (option == 1)
		list[i]->changeType();
	else if (option == 2)
		list[i]->changeBrand();
	else if (option == 3)
		list[i]->changeModel();
	else if (option == 4)
		list[i]->changeYearOfManufacture();
	else if (option == 5)
		list[i]->changeWeight();
	else
		return;
}

void deleteEntry()
{
	if (list.empty())
	{
		cout << "Список пуст!\n";
		system("pause");

		return;
	}

	int entryNum, i = 0;

	cout << "Введите ID записи которую хотите удалить: ";
	cin >> entryNum;

	for (; i < list.size(); i++)
	{
		if (list[i]->getId() == entryNum)
		{
			delete list[i];
			list.erase(list.begin() + i);

			cout << "Запись удалена!\n";
			system("pause");

			return;
		}
	}

	if (i == list.size())
	{
		cout << "Такого ID не существует!\n";
		system("pause");

		return;
	}

}

void showAllEntries()
{
	if (list.empty())
	{
		cout << "Список пуст!\n";
		system("pause");

		return;
	}

	printTableHeader();

	for (Vehicle* vehicle : list)
		vehicle->show();

	system("pause");

	return;
}

void searchByType(string text)
{
	int i = 0, index = -1;

	for (; i < list.size(); i++)
	{
		if (list[i]->getType() == text)
		{
			index = i;
			list[index]->show();
		}
	}

	if (index == -1)
	{
		cout << "Такого типа/марки/модели не существует!\n";
		system("pause");

		return;
	}
}
void searchByBrand(string text)
{
	int i = 0, index = -1;

	for (; i < list.size(); i++)
	{
		if (list[i]->getBrand() == text)
		{
			index = i;
			list[index]->show();
		}
	}

	if (index == -1)
	{
		cout << "Такого типа/марки/модели не существует!\n";
		system("pause");

		return;
	}
}
void searchByModel(string text)
{
	int i = 0, index = -1;

	for (; i < list.size(); i++)
	{
		if (list[i]->getModel() == text)
		{
			index = i;
			list[index]->show();
		}
	}

	if (index == -1)
	{
		cout << "Такого типа/марки/модели не существует!\n";
		system("pause");

		return;
	}
}
void searchShowResult(int value)
{
	int i = 0, index = -1;

	for (; i < list.size(); i++)
	{
		if (list[i]->getYearOfManufacture() == value)
		{
			index = i;
			list[index]->show();
		}
	}

	if (index == -1)
	{
		cout << "Такого типа/марки/модели не существует!\n";
		system("pause");

		return;
	}
}
void searchShowResult(double value)
{
	int i = 0, index = -1;

	for (; i < list.size(); i++)
	{
		if (list[i]->getWeight() == value)
		{
			index = i;
			list[index]->show();
		}
	}

	if (index == -1)
	{
		cout << "Такого типа/марки/модели не существует!\n";
		system("pause");

		return;
	}
}

void search()
{
	if (list.empty())
	{
		cout << "Список пуст!\n";
		system("pause");

		return;
	}

	int fieldNum, searchInfoValue;
	string searchInfo;
	double searchWeight;

	cout << "Поля для поиска: \n";
	cout << "1)Тип средства \n";
	cout << "2)Марка \n";
	cout << "3)Модель \n";
	cout << "4)Год выпуска \n";
	cout << "5)Вес \n";

	cout << "По какому полю хотите произвести поиск?: ";
	cin >> fieldNum;

	if (fieldNum == 1)
	{
		cin.ignore();

		SetConsoleCP(1251);
		cout << "Введите тип средства для поиска: ";
		getline(cin, searchInfo);
		SetConsoleCP(866);

		printTableHeader();
		searchByType(searchInfo);

		system("pause");
		return;
	}
	else if (fieldNum == 2)
	{
		cin.ignore();

		SetConsoleCP(1251);
		cout << "Введите марку для поиска: ";
		getline(cin, searchInfo);
		SetConsoleCP(866);

		printTableHeader();
		searchByBrand(searchInfo);

		system("pause");
		return;
	}
	else if (fieldNum == 3)
	{
		cin.ignore();

		SetConsoleCP(1251);
		cout << "Введите модель для поиска: ";
		getline(cin, searchInfo);
		SetConsoleCP(866);

		printTableHeader();
		searchByModel(searchInfo);

		system("pause");
		return;
	}
	else if (fieldNum == 4)
	{
		cout << "Введите год выпуска для поиска: ";
		cin >> searchInfoValue;

		printTableHeader();
		searchShowResult(searchInfoValue);

		system("pause");
		return;
	}
	else if (fieldNum == 5)
	{
		cout << "Введите вес для поиска: ";
		cin >> searchWeight;

		printTableHeader();
		searchShowResult(searchWeight);

		system("pause");
		return;
	}
}