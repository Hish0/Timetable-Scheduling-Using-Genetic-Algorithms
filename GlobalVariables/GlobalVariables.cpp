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
            // the lecturer meeting of the week is in monday from 12 to 2 , no modules allowed in this time
            if (day == "Monday" && (time == "12:00 PM" || time == "1:00 PM"))
            {
                id++;
                continue;
            }

            allTimeSlots.push_back(TimeSlot(id++, day, time));
        }
    }

    // printing info of all timeslots
    for (int i = 0; i < allTimeSlots.size(); i++)
    {
        allTimeSlots[i].printInfo();
    }
}

// Initialize modules
void initializeModules()
{
    // Initialize modules with ID, Lecturer, Name, Level, Number of Students, Is Lab, number of slots
    allModules.push_back(Module(1, allLecturers[15], "CS100", 1, 100, false, 5));
    allModules.push_back(Module(2, allLecturers[17], "MM101", 1, 100, false, 4));
    allModules.push_back(Module(3, allLecturers[18], "MM102", 1, 100, false, 4));
    allModules.push_back(Module(4, allLecturers[19], "ST101", 1, 100, false, 4));
    allModules.push_back(Module(5, allLecturers[20], "PH112", 1, 100, false, 4));

    allModules.push_back(Module(6, allLecturers[16], "CS111", 2, 100, false, 5));
    allModules.push_back(Module(7, allLecturers[22], "MM103", 2, 100, false, 4));
    allModules.push_back(Module(8, allLecturers[23], "MM104", 2, 100, false, 4));
    allModules.push_back(Module(9, allLecturers[24], "ST102", 2, 100, false, 4));
    allModules.push_back(Module(10, allLecturers[25], "EL101", 2, 100, false, 4));
    allModules.push_back(Module(11, allLecturers[5], "AR051", 2, 100, false, 4)); // 26

    allModules.push_back(Module(12, allLecturers[27], "CS115", 3, 100, false, 3));
    allModules.push_back(Module(13, allLecturers[10], "CS200", 3, 100, false, 3));
    allModules.push_back(Module(14, allLecturers[0], "CS207", 3, 100, false, 3));
    allModules.push_back(Module(15, allLecturers[29], "MA200", 3, 100, false, 4));
    allModules.push_back(Module(16, allLecturers[21], "PH200", 3, 100, false, 3));

    allModules.push_back(Module(17, allLecturers[6], "CS211", 4, 25, true, 4));
    allModules.push_back(Module(18, allLecturers[9], "CS215", 4, 25, true, 4));
    allModules.push_back(Module(19, allLecturers[28], "MA206", 4, 100, false, 4));
    allModules.push_back(Module(20, allLecturers[21], "PH201", 4, 100, false, 3));
    allModules.push_back(Module(21, allLecturers[26], "AR052", 4, 100, false, 4));
    allModules.push_back(Module(22, allLecturers[25], "EL102", 4, 100, false, 4));

    allModules.push_back(Module(23, allLecturers[7], "CS321", 5, 25, true, 4));
    allModules.push_back(Module(24, allLecturers[2], "CS331", 5, 25, true, 4));
    allModules.push_back(Module(25, allLecturers[9], "CS315", 5, 25, true, 4));
    allModules.push_back(Module(26, allLecturers[27], "CS319", 5, 25, true, 4));

    allModules.push_back(Module(27, allLecturers[12], "CS332", 6, 25, true, 4));
    allModules.push_back(Module(28, allLecturers[7], "CS322", 6, 25, true, 4));
    allModules.push_back(Module(29, allLecturers[2], "CS336", 6, 25, true, 4));
    allModules.push_back(Module(30, allLecturers[13], "CS340", 6, 25, true, 4));
    allModules.push_back(Module(31, allLecturers[10], "CS355", 6, 25, true, 4));

    allModules.push_back(Module(32, allLecturers[5], "CS443", 7, 25, true, 4));
    allModules.push_back(Module(33, allLecturers[12], "CS437", 7, 25, true, 4));
    allModules.push_back(Module(34, allLecturers[8], "CS431", 7, 25, true, 4));
    allModules.push_back(Module(35, allLecturers[3], "CS456", 7, 25, true, 4));

    allModules.push_back(Module(36, allLecturers[3], "CS436", 8, 25, true, 4));
    allModules.push_back(Module(37, allLecturers[11], "CS438", 8, 100, false, 4));
    allModules.push_back(Module(38, allLecturers[27], "CS115 (1)", 3, 25, true, 2));
    allModules.push_back(Module(39, allLecturers[15], "CS115 (2)", 3, 25, true, 2));
    allModules.push_back(Module(40, allLecturers[15], "CS115 (3)", 3, 25, true, 2));
    allModules.push_back(Module(41, allLecturers[15], "CS200 (1)", 3, 25, true, 2));
    allModules.push_back(Module(42, allLecturers[15], "CS200 (2)", 3, 25, true, 2));
    allModules.push_back(Module(43, allLecturers[16], "CS207 (1)", 3, 25, true, 2));
    allModules.push_back(Module(44, allLecturers[16], "CS207 (2)", 3, 25, true, 2));
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

// Helper function to trim whitespace from strings
void trimString(std::string &str)
{
    size_t first = str.find_first_not_of(" \t\n");
    size_t last = str.find_last_not_of(" \t\n");
    if (first != std::string::npos && last != std::string::npos)
    {
        str = str.substr(first, (last - first + 1));
    }
    else if (first != std::string::npos)
    {
        str = str.substr(first);
    }
}

bool parseBool(const string &str)
{
    std::istringstream iss(str.substr(str.find(':') + 1));
    std::string value;
    iss >> value;
    return value == "1" || value == "Yes";
}

TimeSlot getTimeSlotById(int timeSlotId)
{
    // Assuming allTimeSlots is a global vector containing all TimeSlot objects
    for (const TimeSlot &slot : allTimeSlots)
    {
        if (slot.getTimeSlotID() == timeSlotId)
        {
            return slot;
        }
    }

    // Handle the case where the time slot ID is not found
    throw std::runtime_error("Time slot ID " + std::to_string(timeSlotId) + " not found.");
}

Lecturer findLecturerByName(const std::string &name)
{
    auto it = std::find_if(allLecturers.begin(), allLecturers.end(),
                           [&name](const Lecturer &lecturer)
                           {
                               return lecturer.getLecturerName() == name;
                           });

    if (it != allLecturers.end())
    {
        // Found the lecturer
        return *it;
    }
    else
    {
        // Lecturer not found, handle this case as needed
        return Lecturer(); // Return a default Lecturer or handle error
    }
}

bool startsWith(const std::string &fullString, const std::string &startingSubstring)
{
    if (fullString.length() < startingSubstring.length())
    {
        return false; // Full string is shorter than the substring to check
    }
    return fullString.substr(0, startingSubstring.length()) == startingSubstring;
}

TimeSlot getRandomTimeSlotFromPreference(const Module &module)
{
    Lecturer lec = module.getLecturer();

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(NULL)));

    // Iterate through the global lecturer preferences
    for (const LecturerTimeSlotPreference &preference : globalLecturerPreferences)
    {
        if (preference.getLecturer().getLecturerID() == lec.getLecturerID())
        {
            const std::vector<TimeSlot> &preferredSlots = preference.getTimeSlots();

            // Check if lecturer has any preferred time slots
            if (!preferredSlots.empty())
            {
                // Generate a random index
                int index = rand() % preferredSlots.size();
                cout << "the slot taken is " << preferredSlots[index].getTimeSlotID();
                return preferredSlots[index];
            }
            break;
        }
    }

    // If no preferred time slots are found, handle accordingly
    // (e.g., throw an exception, return a default time slot, etc.)
}

