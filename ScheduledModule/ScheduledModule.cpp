#include "ScheduledModule.h"

// Default Constructor
ScheduledModule::ScheduledModule()
    : module(), timeSlot(), venue(), isLockedVenue(false), isLockedTimeSlot(false), isValid(false) {}

// Parameterized Constructor
ScheduledModule::ScheduledModule(const Module &mod, const TimeSlot &slot, const Venue &ven,
                                 bool lockedVenue, bool lockedTimeSlot, bool validStatus)
    : module(mod), timeSlot(slot), venue(ven), isLockedVenue(lockedVenue),
      isLockedTimeSlot(lockedTimeSlot), isValid(validStatus) {}

bool ScheduledModule::operator==(const ScheduledModule &other) const
{
    return (
        this->module == other.module &&
        this->timeSlot == other.timeSlot &&
        this->venue == other.venue &&
        this->isLockedVenue == other.isLockedVenue &&
        this->isLockedTimeSlot == other.isLockedTimeSlot &&
        this->isValid == other.isValid);
}

// Getter methods
Module ScheduledModule::getModule() const
{
    return module;
}

TimeSlot ScheduledModule::getTimeSlot() const
{
    return timeSlot;
}

Venue ScheduledModule::getVenue() const
{
    return venue;
}

bool ScheduledModule::getIsLockedVenue() const
{
    return isLockedVenue;
}

bool ScheduledModule::getIsLockedTimeSlot() const
{
    return isLockedTimeSlot;
}

bool ScheduledModule::getIsValid() const
{
    return isValid;
}

// Setter methods
void ScheduledModule::setModule(const Module &mod)
{
    module = mod;
}

void ScheduledModule::setTimeSlot(const TimeSlot &slot)
{
    timeSlot = slot;
}

void ScheduledModule::setVenue(const Venue &ven)
{
    venue = ven;
}

void ScheduledModule::setIsLockedVenue(bool lockedVenue)
{
    isLockedVenue = lockedVenue;
}

void ScheduledModule::setIsLockedTimeSlot(bool lockedTimeSlot)
{
    isLockedTimeSlot = lockedTimeSlot;
}

void ScheduledModule::setIsValid(bool validStatus)
{
    isValid = validStatus;
}
