#include "car.h"

const string ENGINE_ERROR = "Engin Volume must be between 800 - 8000";
const string YEAR_ERROR = "Year must be between 1900 - 2018";
const int YEAR_MAX = 2018;
const int YEAR_MIN = 1900;
const int ENGIN_MAX = 8000;
const int ENGINE_MIN = 1300;
const int FIRST_PLATE = 1000001;


Car::Car(const string make, const string model, const int year, const int engineVolume, const string color) :m_plateNumber(CreatePlateNumber()), m_make(make), m_model(model), m_color(color)
{
	SetYear(year);
	SetEngineVolume(engineVolume);
}

Car::Car(const Car &otherCar):m_plateNumber(otherCar.GetPlate()), m_make(otherCar.GetMake()),m_model(otherCar.GetModel()),m_year(otherCar.GetYear()),m_engineVolume(otherCar.GetEngineVolume()),m_color(otherCar.GetColor())
{
}

string Car::GetMake()const
{
	return m_make;
}

string Car::GetModel()const
{
	return m_model;
}

int Car::GetPlate() const
{
	return m_plateNumber;
}

const size_t Car::CreatePlateNumber()
{
	static int plateSeed = FIRST_PLATE;
	return plateSeed++;
}
void Car::SetYear(const int year)
{
	if (year < YEAR_MIN || year > YEAR_MAX)
	{
		cout << YEAR_ERROR << endl;
		exit(EXIT_FAILURE);
	}
	m_year = year;
}

const int Car::GetYear()const
{
	return m_year;
}

void Car::SetEngineVolume(const int vol)
{

	if (vol < ENGINE_MIN || vol > ENGIN_MAX)
	{
		cout << ENGINE_ERROR << endl;
		exit(EXIT_FAILURE);
	}
	m_engineVolume = vol;
}



const int Car::GetEngineVolume()const
{
	return m_engineVolume;
}

const string Car::GetColor()const
{
	return m_color;
}

Car Car::ComperByYear(const Car &c2)const
{
	return this->GetYear() < c2.GetYear() ? c2 : *this;
}

Car Car::ComperByEnginVolume(const Car &c2)const
{
	return this->GetEngineVolume() < c2.GetEngineVolume() ? c2 : *this;
}

// print the details of car
const void Car::PrintInfoCar()const
{
	cout << "Make: " << this->GetMake() << endl;
	cout << "Model: " << this->GetModel() << endl;
	cout << "Year: " << this->GetYear() << endl;
	cout << "Engin Volume:" << this->GetEngineVolume() << endl;
	cout << "Color: " << this->GetColor() << endl;
	cout << endl;
}

Car Car::ComperByYear(const Car & c1, const Car & c2)
{
	return c1.GetYear() < c2.GetYear() ? c2 : c1;
}

Car Car::ComperByEnginVolume(const Car & c1, const Car & c2)
{
	return c1.GetEngineVolume() < c2.GetEngineVolume() ? c2 : c1;
}

/*
get details of car of user and init car obj
return car
*/
Car GetCarDitailes()
{
	string make = "";
	string model = "";
	int year = 1900;
	int enginVolume = 1300;
	string color = "";

	cout << "Please Enter The Ditails of car:" << endl;
	cout << "Make: ";
	cin >> make;
	cout << "Model: ";
	cin >> model;
	cout << "Year (between 1900 - 2018): ";
	cin >> year;
	cout << "Engin Volume (between 800 - 8000): ";
	cin >> enginVolume;
	cout << "Color: ";
	cin >> color;
	cout << endl;

	Car car(make, model, year, enginVolume, color);
	return car;
}



void main()
{
	Car car = GetCarDitailes();
	car.PrintInfoCar();
	Car car2 = GetCarDitailes();
	car.ComperByYear(car2).PrintInfoCar();
	car.ComperByEnginVolume(car2).PrintInfoCar();
}