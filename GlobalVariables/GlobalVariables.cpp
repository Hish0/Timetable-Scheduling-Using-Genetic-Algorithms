#include "GlobalVariables.h"

// Initialize lecturers with ID and Name
void initializeLecturers()
{
    // Initialize lecturers with ID and Name
    allLecturers.push_back(Lecturer(1, "Dr. Abd Alsalam almaraghni"));
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
    allLecturers.push_back(Lecturer(16, "Dr. Mo3eed 1"));
    allLecturers.push_back(Lecturer(17, "Dr. Mo3eed 2"));
    allLecturers.push_back(Lecturer(18, "Dr. Khadeja"));
    allLecturers.push_back(Lecturer(19, "Dr. Salsabil"));
    allLecturers.push_back(Lecturer(20, "Dr. Nabeel"));
    allLecturers.push_back(Lecturer(21, "Dr. Mokhtar"));
    allLecturers.push_back(Lecturer(22, "Dr. Elbadri"));
    allLecturers.push_back(Lecturer(23, "Dr. Ahmed abd almutaleb"));
    allLecturers.push_back(Lecturer(24, "Dr. Aljalali"));
    allLecturers.push_back(Lecturer(25, "Dr. Ali alaswad"));
    allLecturers.push_back(Lecturer(26, "Dr. Mariam British"));
    allLecturers.push_back(Lecturer(27, "Dr. Amira alelagi"));
    allLecturers.push_back(Lecturer(28, "Dr. Naema albadri"));
    allLecturers.push_back(Lecturer(29, "Dr. Tasneem"));
    allLecturers.push_back(Lecturer(30, "Dr. Farhat"));
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

    // printing info of all timeslots
    // for (int i = 0; i < allTimeSlots.size(); i++)
    // {
    //     allTimeSlots[i].printInfo();
    // }
}

// Initialize modules
void initializeModules()
{
    // Initialize modules with ID, Lecturer, Name, Level, Number of Students, Is Lab, number of slots
    allModules.push_back(Module(1, allLecturers[16], "CS100", 1, 100, false, 5));
    allModules.push_back(Module(2, allLecturers[18], "MM101", 1, 100, false, 5));
    allModules.push_back(Module(3, allLecturers[19], "MM102", 1, 100, false, 5));
    allModules.push_back(Module(4, allLecturers[20], "ST101", 1, 100, false, 5));
    allModules.push_back(Module(5, allLecturers[21], "PH112", 1, 100, false, 5));

    allModules.push_back(Module(6, allLecturers[17], "CS111", 2, 100, false, 5));
    allModules.push_back(Module(7, allLecturers[23], "MM103", 2, 100, false, 5));
    allModules.push_back(Module(8, allLecturers[24], "MM104", 2, 100, false, 5));
    allModules.push_back(Module(9, allLecturers[25], "ST102", 2, 100, false, 5));
    allModules.push_back(Module(10, allLecturers[26], "EL101", 2, 100, false, 2));
    allModules.push_back(Module(11, allLecturers[27], "AR051", 2, 100, false, 2));

    allModules.push_back(Module(12, allLecturers[28], "CS115", 3, 25, true, 5));
    allModules.push_back(Module(13, allLecturers[11], "CS200", 3, 25, true, 4));
    allModules.push_back(Module(14, allLecturers[1], "CS207", 3, 25, true, 4));
    allModules.push_back(Module(15, allLecturers[29], "MA200", 3, 100, false, 5));
    allModules.push_back(Module(16, allLecturers[22], "PH200", 3, 100, false, 3));

    allModules.push_back(Module(17, allLecturers[7], "CS211", 4, 25, true, 5));
    allModules.push_back(Module(18, allLecturers[10], "CS215", 4, 25, true, 5));
    allModules.push_back(Module(19, allLecturers[30], "MA206", 4, 100, false, 5));
    allModules.push_back(Module(20, allLecturers[22], "PH201", 4, 100, false, 3));
    allModules.push_back(Module(21, allLecturers[27], "AR052", 4, 100, false, 2));
    allModules.push_back(Module(22, allLecturers[26], "EL102", 4, 100, false, 2));

    allModules.push_back(Module(23, allLecturers[8], "CS321", 5, 25, true, 4));
    allModules.push_back(Module(24, allLecturers[3], "CS331", 5, 25, true, 4));
    allModules.push_back(Module(25, allLecturers[10], "CS315", 5, 25, true, 5));
    allModules.push_back(Module(26, allLecturers[28], "CS319", 5, 25, true, 4));

    allModules.push_back(Module(27, allLecturers[13], "CS332", 6, 25, true, 4));
    allModules.push_back(Module(28, allLecturers[8], "CS322", 6, 25, true, 4));
    allModules.push_back(Module(29, allLecturers[3], "CS336", 6, 25, true, 4));
    allModules.push_back(Module(30, allLecturers[14], "CS340", 6, 25, true, 4));
    allModules.push_back(Module(31, allLecturers[11], "CS355", 6, 25, true, 4));

    allModules.push_back(Module(32, allLecturers[6], "CS443", 7, 25, true, 4));
    allModules.push_back(Module(33, allLecturers[13], "CS437", 7, 25, true, 4));
    allModules.push_back(Module(34, allLecturers[9], "CS431", 7, 25, true, 4));
    allModules.push_back(Module(35, allLecturers[4], "CS456", 7, 25, true, 4));

    allModules.push_back(Module(36, allLecturers[4], "CS436", 8, 25, true, 4));
    allModules.push_back(Module(37, allLecturers[12], "CS438", 8, 25, true, 4));
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
    allVenues.push_back(Venue(9, "HALL 73", 200, false));
    allVenues.push_back(Venue(10, "HALL 74", 200, false));
    // ... add more venues as needed
}

std::vector<int> crossoverPoints;

void initializeCrossoverPoints()
{
    int currentPoint = 0;
    crossoverPoints.push_back(currentPoint);

    for (const Module &module : allModules)
    {
        int numSlots = module.getNumberOfTimeSlots();

        // If the number of slots is even, we add points in increments of 2
        if (numSlots % 2 == 0)
        {
            for (int i = 2; i <= numSlots; i += 2)
            {
                crossoverPoints.push_back(currentPoint + i);
            }
        }
        // If the number of slots is odd, we add points in increments of 2, but also add the last slot
        else
        {
            for (int i = 2; i < numSlots; i += 2)
            {
                crossoverPoints.push_back(currentPoint + i);
            }
            crossoverPoints.push_back(currentPoint + numSlots);
        }

        // Update the current point for the next module
        currentPoint += numSlots;
    }
}