#ifndef SCHEDULED_MODULE_H
#define SCHEDULED_MODULE_H

#include "../Module/Module.h"     // Adjust this path based on your folder structure
#include "../TimeSlot/TimeSlot.h" // Adjust this path based on your folder structure
#include "../Venue/Venue.h"       // Adjust this path based on your folder structure

class ScheduledModule
{
private:
    Module module;
    TimeSlot timeSlot;
    Venue venue;
    bool isLockedVenue;
    bool isLockedTimeSlot;
    bool isValid;

public:
    // Default Constructor
    ScheduledModule();

    // Parameterized Constructor
    ScheduledModule(const Module &mod, const TimeSlot &slot, const Venue &ven,
                    bool lockedVenue, bool lockedTimeSlot, bool validStatus);

    bool operator==(const ScheduledModule &other) const;

    // Getter methods
    Module getModule() const;
    TimeSlot getTimeSlot() const;
    Venue getVenue() const;
    bool getIsLockedVenue() const;
    bool getIsLockedTimeSlot() const;
    bool getIsValid() const;

    // Setter methods
    void setModule(const Module &mod);
    void setTimeSlot(const TimeSlot &slot);
    void setVenue(const Venue &ven);
    void setIsLockedVenue(bool lockedVenue);
    void setIsLockedTimeSlot(bool lockedTimeSlot);
    void setIsValid(bool validStatus);
};

#endif // SCHEDULED_MODULE_H
