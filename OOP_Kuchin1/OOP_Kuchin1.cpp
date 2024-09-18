#include <iostream>
#include <string>
#include <vector>
#include "StudentsKuchin.cpp"
#include "StudentsRegistryKuchin.h"
#define NOMINMAX
#include <Windows.h>

void ShowMenu()
{
	cout << "1. Добавить студента" << "\n"
		<< "2. Удалить студента " << "\n"
		<< "3. Показать список студентов" << "\n"
		<< "4. Считать список из файла" << "\n"
		<< "5. Сохранить список в файл" << "\n"
		<< "6. Очистить список" << "\n"
		<< "0. Выход" << "\n";
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	setlocale(LC_CTYPE, "Russian");
	StudentsRegistryKuchin registry;
	while (1) {
		ShowMenu();
		int action;
		StudentsRegistryKuchin registry;
		cout << "Type number (0-6): ";
		if (!(cin >> action) or action < 0 or action > 6) {
			cerr << "Invalid input. Please enter a valid integer." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		switch (action)
		{
		case 1:
		{
			StudentsKuchin new_student = new_student.CreateStudent();
			registry.addStudent(new_student);
			break;
		}
		case 2:
		{
			string id;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			while (true) {
				cout << "Введите ID студента: ";
				getline(cin, id);
				if (isInteger(id) && stoi(id) > 0) {
					break;
				}
				else {
					cout << "Неверный ввод. Введите положительное целое число." << endl;
				}
			}

			if (registry.removeStudent(stoi(id))) {
				cout << "Студент успешно удалён." << endl;
			}
			else {
				cout << "Не удалось найти студента с заданным ID." << endl;
			}

			break;
		}
		case 3:
		{
			registry.showStudents();
			break;
		}

		case 4:
		{
			registry.loadFromFile();
			break;
		}


		case 5:
		{
			registry.saveToFile();
			break;
		}

		case 6: {
			registry.clearStudents();
			break;
		}

		case 0: {
			return 0;
		}

		}

	}
}