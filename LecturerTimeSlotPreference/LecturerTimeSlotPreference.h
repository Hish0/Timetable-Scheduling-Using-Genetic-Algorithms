#ifndef LECTURER_TIMESLOT_PREFERENCE_H
#define LECTURER_TIMESLOT_PREFERENCE_H

#include <vector>
#include <string>
#include "../Lecturer/Lecturer.h"
#include "../TimeSlot/TimeSlot.h"

class LecturerTimeSlotPreference
{
private:
    Lecturer lecturer;
    std::vector<TimeSlot> timeSlots; // Changed to a vector of TimeSlot objects
    int rank;                        // Preference rank

public:
    // Default Constructor
    LecturerTimeSlotPreference();

    // Parameterized Constructor
    LecturerTimeSlotPreference(const Lecturer &lect, const std::vector<TimeSlot> &slots, int r);

    // Getter methods
    Lecturer getLecturer() const;
    std::vector<TimeSlot> getTimeSlots() const; // Updated to return a vector
    int getRank() const;

    // Setter methods
    void setLecturer(const Lecturer &lect);
    void setTimeSlots(const std::vector<TimeSlot> &slots); // Updated to accept a vector
    void setRank(int r);
};

#endif // LECTURER_TIMESLOT_PREFERENCE_H
