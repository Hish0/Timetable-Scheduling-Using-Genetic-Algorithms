#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Lecturer
{
private:
    int lecturerID;
    std::string lecturerName;

public:
    // Default Constructor
    Lecturer() : lecturerID(0), lecturerName("Unknown") {}

    // Parameterized Constructor
    Lecturer(int id, const std::string &name) : lecturerID(id), lecturerName(name) {}

    // Getter methods
    int getLecturerID() const
    {
        return lecturerID;
    }

    std::string getLecturerName() const
    {
        return lecturerName;
    }

    // Setter methods
    void setLecturerID(int id)
    {
        lecturerID = id;
    }

    void setLecturerName(const std::string &name)
    {
        lecturerName = name;
    }

    void printInfo() const
    {
        std::cout << "Lecturer ID: " << lecturerID << ", Name: " << lecturerName << std::endl;
    }
};

std::vector<Lecturer> allLecturers; // Global array to hold all lecturers

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

class TimeSlot
{
private:
    int timeSlotID;
    std::string day;
    std::string time;

public:
    // Default Constructor
    TimeSlot() : timeSlotID(0), day("Unknown"), time("00:00") {}

    // Parameterized Constructor
    TimeSlot(int id, const std::string &dayValue, const std::string &timeValue)
        : timeSlotID(id), day(dayValue), time(timeValue) {}

    // Getter methods
    int getTimeSlotID() const
    {
        return timeSlotID;
    }

    std::string getDay() const
    {
        return day;
    }

    std::string getTime() const
    {
        return time;
    }

    // Setter methods
    void setTimeSlotID(int id)
    {
        timeSlotID = id;
    }

    void setDay(const std::string &dayValue)
    {
        day = dayValue;
    }

    void setTime(const std::string &timeValue)
    {
        time = timeValue;
    }

    void printInfo() const
    {
        std::cout << "TimeSlot ID: " << timeSlotID << ", Day: " << day << ", Time: " << time << std::endl;
    }
};

std::vector<TimeSlot> allTimeSlots; // Global array to hold all time slots
void initializeTimeSlots()
{
    // Days of the week
    std::vector<std::string> days = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};

    // Time intervals
    std::vector<std::string> times = {"8:00 AM", "10:00 AM", "12:00 PM", "2:00 PM"};

    int id = 1; // Unique ID for each time slot

    for (const auto &day : days)
    {
        for (const auto &time : times)
        {
            allTimeSlots.push_back(TimeSlot(id++, day, time));
        }
    }
}

class Module
{
private:
    int moduleID;
    Lecturer lecturer;
    std::string name;
    int level; // Changed from std::string to int
    int numberOfStudentsEnrolled;
    bool isLab;

public:
    // Default Constructor
    Module() : moduleID(0), lecturer(), name("Unknown"), level(0), numberOfStudentsEnrolled(0), isLab(false) {}

    // Parameterized Constructor - Changed modLevel from std::string to int
    Module(int modID, const Lecturer &lect, const std::string &modName, int modLevel, int students, bool lab)
        : moduleID(modID), lecturer(lect), name(modName), level(modLevel), numberOfStudentsEnrolled(students), isLab(lab) {}

    // Getter methods
    int getModuleID() const
    {
        return moduleID;
    }

    Lecturer getLecturer() const
    {
        return lecturer;
    }

    std::string getName() const
    {
        return name;
    }

    // Changed return type from std::string to int
    int getLevel() const
    {
        return level;
    }

    int getNumberOfStudentsEnrolled() const
    {
        return numberOfStudentsEnrolled;
    }

    bool getIsLab() const
    {
        return isLab;
    }

    // Setter methods
    void setModuleID(int id)
    {
        moduleID = id;
    }

    void setLecturer(const Lecturer &lect)
    {
        lecturer = lect;
    }

    void setName(const std::string &modName)
    {
        name = modName;
    }

    // Changed parameter type from std::string to int
    void setLevel(int modLevel)
    {
        level = modLevel;
    }

    void setNumberOfStudentsEnrolled(int students)
    {
        numberOfStudentsEnrolled = students;
    }

    void setIsLab(bool lab)
    {
        isLab = lab;
    }

    void printInfo() const
    {
        std::cout << "Module ID: " << moduleID
                  << ", Lecturer: " << lecturer.getLecturerName()
                  << ", Name: " << name
                  << ", Level: " << level
                  << ", Enrolled Students: " << numberOfStudentsEnrolled
                  << ", Is Lab: " << (isLab ? "Yes" : "No") << std::endl;
    }
};

std::vector<Module> allModules; // Global array to hold all modules

