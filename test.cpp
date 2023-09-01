#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib> // for std::rand and std::srand
#include <ctime>   // for std::time
#include <algorithm>
#include <random> // for random functions

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
    allModules.push_back(Module(1, allLecturers[13], "CS100", 1, 100, false));
    allModules.push_back(Module(2, allLecturers[2], "CS111", 1, 95, false));
    allModules.push_back(Module(3, allLecturers[7], "CS115", 1, 85, false));
    allModules.push_back(Module(4, allLecturers[10], "CS200", 2, 30, true));
    allModules.push_back(Module(5, allLecturers[0], "CS207", 2, 25, true));
    allModules.push_back(Module(6, allLecturers[6], "CS211", 2, 30, true));
    allModules.push_back(Module(7, allLecturers[1], "CS215", 2, 30, true));
    allModules.push_back(Module(8, allLecturers[11], "CS315", 3, 27, true));
    allModules.push_back(Module(9, allLecturers[10], "CS319", 3, 26, true));
    allModules.push_back(Module(10, allLecturers[14], "CS321", 3, 20, true));
    allModules.push_back(Module(11, allLecturers[14], "CS322", 3, 24, true));
    allModules.push_back(Module(12, allLecturers[2], "CS331", 3, 22, true));
    allModules.push_back(Module(13, allLecturers[12], "CS332", 3, 23, true));
    allModules.push_back(Module(14, allLecturers[4], "CS336", 3, 18, true));
    allModules.push_back(Module(15, allLecturers[13], "CS340", 3, 17, true));
    allModules.push_back(Module(17, allLecturers[3], "CS436", 4, 15, true));
    allModules.push_back(Module(18, allLecturers[5], "CS443", 4, 13, true));
    allModules.push_back(Module(30, allLecturers[3], "CS456", 4, 14, true));
    allModules.push_back(Module(31, allLecturers[8], "CS431", 4, 16, true));
    allModules.push_back(Module(33, allLecturers[12], "CS437", 4, 19, true));
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
        double fitness = 0.0; // Start with a base fitness value of 0 (perfect score)

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
                fitness += (entry.second - 1) * 10; // Adding 10 for each extra module in the same slot and venue
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
                fitness += (entry.second - 1) * 10; // Adding 10 for each extra module in the same level and time slot
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
                fitness += (entry.second - 1) * 10; // Adding 10 for each extra module for the same lecturer and time slot
            }
        }
        ////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////constraint no4///////////////////////////////////

        // Check if each module is scheduled in a venue with adequate seating
        for (const ScheduledModule &gene : genes)
        {
            int venueCapacity = gene.getVenue().getCapacity();
            int numberOfStudents = gene.getModule().getNumberOfStudentsEnrolled();
            if (numberOfStudents > venueCapacity)
            {
                fitness += (numberOfStudents - venueCapacity) * 10; // Adding 10 for each extra student
            }
        }
        ////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////constraint no5///////////////////////////////////
        // Check if each module is scheduled in an appropriate venue type
        for (const ScheduledModule &gene : genes)
        {
            bool moduleIsLab = gene.getModule().getIsLab();
            bool venueIsLab = gene.getVenue().getIsLab();
            if (moduleIsLab != venueIsLab)
            {
                fitness += 15; // Flat penalty for mismatched types
            }
        }
        ////////////////////////////////////////////////////////////////////////////////

        // ... (evaluate other constraints here)

        return fitness;
    }
};

std::vector<Chromosome> initialPopulation;
int POPULATION_SIZE = 100; // This is a global variable

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

