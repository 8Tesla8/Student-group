#pragma once
#include <iostream>

#include <string.h>
#include <Windows.h>
using namespace std;



class Student
{
private:
	char * _name;
	char * _surname;
	char * _phone;
	int _age;
	double _average;

public:
	Student();
	Student(const char * name, const char * surname, int age, const char * phone, double average);
	~Student();

	void setName(const char * name);
	void setSurname(const char * surname);
	void setPhone(const char * phone);
	void setAge(int &age);
	void setAverage(double &average);

	int getAge()const;
	double getAverage()const;
	char* getName()const;
	char * getSurname()const;
	char * getPhone()const;

	void PrintSt()const;

};