void initializeModules()
{
    // Initialize modules with ID, Lecturer, Name, Level, Number of Students, Is Lab
    allModules.push_back(Module(1, allLecturers[13], "CS100", 1, 50, false));
    allModules.push_back(Module(2, allLecturers[2], "CS111", 1, 45, false));
    allModules.push_back(Module(3, allLecturers[7], "CS115", 1, 40, false));
    allModules.push_back(Module(4, allLecturers[10], "CS200", 2, 35, false));
    allModules.push_back(Module(5, allLecturers[0], "CS207", 2, 30, false));
    allModules.push_back(Module(6, allLecturers[6], "CS211", 2, 25, true));
    allModules.push_back(Module(7, allLecturers[1], "CS215", 2, 40, false));
    allModules.push_back(Module(8, allLecturers[11], "CS315", 3, 45, false));
    allModules.push_back(Module(9, allLecturers[10], "CS319", 3, 40, false));
    allModules.push_back(Module(10, allLecturers[14], "CS321", 3, 50, false));
    allModules.push_back(Module(11, allLecturers[14], "CS322", 3, 45, false));
    allModules.push_back(Module(12, allLecturers[2], "CS331", 3, 40, false));
    allModules.push_back(Module(13, allLecturers[12], "CS332", 3, 35, false));
    allModules.push_back(Module(14, allLecturers[4], "CS336", 3, 30, false));
    allModules.push_back(Module(15, allLecturers[13], "CS340", 3, 25, true));
    allModules.push_back(Module(17, allLecturers[3], "CS436", 4, 45, false));
    allModules.push_back(Module(18, allLecturers[5], "CS443", 4, 40, false));
    allModules.push_back(Module(30, allLecturers[3], "CS456", 4, 25, true));
    allModules.push_back(Module(31, allLecturers[8], "CS431", 4, 40, false));
    allModules.push_back(Module(33, allLecturers[12], "CS437", 4, 40, false));
}

class Venue
{
private:
    int venueID;
    std::string name;
    int capacity;
    bool isLab;

public:
    // Default Constructor
    Venue() : venueID(0), name("Unknown"), capacity(0), isLab(false) {}

    // Parameterized Constructor
    Venue(int id, const std::string &venueName, int cap, bool lab)
        : venueID(id), name(venueName), capacity(cap), isLab(lab) {}

    // Getter methods
    int getVenueID() const
    {
        return venueID;
    }

    std::string getName() const
    {
        return name;
    }

    int getCapacity() const
    {
        return capacity;
    }

    bool getIsLab() const
    {
        return isLab;
    }

    // Setter methods
    void setVenueID(int id)
    {
        venueID = id;
    }

    void setName(const std::string &venueName)
    {
        name = venueName;
    }

    void setCapacity(int cap)
    {
        capacity = cap;
    }

    void setIsLab(bool lab)
    {
        isLab = lab;
    }

    // Method to print Venue information
    void printInfo() const
    {
        std::cout << "Venue ID: " << venueID
                  << ", Name: " << name
                  << ", Capacity: " << capacity
                  << ", Is Lab: " << (isLab ? "Yes" : "No") << std::endl;
    }
};

std::vector<Venue> allVenues; // Global array to hold all venues

void initializeVenues()
{
    // Initialize venues with ID, Name, Capacity, IsLab
    allVenues.push_back(Venue(1, "LAB 1", 20, true));
    allVenues.push_back(Venue(2, "LAB 2", 20, true));
    allVenues.push_back(Venue(3, "LAB 3", 20, true));
    allVenues.push_back(Venue(4, "LAB 4", 20, true));
    allVenues.push_back(Venue(5, "LAB 5", 20, true));
    allVenues.push_back(Venue(6, "HALL 70", 200, false));
    allVenues.push_back(Venue(7, "HALL 71", 200, false));
    allVenues.push_back(Venue(8, "HALL 72", 200, false));
    // ... add more venues as needed
}

class LecturerTimeSlotPreference
{
private:
    Lecturer lecturer;
    TimeSlot timeSlot;
    int rank; // Preference rank (e.g., 1 for most preferred, 2 for second most preferred, etc.)

public:
    // Default Constructor
    LecturerTimeSlotPreference() : lecturer(), timeSlot(), rank(0) {}

    // Parameterized Constructor
    LecturerTimeSlotPreference(const Lecturer &lect, const TimeSlot &slot, int r)
        : lecturer(lect), timeSlot(slot), rank(r) {}

    // Getter methods
    Lecturer getLecturer() const
    {
        return lecturer;
    }

    TimeSlot getTimeSlot() const
    {
        return timeSlot;
    }

    int getRank() const
    {
        return rank;
    }

