#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Car
{
private:
	const string m_make;
	const string m_model;
	int m_year;
	int m_engineVolume;
	const string m_color;

	void SetYear(int year);
	void SetEngineVolume(int vol);
public:
	Car(string make, string model, int year, int engineVolume, string color);
	const string GetMake()const;
	const string GetModel()const;
	const int GetYear()const;
	const int GetEngineVolume()const;
	const string GetColor()const;

	/*
	comper two cars by year
	params: other car reference to comper with
	return the bigger car
	*/
	const Car ComperByYear(Car &c2)const;
	/*
	comper two cars by EnginVolume
	params: other car reference to comper with
	return the bigger car
	*/
	const Car ComperByEnginVolume(Car &c2)const;

	/*
	print the details of car
	*/
	const void PrintInfoCar()const;
};

