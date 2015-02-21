#include "Student.h"

// constructors 
Student::Student() 
{
	const unsigned int size = strlen("Unknown") + 1U;

	_name = new char[size];
	strcpy_s(_name, size, "Unknown");

	_surname = new char[size];
	strcpy_s(_surname, size, "Unknown");

	_phone = new char[size];
	strcpy_s(_phone, size, "Unknown");

	_age = 0;
	_average = 0;
}
Student::Student(const char * name, const char * surname, int age, const char * phone, double average) // constructor 2
{
	const unsigned int Name_size = strlen(name) + 1U;
	_name = new char[Name_size];
	strcpy_s(_name, Name_size, name);

	const unsigned int Surname_size = strlen(surname) + 1U;
	_surname = new char[Surname_size];
	strcpy_s(_surname, Surname_size, surname);

	const unsigned int Phone_size = strlen(phone) + 1U;
	_phone = new char[Phone_size];
	strcpy_s(_phone, Phone_size, phone);

	_age = age;
	_average = average;
}
// Destructor
Student::~Student() 
{
	delete[] _name;
	delete[] _surname;
	delete[] _phone;
}
//inicialicia
void Student::setName(const char * name)
{
	delete[] _name;
	_name = new char[strlen(name) + 1U];
	if (!_name) exit(1);
	strcpy_s(_name, strlen(name) + 1U, name);
}
void Student::setSurname(const char * surname)
{
	delete[] _surname;
	_surname = new char[strlen(surname) + 1U];
	if (!_surname) exit(1);
	strcpy_s(_surname, strlen(surname) + 1U, surname);
}
void Student::setPhone(const char * phone)
{
	delete[] _phone;
	_phone = new char[strlen(phone) + 1U];
	if (!_phone) exit(1);
	strcpy_s(_phone, strlen(phone) + 1U, phone);
}
void Student::setAge(int &age)
{
	_age=age;
}
void Student::setAverage(double &average)
{
	_average=average;
}
//return pointer
char* Student::getName()const
{
	return _name;
}
char * Student::getSurname()const
{
	return _surname;
}
char * Student::getPhone()const
{
	return _phone;
}
// return number
double Student::getAverage()const
{
	return _average;
}
int Student::getAge()const
{
	return _age;
}

void Student::PrintSt()const
{
	cout << "\nSurname: " << _surname << endl;
	cout << "Name: " << _name << endl;
	cout << "Phone: " << _phone << endl;
	cout << "Age: " << _age << endl;
	cout << "Average: " << _average << endl;
}

ostream & operator<<(ostream & os, const Student & obj)
{
	os << "\nSurname: " << obj.getSurname() << endl;
	os << "Name: " << obj.getName() << endl;
	os << "Phone: " << obj.getPhone() << endl;
	os << "Age: " << obj.getAge() << endl;
	os << "Average: " << obj.getAverage() << endl;

	return os;
}

istream & operator>>(istream & is, Student & obj)
{
	char buff[20] = {};
	int Age = 0;
	double Average = 0;

	cout << "\nEnter Surname: ";
	is >> buff;
	obj.setSurname(buff);
	cout << "Enter Name: ";
	is >> buff;
	obj.setName(buff);
	cout << "Enter Phone: ";
	is >> buff;
	obj.setPhone(buff);

	cout << "Enter Age: ";
	is >> Age;
	obj.setAge(Age);

	cout << "Enter Average: ";
	is >> Average;
	obj.setAverage(Average);
	return is;
}