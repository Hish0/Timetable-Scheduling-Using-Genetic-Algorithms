#include "Chromosome.h"
#include <iostream>
#include <map>

using namespace std;

// Default Constructor
Chromosome::Chromosome() {}

// Parameterized Constructor
Chromosome::Chromosome(const vector<ScheduledModule> &genes) : genes(genes) {}

void Chromosome::addGene(const ScheduledModule &gene)
{
    genes.push_back(gene);
}

vector<ScheduledModule> Chromosome::getGenes() const
{
    return genes;
}

void Chromosome::setGenes(const vector<ScheduledModule> &newGenes)
{
    genes = newGenes;
}

void Chromosome::printGenesByDay() const
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

void Chromosome::checkGeneSize()
{
    cout << "The size of genes is: " << genes.size() << endl;
}

bool Chromosome::operator==(const Chromosome &other) const
{
    return this->genes == other.genes;
}

double Chromosome::evaluateFitness()
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
            fitness += 10; // Flat penalty for mismatched types
        }
    }
    ////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////constraint no6///////////////////////////////////
    // Initialize a map to hold the count of modules scheduled for each day for each module
    map<pair<int, int>, int> moduleDayCount;
    const int numberOfTimeSlotsPerDay = 8; // Adjust this based on your specific timetable

    for (const ScheduledModule &gene : genes)
    {
        int moduleID = gene.getModule().getModuleID();
        int timeSlotID = gene.getTimeSlot().getTimeSlotID();
        int day = (timeSlotID - 1) / numberOfTimeSlotsPerDay;

        pair<int, int> moduleDayPair = make_pair(moduleID, day);
        moduleDayCount[moduleDayPair]++;
    }

    // Check for violations of the adjusted sixth constraint
    for (const auto &entry : moduleDayCount)
    {
        int moduleID = entry.first.first;
        int allowedSlotsPerDay = (getModuleHours(moduleID) > 2) ? 2 : 1; // Assuming getModuleHours returns the number of hours for a module

        if (entry.second > allowedSlotsPerDay)
        {
            fitness += (entry.second - allowedSlotsPerDay) * 10; // Adding 10 for each extra slot on the same day
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////

    // ... (evaluate other constraints here)

    return fitness;
}

bool Chromosome::isDiverse(const Chromosome &other) const
{
    int differingGenes = 0;
    const int diversityThreshold = 3; // You can adjust this value

    // Assuming both chromosomes have the same number of genes
    for (size_t i = 0; i < genes.size(); ++i)
    {
        if (!(genes[i] == other.getGenes()[i])) // Assuming you have implemented the equality operator for ScheduledModule
        {
            differingGenes++;
        }
    }

    return (differingGenes >= diversityThreshold);
}

int Chromosome::getModuleHours(int moduleID) const
{
    for (const ScheduledModule &gene : genes)
    {
        if (gene.getModule().getModuleID() == moduleID)
        {
            return gene.getModule().getNumberOfTimeSlots();
        }
    }
    cout << "error in number of hours";
    exit(1);
    return 0; // Return 0 if the module ID was not found (you might want to handle this case differently)
}
