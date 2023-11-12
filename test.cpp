#include <iostream>
#include <cstdlib> // for rand and srand
#include <ctime>   // for time
#include <chrono>
#include <fstream>
#include "GeneticAlgorithm/GeneticAlgorithm.h"

using namespace std;
vector<Lecturer> allLecturers; // Global array to hold all lecturers
vector<TimeSlot> allTimeSlots; // Global array to hold all time slots
vector<Module> allModules;     // Global array to hold all modules
vector<Venue> allVenues;       // Global array to hold all venues
vector<Chromosome> initialPopulation;

void chromosomeToTextFile(const Chromosome &chromosome, const string &filename)
{
    ofstream file(filename);
    int counter = 1;
    for (const ScheduledModule &gene : chromosome.getGenes())
    {
        file << "Gene: " << counter << "\n";
        // Write Module, TimeSlot, and Venue info
        file << gene.getModule().toString() << "\n";
        file << gene.getTimeSlot().toString() << "\n";
        file << gene.getVenue().toString() << "\n";
        // Write additional gene attributes
        file << "IsLockedVenue: " << gene.getIsLockedVenue() << "\n";
        file << "IsLockedTimeSlot: " << gene.getIsLockedTimeSlot() << "\n";
        file << "IsValid: " << gene.getIsValid() << "\n";
        file << "IsFirstSlot: " << gene.getIsFirstSlot() << "\n";
        file << "IsOneSlot: " << gene.getIsOneSlot() << "\n";
        counter++;
    }
    file.close();
}

Chromosome textFileToChromosome(const string &filename)
{
    ifstream file(filename);
    string line;
    Chromosome chromosome;

    while (getline(file, line))
    {
        if (line.starts_with("Gene:"))
        {
            ScheduledModule scheduledModule;
            // Read and set Module info
            getline(file, line);
            Module module;
            module.fromString(line);
            scheduledModule.setModule(module);

            // Read and set TimeSlot info
            getline(file, line);
            TimeSlot timeSlot;
            timeSlot.fromString(line);
            scheduledModule.setTimeSlot(timeSlot);

            // Read and set Venue info
            getline(file, line);
            Venue venue;
            venue.fromString(line);
            scheduledModule.setVenue(venue);

            // Read and set additional attributes
            getline(file, line);
            scheduledModule.setIsLockedVenue(parseBool(line));
            getline(file, line);
            scheduledModule.setIsLockedTimeSlot(parseBool(line));
            getline(file, line);
            scheduledModule.setIsValid(parseBool(line));
            getline(file, line);
            scheduledModule.setIsFirstSlot(parseBool(line));
            getline(file, line);
            scheduledModule.setIsOneSlot(parseBool(line));

            // Add the ScheduledModule to the Chromosome
            chromosome.addGene(scheduledModule);
        }
    }

    file.close();
    return chromosome;
}

