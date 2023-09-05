#include "LecturerTimeSlotPreference.h"

// Default Constructor
LecturerTimeSlotPreference::LecturerTimeSlotPreference() : lecturer(), timeSlot(), rank(0) {}

// Parameterized Constructor
LecturerTimeSlotPreference::LecturerTimeSlotPreference(const Lecturer &lect, const TimeSlot &slot, int r)
    : lecturer(lect), timeSlot(slot), rank(r) {}

// Getter methods
Lecturer LecturerTimeSlotPreference::getLecturer() const
{
    return lecturer;
}

TimeSlot LecturerTimeSlotPreference::getTimeSlot() const
{
    return timeSlot;
}

int LecturerTimeSlotPreference::getRank() const
{
    return rank;
}

// Setter methods
void LecturerTimeSlotPreference::setLecturer(const Lecturer &lect)
{
    lecturer = lect;
}

void LecturerTimeSlotPreference::setTimeSlot(const TimeSlot &slot)
{
    timeSlot = slot;
}

void LecturerTimeSlotPreference::setRank(int r)
{
    rank = r;
}
