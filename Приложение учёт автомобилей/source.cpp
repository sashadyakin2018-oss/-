#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Vehicle
{
private:
	int id, yearOfManufacture;
	string type, brand, model;
	double weight;

public:

	Vehicle(int id, string type, string brand, string model, int yearOfManufacture, double weight) {

		this->id = id;
		this->type = type;
		this->brand = brand;
		this->model = model;
		this->yearOfManufacture = yearOfManufacture;
		this->weight = weight;

	}

	void changeType()
	{
		string text;

		cout << "Введите тип: ";
		getline(cin, text);

		type = text;
	}
	void changeBrand()
	{
		string text;

		cout << "Введите марку: ";
		getline(cin, text);

		brand = text;
	}
	void changeModel()
	{
		string text;

		cout << "Введите модель: ";
		getline(cin, text);

		model = text;
	}
	void changeYearOfManufacture()
	{
		int age;

		cout << "Введите год выпуска: ";
		cin >> age;

		yearOfManufacture = age;
	}
	void changeWeight()
	{
		double value;

		cout << "Введите вес: ";
		cin >> value;

		weight = value;
	}
};

vector<Vehicle> list;
int ID = 0;

void regist()
{
	int yearOfManufacture;
	string type, brand, model;
	double weight;

	cout << "Введите тип транспортного средства: ";
	getline(cin, type);

	cout << "Введите марку транспортного средства: ";
	getline(cin, brand);

	cout << "Введите модель транспортного средства: ";
	getline(cin, model);

	cout << "Введите год выпуска транспортного средства: ";
	cin >> yearOfManufacture;

	cout << "Введите вес транспортного средства: ";
	cin >> weight;

	list.push_back(Vehicle(++ID, type, brand, model, yearOfManufacture, weight));

}

void changeEntry()
{
	int option;

	cout << "Что вы хотите изменить?\n";

	cout << "1)Тип транспортного средства\n";
	cout << "2)Марку транспортного средства\n";
	cout << "3)Модель транспортного средства\n";
	cout << "4)Год выпуска транспортного средства\n";
	cout << "5)Вес транспортного средства\n";

	cout << "Ввод: ";
	cin >> option;

	if (option == 1)
		list[0].changeType();
	else if (option == 2)
		list[0].changeBrand();
	else if (option == 3)
		list[0].changeModel();
	else if (option == 4)
		list[0].changeYearOfManufacture();
	else if (option == 5)
		list[0].changeWeight();
	else 
		return;
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

}

int main() {
	setlocale(LC_ALL, "rus");
	int action;

	while (true)
	{
		system("cls");
		cout << "Приложение для регистрации и учёта  транспортных средств\n";
		
		cout << "1)Зарегистрировать новое средство\n";
		cout << "2)Изменить существующую запись\n";
		cout << "3)Удалить существующую запись\n";
		cout << "4)Посмотреть список зарегистрированных средств\n";

		cout << "Что вы зотите сделать? ";

		cin >> action;
		if (action > 0)
			logicOfActions(action);
		else
			break;

	}



	return 0;
}