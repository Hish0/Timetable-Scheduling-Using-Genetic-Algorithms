#include <iostream>
#include <vector>
#include "Chromosome/Chromosome.h"
#include "GlobalVariables/GlobalVariables.h"

// #include "Lecturer/Lecturer.h" // Assuming Lecturer class is defined in this header file
// #include "TimeSlot/TimeSlot.h"               // Assuming TimeSlot class is defined in this header file
// #include "Module/Module.h"                   // Assuming Module class is defined in this header file
// #include "Venue/Venue.h"                     // Assuming Venues class is defined in this header file
// #include "ScheduledModule/ScheduledModule.h" // Adjust this path based on your folder structure

// int main()
// {
//     // Initialize lecturers
//     vector<Lecturer> allLecturers;
//     allLecturers.push_back(Lecturer(1, "Dr. Abd Alsalam almaraghni"));
//     allLecturers.push_back(Lecturer(2, "Dr. Lutfi alhaweji"));

//     // Initialize modules
//     vector<Module> allModules;
//     allModules.push_back(Module(1, allLecturers[1], "CS100", 1, 100, false, 2));
//     allModules.push_back(Module(2, allLecturers[1], "MM101", 1, 100, false, 2));
//     allModules.push_back(Module(3, allLecturers[1], "MM120", 1, 100, false, 2));

//     // Initialize venues
//     vector<Venue> allVenues;
//     allVenues.push_back(Venue(1, "LAB 4", 30, true));
//     allVenues.push_back(Venue(2, "LAB 5", 30, true));
//     allVenues.push_back(Venue(3, "HALL 70", 200, false));
//     allVenues.push_back(Venue(4, "HALL 71", 200, false));

//     // Initialize time slots
//     vector<TimeSlot> allTimeSlots;
//     allTimeSlots.push_back(TimeSlot(17, "Monday", "8:00 AM"));
//     allTimeSlots.push_back(TimeSlot(18, "Monday", "9:00 AM"));
//     allTimeSlots.push_back(TimeSlot(19, "Monday", "10:00 AM"));
//     allTimeSlots.push_back(TimeSlot(20, "Monday", "11:00 AM"));
//     allTimeSlots.push_back(TimeSlot(23, "Monday", "2:00 AM"));
//     allTimeSlots.push_back(TimeSlot(24, "Monday", "3:00 PM"));
//     allTimeSlots.push_back(TimeSlot(25, "Tuesday", "8:00 AM"));

//     // Initialize scheduled modules
//     vector<ScheduledModule> scheduledModules;
//     scheduledModules.push_back(ScheduledModule(allModules[0], allTimeSlots[1], allVenues[2], false, false, true, true, true));  // CS100 with Dr. Abd Alsalam almaraghni in HALL 70 at 8:00 AM on Saturday
//     scheduledModules.push_back(ScheduledModule(allModules[0], allTimeSlots[2], allVenues[2], false, false, true, true, true));  // MM102 with Dr. Abd Alsalam almaraghni in HALL 70 at 10:00 AM on Saturday
//     scheduledModules.push_back(ScheduledModule(allModules[2], allTimeSlots[4], allVenues[3], false, false, true, true, false)); // MM101 with Dr. Lutfi alhaweji in LAB 5 at 9:00 AM on Saturday
//     scheduledModules.push_back(ScheduledModule(allModules[2], allTimeSlots[5], allVenues[3], false, false, true, true, false)); // ST101 with Dr. Lutfi alhaweji in LAB 5 at 11:00 AM on Saturday

//     // Create a chromosome with these scheduled modules
//     Chromosome chromosome(scheduledModules);

//     // Test evaluateFitness function
//     double fitness = chromosome.evaluateFitness();
//     std::pair<int, std::string> violation = chromosome.catchViolation();
//     int lastTimeSlotIdOfPreviousModule = extractLastSlotId(violation.second); // Extract the last slot ID from the message

//     std::cout << "--->gene id returned frome catch : " << violation.first << std::endl;
//     std::cout << "--->messege of the catch function is : " << violation.second << std::endl;
//     std::cout << "--->lastTimeSlotIdOfPreviousModule of the catch function is : " << lastTimeSlotIdOfPreviousModule << std::endl;
//     std::cout << "[[[[Fitness of the chromosome:]]]] " << fitness << std::endl;

//     return 0;
// }