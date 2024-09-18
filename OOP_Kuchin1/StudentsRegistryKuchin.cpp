#include "StudentsRegistryKuchin.h"


void StudentsRegistryKuchin::addStudent(const StudentsKuchin& student) {
    students.push_back(student);
}


bool StudentsRegistryKuchin::removeStudent(int id) {
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->getStudentID() == id) {
            students.erase(it);
            return true;
        }
    }
    return false;
}
void StudentsRegistryKuchin::clearStudents() {
    students.clear();
}


void StudentsRegistryKuchin::saveToFile() {
    string file_name;
    cout << "Че-то надо написать сюда:";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.clear();
    getline(cin, file_name);
    while (file_name == "")
    {
        cin.clear();
        cout << "Сюда тоже: ";
        getline(cin, file_name);
    }
    ofstream fout;
    fout.open(file_name, ios::out);

    if (fout.is_open()) {
        for (const auto& student : students) {
            student.WriteToFile(fout);
        }
        fout.close();
    }
    else {
        cout << "Chto-to nasrat'." << endl;
    }
}
void StudentsRegistryKuchin::loadFromFile() {
    string file_name;
    ifstream fin;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.clear();
    cout << "Текст: ";
    getline(cin, file_name);
    fin.open(file_name, ios::in);
    while (!fin.is_open())
    {
        cin.clear();
        cout << "Текст: ";
        getline(cin, file_name);
        fin.open(file_name, ios::in);
    }
    if (fin.is_open()) {
        students.clear();
        string read_string;
        StudentsKuchin new_emp = new_emp.ReadFromFile(fin);
        while (new_emp.getStudentID() != -1) {
            students.push_back(new_emp);
            new_emp = new_emp.ReadFromFile(fin);
        }
        fin.close();
    }
}


void StudentsRegistryKuchin::showStudents() const {
    if (students.size() == 0) {
        cout << "Текст." << endl;
    }

    else {
        for (const auto& student : students) {
            student.ShowInfo();
        }
    }
}
