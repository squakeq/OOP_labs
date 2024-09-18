#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class StudentsKuchin
{

private:
	int id;
	string name;
	string surname;
	int age;
	double scholarship;

public:
	StudentsKuchin(int id, string name, string surname, int age, double scholarship)
		: id(id), name(name), surname(surname), age(age), scholarship(scholarship) {};
	int getStudentID() const { return id; }
	string getName() const { return name; }
	string getSurname() const { return surname; }
	int getAge() const { return age; }
	double getScholarship() const { return scholarship; }

	void setStudentID(int id) { id = id; }
	void setName(string& n) { name = n; }
	void setSurname(string& s) { surname = s; }
	void setAge(int a) { age = a; }
	void setScholarship(double sch) { scholarship = sch; }

	StudentsKuchin CreateStudent();
	void ShowInfo() const;

	StudentsKuchin ReadFromFile(ifstream& fin);
	void WriteToFile(ofstream& fout) const;


};