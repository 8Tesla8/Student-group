#pragma once
#include "Group.h"
#include "Student.h"

istream & operator>>(istream & is, Student & obj);
ostream & operator<<(ostream & os, const Student & obj);

Group::Group()
{
	std_count = 0;
	ptr_count = 5;
	pst = new Student *[ptr_count];	
	for (int i = 0; i < ptr_count; i++) 
		pst[i] = nullptr;
}
Group::~Group()
{
	for (int i = 0; i < std_count; i++) delete pst[i];
	delete []pst;
}
void Group::Print()const
{
	if (std_count)
	{
		for (int i = 0; i < std_count; i++)
		{
			cout << *(pst[i]);
			//pst[i]->PrintSt();
		}			
	}
}
int Group::FindStudent(int &choice, const char *buff) const
{
	int number=-1;
	for (int i = 0; i < std_count; i++)
	{
		if (choice == 1 && strcmp(pst[i]->getName(), buff) == 0)
		{
			cout << *(pst[i]);
			//pst[i]->PrintSt();
			number = i;
		}
		else if (choice == 2 && strcmp(pst[i]->getSurname(), buff) == 0)
		{
			cout << *(pst[i]);
			//pst[i]->PrintSt();
			number = i;
		}
		else if (choice == 3 && strcmp(pst[i]->getPhone(), buff) == 0)
		{
			cout << *(pst[i]);
			//pst[i]->PrintSt();
			number = i;
		}
	}
	return number;
}
void Group::Sort(int &choice)
{
	Student * n_stud = nullptr;
	for (int i = 0; i < std_count; i++)
	{
		for (int j = i + 1; j < std_count; j++)
		{
			if (choice == 1 && strcmp(pst[i]->getName(), pst[j]->getName()) > 0)
			{
				n_stud = pst[i];
				pst[i] = pst[j];
				pst[j] = n_stud;
			}
			else if (choice == 2 && strcmp(pst[i]->getSurname(), pst[j]->getSurname()) > 0)
			{
				n_stud = pst[i];
				pst[i] = pst[j];
				pst[j] = n_stud;
			}
			else if (choice == 3 && pst[i]->getAge() > pst[j]->getAge())
			{
				n_stud = pst[i];
				pst[i] = pst[j];
				pst[j] = n_stud;
			}
			else if (choice == 4 && pst[i]->getAverage() > pst[j]->getAverage())
			{
				n_stud = pst[i];
				pst[i] = pst[j];
				pst[j] = n_stud;
			}
		}
	}
}
void Group::AddStudents(int &count)
{
	std_count += count;
	if (std_count >= ptr_count)
	{
		int del_ptr_count = ptr_count;
		Student ** del_ptr = pst;

		// creation new pointer array for students
		if (count >= 5) ptr_count += count;
		else ptr_count += 5;

		pst = new Student *[ptr_count];

		//rewrite perezapis
		for (int i = 0; i < del_ptr_count; i++)
			pst[i] = del_ptr[i];

		for (int i = del_ptr_count; i < ptr_count; i++)
			pst[i] = nullptr;

		delete[]del_ptr; // delete old pointer array

		// add
		for (int i = 0, chet=0 ; i < ptr_count; i++)
		{
			if (chet == count) break;
			if (pst[i] == nullptr)
			{
				pst[i] = new Student;
				chet++;
				cin >> *(pst[i]);
				//EditStudent(i);
			}
		}
	}
	else // add
	{		
		for (int i = 0, chet = 0; i < ptr_count; i++)
		{
			if (chet == count) break;
			if (pst[i] == nullptr)
			{
				pst[i] = new Student;
				chet++;
				cin >> *(pst[i]);
				//EditStudent(i);
			}
		}
	}
}
void Group::EditStudent(int number)
{
	if (std_count)
	{
		char buff[20] = {};
		int Age=0;
		double Average=0;

		cout << "\nEnter Surname: ";
		cin >> buff;
		pst[number]->setSurname(buff);
		cout << "Enter Name: ";
		cin >> buff;
		pst[number]->setName(buff);
		cout << "Enter Phone: ";
		cin >> buff;
		pst[number]->setPhone(buff);

		cout << "Enter Age: ";
		cin >> Age;
		pst[number]->setAge(Age);

		cout << "Enter Average: ";
		cin >> Average;
		pst[number]->setAverage(Average);
	}
}
void Group::DeleteStudent(int number)
{
	if (std_count != 1)
	{
		Student * del_ptr = pst[number];
		delete del_ptr; 

		pst[number] = nullptr;
		// adress sorting
		for (int i = number; i < ptr_count && pst[i+1] != nullptr; i++)
		{
			for (int j = i + 1; j < ptr_count && pst[j] != nullptr; j++)
			{
				del_ptr = pst[i];
				pst[i] = pst[j];
				pst[j] = del_ptr;
			}
		}
		std_count--;
	}
}
void Group::Save()
{
	FILE * f;
	fopen_s(&f, "group", "wb");
	if (f) //zapis v fail
	{
		fwrite(&ptr_count, sizeof(int), 1, f);
		fwrite(&std_count, sizeof(int), 1, f);
		
		fwrite(pst, sizeof(Student *), ptr_count, f); //write pointer array

		int count = 0;
		double average_ = 0;
		for (int i = 0; i < std_count; i++)
		{
			//write all field of object
			count = strlen(pst[i]->getName()) + 1U;
			fwrite(&count, sizeof(int), 1, f);
			fwrite(pst[i]->getName(), sizeof(char*), count, f);

			count = strlen(pst[i]->getSurname()) + 1U;
			fwrite(&count, sizeof(int), 1, f);
			fwrite(pst[i]->getSurname(), sizeof(char*), count, f);

			count = strlen(pst[i]->getPhone()) + 1U;
			fwrite(&count, sizeof(int), 1, f);
			fwrite(pst[i]->getPhone(), sizeof(char*), count, f);
			
			count = pst[i]->getAge();
			fwrite(&count, sizeof(int), 1, f);

			average_ = pst[i]->getAverage();
			fwrite(&average_, sizeof(double), 1, f);		
		}
		fclose(f);
	}
}
void Group::Load()
{
	FILE * f;

	fopen_s(&f, "group", "rb");
	if (f) //chetenie s faila
	{
		int n_std_count = 0, n_ptr_count = 0;

		fread(&n_ptr_count, sizeof(int), 1, f);
		fread(&n_std_count, sizeof(int), 1, f);

		Student **n_pst = new Student*[n_ptr_count];

		fread(n_pst, sizeof(Student*), n_ptr_count, f);
		
		char buff[20] = {};
		int count = 0;
		double average_ = 0;
		for (int i = 0; i < n_std_count; i++)
		{
			n_pst[i] = new Student;

			fread(&count, sizeof(int), 1, f);
			fread(buff, sizeof(char*), count, f); 
			n_pst[i]->setName(buff);

			fread(&count, sizeof(int), 1, f);
			fread(buff, sizeof(char*), count, f);
			n_pst[i]->setSurname(buff);

			fread(&count, sizeof(int), 1, f);
			fread(buff, sizeof(char*), count, f);
			n_pst[i]->setPhone(buff);

			fread(&count, sizeof(int), 1, f);
			n_pst[i]->setAge(count);
				
			fread(&average_, sizeof(double), 1, f);
			n_pst[i]->setAverage(average_);

			n_pst[i]->PrintSt();
		}
		fclose(f);
	}
}