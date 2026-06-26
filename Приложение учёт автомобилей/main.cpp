#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "actions.h"
#include "logicOfActions.h"
#include "Vehicle.h"
#include "globals.h"

using namespace std;

void saveToFile()
{
	ofstream file("vehicles.txt");

	if (!file)
	{
		cout << "Ошибка открытия файла!\n";
		return;
	}

	for (Vehicle* vehicle : list)
	{
		file << vehicle->getId() << ";"
			<< vehicle->getType() << ";"
			<< vehicle->getBrand() << ";"
			<< vehicle->getModel() << ";"
			<< vehicle->getYearOfManufacture() << ";"
			<< vehicle->getWeight()<< ";" << endl;
	}

	file.close();

	cout << "Данные сохранены!\n";
}

void loadFromFile()
{
	ifstream file("vehicles.txt");

	if (!file)
	{
		cout << "Файл не найден!\n";
		return;
	}

	if (file.peek() == EOF)
	{
		cout << "Файл пуст!\n";
		return;
	}

	list.clear();

	string line;

	while (getline(file, line))
	{
		string type, brand, model, temp;
		int id, year;
		double weight;

		stringstream ss(line);

		getline(ss, temp, ';');
		id = stoi(temp);

		getline(ss, type, ';');
		getline(ss, brand, ';');
		getline(ss, model, ';');

		getline(ss, temp, ';');
		year = stoi(temp);

		getline(ss, temp, ';');
		replace(temp.begin(), temp.end(), '.', ',');
		weight = stod(temp);

		if (type == "Автомобиль")
		{
			list.push_back(
				new Car(
					id,
					type,
					brand,
					model,
					year,
					weight
				)
			);
		}
		else if (type == "Корабль")
		{
			list.push_back(
				new Ship(
					id,
					type,
					brand,
					model,
					year,
					weight
				)
			);
		}
		else if (type == "Самолёт")
		{
			list.push_back(
				new Plane(
					id,
					type,
					brand,
					model,
					year,
					weight
				)
			);
		}
		else if (type == "Космический корабль")
		{
			list.push_back(
				new SpaceShip(
					id,
					type,
					brand,
					model,
					year,
					weight
				)
			);
		}
		else
		{
			cout << "Неизвестный тип техники: "
				<< type << endl;
			system("pause");
		}

		if (id > ID)
			ID = id;
	}

	file.close();

	cout << "Данные загружены!\n";
	system("pause");
}

int main() {
	setlocale(LC_ALL, "rus");
	int action;

	loadFromFile();
	
	bool workFlag = true;

	while (workFlag)
	{
		system("cls");
		cout << "Приложение для регистрации и учёта  транспортных средств\n";
		
		cout << "\n1)Зарегистрировать новое средство\n";
		cout << "2)Изменить существующую запись\n";
		cout << "3)Удалить существующую запись\n";
		cout << "4)Посмотреть список зарегистрированных средств\n";
		cout << "5)Поиск по выбранному полю\n";
		cout << "6)Выйти из программы\n";

		cout << "\nЧто вы хотите сделать? ";

		cin >> action;
		if (action > 0 && action != 6)
			logicOfActions(action);
		else if (action == 6)
			workFlag = false;

	}

	saveToFile();

	cout << "Завершение работы, до свидания!\n";
	system("pause");

	return 0;
}