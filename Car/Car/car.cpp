#include "car.h";

const string ENGINE_ERROR = "Engin Volume must be between 800 - 8000";
const string YEAR_ERROR = "Year must be between 1900 - 2018";
const int YEAR_MAX = 2018;
const int YEAR_MIN = 1900;
const int ENGIN_MAX = 8000;
const int ENGINE_MIN = 1300;

void Car::SetMake(string make)
{
	m_make = make;
}

string Car::GetMake()
{
	return m_make;
}

void Car::SetModel(string model)
{
	m_model = model;
}

string Car::GetModel()
{
	return m_model;
}

void Car::SetYear(int year)
{
	if (year < YEAR_MIN || year > YEAR_MAX)
	{
		cout << YEAR_ERROR << endl;
		exit(EXIT_FAILURE);
	}
	m_year = year;
}

int Car::GetYear()
{
	return m_year;
}

void Car::SetEngineVolume(int vol)
{

	if (vol < ENGINE_MIN || vol > ENGIN_MAX)
	{
		cout << ENGINE_ERROR << endl;
		exit(EXIT_FAILURE);
	}
	m_engineVolume = vol;
}

int Car::GetEngineVolume()
{
	return m_engineVolume;
}

void Car::SetColor(string color)
{
	m_color = color;
}

string Car::GetColor()
{
	return m_color;
}

// print the details of car
void PrintInfoCar(Car c)
{
	cout << "Make: " << c.GetMake() << endl;
	cout << "Model: " << c.GetModel() << endl;
	cout << "Year: " << c.GetYear() << endl;
	cout << "Engin Volume:" << c.GetEngineVolume() << endl;
	cout << "Color: " << c.GetColor() << endl;
	cout << endl;
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

Car ComperByYear(Car c1, Car c2)
{
	return c1.GetYear() < c2.GetYear() ? c2 : c1;
}

Car ComperByEnginVolume(Car c1, Car c2)
{
	return c1.GetEngineVolume() < c2.GetEngineVolume() ? c2 : c1;
}

void main()
{
	Car car = GetCarDitailes();
	PrintInfoCar(car);
	Car car2 = GetCarDitailes();
	PrintInfoCar(ComperByYear(car, car2));
	PrintInfoCar(ComperByEnginVolume(car, car2));
}