TimeSlot getRandomTimeSlot(const TimeSlot &exclude)
{
    static bool initialized = false;
    if (!initialized)
    {
        std::srand(std::time(nullptr));
        initialized = true;
    }

    std::vector<TimeSlot> selectableSlots = allTimeSlots; // Assume allTimeSlots is your global vector of TimeSlots

    // Remove the excluded TimeSlot from selectableSlots
    selectableSlots.erase(
        std::remove_if(
            selectableSlots.begin(),
            selectableSlots.end(),
            [&exclude](const TimeSlot &slot)
            { return slot.getTimeSlotID() == exclude.getTimeSlotID(); }),
        selectableSlots.end());

    if (selectableSlots.empty())
    {
        // Handle the case where no time slots are available.
        // This should never happen if 'exclude' is guaranteed to be in 'allTimeSlots'.
        throw std::runtime_error("No available time slots!");
    }

    int randomIndex = std::rand() % selectableSlots.size(); // Generate a random index
    return selectableSlots[randomIndex];                    // Return a random TimeSlot from selectableSlots
}

Venue getRandomVenue()
{
    static bool initialized = false;
    if (!initialized)
    {
        std::srand(std::time(nullptr));
        initialized = true;
    }

    int randomIndex = std::rand() % allVenues.size(); // Generate a random index
    return allVenues[randomIndex];                    // Return a random Venue from allVenues
}

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

    // Add a vector of chromosomes to the population
    void addChromosomes(const std::vector<Chromosome> &newChromosomes)
    {
        chromosomes.insert(chromosomes.end(), newChromosomes.begin(), newChromosomes.end());
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

    // Initialize the first population
    void initializeFirstPopulation()
    {
        for (int i = 0; i < POPULATION_SIZE; ++i)
        {
            Chromosome chromosome;

            for (const auto &module : allModules)
            {
                // Schedule this module twice, as each module has 4 hours per week.

                // Randomly select two different time slots for this module
                TimeSlot timeSlot1 = getRandomTimeSlot();
                TimeSlot timeSlot2 = getRandomTimeSlot(timeSlot1); // Make sure this is different from timeSlot1

                // Randomly select a venue for this module
                Venue venue = getRandomVenue();

                // Create two ScheduledModule objects
                ScheduledModule scheduledModule1(module, timeSlot1, venue, false, false, true);
                ScheduledModule scheduledModule2(module, timeSlot2, venue, false, false, true);

                // Add these ScheduledModule objects to the chromosome
                chromosome.addGene(scheduledModule1);
                chromosome.addGene(scheduledModule2);
            }

            // Add this chromosome to the initial population
            addChromosome(chromosome);
        }
    }

    std::vector<Chromosome> getBestNChromosomes(int n)
    {
        std::vector<Chromosome> sortedChromosomes = chromosomes;
        std::sort(sortedChromosomes.begin(), sortedChromosomes.end(),
                  [](Chromosome &a, Chromosome &b)
                  {
                      return a.evaluateFitness() < b.evaluateFitness(); // Assuming lower fitness is better
                  });
        return std::vector<Chromosome>(sortedChromosomes.begin(), sortedChromosomes.begin() + n);
    }

    // Other methods for selection, crossover, mutation, evaluation, etc. can be added here
};

class GeneticAlgorithm
{
private:
    Population population; // The current population
    double mutationRate;   // Mutation rate
    double crossoverRate;  // Crossover rate
    int eliteCount;        // Number of elite chromosomes to keep in each generation

public:
    // Parameterized Constructor
    GeneticAlgorithm(const Population &initialPopulation, double mutationRate, double crossoverRate, int eliteCount)
        : population(initialPopulation), mutationRate(mutationRate), crossoverRate(crossoverRate), eliteCount(eliteCount) {}

    // Getter and Setter methods for mutationRate, crossoverRate, eliteCount (optional)

    Population selectParents()
    {
        std::vector<Chromosome> selectedParents;
        int tournamentSize = 5; // You can change this

        for (int i = 0; i < population.getChromosomes().size() - eliteCount; ++i) // Leave space for elites
        {
            std::vector<Chromosome> tournament;

            // Randomly select k individuals for the tournament
            for (int j = 0; j < tournamentSize; ++j)
            {
                int index = std::rand() % population.getChromosomes().size();
                tournament.push_back(population.getChromosomes()[index]);
            }

            // Find the best individual in the tournament
            Chromosome best = *std::min_element(
                tournament.begin(), tournament.end(),
                [](Chromosome &a, Chromosome &b)
                {
                    return a.evaluateFitness() < b.evaluateFitness(); // Assuming lower fitness is better
                });

            // Add the winner to the list of parents
            selectedParents.push_back(best);
        }

        return Population(selectedParents);
    }

