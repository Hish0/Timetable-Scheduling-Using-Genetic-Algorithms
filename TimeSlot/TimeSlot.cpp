#include "TimeSlot.h"
#include "../GlobalVariables/GlobalVariables.h"

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

TimeSlot TimeSlot::getNextTimeSlot() const
{
    // Find the current time slot in the global vector
    auto it = std::find(allTimeSlots.begin(), allTimeSlots.end(), *this);

    // If the current time slot is found and it's not the last in the vector
    if (it != allTimeSlots.end() && (it + 1) != allTimeSlots.end())
    {
        // Return the next time slot in the vector
        return *(it + 1);
    }

    // If the current time slot is not found or it's the last in the vector
    // Return the current time slot
    return *this;
}

string TimeSlot::toString() const
{
    std::ostringstream oss;
    oss << "TimeSlot ID: " << timeSlotID
        << ", Day: " << day
        << ", Time: " << time;
    return oss.str();
}
