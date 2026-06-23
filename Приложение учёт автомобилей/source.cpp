#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

class Vehicle
{
protected:
	int id, yearOfManufacture;
	string type, brand, model;
	double weight;

public:
	Vehicle(
		int id,
		string type,
		string brand,
		string model,
		int yearOfManufacture,
		double weight)
	{
		this->id = id;
		this->type = type;
		this->brand = brand;
		this->model = model;
		this->yearOfManufacture = yearOfManufacture;
		this->weight = weight;
	}

	virtual ~Vehicle() {}

	virtual string getVehicleClass()
	{
		return "Транспорт";
	}

	virtual void show()
	{
		cout << left
			<< setw(5) << id
			<< setw(20) << getVehicleClass()
			<< setw(15) << brand
			<< setw(15) << model
			<< setw(10) << yearOfManufacture
			<< setw(10) << weight
			<< endl;
	}

	int getId()
	{
		return id;
	}
	string getType() {
		return type;
	}
	string getBrand() {
		return brand;
	}
	string getModel() {
		return model;
	}
	int getYearOfManufacture() {
		return yearOfManufacture;
	}
	double getWeight() {
		return weight;
	}

	void changeType()
	{
		string text;

		cin.ignore();

		cout << "Введите тип: ";
		getline(cin, text);

		type = text;
	}

	void changeBrand()
	{
		string text;

		cin.ignore();

		cout << "Введите марку: ";
		getline(cin, text);

		brand = text;
	}

	void changeModel()
	{
		string text;

		cin.ignore();

		cout << "Введите модель: ";
		getline(cin, text);

		model = text;
	}

	void changeYearOfManufacture()
	{
		int age;

		cin.ignore();

		cout << "Введите год выпуска: ";
		cin >> age;

		yearOfManufacture = age;
	}

	void changeWeight()
	{
		double value;

		cin.ignore();

		cout << "Введите вес: ";
		cin >> value;

		weight = value;
	}

};

class Car : public Vehicle
{
public:
	Car(
		int id,
		string type,
		string brand,
		string model,
		int yearOfManufacture,
		double weight)
		: Vehicle(
			id,
			type,
			brand,
			model,
			yearOfManufacture,
			weight)
	{
	}

	string getVehicleClass() override
	{
		return "Автомобиль";
	}
};

class Ship : public Vehicle
{
public:
	Ship(
		int id,
		string type,
		string brand,
		string model,
		int yearOfManufacture,
		double weight)
		: Vehicle(
			id,
			type,
			brand,
			model,
			yearOfManufacture,
			weight)
	{
	}

	string getVehicleClass() override
	{
		return "Корабль";
	}
};

class Plane : public Vehicle
{
public:
	Plane(
		int id,
		string type,
		string brand,
		string model,
		int yearOfManufacture,
		double weight)
		: Vehicle(
			id,
			type,
			brand,
			model,
			yearOfManufacture,
			weight)
	{
	}

	string getVehicleClass() override
	{
		return "Самолёт";
	}
};

class SpaceShip : public Vehicle
{
public:
	SpaceShip(
		int id,
		string type,
		string brand,
		string model,
		int yearOfManufacture,
		double weight)
		: Vehicle(
			id,
			type,
			brand,
			model,
			yearOfManufacture,
			weight)
	{
	}

	string getVehicleClass() override
	{
		return "Космический корабль";
	}
};

vector<Vehicle*> list;
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

void logicOfActions(int& action) 
{
	system("cls");

	if (action == 1)
	{
		regist();
	}
	else if (action == 2)
	{
		changeEntry();
	}
	else if (action == 3)
	{
		deleteEntry();
	}
	else if (action == 4)
	{
		showAllEntries();
	}
	else if (action == 5)
	{
		search();
	}

}

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