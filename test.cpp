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
};

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
};

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
};

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
};

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
    // Initialize Lecturers
    Lecturer lecturer1(1, "Dr. Smith");
    Lecturer lecturer2(2, "Dr. Johnson");

    // Initialize TimeSlots
    TimeSlot timeSlot1(1, "Monday", "9:00 AM");
    TimeSlot timeSlot2(2, "Monday", "10:00 AM");
    TimeSlot timeSlot3(3, "Monday", "11:00 AM");

    // Initialize Venues
    Venue venue1(1, "Room A", 45, true); // Capacity 30
    Venue venue2(2, "Room B", 40, true); // Capacity 40

    // Initialize Modules
    Module module1(1, lecturer1, "Math", 1, 25, false);      // 25 students, fits in either venue
    Module module2(2, lecturer2, "Physics", 2, 35, true);    // 35 students, fits in venue2 but not in venue1
    Module module3(3, lecturer2, "Chemistry", 3, 45, false); // 45 students, does not fit in either venue

    // Initialize ScheduledModules
    // All are at different times and different venues, and different lecturers, so constraints 1-3 are met
    ScheduledModule scheduledModule1(module1, timeSlot1, venue1, false, false, true); // Meets all constraints
    ScheduledModule scheduledModule2(module2, timeSlot2, venue1, false, false, true); // Meets all constraints
    ScheduledModule scheduledModule3(module3, timeSlot3, venue1, false, false, true); // Should violate the 4th constraint only

    // Initialize Chromosome
    std::vector<ScheduledModule> genes = {scheduledModule1, scheduledModule2, scheduledModule3};
    Chromosome chromosome(genes);

    // Evaluate Fitness
    double fitness = chromosome.evaluateFitness();

    // Output the fitness value
    std::cout << "Fitness value: " << fitness << std::endl;

    return 0;
}
