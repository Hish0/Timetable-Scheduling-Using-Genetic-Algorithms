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

        // Check for violations
        for (const auto &entry : venueTimeSlotCount)
        {
            if (entry.second > 1)
            {
                // Violation: More than one module is scheduled in the same venue during the same time slot
                return 0.0; // Set fitness to zero or another very low value
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

        // Check for violations
        for (const auto &entry : levelTimeSlotCount)
        {
            if (entry.second > 1)
            {
                // Violation: More than one module at the same level is scheduled during the same time slot
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
    Venue venue1(1, "Room A", 30, false);
    Venue venue2(2, "Room B", 40, true);
    Venue venue3(3, "Room s", 40, true);

    // Initialize Modules
    Module module1(1, lecturer1, "Math", 1, 25, false);      // Level 1
    Module module2(2, lecturer2, "Physics", 1, 35, true);    // Level 1
    Module module3(3, lecturer2, "Chemistry", 2, 35, false); // Level 2

    // Initialize ScheduledModules
    ScheduledModule scheduledModule1(module1, timeSlot3, venue1, false, false, true); // Should violate the first constraint
    ScheduledModule scheduledModule2(module2, timeSlot1, venue3, false, false, true); // Should violate the first constraint
    ScheduledModule scheduledModule3(module2, timeSlot2, venue1, false, false, true);
    ScheduledModule scheduledModule4(module3, timeSlot1, venue2, false, false, true);

    // Initialize Chromosome
    std::vector<ScheduledModule> genes = {scheduledModule1, scheduledModule2, scheduledModule3, scheduledModule4};
    Chromosome chromosome(genes);

    // Evaluate Fitness
    double fitness = chromosome.evaluateFitness();

    // Output the fitness value
    std::cout << "Fitness value: " << fitness << std::endl;

    return 0;
}
