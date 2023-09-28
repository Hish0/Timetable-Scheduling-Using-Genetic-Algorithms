#include "GlobalVariables.h"

// Initialize lecturers with ID and Name
void initializeLecturers()
{
    // Initialize lecturers with ID and Name
    allLecturers.push_back(Lecturer(1, "Dr. Abd Alsalam Bnoor"));
    allLecturers.push_back(Lecturer(2, "Dr. Lutfi alhaweji"));
    allLecturers.push_back(Lecturer(3, "Dr. Raneem Nashnoosh"));
    allLecturers.push_back(Lecturer(4, "Dr. Hassan Abuaisha"));
    allLecturers.push_back(Lecturer(5, "Dr. Zainab Ahmed"));
    allLecturers.push_back(Lecturer(6, "Dr. Samir Embarek"));
    allLecturers.push_back(Lecturer(7, "Dr. Fatima Hmeed"));
    allLecturers.push_back(Lecturer(8, "Dr. Wafaa Nasser"));
    allLecturers.push_back(Lecturer(9, "Dr. Abd Allatif Alshwehdi"));
    allLecturers.push_back(Lecturer(10, "Dr. Omaima Alsheli"));
    allLecturers.push_back(Lecturer(11, "Dr. Adnan Alshreef"));
    allLecturers.push_back(Lecturer(12, "Dr. Ali Aborass"));
    allLecturers.push_back(Lecturer(13, "Dr. Alsunni"));
    allLecturers.push_back(Lecturer(14, "Dr. Fardous"));
    allLecturers.push_back(Lecturer(15, "Dr. Fathia Abu Amer"));
    // ... add more lecturers as needed
}

// Initialize time slots
void initializeTimeSlots()
{
    // Days of the week
    vector<string> days = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};

    // Time intervals
    vector<string> times = {"8:00 AM", "9:00 AM", "10:00 AM", "11:00 AM",
                            "12:00 PM", "1:00 PM", "2:00 PM", "3:00 PM"};

    int id = 1; // Unique ID for each time slot

    for (const auto &day : days)
    {
        for (const auto &time : times)
        {
            allTimeSlots.push_back(TimeSlot(id++, day, time));
        }
    }
    for (int i = 0; i < allTimeSlots.size(); i++)
    {
        allTimeSlots[i].printInfo();
    }
}

// Initialize modules
void initializeModules()
{
    // Initialize modules with ID, Lecturer, Name, Level, Number of Students, Is Lab
    allModules.push_back(Module(1, allLecturers[13], "CS100", 1, 100, false, 4));
    allModules.push_back(Module(2, allLecturers[2], "CS111", 1, 95, false, 4));
    allModules.push_back(Module(3, allLecturers[7], "CS115", 1, 85, false, 4));
    allModules.push_back(Module(4, allLecturers[10], "CS200", 2, 30, true, 4));
    allModules.push_back(Module(5, allLecturers[0], "CS207", 2, 25, true, 4));
    allModules.push_back(Module(6, allLecturers[6], "CS211", 2, 30, true, 4));
    allModules.push_back(Module(7, allLecturers[1], "CS215", 2, 30, true, 4));
    allModules.push_back(Module(8, allLecturers[11], "CS315", 3, 27, true, 4));
    allModules.push_back(Module(9, allLecturers[10], "CS319", 3, 26, true, 4));
    allModules.push_back(Module(10, allLecturers[14], "CS321", 3, 20, true, 4));
    allModules.push_back(Module(11, allLecturers[14], "CS322", 3, 24, true, 4));
    allModules.push_back(Module(12, allLecturers[2], "CS331", 3, 22, true, 4));
    allModules.push_back(Module(13, allLecturers[12], "CS332", 3, 23, true, 4));
    allModules.push_back(Module(14, allLecturers[4], "CS336", 3, 18, true, 4));
    allModules.push_back(Module(15, allLecturers[13], "CS340", 3, 17, true, 4));
    allModules.push_back(Module(16, allLecturers[3], "CS436", 4, 15, true, 4));
    allModules.push_back(Module(17, allLecturers[5], "CS443", 4, 13, true, 4));
    allModules.push_back(Module(18, allLecturers[3], "CS456", 4, 14, true, 4));
    allModules.push_back(Module(19, allLecturers[8], "CS431", 4, 16, true, 4));
    allModules.push_back(Module(20, allLecturers[12], "CS437", 4, 19, true, 4));
}

// Initialize venues
void initializeVenues()
{
    // Initialize venues with ID, Name, Capacity, IsLab
    allVenues.push_back(Venue(1, "LAB 1", 30, true));
    allVenues.push_back(Venue(2, "LAB 2", 30, true));
    allVenues.push_back(Venue(3, "LAB 3", 30, true));
    allVenues.push_back(Venue(4, "LAB 4", 30, true));
    allVenues.push_back(Venue(5, "LAB 5", 30, true));
    allVenues.push_back(Venue(6, "HALL 70", 200, false));
    allVenues.push_back(Venue(7, "HALL 71", 200, false));
    allVenues.push_back(Venue(8, "HALL 72", 200, false));
    // ... add more venues as needed
}