int main()
{
    // Step alpha: Capture the starting time
    auto start = std::chrono::high_resolution_clock::now();

    // Step 0: Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    // Step 1: Initialize Required Data
    initializeTimeSlots();       // Assuming this function initializes all possible time slots
    initializeVenues();          // Assuming this function initializes all possible venues
    initializeLecturers();       // Assuming this function initializes all possible lecturers
    initializeModules();         // Assuming this function initializes all possible modules
    initializeCrossoverPoints(); // Assuming this function initializes all possible CrossoverPoints

    // Define GA parameters
    int POPULATION_SIZE = 50;
    double MUTATION_RATE = 0.1;
    double CROSSOVER_RATE = 0.75;
    int ELITE_COUNT = 2;
    int NUM_GENERATIONS = 10000;
    /////////////////////////////////////////////////

    // std::string moduleData = "Module ID: 1, Lecturer: Dr. Mo3eed 1, Name: CS100, Level: 1, Enrolled Students: 100, Is Lab: No, Number of time slots: 5";
    // std::string timeSlotData = "TimeSlot ID: 3, Day: Saturday, Time: 10:00 AM";
    // std::string venueData = "Venue ID: 10, Name: HALL 74, Capacity: 200, Is Lab: No";

    // // Create a Module object
    // Module myModule;
    // TimeSlot myTimeSlot;
    // Venue myVenue;

    // // Use fromString to initialize the Module object
    // myModule.fromString(moduleData);
    // myTimeSlot.fromString(timeSlotData);
    // myVenue.fromString(venueData);

    // myModule.printInfo();
    // myTimeSlot.printInfo();
    // myVenue.printInfo();

    Chromosome reconstructedChromosome = textFileToChromosome("chromosome_data.txt");
    //  chromosomeToTextFile(reconstructedChromosome, "chromosome_data_testing.txt");
    // int counter = 1;
    // for (const ScheduledModule &gene : reconstructedChromosome.getGenes())
    // {
    //     // Print information about the gene/module, venue, and time slot
    //     cout << "Gene: " << counter << endl;
    //     gene.getModule().printInfo();
    //     gene.getTimeSlot().printInfo();
    //     gene.getVenue().printInfo();
    //     cout << "IsLockedVenue: " << gene.getIsLockedVenue() << endl;
    //     cout << "IsLockedTimeSlot: " << gene.getIsLockedTimeSlot() << endl;
    //     cout << "IsValid: " << gene.getIsValid() << endl;
    //     cout << "IsFirstSlot: " << gene.getIsFirstSlot() << endl;
    //     cout << "IsOneSlot: " << gene.getIsOneSlot() << endl;
    //     counter++;
    // }
    cout << "Best Chromosome Fitness:######## " << reconstructedChromosome.evaluateFitness() << endl;

    /////////////////////////////////////////////////
    //  Step 2: Initialize the First Population
    Population initialPop;
    // initialPop.initializeFirstPopulation(POPULATION_SIZE);
    initialPop.initializePopulationChromosome(POPULATION_SIZE, reconstructedChromosome);

    // Step 3: Initialize the Genetic Algorithm
    GeneticAlgorithm GA(initialPop, MUTATION_RATE, CROSSOVER_RATE, ELITE_COUNT);

    // Step 4: Run the Genetic Algorithm
    GA.run(NUM_GENERATIONS);

    // Step 5: Evaluate and Display the Best Solution Found
    Chromosome bestChromosome = GA.getBestChromosome(); // Assuming you add a function to return the best chromosome
    // cout << "Best Chromosome: " << endl;

    // int counter = 1;
    // for (const ScheduledModule &gene : bestChromosome.getGenes())
    // {
    //     // Print information about the gene/module, venue, and time slot
    //     cout << "Gene: " << counter << endl;
    //     gene.getModule().printInfo();
    //     gene.getTimeSlot().printInfo();
    //     gene.getVenue().printInfo();
    //     cout << "IsLockedVenue: " << gene.getIsLockedVenue() << endl;
    //     cout << "IsLockedTimeSlot: " << gene.getIsLockedTimeSlot() << endl;
    //     cout << "IsValid: " << gene.getIsValid() << endl;
    //     cout << "IsFirstSlot: " << gene.getIsFirstSlot() << endl;
    //     cout << "IsOneSlot: " << gene.getIsOneSlot() << endl;
    //     counter++;
    // }

    // save the best chromosome in a file named "chromosome_data"
    chromosomeToTextFile(bestChromosome, "chromosome_data.txt");

    // Evaluate fitness of the best chromosome
    double fitness = bestChromosome.evaluateFitness();
    cout << "Best Chromosome Fitness: " << fitness << endl;

    GA.printProgress();
    ////////////////////////////////////////
    // Call the function to check for violations
    std::pair<int, std::string> violation = bestChromosome.catchViolation();

    // Check if a violation was detected
    if (violation.first != -1)
    {
        // A violation was detected
        std::cout << "Violation detected at gene index " << violation.first << ": " << violation.second << std::endl;
    }
    else
    {
        // No violation was detected
        std::cout << violation.second << std::endl;
    }
    ////////////////////////////////////////
    // Step 6: Capture the ending time
    auto end = std::chrono::high_resolution_clock::now();

    // Compute the total duration in seconds
    auto totalSeconds = std::chrono::duration_cast<std::chrono::seconds>(end - start);

    // Extract minutes and seconds
    auto minutes = totalSeconds.count() / 60;
    auto seconds = totalSeconds.count() % 60;

    std::cout << "Time taken to finish is: " << minutes << " minutes and " << seconds << " seconds" << std::endl;

    return 0;
}