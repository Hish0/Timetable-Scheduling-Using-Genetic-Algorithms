#include "Module.h"
#include "../GlobalVariables/GlobalVariables.h"

// Default Constructor
Module::Module() : moduleID(0), lecturer(), name("Unknown"), level(0),
                   numberOfStudentsEnrolled(0), isLab(false), numberOfTimeSlots(0) {} // Default to 2

// Parameterized Constructor
Module::Module(int modID, const Lecturer &lect, const string &modName, int modLevel,
               int students, bool lab, int slots)
    : moduleID(modID), lecturer(lect), name(modName), level(modLevel),
      numberOfStudentsEnrolled(students), isLab(lab), numberOfTimeSlots(slots) {}

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

int Module::getNumberOfTimeSlots() const
{
    return numberOfTimeSlots;
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

void Module::setNumberOfTimeSlots(int slots)
{
    numberOfTimeSlots = slots;
}

void Module::printInfo() const
{
    cout << "Module ID: " << moduleID
         << ", Lecturer: " << lecturer.getLecturerName()
         << ", Name: " << name
         << ", Level: " << level
         << ", Enrolled Students: " << numberOfStudentsEnrolled
         << ", Is Lab: " << (isLab ? "Yes" : "No")
         << ", Number of time slots: " << numberOfTimeSlots << endl;
}

// Convert printInfo to toString
std::string Module::toString() const
{
    std::ostringstream oss;
    oss << "Module ID: " << moduleID
        << ", Lecturer: " << lecturer.getLecturerName()
        << ", Name: " << name
        << ", Level: " << level
        << ", Enrolled Students: " << numberOfStudentsEnrolled
        << ", Is Lab: " << (isLab ? "Yes" : "No")
        << ", Number of time slots: " << numberOfTimeSlots;
    return oss.str();
}

// New fromString method
void Module::fromString(const std::string &str)
{
    std::istringstream iss(str);
    std::string token;

    // Assuming the format is like "Module ID: 1, Lecturer: Dr. Mo3eed 1, Name: CS100, Level: 1, Enrolled Students: 100, Is Lab: No, Number of time slots: 5"
    while (getline(iss, token, ','))
    {
        std::istringstream tokenStream(token);
        std::string key;
        std::string value;

        // Split the token into key and value
        getline(tokenStream, key, ':');
        getline(tokenStream, value);
        trimString(key);   // Function to trim leading and trailing spaces
        trimString(value); // Function to trim leading and trailing spaces

        // Set the appropriate attribute based on the key
        if (key == "Module ID")
        {
            this->moduleID = stoi(value);
        }
        else if (key == "Lecturer")
        {
            Lecturer foundLecturer = findLecturerByName(value);
            this->lecturer = foundLecturer;
        }
        else if (key == "Name")
        {
            this->name = value;
        }
        else if (key == "Level")
        {
            this->level = stoi(value);
        }
        else if (key == "Enrolled Students")
        {
            this->numberOfStudentsEnrolled = stoi(value);
        }
        else if (key == "Is Lab")
        {
            this->isLab = (value == "Yes");
        }
        else if (key == "Number of time slots")
        {
            this->numberOfTimeSlots = stoi(value);
        }
    }
}
