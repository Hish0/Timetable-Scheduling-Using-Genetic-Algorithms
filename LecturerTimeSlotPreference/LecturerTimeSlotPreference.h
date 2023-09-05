#ifndef LECTURER_TIMESLOT_PREFERENCE_H
#define LECTURER_TIMESLOT_PREFERENCE_H

#include <string>
#include "../Lecturer/Lecturer.h" // Assuming Lecturer.h is in a folder named Lecturer
#include "../TimeSlot/TimeSlot.h" // Assuming TimeSlot.h is in a folder named TimeSlot

class LecturerTimeSlotPreference
{
private:
    Lecturer lecturer;
    TimeSlot timeSlot;
    int rank; // Preference rank

public:
    // Default Constructor
    LecturerTimeSlotPreference();

    // Parameterized Constructor
    LecturerTimeSlotPreference(const Lecturer &lect, const TimeSlot &slot, int r);

    // Getter methods
    Lecturer getLecturer() const;
    TimeSlot getTimeSlot() const;
    int getRank() const;

    // Setter methods
    void setLecturer(const Lecturer &lect);
    void setTimeSlot(const TimeSlot &slot);
    void setRank(int r);
};

#endif // LECTURER_TIMESLOT_PREFERENCE_H
