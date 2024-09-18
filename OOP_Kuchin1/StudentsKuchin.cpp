#include "StudentsKuchin.h"
#include "Checkup.h"
#include <vector>
#include <sstream>

StudentsKuchin StudentsKuchin::CreateStudent()
{
	string id;
	string name;
	string surname;
	string age;
	string scholarship;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	while (true) {
		cout << "Введите ID студента: ";
		getline(cin, id);
		if (isInteger(id) && stoi(id) > 0) {
			break;
		}
		else {
			cout << "Неверный ввод. Должно быть целое число." << endl;
		}
	}
	cout << "Введите имя студента: ";
	getline(cin, name);

	cout << "Введите фамилию студента: ";
	getline(cin, surname);

	while (true) {
		cout << "Введите возраст студента";
		getline(cin, age);
		if (isInteger(age) && stoi(age) > 0) {
			break;
		}
		else {
			cout << "Неверный ввод. Должно быть целое число." << endl;
		}
	}
	while (true) {
		cout << "Введите стипендию студента";
		getline(cin, scholarship);
		if (isInteger(scholarship) && stoi(scholarship) > 0) {
			break;
		}
		else {
			cout << "Неверный ввод. Должно быть целое число." << endl;
		}
	}

	StudentsKuchin new_student(0, "", "", 0, 0);
	new_student.setStudentID(stoi(id));
	new_student.setName(name);
	new_student.setSurname(surname);
	new_student.setAge(stoi(age));
	new_student.setScholarship(stoi(scholarship));

	return new_student;
}
void StudentsKuchin::ShowInfo() const {
	cout << "ID: " << id << ", "
		<< "Имя: " << name << ", "
		<< "Фамилия: " << surname << ", "
		<< "Возраст: " << age << ", "
		<< "Стипендия: " << endl;
}

vector<string> split(const string& s, char delim) {
	vector<string> result;
	stringstream ss(s);
	string item;

	while (getline(ss, item, delim)) {
		result.push_back(item);
	}

	return result;
}
StudentsKuchin StudentsKuchin::ReadFromFile(ifstream& fin) {
	StudentsKuchin emp(-1, "", "", 0, 0);
	if (fin.is_open()) {
		int id, age, scholarship;
		string name, surname, cur_string;
		getline(fin, cur_string);
		vector<string> elements = split(cur_string, ' ');
		if (elements.size() == 5) {
			emp.setStudentID(stoi(elements[0]));
			emp.setName(elements[1]);
			emp.setSurname(elements[2]);
			emp.setAge(stoi(elements[3]));
			emp.setScholarship(stoi(elements[4]));
		}
	}

	return emp;
}


void StudentsKuchin::WriteToFile(ofstream& fout) const {
	fout << id << ' ' << name << ' ' << surname << ' ' << age << ' ' << scholarship << endl;
}
