#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Car
{
private:
	string m_make;
	string m_model;
	int m_year;
	int m_engineVolume;
	string m_color;
public:
		
	Car(string make, string model, int year, int engineVolume, string color) :m_make(make), m_model(model), m_color(color)
	{
		SetYear(year);
		SetEngineVolume(engineVolume);
	}

	void SetMake(string make);
	string GetMake();
	void SetModel(string model);
	string GetModel();
	void SetYear(int year);
	int GetYear();
	void SetEngineVolume(int vol);
	int GetEngineVolume();
	void SetColor(string color);
	string GetColor();

};
