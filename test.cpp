#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib> // for rand and srand
#include <ctime>   // for time
#include <algorithm>
#include <random> // for random functions

using namespace std;

class Lecturer
{
private:
    int lecturerID;
    string lecturerName;

public:
    // Default Constructor
    Lecturer() : lecturerID(0), lecturerName("Unknown") {}

    // Parameterized Constructor
    Lecturer(int id, const string &name) : lecturerID(id), lecturerName(name) {}

    // Getter methods
    int getLecturerID() const
    {
        return lecturerID;
    }

    string getLecturerName() const
    {
        return lecturerName;
    }

    // Setter methods
    void setLecturerID(int id)
    {
        lecturerID = id;
    }

    void setLecturerName(const string &name)
    {
        lecturerName = name;
    }

    void printInfo() const
    {
        cout << "Lecturer ID: " << lecturerID << ", Name: " << lecturerName << endl;
    }
};

vector<Lecturer> allLecturers; // Global array to hold all lecturers

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
    string day;
    string time;

public:
    // Default Constructor
    TimeSlot() : timeSlotID(0), day("Unknown"), time("00:00") {}

    // Parameterized Constructor
    TimeSlot(int id, const string &dayValue, const string &timeValue)
        : timeSlotID(id), day(dayValue), time(timeValue) {}

    // Getter methods
    int getTimeSlotID() const
    {
        return timeSlotID;
    }

    string getDay() const
    {
        return day;
    }

    string getTime() const
    {
        return time;
    }

    // Setter methods
    void setTimeSlotID(int id)
    {
        timeSlotID = id;
    }

    void setDay(const string &dayValue)
    {
        day = dayValue;
    }

    void setTime(const string &timeValue)
    {
        time = timeValue;
    }

    void printInfo() const
    {
        cout << "TimeSlot ID: " << timeSlotID << ", Day: " << day << ", Time: " << time << endl;
    }

    bool isEmpty() const
    {
        // Define logic to determine if the TimeSlot object is empty
        return this->getDay().empty() && (this->getTimeSlotID() == 0); // Example logic
    }
};

vector<TimeSlot> allTimeSlots; // Global array to hold all time slots
void initializeTimeSlots()
{
    // Days of the week
    vector<string> days = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};

    // Time intervals
    vector<string> times = {"8:00 AM", "10:00 AM", "12:00 PM", "2:00 PM"};

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
    string name;
    int level; // Changed from string to int
    int numberOfStudentsEnrolled;
    bool isLab;

public:
    // Default Constructor
    Module() : moduleID(0), lecturer(), name("Unknown"), level(0), numberOfStudentsEnrolled(0), isLab(false) {}

    // Parameterized Constructor - Changed modLevel from string to int
    Module(int modID, const Lecturer &lect, const string &modName, int modLevel, int students, bool lab)
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

    string getName() const
    {
        return name;
    }

    // Changed return type from string to int
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

    void setName(const string &modName)
    {
        name = modName;
    }

    // Changed parameter type from string to int
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
        cout << "Module ID: " << moduleID
             << ", Lecturer: " << lecturer.getLecturerName()
             << ", Name: " << name
             << ", Level: " << level
             << ", Enrolled Students: " << numberOfStudentsEnrolled
             << ", Is Lab: " << (isLab ? "Yes" : "No") << endl;
    }
};

vector<Module> allModules; // Global array to hold all modules

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
    string name;
    int capacity;
    bool isLab;

public:
    // Default Constructor
    Venue() : venueID(0), name("Unknown"), capacity(0), isLab(false) {}

    // Parameterized Constructor
    Venue(int id, const string &venueName, int cap, bool lab)
        : venueID(id), name(venueName), capacity(cap), isLab(lab) {}

    // Getter methods
    int getVenueID() const
    {
        return venueID;
    }

    string getName() const
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

    void setName(const string &venueName)
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
        cout << "Venue ID: " << venueID
             << ", Name: " << name
             << ", Capacity: " << capacity
             << ", Is Lab: " << (isLab ? "Yes" : "No") << endl;
    }
};

