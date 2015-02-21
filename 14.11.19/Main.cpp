#include "Student.h"
#include "Group.h"

void inscription_find(int & choice)
{
	do{
		system("cls");
		cout
			<< "Select search criteria: \n"
			<< "1 - Name\n"
			<< "2 - Surname\n"
			<< "3 - Phone\n"
			<< "5 - Cansel\n"
			<< "Enter number: ";
		cin >> choice;

		if (choice == 1) cout << "\nEnter the Name you wanna find: ";
		else if (choice == 2) cout << "\nEnter the Surname you wanna find: ";
		else if (choice == 3) cout << "\nEnter the Phone you wanna find: ";
		else
		{
			cout << "\nYou enter invalid number, try againe.";
			Sleep(2000);
		}
	} while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5);
}

//ostream & operator<<(ostream & os, const Student & obj)
//{
//	os << "\nSurname: " << obj.getSurname() << endl;
//	os << "Name: " << obj.getName() << endl;
//	os << "Phone: " << obj.getPhone() << endl;
//	os << "Age: " << obj.getAge() << endl;
//	os << "Average: " << obj.getAverage() << endl;
//
//	return os;
//}
//
//istream & operator>>(istream & is, Student & obj)
//{
//	char buff[20] = {};
//	int Age=0;
//	double Average=0;
//
//	cout << "\nEnter Surname: ";
//	is >> buff;
//	obj.setSurname(buff);
//	cout << "Enter Name: ";
//	is >> buff;
//	obj.setName(buff);
//	cout << "Enter Phone: ";
//	is >> buff;
//	obj.setPhone(buff);
//
//	cout << "Enter Age: ";
//	is >> Age;
//	obj.setAge(Age);
//
//	cout << "Enter Average: ";
//	is >> Average;
//	obj.setAverage(Average);
//	return is;
//}

int main()
{
	Group group;

	int choice = 0;
	do {
		cout << '\n'
			<< "1 - Creation group list\n"
			<< "2 - Print group list\n"
			<< "3 - Edit group list\n"
			<< "4 - Poisk\n"
			<< "5 - Sorting\n"
			<< "6 - Add new student\n"
			<< "7 - Delete Student\n"
			<< "8 - Save group list\n" 
			<< "9 - Load group list\n" 
			<< "0 - Exit\n"
			<< "Enter number: ";
		cin >> choice;
		if (choice == 1) // Creation
		{
			system("cls");
			cout << "Enter count of students: ";
			int count = 0;
			cin >> count;
			group.AddStudents(count); // Creation and initialization	
		}
		else if (choice == 2) //Print
		{
			system("cls");
			group.Print();
		}
		else if (choice == 3) // Edit
		{
			inscription_find(choice);
			if (choice == 4) continue;

			char buff[20] = {};
			cin >> buff;

			int find_number = 0; // number is index of pointer array 
			find_number = group.FindStudent(choice, buff);

			if (find_number < 0)
			{
				cout << "\nNo results\n";
				Sleep(2000);
			}
			else if (find_number >= 0)
			{
				cout << "\nEnter new data: ";
				//group.EditStudent(find_number);
			}
			system("cls");
		}
		else if (choice == 4) // serch
		{
			inscription_find(choice);
			if (choice == 4) continue;

			char buff[20] = {};
			cin >> buff;

			int find_number = 0; // number is index of pointer array 
			find_number = group.FindStudent(choice, buff);
			if (find_number < 0)
			{
				cout << "\nNo results\n";
				Sleep(2000);
			}
		}
		else if (choice == 5) // sorting 
		{
			do{
				system("cls");
				cout << "Select sorting criteria:\n"
					<< "1 - Name\n"
					<< "2 - Surname\n"
					<< "3 - Age\n"
					<< "4 - Avarage\n"
					<< "5 - Cansel\n"
					<< "Enter number: ";
				cin >> choice;

				if (choice < 1 || choice > 4)
				{
					cout << "\nYou enter invalid number, try againe.";
					Sleep(2000);
				}
			} while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5);
			if (choice == 5) continue;

			group.Sort(choice);
			system("cls");
		}
		else if (choice == 6) // Add new student
		{
			system("cls");
			cout << "\nEnter the count of new students: ";
			int count = 0;
			cin >> count;
			group.AddStudents(count); // Creation and initialization
		}
		else if (choice == 7) // Delete Student
		{
			inscription_find(choice);
			if (choice == 4) continue;

			char buff[20] = {};
			cin >> buff;

			int find_number = 0; // number is index of pointer array 
			find_number = group.FindStudent(choice, buff);
			if (find_number < 0)
			{
				cout << "\nNo results\n";
				Sleep(2000);
			}
			else if (find_number >= 0)
			{
				group.DeleteStudent(find_number);
			}
		}
		else if (choice == 8) // Save group list
		{		
			group.Save();
			system("cls");
		}
		else if (choice == 9) // Load group list
		{
			system("cls");
			group.Load();
		}
		else if (!choice) break;
		else
		{
			cout << "\nYou enter invalid number, try againe.";
			Sleep(2000);
		}
	} while (true);
	return 0;
}