#pragma once // To avoid multiple inclusions

#include <vector>
#include "../Lecturer/Lecturer.h" // Assuming Lecturer class is defined in this header file
#include "../TimeSlot/TimeSlot.h" // Assuming TimeSlot class is defined in this header file
#include "../Module/Module.h"     // Assuming Module class is defined in this header file
#include "../Venue/Venue.h"       // Assuming Venues class is defined in this header file

extern std::vector<Lecturer> allLecturers;
extern std::vector<TimeSlot> allTimeSlots;
extern std::vector<Module> allModules;
extern std::vector<Venue> allVenues;

void initializeLecturers();
void initializeTimeSlots();
void initializeModules();
void initializeVenues();
