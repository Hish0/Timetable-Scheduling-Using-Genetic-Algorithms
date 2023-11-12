#ifndef LECTURER_H
#define LECTURER_H

#include <string>
#include <iostream>
#include <sstream>

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
    string toString() const;
    void fromString(const std::string &str);
};

#endif // LECTURER_H
