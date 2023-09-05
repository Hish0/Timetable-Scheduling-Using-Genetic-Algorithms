#ifndef UTILITY_FUNCTIONS_H
#define UTILITY_FUNCTIONS_H

#include "../TimeSlot/TimeSlot.h" // Adjust the path based on your folder structure
#include "../Venue/Venue.h"       // Adjust the path based on your folder structure

namespace Utility
{
    TimeSlot getRandomTimeSlot();
    TimeSlot getRandomTimeSlot(const TimeSlot &exclude);
    Venue getRandomVenue();
    // ... Add other utility functions here
}

#endif // UTILITY_FUNCTIONS_H
