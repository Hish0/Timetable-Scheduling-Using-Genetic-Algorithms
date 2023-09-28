#include "TimeSlot.h"

// Default Constructor
TimeSlot::TimeSlot() : timeSlotID(0), day("Unknown"), time("00:00") {}

// Parameterized Constructor
TimeSlot::TimeSlot(int id, const string &dayValue, const string &timeValue)
    : timeSlotID(id), day(dayValue), time(timeValue) {}

bool TimeSlot::operator==(const TimeSlot &other) const
{
    return (this->timeSlotID == other.timeSlotID &&
            this->day == other.day &&
            this->time == other.time);
}

// Getter methods
int TimeSlot::getTimeSlotID() const
{
    return timeSlotID;
}

string TimeSlot::getDay() const
{
    return day;
}

string TimeSlot::getTime() const
{
    return time;
}

// Setter methods
void TimeSlot::setTimeSlotID(int id)
{
    timeSlotID = id;
}

void TimeSlot::setDay(const string &dayValue)
{
    day = dayValue;
}

void TimeSlot::setTime(const string &timeValue)
{
    time = timeValue;
}

void TimeSlot::printInfo() const
{
    cout << "TimeSlot ID: " << timeSlotID << ", Day: " << day << ", Time: " << time << endl;
}

bool TimeSlot::isEmpty() const
{
    return this->getDay().empty() && (this->getTimeSlotID() == 0);
}

bool TimeSlotComparator::operator()(const TimeSlot &a, const TimeSlot &b) const
{
    return a.getTimeSlotID() < b.getTimeSlotID();
}