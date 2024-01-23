#pragma once // To avoid multiple inclusions

#include <vector>
#include "Lecturer.h" // Assuming Lecturer class is defined in this header file
#include "TimeSlot.h" // Assuming TimeSlot class is defined in this header file
#include "Module.h"   // Assuming Module class is defined in this header file
#include "Venue.h"    // Assuming Venues class is defined in this header file
#include "Chromosome.h"
#include "Population.h"
#include "LecturerTimeSlotPreference.h"

extern std::vector<Lecturer> allLecturers;
extern std::vector<TimeSlot> allTimeSlots;
extern std::vector<Module> allModules;
extern std::vector<Venue> allVenues;
extern std::vector<int> crossoverPoints;
extern std::vector<LecturerTimeSlotPreference> globalLecturerPreferences;

void initializeLecturers();
void initializeTimeSlots();
void initializeModules();
void initializeVenues();
void initializeLecturerTimeSlotPreference();
void initializeCrossoverPoints();
void trimString(std::string &str);
TimeSlot getTimeSlotById(int timeSlotId);
int extractLastSlotId(const std::string &message);

bool parseBool(const string &str);
Lecturer findLecturerByName(const std::string &name);
bool startsWith(const std::string &fullString, const std::string &startingSubstring);
TimeSlot getRandomTimeSlotFromPreference(const Module &module);
