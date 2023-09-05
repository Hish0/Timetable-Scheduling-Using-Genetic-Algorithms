#include "Lecturer.h"

// Default Constructor
Lecturer::Lecturer() : lecturerID(0), lecturerName("Unknown") {}

// Parameterized Constructor
Lecturer::Lecturer(int id, const string &name) : lecturerID(id), lecturerName(name) {}

bool Lecturer::operator==(const Lecturer &other) const
{
    return (this->lecturerID == other.lecturerID &&
            this->lecturerName == other.lecturerName);
}

// Getter methods
int Lecturer::getLecturerID() const
{
    return lecturerID;
}

string Lecturer::getLecturerName() const
{
    return lecturerName;
}

// Setter methods
void Lecturer::setLecturerID(int id)
{
    lecturerID = id;
}

void Lecturer::setLecturerName(const string &name)
{
    lecturerName = name;
}

void Lecturer::printInfo() const
{
    cout << "Lecturer ID: " << lecturerID << ", Name: " << lecturerName << endl;
}
