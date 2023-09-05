#ifndef TIMESLOT_H
#define TIMESLOT_H

#include <string>
#include <iostream>

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
};

#endif // TIMESLOT_H
