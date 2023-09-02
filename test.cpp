#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib> // for rand and srand
#include <ctime>   // for time
#include <algorithm>
#include <random> // for random functions
#include <sstream>

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

    bool operator==(const Lecturer &other) const
    {
        return (this->lecturerID == other.lecturerID &&
                this->lecturerName == other.lecturerName);
    }

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

    bool operator==(const TimeSlot &other) const
    {
        return (this->timeSlotID == other.timeSlotID &&
                this->day == other.day &&
                this->time == other.time);
    }

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

    bool operator==(const Module &other) const
    {
        return (this->moduleID == other.moduleID &&
                this->lecturer == other.lecturer &&
                this->name == other.name &&
                this->level == other.level &&
                this->numberOfStudentsEnrolled == other.numberOfStudentsEnrolled &&
                this->isLab == other.isLab);
    }
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
    allModules.push_back(Module(16, allLecturers[3], "CS436", 4, 15, true));
    allModules.push_back(Module(17, allLecturers[5], "CS443", 4, 13, true));
    allModules.push_back(Module(18, allLecturers[3], "CS456", 4, 14, true));
    allModules.push_back(Module(19, allLecturers[8], "CS431", 4, 16, true));
    allModules.push_back(Module(20, allLecturers[12], "CS437", 4, 19, true));
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

    bool operator==(const Venue &other) const
    {
        return (this->venueID == other.venueID &&
                this->name == other.name &&
                this->capacity == other.capacity &&
                this->isLab == other.isLab);
    }

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

    bool operator==(const ScheduledModule &other) const
    {
        return (
            this->module == other.module &&
            this->timeSlot == other.timeSlot &&
            this->venue == other.venue &&
            this->isLockedVenue == other.isLockedVenue &&
            this->isLockedTimeSlot == other.isLockedTimeSlot &&
            this->isValid == other.isValid);
    }

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

    void printGenesByDay() const
    {
        // Initialize a map to organize the genes by day and time slot
        map<string, map<int, pair<string, string>>> dayTimeSlotMap;

        for (const ScheduledModule &gene : genes)
        {
            string day = gene.getTimeSlot().getDay();            // Assuming TimeSlot has a getDay() method that returns a string
            int timeSlotID = gene.getTimeSlot().getTimeSlotID(); // Assuming TimeSlot has a getID() method
            string moduleCode = gene.getModule().getName();      // Assuming Module has a getName() method
            string venueName = gene.getVenue().getName();        // Assuming Venue has a getName() method

            dayTimeSlotMap[day][timeSlotID] = make_pair(moduleCode, venueName);
        }

        // Now print out the organized information
        for (const auto &dayEntry : dayTimeSlotMap)
        {
            cout << "Day: " << dayEntry.first << endl;

            for (const auto &timeSlotEntry : dayEntry.second)
            {
                cout << " Time Slot: " << timeSlotEntry.first << " - Module: " << timeSlotEntry.second.first << " - Venue: " << timeSlotEntry.second.second << endl;
            }
        }
    }

    void checkGeneSize()
    {
        cout << "The size of genes is: " << genes.size() << endl;
    }

    bool operator==(const Chromosome &other) const
    {
        return this->genes == other.genes; // Assuming genes is a member variable
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
    void removeChromosome(const Chromosome &target)
    {
        auto it = find(chromosomes.begin(), chromosomes.end(), target);
        if (it != chromosomes.end())
        {
            chromosomes.erase(it);
        }
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
            int counter = 0;

            for (const auto &module : allModules)
            {
                // cout << "Size of allModules: " << allModules.size() << endl;
                //  Schedule this module twice, as each module has 4 hours per week.

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
                counter++;
            }
            // cout << "Loop ran " << counter << " times." << endl;
            //  Add this chromosome to the initial population
            addChromosome(chromosome);
            // cout << "the size of the chromosome num ==>" << i + 1;
            chromosome.checkGeneSize();
        }
    }

    vector<Chromosome> getBestNChromosomes(int n)
    {

        vector<Chromosome> sortedChromosomes = chromosomes;

        cout << "Get best, Size of sortedChromosomes Befor sorting: " << sortedChromosomes.size() << endl;

        sort(sortedChromosomes.begin(), sortedChromosomes.end(),
             [](Chromosome &a, Chromosome &b)
             {
                 return a.evaluateFitness() < b.evaluateFitness(); // Assuming lower fitness is better
             });

        cout << "Get best, Size of sortedChromosomes After sorting: " << sortedChromosomes.size() << endl;

        return vector<Chromosome>(sortedChromosomes.begin(), sortedChromosomes.begin() + n);
    }

    vector<Chromosome> getWorstNChromosomes(int n)
    {
        vector<Chromosome> sortedChromosomes = chromosomes;

        cout << "Get worst, Size of sortedChromosomes Before sorting: " << sortedChromosomes.size() << endl;

        sort(sortedChromosomes.begin(), sortedChromosomes.end(),
             [](Chromosome &a, Chromosome &b)
             {
                 return a.evaluateFitness() > b.evaluateFitness(); // Assuming higher fitness is worse
             });

        cout << "Get worst, Size of sortedChromosomes After sorting: " << sortedChromosomes.size() << endl;

        return vector<Chromosome>(sortedChromosomes.end() - n, sortedChromosomes.end());
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

    // Population selectParents()
    // {
    //     vector<Chromosome> selectedParents;
    //     int tournamentSize = 6; // You can change this

    //     for (int i = 0; i < population.getChromosomes().size() - eliteCount; ++i) // Leave space for elites
    //     {
    //         vector<Chromosome> tournament;

    //         // Randomly select k individuals for the tournament
    //         for (int j = 0; j < tournamentSize; ++j)
    //         {
    //             int index = rand() % population.getChromosomes().size();
    //             tournament.push_back(population.getChromosomes()[index]);
    //         }

    //         cout << "Tournament Size: " << tournament.size() << endl;

    //         // Find the best individual in the tournament
    //         Chromosome best = *min_element(
    //             tournament.begin(), tournament.end(),
    //             [](Chromosome &a, Chromosome &b)
    //             {
    //                 return a.evaluateFitness() < b.evaluateFitness(); // Assuming lower fitness is better
    //             });

    //         cout << "Before adding the best individual, selectedParents size: " << selectedParents.size() << endl;
    //         // Add the winner to the list of parents
    //         selectedParents.push_back(best);
    //         cout << "After adding the best individual, selectedParents size: " << selectedParents.size() << endl;
    //     }
    //     cout << "Before returning the selectedParents, selectedParents size: " << selectedParents.size() << endl;
    //     return Population(selectedParents);
    // }
    Population selectParents()
    {
        vector<Chromosome> selectedParents;
        vector<double> cumulativeFitness;
        double totalFitness = 0.0;

        cout << "Starting Roulette Wheel Selection..." << endl;

        // Calculate total fitness and cumulative fitness
        for (auto &chromosome : population.getChromosomes())
        {
            double fitness = chromosome.evaluateFitness();
            totalFitness += fitness;
            cumulativeFitness.push_back(totalFitness);
        }

        cout << "Total Fitness: " << totalFitness << endl;
        cout << "Cumulative Fitness Vector: ";
        for (const auto &val : cumulativeFitness)
        {
            cout << val << " ";
        }
        cout << endl;

        for (int i = 0; i < population.getChromosomes().size() - eliteCount; ++i)
        {
            // Generate a random number between 0 and totalFitness
            double randomFitness = static_cast<double>(rand()) / RAND_MAX * totalFitness;

            cout << "Random Fitness for selection: " << randomFitness << endl;

            // Find the first chromosome whose cumulative fitness is greater than or equal to randomFitness
            auto it = lower_bound(cumulativeFitness.begin(), cumulativeFitness.end(), randomFitness);
            int index = it - cumulativeFitness.begin();

            cout << "Selected Chromosome Index: " << index << endl;

            // Add the selected parent
            selectedParents.push_back(population.getChromosomes()[index]);
        }

        cout << "Number of selected parents: " << selectedParents.size() << endl;

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

    void replacePopulation(const Population &offspringPopulation)
    {
        vector<Chromosome> newOffspring = offspringPopulation.getChromosomes();
        vector<Chromosome> oldElites = this->population.getBestNChromosomes(eliteCount);

        cout << "in--> Selection befor removing elites, Size of population: " << population.getChromosomes().size() << endl;
        cout << "in--> Selection befor removing elites, Size of oldElites: " << oldElites.size() << endl;

        // Remove elites from the old population
        for (const Chromosome &elite : oldElites)
        {
            this->population.removeChromosome(elite);
        }

        cout << "in--> Selection after removing elites, Size of population: " << population.getChromosomes().size() << endl;
        cout << "in--> Selection after removing elites, Size of oldElites: " << oldElites.size() << endl;

        cout << "in--> Selection after removing elites, Size of newOffspring####: " << newOffspring.size() << endl;
        // Get the number of chromosomes to be replaced in the old population
        int numToReplace = newOffspring.size();

        // Get the worst-performing individuals to remove them
        vector<Chromosome> oldWorst = this->population.getWorstNChromosomes(numToReplace);

        cout << "in--> Selection befor removing worst-performing, Size of population: " << population.getChromosomes().size() << endl;

        // Remove worst-performing individuals
        for (const Chromosome &worst : oldWorst)
        {
            this->population.removeChromosome(worst);
        }

        cout << "in--> Selection after removing worst-performing, Size of population: " << population.getChromosomes().size() << endl;

        cout << "in--> Selection before Add new offspring, Size of population: " << population.getChromosomes().size() << endl;

        // Add new offspring
        this->population.addChromosomes(newOffspring);
        cout << "in--> Selection after Add new offspring, Size of population: " << population.getChromosomes().size() << endl;
        cout << "in--> Selection before Add back the elites, Size of population: " << population.getChromosomes().size() << endl;

        // Add back the elites
        this->population.addChromosomes(oldElites);
        cout << "in--> Selection after Add back the elites, Size of population: " << population.getChromosomes().size() << endl;
    }

    void runOneGeneration()
    {
        cout << "Running one generation..." << endl;
        // Check Elitism
        if (eliteCount > population.getChromosomes().size())
        {
            cout << "Error: Elite count greater than population size!" << endl;
            // You may choose to return or throw an exception here
            return;
        }
        cout << "Starting Elitism..." << endl;
        // 1. Elitism
        vector<Chromosome> elites = population.getBestNChromosomes(eliteCount);

        cout << "Size of population before selectParents: " << population.getChromosomes().size() << endl;

        cout << "Completed Elitism. Starting Selection..." << endl;
        // 2. Selection
        Population parents = selectParents();
        cout << "After Selection, Size of parent population: " << parents.getChromosomes().size() << endl;
        cout << "After Selection, Size of population: " << population.getChromosomes().size() << endl;

        parents.addChromosomes(elites); // Add elites
        cout << "After adding the elites to the parents, Size of parent population: " << parents.getChromosomes().size() << endl;
        cout << "After adding the elites to the parents, Size of population: " << population.getChromosomes().size() << endl;

        cout << "Completed Selection. Starting Crossover and Mutation..." << endl;

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
                cout << "Before mutation, population size: " << population.getChromosomes().size() << endl;
                cout << "Before mutation, Size of offspring population: " << offspring.getChromosomes().size() << endl;
                cout << "Before mutation, Size of parent population: " << parents.getChromosomes().size() << endl;
                mutate(child);
                cout << "After mutation, population size: " << population.getChromosomes().size() << endl;
                cout << "After mutation, Size of offspring population: " << offspring.getChromosomes().size() << endl;
                cout << "After mutation, Size of parent population: " << parents.getChromosomes().size() << endl;
            }
            cout << "----------> offspring population: " << offspring.getChromosomes().size() << endl;

            offspring.addChromosome(child);
        }
        cout << "After Crossover and Mutation, population size: " << population.getChromosomes().size() << endl;
        cout << "After Crossover and Mutation, Size of offspring population: " << offspring.getChromosomes().size() << endl;
        cout << "After Crossover and Mutation, Size of parent population: " << parents.getChromosomes().size() << endl;

        cout << "Before Replacement, population size: " << population.getChromosomes().size() << endl;
        cout << "Before Replacement, Size of offspring population: " << offspring.getChromosomes().size() << endl;
        cout << "Before Replacement, Size of parent population: " << parents.getChromosomes().size() << endl;

        cout << "Completed Crossover and Mutation. Starting Replacement..." << endl;

        // 4. Replacement
        replacePopulation(offspring);
        cout << "After Replacement, population size: " << population.getChromosomes().size() << endl;
        cout << "After Replacement, Size of offspring population: " << offspring.getChromosomes().size() << endl;
        cout << "After Replacement, Size of parent population: " << parents.getChromosomes().size() << endl;

        cout << "Completed Replacement." << endl;

        cout << "One generation completed." << endl;
    }

    // Method to run the Genetic Algorithm for 'n' generations
    void run(int numberOfGenerations)
    {
        cout << "Starting GA run for " << numberOfGenerations << " generations." << endl;
        for (int i = 0; i < numberOfGenerations; ++i)
        {
            cout << "Starting generation " << i + 1 << endl;
            runOneGeneration();
            cout << "Completed generation " << i + 1 << endl;
        }
        cout << "GA run completed." << endl;
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
    cout << "Seeding random number generator..." << endl;
    // Step 0: Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    cout << "Initializing required data..." << endl;
    // Step 1: Initialize Required Data
    initializeTimeSlots(); // Assuming this function initializes all possible time slots
    initializeVenues();    // Assuming this function initializes all possible venues
    initializeLecturers(); // Assuming this function initializes all possible lecturers
    initializeModules();   // Assuming this function initializes all possible modules

    // Define GA parameters
    int POPULATION_SIZE = 50;
    double MUTATION_RATE = 0.05;
    double CROSSOVER_RATE = 0.1;
    int ELITE_COUNT = 2;
    int NUM_GENERATIONS = 3;

    cout << "Initializing first population..." << endl;
    // Step 2: Initialize the First Population
    Population initialPop;
    initialPop.initializeFirstPopulation(POPULATION_SIZE);
    cout << "Initial population size: " << initialPop.getChromosomes().size() << endl;

    cout << "Initializing Genetic Algorithm..." << endl;
    // Step 3: Initialize the Genetic Algorithm
    GeneticAlgorithm GA(initialPop, MUTATION_RATE, CROSSOVER_RATE, ELITE_COUNT);

    cout << "Running Genetic Algorithm..." << endl;
    // Step 4: Run the Genetic Algorithm
    GA.run(NUM_GENERATIONS);
    cout << "Genetic Algorithm completed." << endl;

    // Step 5: Evaluate and Display the Best Solution Found
    Chromosome bestChromosome = GA.getBestChromosome(); // Assuming you add a function to return the best chromosome
    cout << "Best Chromosome: " << endl;

    int counter = 1;
    for (const ScheduledModule &gene : bestChromosome.getGenes())
    {
        // Print information about the gene/module, venue, and time slot
        cout << "Gene: " << counter << endl;
        gene.getModule().printInfo();
        gene.getTimeSlot().printInfo();
        gene.getVenue().printInfo();
        counter++;
    }

    // Evaluate fitness of the best chromosome
    double fitness = bestChromosome.evaluateFitness();
    cout << "Best Chromosome Fitness: " << fitness << endl;
    bestChromosome.checkGeneSize();
    bestChromosome.printGenesByDay();

    // Print violations, if any
    // printViolations(bestChromosome);

    return 0;
}