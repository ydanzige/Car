#include "car.h"
namespace Car
{

	const std::string ENGINE_ERROR = "Engin Volume must be between 800 - 8000";
	const std::string YEAR_ERROR = "Year must be between 1900 - 2018";
	const int YEAR_MAX = 2018;
	const int YEAR_MIN = 1900;
	const int ENGIN_MAX = 8000;
	const int ENGINE_MIN = 1300;
	const int FIRST_PLATE = 1000001;


	Car::Car(const std::string make, const std::string model, const int year, const int engineVolume, const std::string color) :m_plateNumber(CreatePlateNumber()), m_make(make), m_model(model), m_color(color)
	{
		SetYear(year);
		SetEngineVolume(engineVolume);
	}

	Car::Car(const Car &otherCar) :m_plateNumber(otherCar.GetPlate()), m_make(otherCar.GetMake()), m_model(otherCar.GetModel()), m_year(otherCar.GetYear()), m_engineVolume(otherCar.GetEngineVolume()), m_color(otherCar.GetColor())
	{
	}

	std::string Car::GetMake()const
	{
		return m_make;
	}

	std::string Car::GetModel()const
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
			std::cout << YEAR_ERROR << std::endl;
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
			std::cout << ENGINE_ERROR << std::endl;
			exit(EXIT_FAILURE);
		}
		m_engineVolume = vol;
	}



	const int Car::GetEngineVolume()const
	{
		return m_engineVolume;
	}

	const std::string Car::GetColor()const
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
		std::cout << "Make: " << this->GetMake() << std::endl;
		std::cout << "Model: " << this->GetModel() << std::endl;
		std::cout << "Year: " << this->GetYear() << std::endl;
		std::cout << "Engin Volume:" << this->GetEngineVolume() << std::endl;
		std::cout << "Color: " << this->GetColor() << std::endl;
		std::cout << std::endl;
	}

	Car Car::ComperByYear(const Car & c1, const Car & c2)
	{
		return c1.GetYear() < c2.GetYear() ? c2 : c1;
	}

	Car Car::ComperByEnginVolume(const Car & c1, const Car & c2)
	{
		return c1.GetEngineVolume() < c2.GetEngineVolume() ? c2 : c1;
	}
}
	/*
	get details of car of user and init car obj
	return car
	*/
	Car::Car GetCarDitailes()
	{
		std::string make = "";
		std::string model = "";
		int year = 1900;
		int enginVolume = 1300;
		std::string color = "";

		std::cout << "Please Enter The Ditails of car:" << std::endl;
		std::cout << "Make: ";
		std::cin >> make;
		std::cout << "Model: ";
		std::cin >> model;
		std::cout << "Year (between 1900 - 2018): ";
		std::cin >> year;
		std::cout << "Engin Volume (between 800 - 8000): ";
		std::cin >> enginVolume;
		std::cout << "Color: ";
		std::cin >> color;
		std::cout << std::endl;

		Car::Car car(make, model, year, enginVolume, color);
		return car;
	}



	void main()
	{
		Car::Car car = GetCarDitailes();
		car.PrintInfoCar();
		Car::Car car2 = GetCarDitailes();
		car.ComperByYear(car2).PrintInfoCar();
		car.ComperByEnginVolume(car2).PrintInfoCar();
	}