    // Method for Crossover
    Chromosome crossover(const Chromosome &parent1, const Chromosome &parent2)
    {
        // Implement the crossover logic here
    }

    // Method for Mutation
    void mutate(Chromosome &chromosome)
    {
        // Implement the mutation logic here
    }

    // Method for Replacement
    void replacePopulation(const Population &newPopulation)
    {
        // Implement the replacement logic here
    }

    void runOneGeneration()
    {
        // 1. Elitism
        std::vector<Chromosome> elites = population.getBestNChromosomes(eliteCount);

        // 2. Selection
        Population parents = selectParents();
        parents.addChromosomes(elites); // Add elites

        // 3. Crossover and Mutation
        Population offspring;
        for (int i = 0; i < parents.getChromosomes().size(); i += 2)
        {
            Chromosome child = crossover(parents.getChromosomes()[i], parents.getChromosomes()[i + 1]);
            mutate(child);
            offspring.addChromosome(child);
        }

        // 4. Replacement
        replacePopulation(offspring);
    }

    // Method to run the Genetic Algorithm for 'n' generations
    void run(int numberOfGenerations)
    {
        for (int i = 0; i < numberOfGenerations; ++i)
        {
            runOneGeneration();
        }
    }

    // ... (other utility methods)
};

void printViolations(const Chromosome &chromosome)
{
    std::map<std::pair<int, int>, int> venueTimeSlotCount, levelTimeSlotCount, lecturerTimeSlotCount;

    for (const ScheduledModule &gene : chromosome.getGenes())
    {
        int venueID = gene.getVenue().getVenueID();
        int timeSlotID = gene.getTimeSlot().getTimeSlotID();
        venueTimeSlotCount[std::make_pair(venueID, timeSlotID)]++;

        int level = gene.getModule().getLevel();
        levelTimeSlotCount[std::make_pair(level, timeSlotID)]++;

        int lecturerID = gene.getModule().getLecturer().getLecturerID();
        lecturerTimeSlotCount[std::make_pair(lecturerID, timeSlotID)]++;
    }

    // Check for violations and print them
    for (const auto &entry : venueTimeSlotCount)
    {
        if (entry.second > 1)
        {
            std::cout << "Violation: More than one module in the same slot and venue. VenueID: " << entry.first.first << ", TimeSlotID: " << entry.first.second << std::endl;
        }
    }

    for (const auto &entry : levelTimeSlotCount)
    {
        if (entry.second > 1)
        {
            std::cout << "Violation: More than one module at the same level and time slot. Level: " << entry.first.first << ", TimeSlotID: " << entry.first.second << std::endl;
        }
    }

    for (const auto &entry : lecturerTimeSlotCount)
    {
        if (entry.second > 1)
        {
            std::cout << "Violation: More than one module for the same lecturer and time slot. LecturerID: " << entry.first.first << ", TimeSlotID: " << entry.first.second << std::endl;
        }
    }
}

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

    POPULATION_SIZE = 1;

    // Step 2: Initialize the First Population
    Population initialPop;
    initialPop.initializeFirstPopulation();

    // Step 3: Print the Initial Population
    Chromosome initialChromosome = initialPop.getChromosomes()[0]; // Should get the first and only chromosome
    std::cout << "Initial Chromosome: " << std::endl;
    for (const ScheduledModule &gene : initialChromosome.getGenes())
    {
        // Print information about the gene/module, venue, and time slot
        std::cout << "Gene: " << std::endl;
        gene.getModule().printInfo();
        gene.getTimeSlot().printInfo();
        gene.getVenue().printInfo();
    }

    // Step 4: Evaluate Fitness
    double fitness = initialChromosome.evaluateFitness();
    std::cout << "Initial Chromosome Fitness: " << fitness << std::endl;

    // Print violations
    printViolations(initialChromosome);

    return 0;
}
