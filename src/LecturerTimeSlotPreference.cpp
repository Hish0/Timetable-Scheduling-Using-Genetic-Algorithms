#include "../include/LecturerTimeSlotPreference.h"

// Default Constructor
LecturerTimeSlotPreference::LecturerTimeSlotPreference() : lecturer(), timeSlots(), rank(0) {}

// Parameterized Constructor
LecturerTimeSlotPreference::LecturerTimeSlotPreference(const Lecturer &lect, const std::vector<TimeSlot> &slots, int r)
    : lecturer(lect), timeSlots(slots), rank(r) {}

// Getter methods
Lecturer LecturerTimeSlotPreference::getLecturer() const
{
    return lecturer;
}

std::vector<TimeSlot> LecturerTimeSlotPreference::getTimeSlots() const
{
    return timeSlots;
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

void LecturerTimeSlotPreference::setTimeSlots(const std::vector<TimeSlot> &slots)
{
    timeSlots = slots;
}

void LecturerTimeSlotPreference::setRank(int r)
{
    rank = r;
}
