#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>

namespace Car {
	
	class Car
	{
	private:
		const size_t m_plateNumber;
		const std::string m_make;
		const std::string m_model;
		int m_year;
		int m_engineVolume;
		const std::string m_color;
		void SetYear(const int year);
		void SetEngineVolume(const int vol);
		/*
		create get and increment the plate number
		*/
		static const size_t CreatePlateNumber();
	public:

		Car(const std::string make, const std::string model, const int year, const int engineVolume, const std::string color);
		//copy ctor
		Car(const Car &other);
		std::string GetMake()const;
		std::string GetModel()const;
		int GetPlate()const;
		const int GetYear()const;
		const int GetEngineVolume()const;
		const std::string GetColor()const;

		/*
		comper two cars by year
		params: other car reference to comper with
		return the bigger car
		*/
		Car ComperByYear(const Car &c2)const;
		/*
		comper two cars by EnginVolume
		params: other car reference to comper with
		return the bigger car
		*/
		Car ComperByEnginVolume(const Car &c2)const;

		/*
		print the details of car
		*/
		const void PrintInfoCar()const;
		/*
		comper two cars by year
		params: two cars reference to comper
		return the bigger car
		*/
		static Car ComperByYear(const Car & c1, const Car &c2);
		/*
		comper two cars by EnginVolume
		params: two cars reference to comper with
		return the bigger car
		*/
		static Car ComperByEnginVolume(const Car & c1, const Car &c2);
	};

}