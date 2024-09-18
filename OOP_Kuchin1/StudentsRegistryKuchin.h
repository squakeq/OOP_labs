#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "StudentsKuchin.h"

using namespace std;

class StudentsRegistryKuchin {
private:
    vector<StudentsKuchin> students;

public:
    void addStudent(const StudentsKuchin& student);

    bool removeStudent(int id);

    void clearStudents();

    void saveToFile();

    void loadFromFile();

    void showStudents() const;
};