vector<Venue> allVenues; // Global array to hold all venues

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
    vector<ScheduledModule> genes; // A chromosome is made up of genes

public:
    // Constructor
    Chromosome() {}

    // Parameterized Constructor
    Chromosome(const vector<ScheduledModule> &genes) : genes(genes) {}

    // Add a gene to the chromosome
    void addGene(const ScheduledModule &gene)
    {
        genes.push_back(gene);
    }

    // Get all genes
    vector<ScheduledModule> getGenes() const
    {
        return genes;
    }

    // Set all genes
    void setGenes(const vector<ScheduledModule> &newGenes)
    {
        genes = newGenes;
    }
    double evaluateFitness()
    {
        ///////////////////////////////constraint no1///////////////////////////////////
        double fitness = 0.0; // Start with a base fitness value of 0 (perfect score)

        // Initialize a map to hold the count of modules scheduled in each venue for each time slot
        map<pair<int, int>, int> venueTimeSlotCount;

        for (const ScheduledModule &gene : genes)
        {
            Venue venue = gene.getVenue();
            TimeSlot timeSlot = gene.getTimeSlot();

            int venueID = venue.getVenueID();          // Assuming Venue has a getID() method that returns a unique identifier
            int timeSlotID = timeSlot.getTimeSlotID(); // Assuming TimeSlot has a getID() method that returns a unique identifier

            // Create a pair of venueID and timeSlotID
            pair<int, int> venueTimeSlotPair = make_pair(venueID, timeSlotID);

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
        map<pair<int, int>, int> levelTimeSlotCount;

        for (const ScheduledModule &gene : genes)
        {
            int level = gene.getModule().getLevel(); // Assuming getLevel() returns an integer
            int timeSlotID = gene.getTimeSlot().getTimeSlotID();

            // Create a pair of level and timeSlotID
            pair<int, int> levelTimeSlotPair = make_pair(level, timeSlotID);

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
        map<pair<int, int>, int> lecturerTimeSlotCount;

        for (const ScheduledModule &gene : genes)
        {
            int lecturerID = gene.getModule().getLecturer().getLecturerID(); // Assuming getLecturerID() returns an integer ID for the lecturer
            int timeSlotID = gene.getTimeSlot().getTimeSlotID();

            // Create a pair of lecturerID and timeSlotID
            pair<int, int> lecturerTimeSlotPair = make_pair(lecturerID, timeSlotID);

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

vector<Chromosome> initialPopulation;

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
        srand(time(nullptr));
        initialized = true;
    }

    vector<TimeSlot> selectableSlots = allTimeSlots; // Assume allTimeSlots is your global vector of TimeSlots

    // Remove the excluded TimeSlot from selectableSlots
    selectableSlots.erase(
        remove_if(
            selectableSlots.begin(),
            selectableSlots.end(),
            [&exclude](const TimeSlot &slot)
            { return slot.getTimeSlotID() == exclude.getTimeSlotID(); }),
        selectableSlots.end());

    if (selectableSlots.empty())
    {
        // Handle the case where no time slots are available.
        // This should never happen if 'exclude' is guaranteed to be in 'allTimeSlots'.
        throw runtime_error("No available time slots!");
    }

    int randomIndex = rand() % selectableSlots.size(); // Generate a random index
    return selectableSlots[randomIndex];               // Return a random TimeSlot from selectableSlots
}

Venue getRandomVenue()
{
    static bool initialized = false;
    if (!initialized)
    {
        srand(time(nullptr));
        initialized = true;
    }

    int randomIndex = rand() % allVenues.size(); // Generate a random index
    return allVenues[randomIndex];               // Return a random Venue from allVenues
}

class Population
{
private:
    vector<Chromosome> chromosomes; // The population is made up of chromosomes

public:
    // Constructor
    Population() {}

    // Parameterized Constructor
    Population(const vector<Chromosome> &initialPopulation) : chromosomes(initialPopulation) {}

    // Add a chromosome to the population
    void addChromosome(const Chromosome &chromosome)
    {
        chromosomes.push_back(chromosome);
    }

    // Add a vector of chromosomes to the population
    void addChromosomes(const vector<Chromosome> &newChromosomes)
    {
        chromosomes.insert(chromosomes.end(), newChromosomes.begin(), newChromosomes.end());
    }

    // Get all chromosomes
    vector<Chromosome> getChromosomes() const
    {
        return chromosomes;
    }

    // Set all chromosomes
    void setChromosomes(const vector<Chromosome> &newChromosomes)
    {
        chromosomes = newChromosomes;
    }

    // Initialize the first population
    void initializeFirstPopulation(int POPULATION_SIZE)
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

    vector<Chromosome> getBestNChromosomes(int n)
    {
        vector<Chromosome> sortedChromosomes = chromosomes;
        sort(sortedChromosomes.begin(), sortedChromosomes.end(),
             [](Chromosome &a, Chromosome &b)
             {
                 return a.evaluateFitness() < b.evaluateFitness(); // Assuming lower fitness is better
             });
        return vector<Chromosome>(sortedChromosomes.begin(), sortedChromosomes.begin() + n);
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
    GeneticAlgorithm(Population &initialPopulation, double mutationRate, double crossoverRate, int eliteCount)
        : population(initialPopulation), mutationRate(mutationRate), crossoverRate(crossoverRate), eliteCount(eliteCount) {}

    // Getter and Setter methods for mutationRate, crossoverRate, eliteCount (optional)

    Population selectParents()
    {
        vector<Chromosome> selectedParents;
        int tournamentSize = 5; // You can change this

        for (int i = 0; i < population.getChromosomes().size() - eliteCount; ++i) // Leave space for elites
        {
            vector<Chromosome> tournament;

            // Randomly select k individuals for the tournament
            for (int j = 0; j < tournamentSize; ++j)
            {
                int index = rand() % population.getChromosomes().size();
                tournament.push_back(population.getChromosomes()[index]);
            }

            // Find the best individual in the tournament
            Chromosome best = *min_element(
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

    Chromosome crossover(const Chromosome &parent1, const Chromosome &parent2)
    {
        Chromosome child1, child2;
        int geneLength = parent1.getGenes().size();

        // Identify valid crossover points (every 2 genes, for example)
        vector<int> crossoverPoints;
        for (int i = 2; i < geneLength; i += 2)
        {
            crossoverPoints.push_back(i);
        }

        // Randomly select two crossover points
        int crossoverIndex1 = crossoverPoints[rand() % crossoverPoints.size()];
        int crossoverIndex2 = crossoverPoints[rand() % crossoverPoints.size()];

        // Sort the indices
        if (crossoverIndex1 > crossoverIndex2)
        {
            swap(crossoverIndex1, crossoverIndex2);
        }

        // Perform crossover to create two children
        for (int i = 0; i < geneLength; ++i)
        {
            if (i < crossoverIndex1 || i >= crossoverIndex2)
            {
                child1.addGene(parent1.getGenes()[i]);
                child2.addGene(parent2.getGenes()[i]);
            }
            else
            {
                child1.addGene(parent2.getGenes()[i]);
                child2.addGene(parent1.getGenes()[i]);
            }
        }

        // Choose one child for the next generation based on fitness (you could also return both)
        if (child1.evaluateFitness() < child2.evaluateFitness())
        {
            return child1;
        }
        else
        {
            return child2;
        }
    }
    // Returns a random venue from the list of all available venues
    Venue getRandomVenue()
    {
        // Assuming `allVenues` is a vector containing all available Venue objects
        int index = rand() % allVenues.size();
        return allVenues[index];
    }

    // Finds a time slot that is empty in all venues for a particular day
    TimeSlot findEmptyTimeSlot(const string &day, const vector<Chromosome> &chromosomes)
    {
        // Let's assume timeSlots is a vector containing all possible TimeSlot objects for a given day
        for (const auto &candidateTimeSlot : allTimeSlots)
        {
            bool isEmpty = true;

            // Loop through all chromosomes and their genes to check if the time slot is empty
            for (const auto &chromosome : chromosomes)
            {
                for (const auto &gene : chromosome.getGenes())
                {
                    if (gene.getTimeSlot().getDay() == day &&
                        gene.getTimeSlot().getTimeSlotID() == candidateTimeSlot.getTimeSlotID())
                    {
                        isEmpty = false;
                        break;
                    }
                }
                if (!isEmpty)
                    break;
            }

            // If we found an empty slot, return it
            if (isEmpty)
                return candidateTimeSlot;
        }

        // If no empty time slot is found, return a default TimeSlot or signal that none was found
        return TimeSlot(); // This could be a special TimeSlot indicating no empty slot was found
    }

    // Gets another time slot that is different from the current one
    TimeSlot getAnotherAvailableTimeSlot(const TimeSlot &current, const vector<TimeSlot> &allTimeSlots)
    {
        vector<TimeSlot> otherSlots;

        // Loop through all available time slots and find one that is different from `current`
        for (const auto &slot : allTimeSlots)
        {
            if (slot.getTimeSlotID() != current.getTimeSlotID())
            {
                otherSlots.push_back(slot);
            }
        }

        // Randomly select one from otherSlots
        int index = rand() % otherSlots.size();
        return otherSlots[index];
    }

    void mutate(Chromosome &chromosome)
    {
        // Assuming `chromosome.getGenes()` returns a reference to the vector of genes
        // vector<ScheduledModule> &genes = chromosome.getGenes();
        vector<ScheduledModule> genes = chromosome.getGenes();

        // Randomly pick one gene to change the venue
        int randomIndexForVenue = rand() % genes.size();
        Venue newVenue = getRandomVenue();
        genes[randomIndexForVenue].setVenue(newVenue);

        // Randomly pick another gene to change the time slot
        int randomIndexForTimeSlot = rand() % genes.size();
        while (randomIndexForTimeSlot == randomIndexForVenue)
        {
            // Ensure we pick a different gene
            randomIndexForTimeSlot = rand() % genes.size();
        }

        string day = genes[randomIndexForTimeSlot].getTimeSlot().getDay();

        // First, try to find an empty time slot
        TimeSlot newTimeSlot = findEmptyTimeSlot(day, population.getChromosomes());

        // If we can't find an empty time slot, get another available time slot
        if (newTimeSlot.isEmpty())
        { // Assuming TimeSlot() returns a special "empty" time slot
            newTimeSlot = getAnotherAvailableTimeSlot(genes[randomIndexForTimeSlot].getTimeSlot(), allTimeSlots);
        }

        genes[randomIndexForTimeSlot].setTimeSlot(newTimeSlot);

        chromosome.setGenes(genes);
    }

    void replacePopulation(const Population &newPopulation)
    {
        vector<Chromosome> newGenes = newPopulation.getChromosomes();
        vector<Chromosome> oldElites = this->population.getBestNChromosomes(eliteCount);

        newGenes.insert(newGenes.end(), oldElites.begin(), oldElites.end());
        this->population.setChromosomes(newGenes);
    }

    void runOneGeneration()
    {
        // 1. Elitism
        vector<Chromosome> elites = population.getBestNChromosomes(eliteCount);

        // 2. Selection
        Population parents = selectParents();
        parents.addChromosomes(elites); // Add elites

        // 3.Crossover and Mutation
        Population offspring;
        for (int i = 0; i < parents.getChromosomes().size(); i += 2)
        {
            double randomValueForCrossover = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
            double randomValueForMutation = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);

            Chromosome child;
            if (randomValueForCrossover <= crossoverRate)
            {
                child = crossover(parents.getChromosomes()[i], parents.getChromosomes()[i + 1]);
            }
            else
            {
                // If not crossing over, add one of the parents to the next generation.
                child = parents.getChromosomes()[i];
            }

            if (randomValueForMutation <= mutationRate)
            {
                mutate(child);
            }

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

    Chromosome getBestChromosome()
    {
        // Assuming that Population::getBestNChromosomes returns the best 'n' chromosomes sorted by fitness
        vector<Chromosome> bestChromosomes = population.getBestNChromosomes(1);

        // Since we asked for only 1 best chromosome, it will be at index 0.
        return bestChromosomes[0];
    }

    // ... (other utility methods)
};

void printViolations(const Chromosome &chromosome)
{
    map<pair<int, int>, int> venueTimeSlotCount, levelTimeSlotCount, lecturerTimeSlotCount;

    for (const ScheduledModule &gene : chromosome.getGenes())
    {
        int venueID = gene.getVenue().getVenueID();
        int timeSlotID = gene.getTimeSlot().getTimeSlotID();
        venueTimeSlotCount[make_pair(venueID, timeSlotID)]++;

        int level = gene.getModule().getLevel();
        levelTimeSlotCount[make_pair(level, timeSlotID)]++;

        int lecturerID = gene.getModule().getLecturer().getLecturerID();
        lecturerTimeSlotCount[make_pair(lecturerID, timeSlotID)]++;
    }

    // Check for violations and print them
    for (const auto &entry : venueTimeSlotCount)
    {
        if (entry.second > 1)
        {
            cout << "Violation: More than one module in the same slot and venue. VenueID: " << entry.first.first << ", TimeSlotID: " << entry.first.second << endl;
        }
    }

    for (const auto &entry : levelTimeSlotCount)
    {
        if (entry.second > 1)
        {
            cout << "Violation: More than one module at the same level and time slot. Level: " << entry.first.first << ", TimeSlotID: " << entry.first.second << endl;
        }
    }

    for (const auto &entry : lecturerTimeSlotCount)
    {
        if (entry.second > 1)
        {
            cout << "Violation: More than one module for the same lecturer and time slot. LecturerID: " << entry.first.first << ", TimeSlotID: " << entry.first.second << endl;
        }
    }
}

int main()
{
    // Step 0: Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    // Step 1: Initialize Required Data
    initializeTimeSlots(); // Assuming this function initializes all possible time slots
    initializeVenues();    // Assuming this function initializes all possible venues
    initializeLecturers(); // Assuming this function initializes all possible lecturers
    initializeModules();   // Assuming this function initializes all possible modules

    // Define GA parameters
    int POPULATION_SIZE = 50;
    double MUTATION_RATE = 0.2;
    double CROSSOVER_RATE = 0.8;
    int ELITE_COUNT = 2;
    int NUM_GENERATIONS = 100;

    // Step 2: Initialize the First Population
    Population initialPop;
    initialPop.initializeFirstPopulation(POPULATION_SIZE);

    // Step 3: Initialize the Genetic Algorithm
    GeneticAlgorithm GA(initialPop, MUTATION_RATE, CROSSOVER_RATE, ELITE_COUNT);

    // Step 4: Run the Genetic Algorithm
    GA.run(NUM_GENERATIONS);

    // Step 5: Evaluate and Display the Best Solution Found
    Chromosome bestChromosome = GA.getBestChromosome(); // Assuming you add a function to return the best chromosome
    cout << "Best Chromosome: " << endl;

    for (const ScheduledModule &gene : bestChromosome.getGenes())
    {
        // Print information about the gene/module, venue, and time slot
        cout << "Gene: " << endl;
        gene.getModule().printInfo();
        gene.getTimeSlot().printInfo();
        gene.getVenue().printInfo();
    }

    // Evaluate fitness of the best chromosome
    double fitness = bestChromosome.evaluateFitness();
    cout << "Best Chromosome Fitness: " << fitness << endl;

    // Print violations, if any
    printViolations(bestChromosome);

    return 0;
}