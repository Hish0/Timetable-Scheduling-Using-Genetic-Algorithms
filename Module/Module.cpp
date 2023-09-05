#include "Module.h"

// Default Constructor
Module::Module() : moduleID(0), lecturer(), name("Unknown"), level(0), numberOfStudentsEnrolled(0), isLab(false) {}

// Parameterized Constructor
Module::Module(int modID, const Lecturer &lect, const string &modName, int modLevel, int students, bool lab)
    : moduleID(modID), lecturer(lect), name(modName), level(modLevel), numberOfStudentsEnrolled(students), isLab(lab) {}

bool Module::operator==(const Module &other) const
{
    return (this->moduleID == other.moduleID &&
            this->lecturer == other.lecturer &&
            this->name == other.name &&
            this->level == other.level &&
            this->numberOfStudentsEnrolled == other.numberOfStudentsEnrolled &&
            this->isLab == other.isLab);
}

// Getter methods
int Module::getModuleID() const
{
    return moduleID;
}

Lecturer Module::getLecturer() const
{
    return lecturer;
}

string Module::getName() const
{
    return name;
}

int Module::getLevel() const
{
    return level;
}

int Module::getNumberOfStudentsEnrolled() const
{
    return numberOfStudentsEnrolled;
}

bool Module::getIsLab() const
{
    return isLab;
}

// Setter methods
void Module::setModuleID(int id)
{
    moduleID = id;
}

void Module::setLecturer(const Lecturer &lect)
{
    lecturer = lect;
}

void Module::setName(const string &modName)
{
    name = modName;
}

void Module::setLevel(int modLevel)
{
    level = modLevel;
}

void Module::setNumberOfStudentsEnrolled(int students)
{
    numberOfStudentsEnrolled = students;
}

void Module::setIsLab(bool lab)
{
    isLab = lab;
}

void Module::printInfo() const
{
    cout << "Module ID: " << moduleID
         << ", Lecturer: " << lecturer.getLecturerName()
         << ", Name: " << name
         << ", Level: " << level
         << ", Enrolled Students: " << numberOfStudentsEnrolled
         << ", Is Lab: " << (isLab ? "Yes" : "No") << endl;
}
