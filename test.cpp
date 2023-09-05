#include <iostream>
#include <cstdlib> // for rand and srand
#include <ctime>   // for time

#include "GeneticAlgorithm/GeneticAlgorithm.h"

using namespace std;
vector<Lecturer> allLecturers; // Global array to hold all lecturers
vector<TimeSlot> allTimeSlots; // Global array to hold all time slots
vector<Module> allModules;     // Global array to hold all modules
vector<Venue> allVenues;       // Global array to hold all venues
vector<Chromosome> initialPopulation;

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
    int POPULATION_SIZE = 10;
    double MUTATION_RATE = 0.1;
    double CROSSOVER_RATE = 0.3;
    int ELITE_COUNT = 5;
    int NUM_GENERATIONS = 3;

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

    GA.printTotalFitnessHistory();

    return 0;
}