    // Setter methods
    void setLecturer(const Lecturer &lect)
    {
        lecturer = lect;
    }

    void setTimeSlot(const TimeSlot &slot)
    {
        timeSlot = slot;
    }

    void setRank(int r)
    {
        rank = r;
    }
};

class ScheduledModule
{
private:
    Module module;
    TimeSlot timeSlot;
    Venue venue;
    bool isLockedVenue;
    bool isLockedTimeSlot;
    bool isValid;

public:
    // Default Constructor
    ScheduledModule()
        : module(), timeSlot(), venue(), isLockedVenue(false), isLockedTimeSlot(false), isValid(false) {}

    // Parameterized Constructor
    ScheduledModule(const Module &mod, const TimeSlot &slot, const Venue &ven,
                    bool lockedVenue, bool lockedTimeSlot, bool validStatus)
        : module(mod), timeSlot(slot), venue(ven), isLockedVenue(lockedVenue),
          isLockedTimeSlot(lockedTimeSlot), isValid(validStatus) {}

    // Getter methods
    Module getModule() const
    {
        return module;
    }

    TimeSlot getTimeSlot() const
    {
        return timeSlot;
    }

    Venue getVenue() const
    {
        return venue;
    }

    bool getIsLockedVenue() const
    {
        return isLockedVenue;
    }

    bool getIsLockedTimeSlot() const
    {
        return isLockedTimeSlot;
    }

    bool getIsValid() const
    {
        return isValid;
    }

    // Setter methods
    void setModule(const Module &mod)
    {
        module = mod;
    }

    void setTimeSlot(const TimeSlot &slot)
    {
        timeSlot = slot;
    }

    void setVenue(const Venue &ven)
    {
        venue = ven;
    }

    void setIsLockedVenue(bool lockedVenue)
    {
        isLockedVenue = lockedVenue;
    }

    void setIsLockedTimeSlot(bool lockedTimeSlot)
    {
        isLockedTimeSlot = lockedTimeSlot;
    }

    void setIsValid(bool validStatus)
    {
        isValid = validStatus;
    }
};

class Chromosome
{
private:
    std::vector<ScheduledModule> genes; // A chromosome is made up of genes

public:
    // Constructor
    Chromosome() {}

    // Parameterized Constructor
    Chromosome(const std::vector<ScheduledModule> &genes) : genes(genes) {}

    // Add a gene to the chromosome
    void addGene(const ScheduledModule &gene)
    {
        genes.push_back(gene);
    }

    // Get all genes
    std::vector<ScheduledModule> getGenes() const
    {
        return genes;
    }

