#ifndef TIMESLOT_H
#define TIMESLOT_H

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class TimeSlot
{
private:
    int timeSlotID;
    string day;
    string time;

public:
    // Default Constructor
    TimeSlot();

    // Parameterized Constructor
    TimeSlot(int id, const string &dayValue, const string &timeValue);

    bool operator==(const TimeSlot &other) const;

    // Getter methods
    int getTimeSlotID() const;
    string getDay() const;
    string getTime() const;

    // Setter methods
    void setTimeSlotID(int id);
    void setDay(const string &dayValue);
    void setTime(const string &timeValue);

    void printInfo() const;
    bool isEmpty() const;
    TimeSlot getNextTimeSlot() const;
    string toString() const;
    void fromString(const std::string &str);
};

struct TimeSlotComparator
{
    bool operator()(const TimeSlot &a, const TimeSlot &b) const;
};
#endif // TIMESLOT_H