// after id 20 there is a jump to 23
void initializeLecturerTimeSlotPreference()
{
    globalLecturerPreferences.push_back(LecturerTimeSlotPreference(allLecturers[2],
                                                                   {allTimeSlots[0],
                                                                    allTimeSlots[1],
                                                                    allTimeSlots[8],
                                                                    allTimeSlots[9],
                                                                    allTimeSlots[16],
                                                                    allTimeSlots[17],
                                                                    allTimeSlots[22],
                                                                    allTimeSlots[23],
                                                                    allTimeSlots[30],
                                                                    allTimeSlots[31],
                                                                    allTimeSlots[38],
                                                                    allTimeSlots[39]},
                                                                   0));
}

int extractLastSlotId(const std::string &message)
{
    std::string delimiter = "last slot ID of previous module: ";
    size_t startPos = message.find(delimiter);
    if (startPos != std::string::npos)
    {
        startPos += delimiter.length();              // Move start position to the beginning of the number
        size_t endPos = message.find(';', startPos); // Find the end of the number
        // If no semicolon is found, endPos will be npos, and substr will go to the end of the string
        std::string slotIdStr = message.substr(startPos, endPos - startPos);
        std::cout << "Extracted slot ID string: " << slotIdStr << std::endl;
        return std::stoi(slotIdStr); // Convert extracted string to integer
    }
    return -1; // Return an invalid value if the ID is not found
}
