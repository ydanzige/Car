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

	void SetYear(const int year);
	void SetEngineVolume(const int vol);
public:
	Car(const string make, const string model, const int year, const int engineVolume, const string color);
	//copy ctor
	Car(const Car &other);
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
	static Car ComperByYear(const Car & c1 ,const Car &c2);
	/*
	comper two cars by EnginVolume
	params: two cars reference to comper with
	return the bigger car
	*/
	static Car ComperByEnginVolume(const Car & c1, const Car &c2);
};

