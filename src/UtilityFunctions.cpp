#include "../include/UtilityFunctions.h"
#include "../include/GlobalVariables.h"

namespace Utility
{

    // Function to get a random TimeSlot (implementation needed)
    TimeSlot getRandomTimeSlot()
    {
        // Initialize the random seed if needed
        static bool initialized = false;
        if (!initialized)
        {
            srand(time(nullptr));
            initialized = true;
        }

        // Randomly select an index
        int index = rand() % allTimeSlots.size();

        // Return the TimeSlot at that index
        return allTimeSlots[index];
    }

    // Function to get a random TimeSlot that is different from the one passed as an argument (implementation needed)
    TimeSlot getRandomTimeSlot(const TimeSlot &exclude)
    {

        static bool initialized = false;
        if (!initialized)
        {
            srand(time(nullptr));
            initialized = true;
        }

        vector<TimeSlot> selectableSlots = allTimeSlots; // Assume allTimeSlots is your global vector of TimeSlots

        // Remove the excluded TimeSlot from selectableSlots
        selectableSlots.erase(
            remove_if(
                selectableSlots.begin(),
                selectableSlots.end(),
                [&exclude](const TimeSlot &slot)
                { return slot.getTimeSlotID() == exclude.getTimeSlotID(); }),
            selectableSlots.end());

        if (selectableSlots.empty())
        {
            // Handle the case where no time slots are available.
            // This should never happen if 'exclude' is guaranteed to be in 'allTimeSlots'.
            throw runtime_error("No available time slots!");
        }

        int randomIndex = rand() % selectableSlots.size(); // Generate a random index
        return selectableSlots[randomIndex];               // Return a random TimeSlot from selectableSlots
    }

    // Function to get a random Venue (implementation needed)
    Venue getRandomVenue()
    {

        static bool initialized = false;
        if (!initialized)
        {
            srand(time(nullptr));
            initialized = true;
        }

        int randomIndex = rand() % allVenues.size(); // Generate a random index
        return allVenues[randomIndex];               // Return a random Venue from allVenues
    }

    // ... Add other utility functions here
}
