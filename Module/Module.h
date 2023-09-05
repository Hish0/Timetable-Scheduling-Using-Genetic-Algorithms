#ifndef MODULE_H
#define MODULE_H

#include <string>
#include <iostream>
#include "../Lecturer/Lecturer.h" // Assuming Lecturer.h is in a folder named Lecturer

using namespace std;

class Module
{
private:
    int moduleID;
    Lecturer lecturer;
    string name;
    int level;
    int numberOfStudentsEnrolled;
    bool isLab;

public:
    // Default Constructor
    Module();

    // Parameterized Constructor
    Module(int modID, const Lecturer &lect, const string &modName, int modLevel, int students, bool lab);

    bool operator==(const Module &other) const;

    // Getter methods
    int getModuleID() const;
    Lecturer getLecturer() const;
    string getName() const;
    int getLevel() const;
    int getNumberOfStudentsEnrolled() const;
    bool getIsLab() const;

    // Setter methods
    void setModuleID(int id);
    void setLecturer(const Lecturer &lect);
    void setName(const string &modName);
    void setLevel(int modLevel);
    void setNumberOfStudentsEnrolled(int students);
    void setIsLab(bool lab);

    void printInfo() const;
};

#endif // MODULE_H
