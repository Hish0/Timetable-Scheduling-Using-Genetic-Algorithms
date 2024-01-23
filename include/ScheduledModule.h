#ifndef SCHEDULED_MODULE_H
#define SCHEDULED_MODULE_H

#include "Module.h"   // Adjust this path based on your folder structure
#include "TimeSlot.h" // Adjust this path based on your folder structure
#include "Venue.h"    // Adjust this path based on your folder structure

class ScheduledModule
{
private:
    Module module;
    TimeSlot timeSlot;
    Venue venue;
    bool isLockedVenue;
    bool isLockedTimeSlot;
    bool isValid;
    bool isFirstSlot;
    bool isOneSlot;

public:
    // Default Constructor
    ScheduledModule();

    // Parameterized Constructor
    ScheduledModule(const Module &mod, const TimeSlot &slot, const Venue &ven,
                    bool lockedVenue, bool lockedTimeSlot, bool validStatus, bool isFirstSlot, bool isOneSlot);

    bool operator==(const ScheduledModule &other) const;

    // Getter methods
    Module getModule() const;
    TimeSlot getTimeSlot() const;
    Venue getVenue() const;
    bool getIsLockedVenue() const;
    bool getIsLockedTimeSlot() const;
    bool getIsValid() const;
    bool getIsFirstSlot() const;
    bool getIsOneSlot() const;

    // Setter methods
    void setModule(const Module &mod);
    void setTimeSlot(const TimeSlot &slot);
    void setVenue(const Venue &ven);
    void setIsLockedVenue(bool lockedVenue);
    void setIsLockedTimeSlot(bool lockedTimeSlot);
    void setIsValid(bool validStatus);
    void setIsFirstSlot(bool FirstSlot);
    void setIsOneSlot(bool OneSlot);
};

#endif // SCHEDULED_MODULE_H