    // Set all genes
    void setGenes(const std::vector<ScheduledModule> &newGenes)
    {
        genes = newGenes;
    }
    double evaluateFitness()
    {
        ///////////////////////////////constraint no1///////////////////////////////////
        double fitness = 1.0; // Start with a base fitness value

        // Initialize a map to hold the count of modules scheduled in each venue for each time slot
        std::map<std::pair<int, int>, int> venueTimeSlotCount;

        for (const ScheduledModule &gene : genes)
        {
            Venue venue = gene.getVenue();
            TimeSlot timeSlot = gene.getTimeSlot();

            int venueID = venue.getVenueID();          // Assuming Venue has a getID() method that returns a unique identifier
            int timeSlotID = timeSlot.getTimeSlotID(); // Assuming TimeSlot has a getID() method that returns a unique identifier

            // Create a pair of venueID and timeSlotID
            std::pair<int, int> venueTimeSlotPair = std::make_pair(venueID, timeSlotID);

            // Increment the count for this venue and time slot
            venueTimeSlotCount[venueTimeSlotPair]++;
        }

        // Check for violations of the first constraint
        for (const auto &entry : venueTimeSlotCount)
        {
            if (entry.second > 1)
            {
                std::cout << "Violation in Constraint 1: VenueID = " << entry.first.first
                          << ", TimeSlotID = " << entry.first.second
                          << ", Count = " << entry.second << std::endl;
                return 0.0;
            }
        }
        ////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////constraint no2///////////////////////////////////

        // Initialize a map to hold the count of modules scheduled at each level for each time slot
        std::map<std::pair<int, int>, int> levelTimeSlotCount;

        for (const ScheduledModule &gene : genes)
        {
            int level = gene.getModule().getLevel(); // Assuming getLevel() returns an integer
            int timeSlotID = gene.getTimeSlot().getTimeSlotID();

            // Create a pair of level and timeSlotID
            std::pair<int, int> levelTimeSlotPair = std::make_pair(level, timeSlotID);

            // Increment the count for this level and time slot
            levelTimeSlotCount[levelTimeSlotPair]++;
        }

        // Check for violations of the second constraint
        for (const auto &entry : levelTimeSlotCount)
        {
            if (entry.second > 1)
            {
                std::cout << "Violation in Constraint 2: Level = " << entry.first.first
                          << ", TimeSlotID = " << entry.first.second
                          << ", Count = " << entry.second << std::endl;
                return 0.0;
            }
        }
        ////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////constraint no3///////////////////////////////////

        // Initialize a map to hold the count of modules scheduled for each lecturer for each time slot
        std::map<std::pair<int, int>, int> lecturerTimeSlotCount;

        for (const ScheduledModule &gene : genes)
        {
            int lecturerID = gene.getModule().getLecturer().getLecturerID(); // Assuming getLecturerID() returns an integer ID for the lecturer
            int timeSlotID = gene.getTimeSlot().getTimeSlotID();

            // Create a pair of lecturerID and timeSlotID
            std::pair<int, int> lecturerTimeSlotPair = std::make_pair(lecturerID, timeSlotID);

            // Increment the count for this lecturer and time slot
            lecturerTimeSlotCount[lecturerTimeSlotPair]++;
        }

        // Check for violations of the third constraint
        for (const auto &entry : lecturerTimeSlotCount)
        {
            if (entry.second > 1)
            {
                std::cout << "Violation in Constraint 3: LecturerID = " << entry.first.first
                          << ", TimeSlotID = " << entry.first.second
                          << ", Count = " << entry.second << std::endl;
                return 0.0;
            }
        }
        ////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////constraint no4///////////////////////////////////

        // Check if each module is scheduled in a venue with adequate seating
        for (const ScheduledModule &gene : genes)
        {
            int venueCapacity = gene.getVenue().getCapacity();                     // Assuming getCapacity() returns the seating capacity of the venue
            int numberOfStudents = gene.getModule().getNumberOfStudentsEnrolled(); // Assuming getNumberOfStudentsEnrolled() returns the number of students enrolled in the module

            if (numberOfStudents > venueCapacity)
            {
                // Violation: The module is scheduled in a venue that does not have adequate seating
                std::cout << "Violation in Constraint 4: VenueCapacity = " << venueCapacity
                          << ", NumberOfStudents = " << numberOfStudents << std::endl;
                return 0.0; // Set fitness to zero or another very low value
            }
        }
        ////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////constraint no5///////////////////////////////////
        // Check if each module is scheduled in an appropriate venue type
        for (const ScheduledModule &gene : genes)
        {
            bool moduleIsLab = gene.getModule().getIsLab(); // Assuming getIsLab() returns the boolean value for the module
            bool venueIsLab = gene.getVenue().getIsLab();   // Assuming getIsLab() returns the boolean value for the venue

            if (moduleIsLab != venueIsLab)
            {
                // Violation: The module and the venue have mismatched types
                std::cout << "Violation in Constraint 5: ModuleIsLab = " << moduleIsLab
                          << ", VenueIsLab = " << venueIsLab << std::endl;
                return 0.0; // Set fitness to zero or another very low value
            }
        }
        ////////////////////////////////////////////////////////////////////////////////

        // ... (evaluate other constraints here)

        return fitness;
    }
};

class Population
{
private:
    std::vector<Chromosome> chromosomes; // The population is made up of chromosomes

public:
    // Constructor
    Population() {}

    // Parameterized Constructor
    Population(const std::vector<Chromosome> &initialPopulation) : chromosomes(initialPopulation) {}

    // Add a chromosome to the population
    void addChromosome(const Chromosome &chromosome)
    {
        chromosomes.push_back(chromosome);
    }

    // Get all chromosomes
    std::vector<Chromosome> getChromosomes() const
    {
        return chromosomes;
    }

    // Set all chromosomes
    void setChromosomes(const std::vector<Chromosome> &newChromosomes)
    {
        chromosomes = newChromosomes;
    }

    // Other methods for selection, crossover, mutation, evaluation, etc. can be added here
};

int main()
{
    // Initialize time slots
    initializeTimeSlots();

    // Initialize venues
    initializeVenues();

    // Initialize lecturers
    initializeLecturers();

    // Initialize modules
    initializeModules();

    // Print the initialized time slots
    for (const auto &timeSlot : allTimeSlots)
    {
        timeSlot.printInfo();
    }

    // Print information about each venue for testing
    for (const Venue &venue : allVenues)
    {
        venue.printInfo();
    }

    // Print information about each lecturer for testing
    for (const Lecturer &lecturer : allLecturers)
    {
        lecturer.printInfo();
    }

    // Print information about each module for testing
    for (const Module &module : allModules)
    {
        module.printInfo();
    }

    return 0;
}
