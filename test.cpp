#include <iostream>
#include <cstdlib> // for rand and srand
#include <ctime>   // for time
#include <chrono>
#include "GeneticAlgorithm/GeneticAlgorithm.h"

using namespace std;
vector<Lecturer> allLecturers; // Global array to hold all lecturers
vector<TimeSlot> allTimeSlots; // Global array to hold all time slots
vector<Module> allModules;     // Global array to hold all modules
vector<Venue> allVenues;       // Global array to hold all venues
vector<Chromosome> initialPopulation;

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

    //  Step 2: Initialize the First Population
    Population initialPop;
    initialPop.initializeFirstPopulation(POPULATION_SIZE);

    // Step 3: Initialize the Genetic Algorithm
    GeneticAlgorithm GA(initialPop, MUTATION_RATE, CROSSOVER_RATE, ELITE_COUNT);

    // Step 4: Run the Genetic Algorithm
    GA.run(NUM_GENERATIONS);

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