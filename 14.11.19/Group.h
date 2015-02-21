#include "Student.h"

class Group
{
private:
	int ptr_count;
	int std_count;
	Student ** pst;
	
public:
	Group();
	~Group();

	int FindStudent(int &choice, const char *buff) const;
	void Sort(int &choice); 
	void AddStudents(int &count); 
	void DeleteStudent(int number);
	void EditStudent(int number); 
	void Save();
	void Load();
	void Print()const; 
};

