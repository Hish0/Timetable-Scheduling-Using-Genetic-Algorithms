#ifndef LECTURER_H
#define LECTURER_H

#include <string>
#include <iostream>

using namespace std;

class Lecturer
{
private:
    int lecturerID;
    string lecturerName;

public:
    // Default Constructor
    Lecturer();

    // Parameterized Constructor
    Lecturer(int id, const string &name);

    bool operator==(const Lecturer &other) const;

    // Getter methods
    int getLecturerID() const;
    string getLecturerName() const;

    // Setter methods
    void setLecturerID(int id);
    void setLecturerName(const string &name);

    void printInfo() const;
};

#endif // LECTURER_H
