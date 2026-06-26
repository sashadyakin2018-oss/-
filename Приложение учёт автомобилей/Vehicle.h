#pragma once
#include <iostream>
#include <string>
#include <iomanip>

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